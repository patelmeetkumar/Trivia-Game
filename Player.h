#pragma once
#include <vector>
#include "Question.h"

class Player
{

private:
	std::vector<const Question*> right, wrong;

public:
	Player() {} //inline constructor
	~Player() {} // inline destructor
	void addRight (const Question* val);
	void addWrong(const Question* val);
	void reset();
	void displayRightQuestions();
	void displayWrongQuestions();
	int getRightCount() const;
	int getWrongCount() const;

};


