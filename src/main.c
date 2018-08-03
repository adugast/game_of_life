#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "argument_manager.h"
#include "gol_manager.h"


// TODO: add security to loop also on the borders
static unsigned int count_neighbors_cells(gol_t *hdl, unsigned int x, unsigned int y)
{
    unsigned int nb_cells = 0;

    (hdl->map[y][x + 1] == hdl->tok) ? nb_cells++ : 0;
    (hdl->map[y + 1][x] == hdl->tok) ? nb_cells++ : 0;
    (hdl->map[y + 1][x + 1] == hdl->tok) ? nb_cells++ : 0;
    (hdl->map[y - 1][x - 1] == hdl->tok) ? nb_cells++ : 0;
    (hdl->map[y][x - 1] == hdl->tok) ? nb_cells++ : 0;
    (hdl->map[y + 1][x - 1] == hdl->tok) ? nb_cells++ : 0;
    (hdl->map[y - 1][x + 1] == hdl->tok) ? nb_cells++ : 0;
    (hdl->map[y - 1][x] == hdl->tok) ? nb_cells++ : 0;

    return nb_cells;
}


static void game_of_life(gol_t *hdl)
{
    unsigned int y;
    for (y = 1; y < hdl->height - 1; y++) {
        unsigned int x;
        for (x = 1; x < hdl->width - 1; x++) {
            unsigned int nb_cells = count_neighbors_cells(hdl, x, y);
            // condition to kill the cell
            if (nb_cells < 2 || nb_cells > 3) {
                if (hdl->map[y][x] == '*')
                    hdl->current_cells_nbr--;
                hdl->map[y][x] = ' ';
            }

            // condition to create a cell
            if (nb_cells == 3) {
                if (hdl->map[y][x] == ' ')
                    hdl->current_cells_nbr++;
                hdl->map[y][x] = hdl->tok;
            }
        }
    }
}


static int gol(struct argument *args)
{
    // retrieve a gol handler with width and height of the map
    gol_t *hdl = gol_init_map_handler(args->width_m, args->height_m);

    // fill the map with nbr of characters at random position
    gol_fill_map(hdl, args->nbcells_m, args->tok_m);

    unsigned int time;
    for (time = 0; time < args->lifetime_m; time++) {

        // clear the screen
        system("clear");

        // dump the gol map
        gol_dump_map(hdl);

        // print info about the universe
        if (args->statistics_m == true) {
            printf("timelife:%d/%d\n", time + 1, args->lifetime_m);
            printf("freqence:%d iteration/sec\n", 1000000 / args->sleep_m);
            printf("nbr of cells in the universe:%d\n", hdl->current_cells_nbr);
            // add nbr of died cells ?
            // add nbr of born cells ?
        }

        game_of_life(hdl);

        usleep(args->sleep_m);
    }

    // free the gol handler
    gol_free_handler(hdl);

    return 0;
}


int main(int argc, char *argv[])
{
    struct argument args;

    argument_manager(argc, argv, &args);

    gol(&args);

    return 0;
}

