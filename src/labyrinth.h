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
    size_t row;
    size_t col;
};

/**
 * Maze representation.
 * Handles extracting of paths in a given
 * maze.
 * 
 * @param checkLastRow: Look for paths from the last row.(Default true).
 This is from the assumption that a maze can have starting points from either the top or last row.
 **/
class Maze {
    public:
        Maze(bool checkLastRow=true);

        /**
         *  Finds the longest traceable path in a passed maze vector.
         * @param maze: The Coordinate grid
         * @returns Vector with Coordinates to the longest path.
         */
        std::vector<Coordinate> findLongestPath(std::vector<std::vector<Marker>> maze)
            ;
    private:
        /// Checks whether a Coordinate leads to a dead end.
        /// This means a single complete path
        bool leadsToEnd(Coordinate point,
                std::vector<Coordinate> *path,
                std::vector<std::vector<Marker>> *maze
                );

        /// Finds all the PATH starting points in the maze.
        /// Entry points assumed to exist in either the top
        /// or the bottom maze row.
        void getEntryPoints(
                std::vector<Coordinate> *entryPoints,/**< Points to starting path coordinates. */  
                std::vector<std::vector<Marker>> maze, /**< Maze grid. */  
                bool check_last_row /**< option to check for starting points in last maze row. */  
                );
        bool check_last_row; /**< Flag to look for paths from bottom*/

        /// Checks whether a given point marks the end
        /// of a path.
        bool isNotEnd(Coordinate c,
                std::vector<std::vector<Marker>> grid
                );

        /**< Traversible directions on grid */
        const int DIRECTIONS[4][2] = {
            {0, 1}, // RIGHT
            {0, -1}, // LEFT
            {1, 0}, // DOWN
            {-1, 0} // UP
        };


};

// TODO Move these to utils

/// Start Helper Function
int show_usage(char *arg_vec[], int argc);

/// Extracts the labyrinth from file
void read_labyrinth(
        std::vector<std::vector<Marker>> *grid,
        char * file);

#endif
