#include <iostream>
#include "CubeGen.h"
#include <vector>
#include <random>
#include <iterator>
#include <map>
#include <utility>      // std::pair, std::make_pair


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

void CubeGen::front_turn(std::vector<std::vector<std::vector<char> > > matrix_obj) {

    // Here, we will define matrix[0] as "F" (front). Probably wrong, but whatever!
    // Purpose of this is to turn the top row of F and place it in the top row of R, then we move
    // All of the other adjacent top rows accordingly (B, and L).
    // std::cout << "*****" << std::endl;
    std::vector<std::vector<std::vector<char> > > new_matrix = matrix_obj;
    std::vector<std::vector<char> > F = matrix_obj[0];
    std::vector<std::vector<char> > R = matrix_obj[1];
    std::vector<std::vector<char> > B = matrix_obj[2];
    std::vector<std::vector<char> > L = matrix_obj[3];

    std::vector<char> F_top = F[0];
    std::vector<char> R_top = R[0];
    std::vector<char> B_top = B[0];
    std::vector<char> L_top = L[0];

    side_printer(F);
    side_printer(R);
    R[0] = F_top;
    B[0] = R_top;
    L[0] = B_top;
    F[0] = L_top;
    std::cout << "*****" << std::endl;
    matrix_obj[0][0] = F[0];
    matrix_obj[1][0] = R[0];
    matrix_obj[2][0] = B[0];
    matrix_obj[3][0] = L[0];

    // std::cout << "F" << std::endl; 
    // side_printer(matrix_obj[0]);
    // std::cout << "R" << std::endl; 
    // side_printer(matrix_obj[1]);
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

    std::map <char,std::vector<std::vector<char> > > myMap;
    for (int i = 0; i < 6; i++) {
        std::pair <char,std::vector<std::vector<char> > > temp (static_moves[i],cube_matrix[i]);
        myMap[temp.first]=temp.second;
    }
    side_printer(myMap['F']);
    side_printer(myMap['U']);
    return;
}

