#pragma once
#include <iostream>

class thread_is_running :
    public std::exception
{
public:
    virtual const char* what() const throw();
};

