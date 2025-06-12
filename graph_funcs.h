#ifndef GRAPH_STRUCTS_H
#define GRAPH_STRUCTS_H

#include <iostream>
#include <vector>

#include "utils.h"

const int INF = INT_MAX;

void make_graph_arr (std::vector<std::vector<int>>& adjacency_matrix, int& size);
void add_edge_arr_undirect (std::vector<std::vector<int>>& adjacency_matrix, int i, int j);
void get_edge_arr (std::vector<std::vector<int>>& adjacency_matrix, int i, int j);
void delete_edge_arr_undirect (std::vector<std::vector<int>>& adjacency_matrix, int i, int j);
void delete_all_edges (std::vector<std::vector<int>>& adjacency_matrix);
void display_graph_arr (std::vector<std::vector<int>>& adjacency_matrix, int size);
void dijkstra_arr(std::vector<std::vector<int>>& adjacency_matrix, int from);
void clear_adjacency_matrix(std::vector<std::vector<int>>& adjacency_matrix);

#endif

// typedef struct Node {
//     int to;
//     int vertex;
//     struct Node *next;
// };
//
// typedef struct Graph {
//     int count_nodes;
//     struct Node **nodes;
// };
