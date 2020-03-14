#include "labyrinth.h"
#include <iostream>


std::vector<Coordinate> Maze::findLongestPath(std::vector<std::vector<Marker>> maze) {

    std::vector<Coordinate> path;
    std::vector<Coordinate> EntryPoints;

    for (int coord = 0; coord < maze[0].size(); coord++) {
        if (maze[0][coord] == PATH) {
            Coordinate starting_coord = Coordinate {.row = 0, .col = coord};
            EntryPoints.push_back(starting_coord);
    }
    }


    for(auto entry: EntryPoints) {
       // this->leadsToEnd(entry, maze);
    }
    return EntryPoints;
}

bool Maze::leadsToEnd() {
    return true;
}


