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
                    'B','B','B','B','B','B','B','B','B'};
    int root_colors_size = sizeof(colors2)/sizeof(colors2[0]);
    std::cout << root_colors_size << std::endl;

    int a = 2;
    std::cout << "made it this far " << std::endl;
    CubeGen cube_test = CubeGen(a);
    std::cout << "runs" << std::endl;
}