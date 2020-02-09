#pragma once
#include <iostream>
#include <vector>
// #using namespace std;

class CubeGen {
    // const std::vector<int> colors;
    public:
        int num_of_scrambles;
        int _sides = 6;
        int _rows_per_side = 3;
        int _squares_per_row = 3;
        std::vector<std::vector<std::vector<char> > > cube_matrix;
        const char static_colors[54] = {'U','U','U','U','U','U','U','U','U',
                'L','L','L','L','L','L','L','L','L',
                'F','F','F','F','F','F','F','F','F',
                'D','D','D','D','D','D','D','D','D',
                'R','R','R','R','R','R','R','R','R',
                'B','B','B','B','B','B','B','B','B'};
        const int colors_obj_size = 54;

        CubeGen();
        CubeGen(int num_of_scrambles);
        std::vector<std::vector<std::vector<char> > > matrix_obj;
        // template <typename T> remove_at(std::vector<T>&v, typename std::vector<T>::size_type n);
        // char remove_at(std::vector<char>&v, int n);
        int choose_random_index(int vect_size);
        char remove_at(std::vector<char>&v, int n);
        void side_printer(std::vector<std::vector<char> > side_obj);
        char smart_remove(std::vector<char>&v);
};