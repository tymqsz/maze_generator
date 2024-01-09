#include<stdio.h>
#include<stdlib.h>

#include "data.h"
#include "algs.h"
#define INF 1000000000

void swp(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void randomize_vec(int* v)
{
	int i = 0, j = 3;

	int iter = rand() % 100;

	int n = 0;

	while(n < iter)
	{
		i = i % 4;
		j = j % 4;

		swp(&v[i], &v[j]);

		i += 1;
		j += 2;
		n += 1;
	}
}

void randomize_lab(node* v, int* vis, int crt_node, int n)
{
	if(sum(vis, n) == n*n) return;
	
	int dir_vec[4] = {0, 1, 2, 3};
	randomize_vec(dir_vec);

	int nxt_node;
	int dir;
	for(int i = 0; i < 4; i++)
	{
		dir = dir_vec[i];
		nxt_node = get_child(crt_node, dir, n);
		if(good_mv(v, crt_node, dir) && !vis[nxt_node])
		{	
			vis[nxt_node] = 1;
			
			if(dir == 0)
			{
				v[crt_node].W = 1;
				v[crt_node-1].E = 1;
				v[crt_node].dir[0] = 1;
				v[crt_node-1].dir[1] = 1;
			}	
			if(dir == 1)
			{
				v[crt_node].E = 1;
				v[crt_node+1].W = 1;
				v[crt_node].dir[1] = 1;
				v[crt_node+1].dir[0] = 1;
			}
			if(dir == 2)
			{
				v[crt_node].N = 1;
				v[crt_node-n].S = 1;
				v[crt_node].dir[2] = 1;
				v[crt_node-n].dir[3] = 1;
			}
			if(dir == 3)
			{
				v[crt_node].S = 1;
				v[crt_node+n].N = 1;
				v[crt_node].dir[3] = 1;
				v[crt_node+n].dir[2] = 1;
			}

			randomize_lab(v, vis, nxt_node, n);
		}
	}
}

void destroy_walls(node* v, int n, int n_add)
{
	int index, dir;
	int i = 0;
	int max_iter = 1000;
	int j = 0;

	while(i < n_add && j < max_iter)
	{
		j++;
		index = rand()%(n*n);
		dir = rand()%4;
		
			if(dir == 0 && v[index].W == 0)
			{
				v[index].W = 1;
				v[index-1].E = 1;
				v[index].dir[0] = 1;
				v[index-1].dir[1] = 1;
				i++;
			}	
			if(dir == 1 && v[index].E == 0)
			{
				v[index].E = 1;
				v[index+1].W = 1;
				v[index].dir[1] = 1;
				v[index+1].dir[0] = 1;
				i++;
			}
			if(dir == 2 && v[index].N == 0)
			{
				v[index].N = 1;
				v[index-n].S = 1;
				v[index].dir[2] = 1;
				v[index-n].dir[3] = 1;
				i++;
			}
			if(dir == 3 && v[index].S == 0)
			{
				v[index].S = 1;
				v[index+n].N = 1;
				v[index].dir[3] = 1;
				v[index+n].dir[2] = 1;
				i++;
			}
	}
}

void create_graph(node* v, double** g, int node, int* pred, int n)
{
	int* pred_copy = malloc(n *n* sizeof(int));
    for (int i = 0; i < n*n; i++) pred_copy[i] = pred[i];

	int child;
	for(int i = 0; i < 4; i++)
	{
		child = get_child(node, i, n);
		
		if(v[node].dir[i] && !pred[child])
		{
			pred_copy[child] = 1;
			g[node][i] = 0.1 + 9.9*rand() / RAND_MAX;

			create_graph(v, g, child, pred_copy, n);
		}
	}

	free(pred_copy);
}

void extract_paths(double** g, int* path, int node_cnt, double path_len, int n, int node, int end, double* win_len, int* win_path)
{
	if(node == end)
	{
		int i = 0;
		while(i < node_cnt-1)
		{
			printf("v%d->", path[i]+1);
			i++;
		}
		printf("v%d (len: %lf)\n", path[node_cnt-1]+1, path_len);

		if(*win_len > path_len)
		{
			*win_len = path_len;
			int j = 0;
			while(j  < n*n)
			{
				win_path[j] = path[j];
				j++;
			}
		}

		return;
	}

	int* path_copy = malloc(n *n* sizeof(int));
    for (int i = 0; i < n*n; i++) path_copy[i] = path[i];

	int child;
	for(int i = 0; i < 4; i++)
	{
		child = get_child(node, i, n);
		
		int loop = 0;
		for(int j = 0; j < n*n && path_copy[j] != -1; j++)
		{
			if(child == path_copy[j]) loop = 1;
		}

		if(g[node][i] && !loop)
		{
			path_copy[node_cnt] = child;

			extract_paths(g, path_copy, node_cnt+1, path_len + g[node][i], n, child, end, win_len, win_path);
		}
	}

	free(path_copy);

}


