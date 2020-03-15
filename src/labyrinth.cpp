#include "labyrinth.h"
#include <iostream>
#include <cstddef>
#include <map>


Maze::Maze(bool checkLastRow) {
    this->check_last_row = checkLastRow;
}

std::vector<Coordinate> Maze::findLongestPath(std::vector<std::vector<Marker>> maze) {

    std::map <size_t, std::vector<Coordinate>> all_paths= std::map <size_t, std::vector<Coordinate>> ();
    std::vector<Coordinate> EntryPoints;

    getEntryPoints(&EntryPoints, maze, this->check_last_row);


    /* No entry point*/
    if (EntryPoints.empty())
        return EntryPoints;

    for(auto entry: EntryPoints) {
        std::vector<Coordinate> path;

        /* Mark as Visited */
        maze.at(entry.row).at(entry.col) = WALL;
        path.push_back(entry);

        if (leadsToEnd(entry, &path, &maze)) {
            all_paths[path.size()] = path;

        }
    }
    return all_paths.rbegin()->second;
}

bool Maze::leadsToEnd(Coordinate point,
        std::vector<Coordinate> *path,
        std::vector<std::vector<Marker>> *maze
        )  {

    for(auto&  direction: this->DIRECTIONS) {
        // We were told not to go UP
        if (!this-> check_last_row && direction == DIRECTIONS[3])
            continue;
        Coordinate nxt_point =  Coordinate {
            .row = point.row + *direction,
                .col = point.col + *(direction + 1),
        };

        if (isNotEnd(nxt_point, *maze)) {
            // Mark as visited
            maze->at( nxt_point.row ).at( nxt_point.col ) = WALL;
            path->push_back(nxt_point);

            return leadsToEnd(nxt_point, path, maze);
        }

    }
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

bool Maze::isNotEnd(Coordinate point,
        std::vector<std::vector<Marker>> maze
        ) {
    return point.row < maze.size() and point.col < maze.at(point.row).size() and point.row >= 0 and point.col >= 0 and maze.at(point.row).at( point.col ) == PATH;
}
