#ifndef __ARGUMENT_MANAGER_H__
#define __ARGUMENT_MANAGER_H__


#include <stdbool.h>


struct argument {
    unsigned int width_m;   // map width
    unsigned int height_m;  // map height
    unsigned int nbcells_m; // cells number present at the begin of the universe
    unsigned int sleep_m;
    unsigned int lifetime_m;
    bool statistics_m;          // activate dump statistics
    char tok_m;                 // character representing one cell
};


void argument_manager(int argc, char **argv, struct argument *args);


#endif /* __ARGUMENT_MANAGER_H__ */

