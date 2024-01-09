#ifndef AG
#define AG
#include "data.h"

void swp(int* a, int* b);

void randomize_lab(node*v, int* vis, int crt_node, int n);

void create_graph(node* v, double** g, int node, int* pred, int n);

void randomize_vec(int* v);

void dijkstra(double** g, int start, int n, double* dist);

void retrive_path(double** g, double* dist, int n, int start, int end, int* path);

void extract_paths(double** g, int* path, int node_cnt, double path_len, int n, int node, int end, double* win_len, int* win_path);

void destroy_walls(node* v, int n, int n_add);
#endif
