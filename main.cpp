/*****************************************************************************************************************************************************
Program: MathTutorV4
Programmers: Jacob Karsky, and Brayden Tolle
Date: 10/30/2026
Section 3: 12:00
Github Repo:https://github.com/Insanedoomed/MathTutorV5
Description: A wizard/magic themed math tutor that displays the intro featuring
ASCII art and jokes, it then asks a simple math question which is checked for correctness
and then it outputs an end of program message.
****************************************************************************************************************************************************/
#include <cctype> // Checks numbers and characters
#include <cstdlib> // for srand and rand
#include <ctime> // for time seeding
#include <iomanip> // Adds for width issues for our box (We asked jesse how to)
#include <iostream> //required for cout and cin
#include <limits> // for the use of numeric_limits
#include <sstream> // ostringstream
#include <string> // for string data types
#include <vector> // holds data

using namespace std; //sets standard namespace

void DisplayGameIntro();

string GetUserName();

int GetNumericValue();

string AskToPlayAgain(string userName);

void DisplaySummaryReport(const vector<vector<int>> &questions);

bool GiveThreeAttempts(const string &userName, int questionNumber, int mathLevel, int leftNum, char mathSymbol,
                       int rightNum, int correctAns, vector<int> &row);

void CheckForLevelRangeChange(int &totalCorrect, int &totalIncorrect, int &mathLevel, int &levelRange);

void boxLine(const string &text, int width) {
    cout << " | " << left << setw(width - 2) << text << " |" << endl;
} // void = returns nothing, it only prints

const int MAX_ATTEMPTS = 3; // Our max attempts; stays the same throughout program
const int LEVEL_RANGE = 10; // Starting range of 1-10; adds ten each level up
const int BOX_INNER = 40; // number of characters between the two | borders

//start of the main function
int main() {
    //initializing variables
    srand(time(0)); // Seed first; used to randomize the numeric operator (+,-,*,/)


    enum MathType { MT_ADD = 1, MT_SUB = 2, MT_MUL = 3, MT_DIV = 4 }; // Our Enum for all the problems

    MathType mathType = MT_ADD; // sets MathType to a one

    vector<vector<int> > questions; // Vector for our tabel. Sets questions as a holder

    int correctAns; // The correct answer

    int rightNum = 0; // the 2nd random number between 1 and level change
    int leftNum = 0; // the 1st random number between 1 and level change
    int temp = 0; // Uses to swap two values

    int questionNumber = 0; // Current question number
    int LevelRange = LEVEL_RANGE; // turns it into a variable that later is used to check for equality

    int mathLevel = 1; // Current Math level
    char mathSymbol; // {+, -, *, /}
    int totalIncorrect = 0; // Current number of incorrect questions; used later for leveling down
    int totalCorrect = 0; // Current number of Correct questions; used for later for leveling up

    string border = " |" + string(BOX_INNER, '-') + "|"; // builds the box's top/bottom line: " |" + 40 dashes + "|"
    string userName; // User's name
    string userInput = "?"; //User input
    bool isCorrect = false;

    DisplayGameIntro();

    userName = GetUserName();


    // start of loop
    do {
        questionNumber++; // each loop, it adds one to question each time the user responds yes

        mathType = static_cast<MathType>(rand() % 4 + 1); //Turning into random

        rightNum = ((rand() % LevelRange) + 1); // Value from 1-whatever level the user is
        leftNum = ((rand() % LevelRange) + 1); // Value from 1-whatever level the user is


        //Switch to calculate the correct answer and which math operator to display
        switch (mathType) {
            case MT_ADD: // addition
                correctAns = leftNum + rightNum;
                mathSymbol = '+';
                break;

            case MT_SUB: // subtraction
                // Ensure the left number is the bigger one to avoid negatives
                if (leftNum < rightNum) {
                    temp = leftNum;
                    leftNum = rightNum;
                    rightNum = temp;
                }
                correctAns = leftNum - rightNum;
                mathSymbol = '-';
                break;

            case MT_MUL: // multiplication
                correctAns = leftNum * rightNum;
                mathSymbol = '*';
                break;

            case MT_DIV: // division
                // Build the dividend so the answer is always a whole number
                correctAns = leftNum;
                leftNum = leftNum * rightNum;
                mathSymbol = '/';
                break;

            default: //error handling - should never happen
                cout << "Invalid question type: " << mathType << endl;
                cout << "Program ended with an error -1" << endl;
                cout << "Please report this error to Brayden Tolle or Barnabas Htoo" << endl;
                return -1;
        } //End of the switch

        //Storing the math level, left number, math symbol, right number, and correct answer
        vector<int> row = {mathLevel, leftNum, mathSymbol, rightNum, correctAns};

        isCorrect = GiveThreeAttempts(userName, questionNumber, mathLevel, leftNum, mathSymbol, rightNum, correctAns,
                                      row);
        if (isCorrect) {
            totalCorrect++;
        } else {
            totalIncorrect++;
        }

        questions.push_back(row); // add the data of row to the end of the 2D vector

        CheckForLevelRangeChange(totalCorrect, totalIncorrect, mathLevel, LevelRange);

        getline(cin, userInput); // Clears user input

        userInput = AskToPlayAgain(userName);

    } while (userInput == "y" || userInput == "yes"); // User's answer to the yes or no


    DisplaySummaryReport(questions);

    cout << "Keep Calm and do math!" << endl; // closing messages printed outside the box
    cout << "This is MathTutorV4, thanks for playing!" << endl;
    cout << "Thank you this is all for now!" << endl;

    return 0;
} // end of main

//*********************************************************************************************************************
//* Display the game intro and some jokes
//* Params:
//* Return: N/A
// ********************************************************************************************************************
void DisplayGameIntro() {
    //Display the program's header
    cout <<
            "(*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*]"
            << endl;
    cout << "                       {*} Welcome to the tower of the wizard of magical math tutoring! (V5) {*}" << endl;
    cout << R"(
,---.    ,---.   ____   ,---------. .---.  .---.    .--.      .--..-./`)  ____..--'   ____    .-------.     ______
|    \  /    | .'  __ `.\          \|   |  |_ _|    |  |_     |  |\ .-.')|        | .'  __ `. |  _ _   \   |    _ `''.
|  ,  \/  ,  |/   '  \  \`--.  ,---'|   |  ( ' )    | _( )_   |  |/ `-' \|   .-'  '/   '  \  \| ( ' )  |   | _ | ) _  \
|  |\_   /|  ||___|  /  |   |   \   |   '-(_{;}_)   |(_ o _)  |  | `-'`"`|.-'.'   /|___|  /  ||(_ o _) /   |( ''_'  ) |
|  _( )_/ |  |   _.-`   |   :_ _:   |      (_,_)    | (_,_) \ |  | .---.    /   _/    _.-`   || (_,_).' __ | . (_) `. |
| (_ o _) |  |.'   _    |   (_I_)   | _ _--.   |    |  |/    \|  | |   |  .'._( )_ .'   _    ||  |\ \  |  ||(_    ._) '
|  (_,_)  |  ||  _( )_  |  (_(=)_)  |( ' ) |   |    |  '  /\  `  | |   |.'  (_'o._)|  _( )_  ||  | \ `'   /|  (_.\.' /
|  |      |  |\ (_ o _) /   (_I_)   (_{;}_)|   |    |    /  \    | |   ||    (_,_)|\ (_ o _) /|  |  \    / |       .'
'--'      '--' '.(_,_).'    '---'   '(_,_) '---'    `---'    `---` '---'|_________| '.(_,_).' ''-'   `'-'  '-----'`

                                                                                                                                 )"
            << endl;
    //Display the program's jokes
    cout <<
            "(*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*]"
            << endl;
    cout << R"(A wise wizards words:
        (*) What's a wizard's favorite school subject? spell-gebra!
        (*) Why did the sorcerer break his calculator? He wanted to do math-a-magics in his head!
        (*) What is a witch's favorite shape? A Hex-agon!
        (*) What do you call a snake that is 3.14 feet long? A Pi-thon!)" << endl << endl;

    cout <<
            "(*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*]"
            << endl;
    return;
} // end of DisplayGameIntro

//*********************************************************************************************************************
//* Asks the user's name
//* Params:
// *Return: User's Name as a string
// ********************************************************************************************************************
string GetUserName() {
    string userName = "?";
    //obtaining user's name and welcoming the user
    cout << "What is your name young apprentice?" << endl;
    getline(cin, userName); // handle for spaces in a person's name
    cout << "" << endl;
    //math question and answer
    cout << "Ah... " << userName <<
            "! So you have finally found me. If you truly seek the knowledge hidden within these ancient halls," <<
            endl;
    cout << " you must first prove your mind is sharp." << endl;
    cout << endl;
    return userName;
} // end of get userName

//*********************************************************************************************************************
//* makes sure the user enters a valid input
//* Params:
// *Return: User's input as a number
// ********************************************************************************************************************
int GetNumericValue() {
    int userAnswer = 0;
    //Start of Loop that loops until the user enters a valid input
    while (!(cin >> userAnswer)) {
        cin.clear(); // clears the cin error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores the max input, up to '\n'
        cout << "Invalid answer apprentice!" << endl;
        cout << "Please enter a number (like 1,2,3), Apprentice!" << endl;
    }
    return userAnswer;
} // end of loop that handles correct user data

//*********************************************************************************************************************
//* Asks if the user wants another question
//* Params: string user's name
// *Return: user's input (y, yes, n, no)
// ********************************************************************************************************************
string AskToPlayAgain(string userName) {
    string userInput = "?";
    while (true) {
        // asks the user if they want another question
        cout << "Would you like another question, Apprentice? (y=yes/n=no)" << endl;
        getline(cin, userInput);

        for (int i = 0; i < userInput.length(); i++) {
            userInput[i] = tolower(userInput[i]);
        }
        // user chooses yes or no
        if (userInput == "y" || userInput == "yes" ||
            userInput == "n" || userInput == "no") {
        }
        cout << "Please enter y, yes, n, no" << endl;
    }
    return userInput;
}// End of AskToPlayAgain

//*********************************************************************************************************************
//* Display the summary report and grand totals
//* Params:
// *Return: N/A
// ********************************************************************************************************************
void DisplaySummaryReport(const vector<vector<int>> &questions) {

    int mathLevel = 1; // level
    int leftNum = 0; // 1st number
    char mathSymbol; // {+, -, *, /}
    int rightNum = 0; // 2nd number
    int correctAns; // The correct answer
    int attempt = 0; // attempts it took (0 = failed)
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int totalQuestions = 0;
    int average = 0;

    string border = " |" + string(BOX_INNER, '-') + "|";


    // ---------- Summary box ----------

    boxLine("    Math Tutor Summary Report", BOX_INNER);
    cout << border << endl;
    boxLine("", BOX_INNER);
    boxLine("Levels:    Questions       Attempts", BOX_INNER);
    boxLine("______  _______________   __________", BOX_INNER);

    totalCorrect = 0;
    totalIncorrect = 0;

    //
    for (int i = 0; i < questions.size(); i++) {
        // For each saved question: rebuild its table row, count it right/wrong, and print it inside the box
        mathLevel = questions.at(i).at(0);
        leftNum = questions.at(i).at(1);
        mathSymbol = static_cast<char>(questions.at(i).at(2));
        rightNum = questions.at(i).at(3);
        correctAns = questions.at(i).at(4);
        attempt = questions.at(i).at(5);

        ostringstream row; // builds the row as text so the box can pad it
        row << " " << setw(2) << right << mathLevel << " "
                << setw(8) << right << leftNum << " "
                << mathSymbol << " "
                << setw(2) << left << rightNum << " = "
                << setw(7) << left << correctAns << " ";

        if (attempt != 0) {
            row << "    " << attempt;
            totalCorrect++;
        } else {
            row << "Incorrect";
            totalIncorrect++;
        }
        boxLine(row.str(), BOX_INNER); // read: pass the built-up text to boxLine
    }
    // Calculates the final stats and prints them in a second section of the box, followed by the goodbye messages
    totalQuestions = questions.size(); // total questions asked = number of rows saved in the vector
    average = (totalCorrect * 100) / totalQuestions; // percent correct (integer math, so it rounds down)

    cout << border << endl; // line separating the table from the totals

    ostringstream line; // reusable stream for building each totals row as text
    line << "Total Questions : " << totalQuestions;
    boxLine(line.str(), BOX_INNER); // print the row inside the box
    line.str(""); // clear the stream so the next row starts fresh
    line << "Total Correct   : " << totalCorrect;
    boxLine(line.str(), BOX_INNER);
    line.str("");
    line << "Total Incorrect : " << totalIncorrect;
    boxLine(line.str(), BOX_INNER);
    line.str("");
    line << "Average Correct : " << average << "%";
    boxLine(line.str(), BOX_INNER);

    cout << border << endl; // bottom of the box
    cout << endl;

    // Setting the different range average number to show different output accordingly
    if (average >= 95) {
        cout << border << endl;
        boxLine("Fantastic apprentice Grade:A+", BOX_INNER);
        cout << border << endl;
        cout << endl;
    } else if (average >= 90) {
        cout << border << endl;
        boxLine("Way to go apprentice! Grade:A", BOX_INNER);
        cout << border << endl;
    } else if (average >= 85) {
        cout << border << endl;
        boxLine("Nice apprentice! Way to work through Grade:B+", BOX_INNER);
        cout << border << endl;
    } else if (average >= 80) {
        cout << border << endl;
        boxLine("   Good Job apprentice Grade:B!", BOX_INNER);
        cout << border << endl;
    } else if (average >= 75) {
        cout << border << endl;
        boxLine("Nice work apprentice! Grade:C+", BOX_INNER);
        cout << border << endl;
    } else if (average >= 70) {
        cout << border << endl;
        boxLine("Way to power through! Grade:C", BOX_INNER);
        cout << border << endl;
    } else if (average >= 65) {
        cout << border << endl;
        boxLine("Great job apprentice! Grade:D+", BOX_INNER);
        cout << border << endl;
    } else if (average >= 60) {
        cout << border << endl;
        boxLine("Good Work apprentice! Grade:D", BOX_INNER);
        cout << border << endl;
    } else if (average >= 55) {
        cout << border << endl;
        boxLine("Could be worse apprentice. Grade: F+", BOX_INNER);
        cout << border << endl;
    } else {
        cout << border << endl;
        boxLine("There is work to be done! Grade: F", BOX_INNER);
        cout << border << endl;
    }
} // end of DisplaySummaryReport

//*********************************************************************************************************************
//* Display
//* Params:
// *Return:
// ********************************************************************************************************************
bool GiveThreeAttempts(const string &userName, int questionNumber, int mathLevel, int leftNum, char mathSymbol,
                       int rightNum, int correctAns, vector<int> &row) {
    int userAnswer = 0;

    for (int i = 1; i <= MAX_ATTEMPTS; i++) {
        cout << " |----------------------------------|" << endl;
        cout << " | Question: " << left << setw(23) << questionNumber << "|" << endl;
        cout << " | Attempts: " << i << " out of " << left << setw(14) << MAX_ATTEMPTS << "|" << endl;
        cout << " | MathLevel: " << left << setw(22) << mathLevel << "|" << endl;
        cout << " |----------------------------------|" << endl;
        cout << endl;
        cout << userName << ", what is " << leftNum << " " << mathSymbol << " " << rightNum << "?" << endl;
        cout << endl;

        userAnswer = GetNumericValue();

        if (userAnswer == correctAns) {
            cout << "Good job! You Got The Question Right!" << endl;
            cout << endl;
            row.push_back(i); // number of attempts it took
            return true;
        }

        if (i < MAX_ATTEMPTS) {
            cout << "Not quite, apprentice!" << endl;
            cout << endl;
        } else {
            cout << "I'm So Disappointed In You Apprentice..." << endl;
            cout << "You should've gotten that right..." << endl;
            cout << " |----------------------------------|" << endl;
            cout << " | CorrectAnswer: " << left << setw(18) << correctAns << "|" << endl;
            cout << " |----------------------------------|" << endl;
            cout << endl;
            row.push_back(0); // 0 = out of attempts
        }
    }
    return false;
}

//*********************************************************************************************************************
//* Display
//* Params:
// *Return:
// ********************************************************************************************************************
void CheckForLevelRangeChange(int &totalCorrect, int &totalIncorrect, int &mathLevel, int &levelRange) {
    if (totalCorrect >= 3) {
        mathLevel++;
        levelRange += LEVEL_RANGE;
        totalCorrect = 0; // clears it for next level.
        totalIncorrect = 0; // clears it for next level.

        cout << "You have Advanced to the next level" << endl;
        cout << " |----------------------------------|" << endl;
        cout << " | NumUp: " << left << setw(26) << levelRange << "|" << endl;
        cout << " | LevelUp: " << left << setw(24) << mathLevel << "|" << endl;
        cout << " |----------------------------------|" << endl;
        cout << endl;
    }
    // leveling down
    else if (totalIncorrect >= 1) {
        //totalIncorrect >= 1(3 wrong each question = leveldown.| totalIncorrect >= 3(Get 3 questions wrong(9 trys) which levels down
        if (levelRange > LEVEL_RANGE) {
            mathLevel--;
            levelRange -= LEVEL_RANGE;

            cout << "You have moved down a level" << endl;
            cout << " |----------------------------------|" << endl;
            cout << " | NumDown: " << left << setw(24) << levelRange << "|" << endl;
            cout << " | LevelDown: " << left << setw(22) << mathLevel << "|" << endl;
            cout << " |----------------------------------|" << endl;
            cout << endl;
        }
        totalCorrect = 0; // clears total correct
        totalIncorrect = 0; // clears total incorrect
    }
}
