#ifndef __MAIN__H
#define __MAIN__H

#include <vector>
#include "../src/labyrinth.h"

/// Entry Usage Function
int show_usage(char *arg_vec[], int argc);

/// Extracts the labyrinth from file to a Vector
void read_labyrinth(
        std::vector<std::vector<Marker>> *grid,
        char * file);

/// Marks the coordinates in the traced out path in the
/// order of visit
void displayTakenPath(std::vector<std::vector<Marker>> grid,
        std::vector<Coordinate> path);

#endif
