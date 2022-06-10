#pragma once
#include <iostream>
#include <exception>

class thread_terminated :
	public std::exception
{
public:
	virtual const char* what() const throw();
};

