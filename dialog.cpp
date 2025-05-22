#include "dialog.h"

void dialog_arr () {
    int case_number;
    int size, i, j;
    std::vector<std::vector<int>> adjacency_matrix;
    std::cout << "(1) Создать граф с n количеством элементов.\n"
                 "(2) Вывести таблицу смежности\n"
                 "(3) Добавить новвый элемент\n"
                 "(4) Удалить элемент\n"
                 "(5) Получить длину ребра между узлами\n"
                 "(6) Удалить всю матрицу смежности\n"
                 "(7) Алгоритм Дейкстры\n"
                 "(8) PNG файл\n"
                 "(9) Сгенерировать матрицу смежности\n"
                 "(10) Очистить матрицу\n";
    while (get_int(&case_number, 0, 10) != 0  && case_number != 0) {
        switch (case_number) {
            case 1:
                make_graph_arr(adjacency_matrix, size);
            break;
            case 2:
                display_graph_arr(adjacency_matrix, size);
            break;
            case 3:
                std::cout << "Введите i, j:\n";
            get_int(&i, 1, size);
            get_int(&j, 1, size);
            add_edge_arr_undirect(adjacency_matrix, i - 1, j - 1);
            break;
            case 4:
                std::cout << "Введите i, j:\n";
            get_int(&i, 1, size);
            get_int(&j, 1, size);
            delete_edge_arr_undirect(adjacency_matrix, i - 1, j - 1);
            break;
            case 5:
                std::cout << "Введите i, j:\n";
            get_int(&i, 1, size);
            get_int(&j, 1, size);
            get_edge_arr(adjacency_matrix, i - 1 , j - 1);
            break;
            case 6:
                delete_all_edges(adjacency_matrix);
                break;
            case 7:
                std::cout << "Введите i:\n";
            get_int(&i, 0, size - 1);
            dijkstra_arr (adjacency_matrix, i);
            break;
            case 8:
                visualize_graph(adjacency_matrix);
            break;
            case 9:
                make_random_graph(adjacency_matrix);
                break;
            case 10:
                force_clear_adjacency_matrix(adjacency_matrix);
                break;
            break;
            default:
                std::cout << "Число вышло за разрешенный диапазон. Попробуйте еще раз!\n";
            break;
        }
        std::cout << "(1) Создать граф с n количеством элементов.\n"
                 "(2) Вывести таблицу смежности\n"
                 "(3) Добавить новвый элемент\n"
                 "(4) Удалить элемент\n"
                 "(5) Получить длину ребра между узлами\n"
                 "(6) Удалить всю матрицу смежности\n"
                 "(7) Алгоритм Дейкстры\n"
                 "(8) PNG файл\n"
                 "(9) Сгенерировать матрицу смежности\n"
                 "(10) Очистить матрицу\n";
    }
    force_clear_adjacency_matrix(adjacency_matrix);
}