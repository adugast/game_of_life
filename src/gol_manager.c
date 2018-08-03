#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "gol_manager.h"


static char **alloc_map(unsigned int width, unsigned int height)
{
    char **map = calloc(height + 1, sizeof(char *));
    if (map == NULL)
        return NULL;

    unsigned int i;
    for (i = 0; i < height; i++) {
        map[i] = calloc(width + 1, sizeof(char));
        unsigned int j;
        for (j = 0; j < width; j++)
            map[i][j] = ' ';
    }

    return map;
}


static void free_map(char **map)
{
    unsigned int i;
    for (i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}


gol_t *gol_init_map_handler(unsigned int width, unsigned int height)
{
    gol_t *hdl = calloc(1, sizeof(gol_t));
    if (hdl == NULL)
        return NULL;

    hdl->map = alloc_map(width, height);
    hdl->width = width;
    hdl->height = height;
    hdl->current_cells_nbr = 0;

    return hdl;
}


void gol_free_handler(gol_t *hdl)
{
    free_map(hdl->map);
    free(hdl);
}


void gol_fill_map(gol_t *hdl, unsigned int nbr, char c)
{
    hdl->current_cells_nbr = nbr;
    hdl->tok = c;
    srand(time(NULL));

    if ((hdl->height * hdl->width) < nbr)
        nbr = hdl->height * hdl->width;

    unsigned int i;
    for (i = 0; i < nbr; i++) {
        unsigned int x = rand() % hdl->width;
        unsigned int y = rand() % hdl->height;
        if (hdl->map[y][x] == ' ')
            hdl->map[y][x] = c;
        else {
            i--;
            continue;
        }
    }
}


void gol_dump_map(gol_t *hdl)
{
    unsigned int i;
    for (i = 0; i < hdl->height; i++)
        printf("%s\n", hdl->map[i]);
}

