#ifndef __LIB_H_
#define __LIB_H_

typedef void (*Fucn_t)();

void Set_callback(Fucn_t fptr);
void activate_function();

#endif