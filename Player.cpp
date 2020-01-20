#include "Player.h"
#include <iostream>

using namespace std;

void Player :: addRight(const Question* val) 
{
	right.push_back(val);
}
void Player :: addWrong(const Question* val) 
{
	wrong.push_back(val);
}
int Player :: getRightCount() const 
{
	return right.size();
}
int Player :: getWrongCount() const 
{
	return wrong.size();
}

void Player :: reset()
{
	right.clear();
	wrong.clear();
}

void Player :: displayRightQuestions()
{
	for (int i = 0; i < right.size(); i++) 
	{
		cout << *right[i] << endl;
	}
}

void Player :: displayWrongQuestions()
{
	for (int i = 0; i < wrong.size(); i++)
	{
		cout << *wrong[i] << endl;
	}
}