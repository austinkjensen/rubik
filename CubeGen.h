#pragma once
#include <iostream>
#include <vector>


class CubeGen {

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
        const int static_moves_size = 6;
        const char static_moves[6] = {'U','L','F','D','R','B'};
        std::vector<char> cube_face_keys;
        CubeGen();
        CubeGen(int num_of_scrambles);
        std::vector<std::vector<std::vector<char> > > matrix_obj;
        int choose_random_index(int vect_size);
        char remove_at(std::vector<char>&v, int n);
        void side_printer(std::vector<std::vector<char> > side_obj);
        char smart_remove(std::vector<char>&v);

        void front_turn(std::vector<std::vector<std::vector<char> > > matrix_obj);
        
};