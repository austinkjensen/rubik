#include <iostream>
#include "CubeGen.h"
#include <vector>
#include <random>
#include <iterator>

// template <typename T>
// T CubeGen::remove_at(std::vector<T>&v, typename std::vector<T>::size_type n)
// char CubeGen::remove_at(std::vector<char>&v, int n) 
// {
//     char ans = std::move_if_noexcept(v[n]);
//     v[n] = std::move_if_noexcept(v.back());
//     v.pop_back();
//     return ans;
// }

char CubeGen::remove_at(std::vector<char>&v, int n) {
    char ans = std::move_if_noexcept(v[n]);
    v[n] = std::move_if_noexcept(v.back());
    v.pop_back();
    return ans;
}

int CubeGen::choose_random_index(int vect_size) {
    srand(time(NULL));
    int ind = rand() % vect_size;
    return ind;
}

char CubeGen::smart_remove(std::vector<char>&v) {
    char ans = v.at(0);
    v.erase(v.begin());
    return ans;
}

void CubeGen::side_printer(std::vector<std::vector<char> > side_obj) {
    std::cout << "******" << std::endl;
    int side_size = side_obj.size();
    int row_size = side_obj[0].size();
    std::cout <<  "[";
    for (int row = 0; row < side_size; row++) {
        std::cout << "[";
        for (int sq = 0; sq < row_size; sq++) {
            if (sq < (row_size-1)) {
                std::cout << side_obj[row][sq] << ",";
            } else if (sq == (row_size-1)) {
                if (row < (side_size-1)) {
                    std::cout << side_obj[row][sq] << "]," << std::endl;
                } else if (row == side_size-1) {
                    std::cout << side_obj[row][sq] << "]]" << std::endl;
                }
            }
        }
    }
    std::cout << "******" << std::endl;
};

CubeGen::CubeGen(int num_of_scrambles) {

    std::vector<char> vect;
    vect.assign(static_colors,static_colors+colors_obj_size);

    // int sides = 6;
    // int rows_per_side = 3;
    // int squares_per_row = 3;
    // char testArr[sides][rows_per_side][squares_per_row];
    cube_matrix.resize(_sides);

    for (int i = 0; i < _sides; i++) {
        cube_matrix[i].resize(_rows_per_side);
        for (int j = 0; j < _rows_per_side; j++) {
            cube_matrix[i][j].resize(_squares_per_row);
            for (int k = 0; k < _squares_per_row; k++) {
                char temp = smart_remove(vect);
                cube_matrix[i][j][k] = temp;
            }
        }
    }
    side_printer(cube_matrix[0]);
    side_printer(cube_matrix[1]);
    side_printer(cube_matrix[2]);
    side_printer(cube_matrix[3]);
    side_printer(cube_matrix[4]);
    side_printer(cube_matrix[5]);
    return;
}

