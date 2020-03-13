#ifndef __LABYRINTH__H
#define __LABYRINTH__H


#include <vector>

/// The Maze Marker structures
enum Marker {
    WALL = '#',
    PATH = '.',
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
