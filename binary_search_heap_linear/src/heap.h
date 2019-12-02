
#ifndef HEAP_H_INCLUDED

#include "../src/numbers.h"

int father(int i);

int left(int i);

int right(int i);

void heap_sort(number_t ** numbers, int n_lines);

#endif
