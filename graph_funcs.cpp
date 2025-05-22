#include "graph_funcs.h"

void make_graph_arr (std::vector<std::vector<int>>& adjacency_matrix, int& size) {
    std::cout << "Enter number of nodes: ";
    get_int(&size, 0, INT_MAX);
    adjacency_matrix.resize(size, std::vector<int>(size, INF));
    for (int i = 0; i < size; i++) adjacency_matrix[i][i] = 0;
}

void add_edge_arr_undirect (std::vector<std::vector<int>>& adjacency_matrix, int i, int j) {
    int n;
    std::cout << "длина ребра:\n";
    get_int(&n, 0, INT_MAX - 1);
    adjacency_matrix[i][j] = n;
    adjacency_matrix[j][i] = n;
}

void add_edge_arr_direct (std::vector<std::vector<int>>& adjacency_matrix, int i, int j) {
    int n;
    std::cout << "длина ребра:\n";
    get_int(&n, 0, INT_MAX - 1);
    adjacency_matrix[i][j] = n;
}

void get_edge_arr (std::vector<std::vector<int>>& adjacency_matrix, int i, int j) {
    if (adjacency_matrix.empty()) return;
    std::cout << adjacency_matrix[i][j] << std::endl;
}

void delete_edge_arr_undirect (std::vector<std::vector<int>>& adjacency_matrix, int i, int j) {
    //if (i < adjacency_matrix.size() || j < adjacency_matrix[i].size() || adjacency_matrix.empty()) return;
    adjacency_matrix[i][j] = 0;
    adjacency_matrix[j][i] = 0;
}

void display_graph_arr (std::vector<std::vector<int>>& adjacency_matrix, int size) {
    if (adjacency_matrix.empty()) {
        std::cout << "Матрица пустая\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (adjacency_matrix[i][j] == INF) std::cout << "INF" << " ";
            else std::cout << adjacency_matrix[i][j] <<  " ";
        }
        std::cout << std::endl;
    }
}

void delete_all_edges(std::vector<std::vector<int>>& adjacency_matrix) {
    if (adjacency_matrix.empty()) {
        std::cout << "Матрица пустая\n";
        return;
    }
    int size = adjacency_matrix.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            adjacency_matrix[i][j] = (i == j) ? 0 : INF;
    }
}

void force_clear_adjacency_matrix(std::vector<std::vector<int>>& adjacency_matrix) {
    adjacency_matrix.clear();
    adjacency_matrix.shrink_to_fit();
}

void dijkstra_arr(std::vector<std::vector<int>>& adjacency_matrix, int from) {
    if (adjacency_matrix.empty()) return;
    int size = adjacency_matrix.size();
    if (from < 0 || from >= size) {
        std::cerr << "Invalid starting node!" << std::endl;
        return;
    }
    std::vector<int> dist(size, INF);
    std::vector<bool> visited(size, false);
    dist[from] = 0;
    for (int count = 0; count < size - 1; count++) {
        int min_dist = INF;
        int u = -1;
        for (int v = 0; v < size; v++) {
            if (!visited[v] && dist[v] <= min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }
        if (u == -1) break;
        visited[u] = true;
        for (int v = 0; v < size; v++) {
            if (!visited[v] && adjacency_matrix[u][v] != INF &&
                dist[u] != INF && dist[u] + adjacency_matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjacency_matrix[u][v];
                }
        }
    }
    std::cout << "Shortest distances from node " << from << ":\n";
    for (int i = 0; i < size; i++) {
        if (dist[i] == INF) {
            std::cout << "Node " << i << ": INF\n";
        } else {
            std::cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }
}