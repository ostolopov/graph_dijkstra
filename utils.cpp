#include "utils.h"

int get_int(int &number, int min, int max) {
    while (true) {
        if (!(std::cin >> number)) {
            if (std::cin.eof()) {
                std::cout << "\nProgram terminated.\n";
                return 0;
            }
            std::cout << "Invalid number. Please try again!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (number < min || number > max) {
            std::cout << "The number is out of the allowed range. Please try again!\n";
            continue;
        }
        break;
    }
    return 1;
}

void visualize_graph(const std::vector<std::vector<int>>& adjacency_matrix) {
    std::ofstream dot_file("graph.dot");
    if (!dot_file.is_open()) {
        std::cerr << "Ошибка: Не удалось создать файл graph.dot\n";
        return;
    }
    dot_file << "graph G {\n";
    dot_file << "  rankdir=LR;\n";
    dot_file << "  node [shape=circle];\n";
    for (int i = 0; i < adjacency_matrix.size(); ++i) {
        for (int j = i; j < adjacency_matrix[i].size(); ++j) {
            //if (i == j || adjacency_matrix[i][j] == 0 || adjacency_matrix[i][j] == INF)
            if ( adjacency_matrix[i][j] == 0 || adjacency_matrix[i][j] == INF)
                continue;
            dot_file << "  " << i << " -- " << j << " [label=\"" << adjacency_matrix[i][j] << "\"];\n";
        }
    }
    dot_file << "}\n";
    dot_file.close();
    system("dot -Tpng graph.dot -o graph.png && open graph.png");
    std::cout << "Граф сохранён в graph.png\n";
}

void make_random_graph(std::vector<std::vector<int>>& adjacency_matrix) {
    srand(time(0));
    int size = adjacency_matrix.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int temp = rand() % 20 - 1;
            if (temp == -1) {
                adjacency_matrix[i][j] = INF;
                adjacency_matrix[j][i] = INF;
                continue;
            }
            adjacency_matrix[i][j] = temp;
            adjacency_matrix[j][i] = temp;
        }
        adjacency_matrix[i][i] = 0;
    }
}