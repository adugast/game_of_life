#ifndef __ARGUMENT_MANAGER_H__
#define __ARGUMENT_MANAGER_H__


#include <stdbool.h>


struct argument {
    unsigned int width_m; //
    unsigned int height_m; // height of the map
    unsigned int nbcells_m; // nbr of cells present at the begin of the universe
    unsigned int sleep_m;
    unsigned int lifetime_m; //
    bool statistics_m; // boolean to activate statistics dump
    char tok_m; // char that represents the cell
};


void argument_manager(int argc, char **argv, struct argument *args);


#endif /* __ARGUMENT_MANAGER_H__ */
