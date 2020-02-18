#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "argument_manager.h"


static void print_usage(const char *binary_name)
{
    printf("Usage: %s [params]\n", binary_name);
    printf("Available params:\n");
    printf(" -h, --help       : Display this help and exit\n");
    printf(" -v, --version    : Show version information\n");
    printf(" -x, --width      : Set map width\n");
    printf(" -y, --height     : Set map height\n");
    printf(" -n, --nbcells    : Set pre-existant cells number present in the universe\n");
    printf(" -c, --char       : Set char as cell representation\n");
    printf(" -f, --freq       : Set time between each iteration in msec\n");
    printf(" -l, --lifetime   : Set the number of iteration before the game ends\n");
    printf(" -s, --statistics : Dump statistics on the gol universe\n");
}


static void print_version()
{
    printf("gol: version \?.\?.\?\?(\?)-release\n");
    printf("Conway's Game of Life\n");
    printf("Copyright (C) 2018 adugast\n");
    printf("MIT License: <https://opensource.org/licenses/MIT>\n");
    printf("Git Repository: <https://github.com/adugast/gol>\n");
    printf("\n");
    printf("This is free software; you are free to change and redistribute it.\n");
    printf("There is NO WARRANTY, to the extent permitted by law.\n");
}


static void set_default_configuration(struct argument *args)
{
    args->width_m = 40;
    args->height_m = 20;
    args->nbcells_m = 150;
    args->sleep_m = 150000;
    args->lifetime_m = 200;
    args->tok_m = '*';
    args->statistics_m = false;
}


void argument_manager(int argc, char *argv[], struct argument *args)
{
    set_default_configuration(args);

    static struct option long_options[] = {
        {"help",        no_argument, 0, 'h'},
        {"version",     no_argument, 0, 'v'},
        {"width",       required_argument, 0, 'x'},
        {"height",      required_argument, 0, 'y'},
        {"nbcells",     required_argument, 0, 'n'},
        {"char",        required_argument, 0, 'c'},
        {"freq",        required_argument, 0, 'f'},
        {"lifetime",    required_argument, 0, 'l'},
        {"statistics",    no_argument, 0, 's'},
        {0, 0, 0, 0}
    };

    const char *option_string = "hvx:y:n:c:f:l:s";
    int c;
    while ((c = getopt_long(argc, argv, option_string, long_options, NULL)) != -1) {
        switch (c) {
            case 'h': print_usage(argv[0]); exit(EXIT_SUCCESS);
            case 'v': print_version(); exit(EXIT_SUCCESS);
            case 'x': args->width_m = strtol(optarg, NULL, 10); break;
            case 'y': args->height_m = strtol(optarg, NULL, 10); break;
            case 'n': args->nbcells_m = strtol(optarg, NULL, 10); break;
            case 'c': args->tok_m = optarg[0]; break;
            case 'f': args->sleep_m = strtol(optarg, NULL, 10); break;
            case 'l': args->lifetime_m = strtol(optarg, NULL, 10); break;
            case 's': args->statistics_m = true; break;
            default: print_usage(argv[0]); exit(EXIT_SUCCESS);
        }
    }
}

