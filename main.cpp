#include <iostream>
#include <random>
#include <vector>
#include <array>
#include <random>
#include <iterator>

#include "Rubik.h"
#include "Rubik.cpp"
#include "CubeGen.h"
#include "CubeGen.cpp"

// template <typename T>
// T remove_at(std::vector<T>&v, typename std::vector<T>::size_type n)
// {
//     T ans = std::move_if_noexcept(v[n]);
//     v[n] = std::move_if_noexcept(v.back());
//     v.pop_back();
//     return ans;
// }

// int choose_random_index(int vect_size) {
//     srand(time(NULL));
//     int ind = rand() % vect_size;
//     return ind;
// }

void side_printer(std::vector<std::vector<char> > side_obj) {
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
};

void front_turn(std::vector<std::vector<std::vector<char> > > matrix_obj) {
    // Here, we will define matrix[0] as "F" (front). Probably wrong, but whatever!
    // Purpose of this is to turn the top row of F and place it in the top row of R, then we move
    // All of the other adjacent top rows accordingly (B, and L).
    std::cout << "*****" << std::endl;
    std::vector<std::vector<std::vector<char> > > new_matrix = matrix_obj;
    std::vector<std::vector<char> > F = matrix_obj[0];
    std::vector<std::vector<char> > R = matrix_obj[1];
    std::vector<std::vector<char> > B = matrix_obj[2];
    std::vector<std::vector<char> > L = matrix_obj[3];

    std::vector<char> F_top = F[0];
    std::vector<char> R_top = R[0];
    std::vector<char> B_top = B[0];
    std::vector<char> L_top = L[0];

    std::cout << "F" << std::endl; 
    side_printer(F);
    std::cout << "R" << std::endl; 
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

    std::cout << "F" << std::endl; 
    side_printer(matrix_obj[0]);
    std::cout << "R" << std::endl; 
    side_printer(matrix_obj[1]);


    // side_printer(F);

}

int main() {

    char colors1[] = {'U','L','F','D','R','B',
                    'U','L','F','D','R','B',
                    'U','L','F','D','R','B',
                    'U','L','F','D','R','B',
                    'U','L','F','D','R','B',
                    'U','L','F','D','R','B',
                    'U','L','F','D','R','B',
                    'U','L','F','D','R','B',
                    'U','L','F','D','R','B'};
    
    char colors2[] = {'U','U','U','U','U','U','U','U','U',
                    'L','L','L','L','L','L','L','L','L',
                    'F','F','F','F','F','F','F','F','F',
                    'D','D','D','D','D','D','D','D','D',
                    'R','R','R','R','R','R','R','R','R',
                    'B','B','B','B','B','B','R','R','R'};
    int root_colors_size = sizeof(colors2)/sizeof(colors2[0]);
    std::cout << root_colors_size << std::endl;

    int a = 2;
    std::cout << "made it this far " << std::endl;
    CubeGen cube_test = CubeGen(colors2,a);
    std::cout << "runs" << std::endl;
    // int colors_size = sizeof(colors)/sizeof(colors[0]);
    // // std::cout << colors_size << std::endl;
    // std::vector<char> vect;
    // vect.assign(colors,colors+colors_size);

    // // std::cout << vect.at(35) << std::endl;
    // int sides = 6;
    // int rows_per_side = 3;
    // int squares_per_row = 3;
    // int test_ct = 0;
    // char testArr[sides][rows_per_side][squares_per_row];
    // std::vector<std::vector<std::vector<char> > > matrix;
    
    // matrix.resize(sides);
    // for (int i = 0; i < sides; i++) {
    //     matrix[i].resize(rows_per_side);
    //     for (int j = 0; j < rows_per_side; j++) {
    //         matrix[i][j].resize(squares_per_row);
    //         for (int k = 0; k < squares_per_row; k++) {
    //             int random_index = choose_random_index(vect.size());
    //             char temp = remove_at(vect,random_index);
    //             matrix[i][j][k] = temp;
    //         };
    //     };
    // };

    // side_printer(matrix[0]);
    
    // front_turn(matrix);

    // return 0;   

}