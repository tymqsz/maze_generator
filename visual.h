#ifndef VH
#define VH

#include "data.h"

void print_row(node* v, int n, int row, double** g, int* path, char* mode);

void print_lab(node* v, int n, double** g, int* path, char* mode);

void print_weights(double** g, int n);
#endif
