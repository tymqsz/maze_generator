#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "data.h"

int get_child(int node, int dir, int n)
{
	int child;

	switch(dir)
	{
		case 0:
			child = node - 1;
			break;
		case 1:
			child = node + 1;
			break;
		case 2:
			child = node - n;
			break;
		case 3:
			child = node + n;
			break;
	}

	return child;
}

void add_start_end(node* v, int start, int end)
{
	v[start].N = 1;
	v[end].S = 1;
}

void gen_empty(node* v, int n)
{
	for(int i = 0; i < n*n; i++)
	{
		v[i].W = 0;
		v[i].E = 0;
		v[i].N = 0;
		v[i].S = 0;
		v[i].dir = calloc(4, sizeof(int));
	}
	
	for(int i = 0; i < n; i++) v[i].N = -1;
	for(int i = n*(n-1); i < n*n; i++) v[i].S = -1;
	for(int i = 0; i <= n*(n-1); i += n) v[i].W = -1;
	for(int i = n-1; i <= n*n-1; i += n) v[i].E = -1;
}

int good_mv(node* v, int i, int dir)
{
	if(dir == 0 && v[i].W != -1) return 1;
	if(dir == 1 && v[i].E != -1) return 1;
	if(dir == 2 && v[i].N != -1) return 1;
	if(dir == 3 && v[i].S != -1) return 1;
	return 0;
}

int sum(int* v, int n)
{
	int s = 0;
	for(int i = 0; i < n*n; i++) s += v[i];
	return s;
}
