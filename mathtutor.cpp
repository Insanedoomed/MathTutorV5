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
#include "mathtutor.h"
#include <cctype> // Checks numbers and characters
#include <cstdlib> // for srand and rand
#include <iostream> //required for cout and cin
#include <limits> // for the use of numeric_limits
#include <string> // for string data types
#include <vector> // holds data
#include <iomanip> //Adds for width issues for our box (We asked jesse how to)

using namespace std;//sets standard namespace

const int MAX_ATTEMPTS = 3; // Our max attempts; stays the same throughout program

void boxLine(const string &text, int width) {
    cout << " | " << left << setw(width - 2) << text << " |" << endl;
}


//*********************************************************************************************************************
//* Display the game intro and some jokes
//* Params: none
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
//* Params: none
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
//* Params: none
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
        cout << "Would you like another question, Apprentice? (y=yes/n=no)" << endl;
        getline(cin, userInput);

        for (int i = 0; i < userInput.length(); i++) {
            userInput[i] = tolower(userInput[i]);
        }

        if (userInput == "y" || userInput == "yes" ||
            userInput == "n" || userInput == "no") {
            return userInput;
        }
        cout << "Please enter y, yes, n, no" << endl;
    }
} // End of AskToPlayAgain

//*********************************************************************************************************************
//* Display the summary report and grand totals
//* Params: const vector<vector<int> > &questions
// *Return: N/A
// ********************************************************************************************************************
void DisplaySummaryReport(const vector<vector<int> > &questions) {
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
    return;
} // end of DisplaySummaryReport

//*********************************************************************************************************************
//* Display: This will display the Level you're on and tell you how many attempts you have out of how much you have left
//and if you get it right or wrong and also print correct answer if you get all 3 wrong.
//* Params: const string &userName, vector<int> &question
// *Return:false
// ********************************************************************************************************************
bool GiveThreeAttempts(const string &userName, vector<int> &question,int questionNumber) {
    int mathLevel = question.at(0);
    int leftNum = question.at(1);
    char mathSymbol = static_cast<char>(question.at(2));
    int rightNum = question.at(3);
    int correctAns = question.at(4);

    ostringstream questionText;
    questionText << leftNum << " " << mathSymbol << " " << rightNum;

    string border = " |" + string(BOX_INNER, '-') + "|";

    int userAnswer = 0;
    int attemptused = 0;
    bool isCorrect = false;

    for (int i = 1; i <= MAX_ATTEMPTS && !isCorrect; i++) {
        // show the question inside a box
        ostringstream header;
        cout << " |----------------------------------|" << endl;
        cout << " | Question: " << left << setw(23) << questionNumber << "|" << endl;
        cout << " | Attempts: " << i << " out of " << left << setw(14) << MAX_ATTEMPTS << "|" << endl;;
        cout << " | MathLevel: " << left << setw(22) << mathLevel << "|" << endl;
        cout << " |----------------------------------|" << endl;
        cout << endl;
        cout << userName << ", what is " << leftNum << mathSymbol << rightNum << "?" << endl; // Asks question
        cout << endl;
        userAnswer = GetNumericValue();

        if (userAnswer == correctAns) {
            cout << "Good job! You Got The Question Right!" << endl;
            cout << endl;
            isCorrect = true;
            question.push_back(i); // attempts it took
            attemptused = i;
        } else if (i < MAX_ATTEMPTS) {
            cout << "Not quite, apprentice!" << endl;
            cout << endl;
        } else {
            // out of attempts: reveal the answer
            cout << "The wizard is disappointed, " << userName << "..." << endl;
            cout << border << endl;
            boxLine("The correct answer was:", BOX_INNER);
            boxLine(questionText.str() + " = " + to_string(correctAns), BOX_INNER);
            cout << border << endl;
            cout << endl;
        }
    }
    question.push_back(attemptused);   // attempts it took, or 0 if failed
    return isCorrect;
}

//*********************************************************************************************************************
//* Display: This Determines wether you level up or down. It will tell you what your num and level range goes up to and
//down.
//* Params: int &totalCorrect, int &totalIncorrect, int &mathLevel, int &levelRange
// *Return: N/A
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
        int questionNumber = 0;// Sets the question to 0 to clear it for the new level. EX: question 1 out of LVL 3
    }
    // leveling down
    else if (totalIncorrect >= 1) {
        // one question missed on all 3 attempts = level down (never below level 1)
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
    return;
}

//*********************************************************************************************************************
//* Generates a random math question for the current level
//* Params: int mathLevel, int levelRange
//* Return: {mathLevel, leftNum, mathSymbol, rightNum, correctAns}
//*********************************************************************************************************************
vector<int> GenerateRandomQuestions(int mathLevel, int levelRange) {
    enum MathType { MT_ADD = 1, MT_SUB = 2, MT_MUL = 3, MT_DIV = 4 };

    MathType mathType = static_cast<MathType>(rand() % 4 + 1);
    int rightNum = (rand() % levelRange) + 1; // 1 to levelRange
    int leftNum = (rand() % levelRange) + 1; // 1 to levelRange
    int temp = 0; // used to swap two values
    int correctAns = 0;
    char mathSymbol = '?';

    switch (mathType) {
        case MT_ADD:
            correctAns = leftNum + rightNum;
            mathSymbol = '+';
            break;

        case MT_SUB:
            if (leftNum < rightNum) {
                // keep the answer from being negative
                temp = leftNum;
                leftNum = rightNum;
                rightNum = temp;
            }
            correctAns = leftNum - rightNum;
            mathSymbol = '-';
            break;

        case MT_MUL:
            correctAns = leftNum * rightNum;
            mathSymbol = '*';
            break;

        case MT_DIV:
            correctAns = leftNum; // build the dividend so the answer is a whole number
            leftNum = leftNum * rightNum;
            mathSymbol = '/';
            break;

        default: // should never happen
            cout << "Invalid question type: " << static_cast<int>(mathType) << endl;
            cout << "Program ended with an error -1" << endl;
            cout << "Please report this error to Brayden Tolle or Barnabas Htoo" << endl;
            exit(-1);
    }
    return {mathLevel, leftNum, mathSymbol, rightNum, correctAns};
} // end of GenerateRandomQuestions
