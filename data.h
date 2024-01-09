#ifndef DH
#define DH

#include<stdio.h>

typedef struct{
	int W;
	int E;
	int N;
	int S;
	int* dir;
} node;

void destroy_walls(node* v, int n, int n_add);

void gen_empty(node* v, int n);

void add_start_end(node* v, int start, int end);

int sum(int* v, int n);

int get_child(int node, int dir, int n);

int good_mv(node* v, int i, int dir);
#endif
