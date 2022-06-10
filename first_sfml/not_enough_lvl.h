#pragma once
#include <iostream>
#include <exception>
class not_enough_lvl 
	: public std::exception
{
public:
	virtual const char* what() const throw();
};

