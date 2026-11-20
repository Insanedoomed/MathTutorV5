/*****************************************************************************************************************************************************
Program: MathTutorV4
Programmers: Jacob Karsky, and Brayden Tolle
Date: 10/30/2026
Section 3: 12:00
Github Repo:https://github.com/Insanedoomed/MathTutorV5
Description: A wizard/magic themed math tutor that displays the intro featuring
ASCII art and jokes, it then asks a simple math question which is checked for correctness
and then it outputs an end of program message.
***********************************/

#ifndef MATHTUTOR_H
#define MATHTUTOR_H

#include <string> // for string data types
#include <vector> // for storing the questions in a 2D vector

using namespace std;//sets standard namespace

const int LEVEL_RANGE = 10; // Starting range of 1-10; adds ten each level up
const int BOX_INNER = 40; // number of characters between the two | borders

void DisplayGameIntro(); // Prototype: Displays Game intro such as jokes and asterix
string GetUserName();// Prototype: Gets the Username and Returns it so we have it
vector<int> GenerateRandomQuestions(int mathLevel, int levelRange);// Prototype: Generates random question using random
int GetNumericValue();// Prototype: Handles user error. such as typing a character instead of a letter.
bool GiveThreeAttempts(const string &userName, vector<int> &question,int questionNumber);// Prototype: Allows for 3 attempts for each question
void CheckForLevelRangeChange(int &totalCorrect, int &totalIncorrect, int &mathLevel, int &levelRange);// Prototype: Determines if you will level down or not
string AskToPlayAgain(string userName);// Prototype: A while true loop that asks if you want to play again if yes then it loops if no it ends
void DisplaySummaryReport(const vector<vector<int>> &questions);// Prototype: A basic summaryReport of questions and attempts and answers.

#endif// MATHTUTOR_H
