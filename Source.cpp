#include <iostream>
#include <string>
#include "Question.h"
#include "Player.h"
#include <vector>

using namespace std;

int main() 
{
	string Question1 = "What's is the smallest country in the world?";
	string option11 = "Nauru";
	string option12 = "Vatican City";
	string option13 = "Tuvalu";
	string option14 = "Iceland";
	char answer1 = 'B';
	Question one(Question1, option11, option12, option13, option14);

	string Question2 = "What is 0!?";
	string option21 = "-1";
	string option22 = "0";
	string option23 = "1";
	string option24 = "undefined";
	char answer2 = 'C';
	Question two(Question2, option21, option22, option23, option24);

	string Question3 = "How is California's GDP compared to all possible countries?";
	string option31 = "In top 5";
	string option32 = "In top 10";
	string option33 = "In top 25";
	string option34 = "1n top 50";
	char answer3 = 'A';
	Question three(Question3, option31, option32, option33, option34);

	string Question4 = "How many counties are there in California?";
	string option41 = "35";
	string option42 = "43";
	string option43 = "52";
	string option44 = "58";
	char answer4 = 'D';
	Question four(Question4, option41, option42, option43, option44);

	string Question5 = "What time zone is Los Angeles in?";
	string option51 = "Mountain Time Zone";
	string option52 = "Pacific Time Zone";
	string option53 = "Central Time Zone";
	string option54 = "Eastern Time Zone";
	char answer5 = 'B';
	Question five(Question5, option51, option52, option53, option54);

	string Question6 = "What is the element Sb called?";
	string option61 = "Antimony";
	string option62 = "Silicon";
	string option63 = "Selenium";
	string option64 = "Lead";
	char answer6 = 'A';
	Question six(Question6, option61, option62, option63, option64);

	string Question7 = "What is the most abundant organism on Earth?";
	string option71 = "Humans";
	string option72 = "Prochlorococcus";
	string option73 = "Synechococcus";
	string option74 = "Pelagibacter ubique";
	char answer7 = 'B';
	Question seven(Question7, option71, option72, option73, option74);

	string Question8 = "What is the range of a credit score?";
	string option81 = "1-100";
	string option82 = "100-1000";
	string option83 = "300-850";
	string option84 = "400-800";
	char answer8 = 'C';
	Question eight(Question8, option81, option82, option83, option84);

	string Question9 = "Who is the chancellor of Germany?";
	string option91 = "Angela Merkel";
	string option92 = "Janet Yellen";
	string option93 = "Nancy Pelosi";
	string option94 = "Theresa May";
	char answer9 = 'A';
	Question nine(Question9, option91, option92, option93, option94);

	string Question10 = "How many weeks is a semester?";
	string option101 = "10";
	string option102 = "12";
	string option103 = "15";
	string option104 = "16";
	char answer10 = 'C';
	Question ten(Question10, option101, option102, option103, option104);



	cout << "Welcome to the game!" << endl << endl;
	int numberOfUsers = 0;

	do 
	{
		cout << "Please enter the number of players? ";
		cin >> numberOfUsers;
	} while (numberOfUsers <= 0);

	cout << endl;

	vector <Player> playerList(numberOfUsers);

	vector<Question*> questionList;
	questionList.push_back(&one);
	questionList.push_back(&two);
	questionList.push_back(&three);
	questionList.push_back(&four);
	questionList.push_back(&five);
	questionList.push_back(&six);
	questionList.push_back(&seven);
	questionList.push_back(&eight);
	questionList.push_back(&nine);
	questionList.push_back(&ten);

	vector<char> answerList{ answer1, answer2, answer3, answer4, 
		answer5, answer6, answer7, answer8, answer9, answer10 };

	for (int questionNumber = 0; questionNumber < 5; questionNumber++) 
	{
		const auto *question = questionList.at(questionNumber);
		cout << *question << endl;

		for (unsigned playerNumber = 0; playerNumber < playerList.size(); playerNumber++) // vector size is unsigned
		{
			cout << "For the player number: " << playerNumber + 1 << endl;
			char userAnswer;
			cout << "Please enter the response to the question (ie: A, B, C, D): ";
			cin >> userAnswer;
			cout << endl;
			userAnswer = toupper(userAnswer);

			if (userAnswer == answerList.at(questionNumber))
			{
				playerList.at(playerNumber).addRight(question);
			}
			else
			{
				playerList.at(playerNumber).addWrong(question);
			}

		}
	}

	for (unsigned playerPrintOut = 0; playerPrintOut < playerList.size(); playerPrintOut++)
	{
		cout << "For the player number: " << playerPrintOut + 1 << endl;

		cout << "The number of questions answered right are: " << playerList.at(playerPrintOut).getRightCount() << endl;
		// Print all the questions answered right here.
		cout << "Here's the questions answered right: " << endl << endl;
		playerList.at(playerPrintOut).displayRightQuestions();
		cout << endl;

		cout << "The number of questions answered wrong are: " << playerList.at(playerPrintOut).getWrongCount() << endl;
		// Print all the questions answered wrong here.
		cout << "Here's the questions answered wrong: " << endl << endl;
		playerList.at(playerPrintOut).displayWrongQuestions();
		cout << endl;

		playerList.at(playerPrintOut).reset(); // Loop through each player, and reset on all of them.
		
	}


	char playAgain;
	do
	{
		cout << endl << "Do you want to play again (ie: Y, N)? ";
		cin >> playAgain;
		playAgain = toupper(playAgain);
	} while (playAgain != 'Y' && playAgain != 'N');

	if (playAgain == 'N') 
	{
		cout << "Thank you for playing the game! Game ended!!!" << endl;


		return 0;
	}

	cout << endl << endl << "The second round of game begins:" << endl;

	for (int questionNumber = 5; questionNumber < 10; questionNumber++)
	{
		const auto *question = questionList.at(questionNumber);
		cout << *question << endl;

		for (unsigned playerNumber = 0; playerNumber < playerList.size(); playerNumber++)
		{
			cout << "For the player number: " << playerNumber + 1 << endl;
			char userAnswer;
			cout << "Please enter the response to the question (ie: A, B, C, D): ";
			cin >> userAnswer;
			cout << endl;
			userAnswer = toupper(userAnswer);

			if (userAnswer == answerList.at(questionNumber))
			{
				playerList.at(playerNumber).addRight(question);
			}
			else
			{
				playerList.at(playerNumber).addWrong(question);
			}

		}
	}

	for (unsigned playerPrintOut = 0; playerPrintOut < playerList.size(); playerPrintOut++)
	{
		cout << "For the player number: " << playerPrintOut + 1 << endl;

		cout << "The number of questions answered right are: " << playerList.at(playerPrintOut).getRightCount() << endl;
		// Print all the questions answered right here.
		cout << "Here's the questions answered right: " << endl << endl;
		playerList.at(playerPrintOut).displayRightQuestions();
		cout << endl;

		cout << "The number of questions answered wrong are: " << playerList.at(playerPrintOut).getWrongCount() << endl;
		// Print all the questions answered wrong here.
		cout << "Here's the questions answered wrong: " << endl << endl;
		playerList.at(playerPrintOut).displayWrongQuestions();
		cout << endl;

		playerList.at(playerPrintOut).reset(); // Loop through each player, and reset on all of them.
	}

	cout << endl << endl << "Thank you for playing the game! Game ended!!!" << endl;


	return 0;

}



/*

int currentQuestionNumber = 0;
for (const auto *question : questionList)
{
	cout << *question << endl;

	for (auto &player : playerList)
	{
		char userAnswer;
		cout << "Please enter the response to the question (ie: A, B, C, D): ";
		cin >> userAnswer;
		userAnswer = toupper(userAnswer);

		if (userAnswer == answerList.at(currentQuestionNumber))
		{
			player.addRight(question);
		}
		else
		{
			player.addWrong(question);
		}
	}
	currentQuestionNumber++;
}

for (int playerPrintOut = 0; playerPrintOut < playerList.size(); playerPrintOut++)
{
	cout << "For the player number: " << playerPrintOut << endl;
	cout << "The number of questions answered right are: " << playerList.at(playerPrintOut).getRightCount() << endl;
	cout << "The number of questions answered wrong are: " << playerList.at(playerPrintOut).getWrongCount() << endl;
}

*/