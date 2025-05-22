#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>

int get_int(int *number, int min, int max);
void visualize_graph(const std::vector<std::vector<int>>& adjacency_matrix);
void make_random_graph(std::vector<std::vector<int>>& adjacency_matrix);

#endif