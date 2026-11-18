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

using namespace std;\

const int LEVEL_RANGE = 10; // Starting range of 1-10; adds ten each level up
const int BOX_INNER = 40; // number of characters between the two | borders

void DisplayGameIntro();
string GetUserName();
vector<int> GenerateRandomQuestions(int mathLevel, int levelRange);
int GetNumericValue();
bool GiveThreeAttempts(const string &userName, vector<int> &question);
void CheckForLevelRangeChange(int &totalCorrect, int &totalIncorrect, int &mathLevel, int &levelRange);
string AskToPlayAgain(string userName);
void DisplaySummaryReport(const vector<vector<int>> &questions);

#endif
