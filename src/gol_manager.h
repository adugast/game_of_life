#ifndef __GOL_MANAGER_H__
#define __GOL_MANAGER_H__


typedef struct gol {
    char **map; // map of chars
    unsigned int width; // map width
    unsigned int height; // map height
    char tok;
    unsigned int current_cells_nbr;
} gol_t;


gol_t *gol_init_map_handler(unsigned int width, unsigned int height);
void gol_free_handler(gol_t *hdl);
void gol_fill_map(gol_t *hdl, unsigned int nbr, char c);
void gol_dump_map(gol_t *hdl);


#endif /* __GOL_MANAGER_H__ */
