#ifndef SAND
#define SAND
#include <stdio.h>
#include <stdlib.h>
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void toppling(int grid1[3][3], int grid2[3][3]);
void sum_grids(int grid1[3][3], int grid2[3][3]);
int is_stable(int grid1[3][3], int grid2[3][3]);
void print_sandpiles(int grid[3][3]);

#endif