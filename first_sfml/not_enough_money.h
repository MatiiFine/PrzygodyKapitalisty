#pragma once
#include <iostream>
#include <exception>

class not_enough_money :
    public std::exception
{
public:
    virtual const char* what() const throw();
};

