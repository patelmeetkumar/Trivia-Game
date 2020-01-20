#include "Question.h"


	Question :: Question(string inquiry, string op1, string op2, string op3, string op4)
	{
		query = inquiry;
		option1 = op1;
		option2 = op2;
		option3 = op3;
		option4 = op4;
	}

	string Question::getQuery() const
	{
		return query;
	}

	string Question::getOption1() const
	{
		return option1;
	}

	string Question::getOption2() const
	{
		return option2;
	}

	string Question::getOption3() const
	{
		return option3;
	}

	string Question::getOption4() const
	{
		return option4;
	}

	//The questions at the top, then each option below it in a new line, where A is the first option,
	// b is the second option, and so forth.
	ostream &operator<< (ostream &lhs, const Question &rhs) 
	{
		lhs << rhs.getQuery() << std::endl;
		lhs << "A. " << rhs.getOption1() << std::endl;
		lhs << "B. " << rhs.getOption2() << std::endl;
		lhs << "C. " << rhs.getOption3() << std::endl;
		lhs << "D. " << rhs.getOption4() << std::endl;
		return lhs;
	}
