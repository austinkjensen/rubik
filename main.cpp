#include <iostream>
#include <random>
#include <vector>
#include "Rubik.h"
#include "Rubik.cpp"


// using namespace std;
// #include <vector>
#include <array>
#include <random>
#include <iterator>


template <typename T>
T remove_at(std::vector<T>&v, typename std::vector<T>::size_type n)
{
    T ans = std::move_if_noexcept(v[n]);
    v[n] = std::move_if_noexcept(v.back());
    v.pop_back();
    return ans;
}

int choose_random_index(int vect_size) {
    srand(time(NULL));
    int ind = rand() % vect_size;
    return ind;
}

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
    std::vector<std::vector<char> > F = matrix_obj[0];
    side_printer(F);


}

int main() {

    char colors[] = {'U','L','F','D','R','B',
                    'U','L','F','D','R','B',
                    'U','L','F','D','R','B',
                    'U','L','F','D','R','B',
                    'U','L','F','D','R','B',
                    'U','L','F','D','R','B',
                    'U','L','F','D','R','B',
                    'U','L','F','D','R','B',
                    'U','L','F','D','R','B'};

    int colors_size = sizeof(colors)/sizeof(colors[0]);
    std::cout << colors_size << std::endl;
    std::vector<char> vect;
    vect.assign(colors,colors+colors_size);

    std::cout << vect.at(35) << std::endl;
    int sides = 6;
    int rows_per_side = 3;
    int squares_per_row = 3;
    int test_ct = 0;
    char testArr[sides][rows_per_side][squares_per_row];
    std::vector<std::vector<std::vector<char> > > matrix;
    
    matrix.resize(sides);
    for (int i = 0; i < sides; i++) {
        matrix[i].resize(rows_per_side);
        for (int j = 0; j < rows_per_side; j++) {
            matrix[i][j].resize(squares_per_row);
            for (int k = 0; k < squares_per_row; k++) {
                int random_index = choose_random_index(vect.size());
                char temp = remove_at(vect,random_index);
                matrix[i][j][k] = temp;
            };
        };
    };

    side_printer(matrix[0]);
    std::cout << "*****" << std::endl;
    front_turn(matrix);
    // side_printer(matrix[1]);
    // side_printer(matrix[2]);
    // side_printer(matrix[3]);
    // side_printer(matrix[4]);
    // side_printer(matrix[5]);

    // std::cout << &(matrix[0]) << std::endl;
    // std::cout << &(matrix[0][1]) << std::endl;
    // std::cout << &(matrix[0][2]) << std::endl;
    return 0;

}