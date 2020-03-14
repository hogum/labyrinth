# include "labyrinth.h"
# include <iostream>

int main(int argc, char **argv) {
    std::vector<std::vector<Marker>> maze;
    std::vector<Coordinate> path;
    std::vector<Marker> m;
    std::vector<Marker> mm;
    std::vector<Marker> mmm;

    Maze mz; 

    for(int i= 0; i< 11; i++){
        m.push_back(PATH);   
        mm.push_back(WALL);
        mmm.push_back(WALL);
    }
    m[3] =WALL;
    m[4] =WALL;
    m[7] =WALL;
    mmm[7] =PATH;
    mmm[9] =PATH;
    mmm[10] =PATH;

    for(int i= 0; i< 11; i++){
    }
    maze.push_back(m);
    maze.push_back(mm);
    maze.push_back(mmm);

    path = mz.findLongestPath(maze);

    for(auto i: path) {
        std::cout << "row: " << i.row << std::endl;
        std::cout << "col: " << i.col << std::endl;
        std::cout << std::endl;
    }
}
