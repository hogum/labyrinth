# include "labyrinth.h"
# include <iostream>

int main(int argc, char **argv) {
    std::vector<std::vector<Marker>> maze;
    std::vector<Coordinate> path;
    std::vector<Marker> m;
    std::vector<Marker> mm;
    std::vector<Marker> mmm;

    Maze mz; 

    for(int i= 0; i< 5; i++){
        m.push_back(PATH);   
        mm.push_back(WALL);
        mmm.push_back(WALL);
    }
    m[3] =WALL;
    m[2] =WALL;
    m[0] =WALL;
    mm[1] =PATH;

    for(int i= 0; i< 5; i++){
    }
    maze.push_back(m);
    maze.push_back(mm);
    maze.push_back(mm);
    maze.push_back(mm);
    maze.push_back(mm);
    maze.push_back(mmm);

    path = mz.findLongestPath(maze);

    for(auto i: path) {
        std::cout << "row: " << i.row << std::endl;
        std::cout << "col: " << i.col << std::endl;
        std::cout << std::endl;
    }
}
