#ifndef __LABYRINTH__H
#define __LABYRINTH__H


#include <vector>

/// The Maze Marker structures
enum Marker: char {
    WALL = '#',
    PATH = '.',
};

/// Represents a single coordinate point on the Maze
struct Coordinate {
    int row;
    int col;
};

/// Handles extracting of paths in a given
/// maze
class Maze {
    public:
        /// Finds the longest traceable path in a passed maze vector.
        /// 
        std::vector<Coordinate> findLongestPath(std::vector<std::vector<Marker>> maze)
;
    private:
        /// Checks whether a Coordinate leads to a dead end.
        /// This means a single complete path
        bool leadsToEnd();
        std::vector<Coordinate> path;
};

#endif
