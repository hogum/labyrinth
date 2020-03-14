#include "labyrinth.h"
#include <iostream>
#include <cstddef>


Maze::Maze(bool checkLastRow) {
    this->check_last_row = checkLastRow;
}

std::vector<Coordinate> Maze::findLongestPath(std::vector<std::vector<Marker>> maze) {

    std::vector<Coordinate> path;
    std::vector<Coordinate> EntryPoints;

    getEntryPoints(&EntryPoints, maze, this->check_last_row);



    for(auto entry: EntryPoints) {
        // this->leadsToEnd(entry, maze);
    }
    return EntryPoints;
}

bool Maze::leadsToEnd() {
    return true;
}

void Maze::getEntryPoints(
        std::vector<Coordinate> *entryPoints,
        std::vector<std::vector<Marker>> maze,
        bool check_last_row) {

    size_t start_rows[] = {0, maze.size() - 1};

    for (const size_t &row_ : start_rows) {
        if((!check_last_row && row_ > 0) || 
                !entryPoints->empty()) /* Found starting points */
            break;

        for (size_t coord = 0; coord < maze[row_].size(); coord++) {
            if (maze[row_][coord] == PATH) {
                Coordinate starting_coord = Coordinate {
                    .row = row_,
                        .col = coord
                };
                entryPoints->push_back(starting_coord);
            }
        }

    }
}
