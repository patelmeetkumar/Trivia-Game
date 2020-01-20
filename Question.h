#pragma once
#include <string>
#include <ostream>

using namespace std;

class Question
{

private:
	string query;
	string option1;
	string option2;
	string option3;
	string option4;

public:
	Question(string inquiry, string op1, string op2, string op3, string op4);

	string getQuery() const;
	string getOption1() const;
	string getOption2() const;
	string getOption3() const;
	string getOption4() const;

	friend ostream &operator<< (ostream &lhs, const Question &rhs);
};