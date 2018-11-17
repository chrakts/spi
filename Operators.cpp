/*
 * Operators.cpp
 *
 * Created: 16.03.2017 15:26:12
 *  Author: a16007
 */ 

#include "Operators.h"


void * operator new(size_t size)
{
	return malloc(size);
}

void operator delete(void * ptr)
{
	free(ptr);
}