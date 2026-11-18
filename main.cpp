/*****************************************************************************************************************************************************
Program: MathTutorV4
Programmers: Jacob Karsky and Brayden Tolle
Date: 11/13/2026
Section 3: 12:00
Github Repo:https://github.com/Insanedoomed/MathTutorV5
Description: A wizard/magic themed math tutor for children

* Displays the intro featuring ASCII art and jokes

* Asks a simple math question which is checked for correctness

* Gives the user 3 attempts to get the question right

* After 3 correct answers the program levels up

* If there are 3 incorrect answers in a row, the user levels down

* Asks the user if they want to play again

* Stores every math question and answer then displays it at the end in a summary report

****************************************************************************************************************************************************/
#include <iostream> //required for cout and cin
#include <ctime> // for time seeding
#include <sstream> // ostringstream
#include "mathtutor.h"

using namespace std; //sets standard namespace

//start of the main function
int main() {

    srand(time(0)); // Seed first; used to randomize the numeric operator (+,-,*,/)

    // used to store all the questions for a summary report
    vector<int> currentQuestion;

    vector<vector<int> > questions; // Vector for our tabel. Sets questions as a holder

    //initializing variables
    int LevelRange = LEVEL_RANGE; // turns it into a variable that later is used to check for equality
    int mathLevel = 1; // Current Math level
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
        currentQuestion = GenerateRandomQuestions(mathLevel, LevelRange);
        isCorrect = GiveThreeAttempts(userName, currentQuestion);

        if (isCorrect) {
            totalCorrect++;
        } else {
            totalIncorrect++;
        }

        questions.push_back(currentQuestion); // attempts already added inside GiveThreeAttempts

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