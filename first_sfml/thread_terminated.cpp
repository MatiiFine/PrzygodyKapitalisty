#include "thread_terminated.h"

const char* thread_terminated::what() const throw()
{
    return "thread has been terminated";
}
