#pragma once
#include <iostream>

using namespace std;




class Rubik {
    public:
        Rubik();
        

        class Side {
            public:
                Side();
                Side(std::vector<int>[9]);
                char data;
                // std::vector<int> data[9];
                // int sides = 6;
                // int rows_per_side = 3;
                // int squares_per_row = 3;
                // std::vector<std::vector<std::vector<char> > > our_matrix[];

                // int choose_random_index(int vect_size);
                // char remove_at(std::vector<int>&v, int n);
        };

        // Rubik(Side side0, Side side1, Side side2, Side side3, Side side4, Side side5);

    private:
};
