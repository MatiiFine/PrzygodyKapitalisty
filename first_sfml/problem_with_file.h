#pragma once
#include <iostream>
#include <exception>

class problem_with_file :
	public std::exception
{
public:
	virtual const  char* what() const throw();
};

