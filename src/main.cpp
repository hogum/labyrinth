# include "labyrinth.h"
# include <iostream>

int main(int argc, char **argv) {
    std::vector<std::vector<Marker>> maze;
    std::vector<Coordinate> path;
    std::vector<Marker> m;
    std::vector<Marker> mm;

    Maze mz; 

    for(int i= 0; i< 11; i++){
        m.push_back(PATH);   
        mm.push_back(WALL);
    }
    mm[3] =PATH;

    for(int i= 0; i< 11; i++){
    }
    maze.push_back(m);
    maze.push_back(mm);

    path = mz.findLongestPath(maze);

    for(auto i: path) {
        std::cout << i.row << std::endl;
    }
}
