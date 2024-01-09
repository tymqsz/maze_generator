#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "data.h"

char get_move_symbol(double** g, int node)
{
	if(g[node][0] && g[node][1] && g[node][2]) return '%';
	else if(g[node][3] && g[node][1] && g[node][2]) return '+';
	else if(g[node][3] && g[node][0] && g[node][2]) return '&';
	else if(g[node][3] && g[node][1] && g[node][0]) return '#';
	else if(g[node][0] && g[node][1]) return '=';
	else if(g[node][1] && g[node][2]) return 'L';
	else if(g[node][0] && g[node][2]) return 'J';
	else if(g[node][0] && g[node][3]) return '`';
	else if(g[node][2] && g[node][3]) return '$';
	else if(g[node][3] && g[node][1]) return '/';
	else if(g[node][0]) return '<';
	else if(g[node][1]) return '>';
	else if(g[node][2]) return '^';
	else if(g[node][3]) return 'Y';
	else return ' ';
}

void print_row(node* v, int n, int row, double** g, int* path, char* mode)
{
	for(int i = 0; i < n; i++)
	{
		if(v[row*n+i].N == 1) printf("  ");
		else printf(" ―");
	}
	printf("\n");

	for(int i = 0; i < n; i++)
	{
		if(v[row*n+i].W != 1) printf("|");
		else printf(" ");
		
		if(strcmp(mode, "path") == 0)
		{
			if(path[row*n+i]) printf("*");
			else printf(" ");
		}
		else if(strcmp(mode, "moves") == 0) printf("%c", get_move_symbol(g, row*n+i));
		else printf(" ");
	}
	if(v[row*n+n-1].E != 1) printf("|");
	else printf(" ");

	printf("\n");
}


void print_lab(node* v, int n, double** g, int* path, char* mode)
{
	for(int i = 0; i < n; i++) print_row(v, n, i, g, path, mode);
	
	printf(" ");
	for(int i = 0; i < n; i++)
	{
		if(v[(n-1)*n+i].S == 1) printf("  ");
		else printf("― ");
	}
	printf("\n");
}



void print_weights(double** g, int n)
{
	for(int i = 0; i < n*n; i++)
	{
		printf("%d: ", i);
		for(int j = 0; j < 4; j++)
		{
			printf("%lf ", g[i][j]);
		}
		printf("\n");
	}
}
