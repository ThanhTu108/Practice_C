#include "lib.h"
#include <stdio.h>
#include <unistd.h>

Fucn_t f = NULL;

void activate_function(int seconds, Fucn_t fptr)
{
    sleep(seconds);
    if(fptr)
    {
        f = fptr; 
    }
    f();
}

