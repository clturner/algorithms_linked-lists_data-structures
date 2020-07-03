#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H
#include <stdio.h>
#include <stdlib.h>

int advanced_binary(int *array, size_t size, int value);
void pa(int *array, int start, int finish);
void frmt(int num, int *array, int low, int mid, int high);
int checker(int *array, int start, int value);
int bs(int *array, int low, int high, int value, size_t size);


#endif
