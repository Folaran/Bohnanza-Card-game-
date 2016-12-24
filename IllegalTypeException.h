#include <iostream>
#include <exception>
#include "chain.h"
using namespace std;



class IllegalTypeExcpetion : public exception //runtime_error....gives call to implicitly bla
{
public:
	const char* what() const throw()
	{
		return "You can't chain cards of different types"; // my error message
	}
	Chain<Card>& operator+=(Card* newCard);
};