#pragma once

#include <stdlib.h>
#include <stddef.h>

void * operator new(size_t size);
void operator delete(void * ptr);
