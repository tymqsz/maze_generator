#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include "visual.h"
#include "algs.h"

#define INF 1000000000

int main(int argc, char** argv)
{
	srand(time(NULL));
	
	// creating vector of nodes (size n*n)
	int n = argc > 1 ? atoi(argv[1]) : 8;
	node* v;
	v = malloc(n*n*sizeof(node));
	
	gen_empty(v, n);


	// generating start-end
	int r1 = rand() % (n);
	int r2 = rand() % (n);
	int start = r1;
	int end = r2 + (n-1)*n;


	// adding random walls to labyrinth
	int* vis = calloc(n*n, sizeof(int));
		
	randomize_lab(v, vis, start, n);

	int to_destroy = argc > 2 ? atoi(argv[2]) : sqrt(n);
	destroy_walls(v, n, to_destroy);
	
	add_start_end(v, start, end);


	// creating weighted graph based on labyrinth
	double**g = malloc(sizeof(double*)*n*n);
	for(int i = 0; i < n*n;  i++) g[i] = malloc(4*sizeof(double));
	
	int* pred = calloc(n*n, sizeof(int));
	create_graph(v, g, start, pred, n);
	
	
	//finding paths
	int* path = malloc(sizeof(int)*n*n);
	for(int i = 0; i < n*n; i++) path[i] = -1;
	path[0] = start;
	double win_len = INF;
	int* win_path = malloc(n*n*sizeof(int));
	int* path_n = calloc(n*n, sizeof(int));

	print_lab(v, n, g, path_n, "raw");
	
	printf("\npossible paths:\n");
	extract_paths(g, path, 1, 0.0, n, start, end, &win_len, win_path);
	
	printf("\nshortest path (len: %lf): ", win_len);
	int i = 0;
	while(win_path[i+1] != -1)
	{
		path_n[win_path[i]] = 1;
		printf("v%d->", win_path[i]+1);
		i++;
	}
	path_n[win_path[i]] = 1;
	printf("v%d\n", win_path[i]+1);
	
	print_lab(v, n, g, path_n, "path");

	// freeing
	for(int i = 0; i < n*n;  i++) free(g[i]);
	free(g);

	free(pred);
	free(path);
	free(win_path);
	free(path_n);
	free(v);
}
