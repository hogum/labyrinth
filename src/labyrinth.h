#ifndef __LABYRINTH__H
#define __LABYRINTH__H

// typedef struct Marker Marker;

#include <vector>

/// The Maze Marker structures
struct Marker {
    char wall = '#';
    char path = '.';
};

/// A single point on the Maze
struct Coordinate {
    int row;
    int col;
};

/// Handles extracting of paths in a given
/// maze
class Maze {
    public:
        std::vector<Coordinate> findLongestPath(std::vector<std::vector<Marker>> maze)
;
    private:
        bool leadsToEnd();

};

#endif
