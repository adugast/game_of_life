# Game of life [![Language: C](https://img.shields.io/badge/Language-C-brightgreen.svg)](https://en.wikipedia.org/wiki/C_(programming_language)) [![Builder: CMake](https://img.shields.io/badge/Builder-CMake-brightgreen.svg)](https://cmake.org/)  [![License: MIT](https://img.shields.io/badge/License-MIT-brightgreen.svg)](https://opensource.org/licenses/MIT)

## Introduction

C implementation of the Conway's Game of Life

## Usage:
Launch the game of life:   
```
$>./gol -s
```

## Output:

```
    *       *    *          ***   *     
*          *  ** ******** * *           
            **   *      * *             
             *  ** *   *   *            
                 *       *           * *
                  **     **          ** 
                 *  *                   
                 *  **                  
     ***        * * **                  
   *   *       ** *                   **
   ** *         * *                    *
   *    **  *****  *                *** 
   ****  *** * * * **               *   
  *    ***    ** * **                   
 * *  *  *     * *                      
 * * * ***       *                     *
 * * *           **                     
  ** * **                               
    *  **                              *
    * *                *    *  *   **   
timelife:11/200
frequence:6 iteration/sec
nbr of cells in the universe:136
```

## Help:

```
Usage: ./gol [params]
Available params:
 -h, --help       : Display this help and exit
 -v, --version    : Show version information
 -x, --width      : Set map width
 -y, --height     : Set map height
 -n, --nbcells    : Set pre-existant cells number present in the universe
 -c, --char       : Set char as cell representation
 -f, --freq       : Set time between each iteration in msec
 -l, --lifetime   : Set the number of iteration before the game ends
 -s, --statistics : Dump statistics on the gol universe
```

## More info:

* [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) - Wikipedia page

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
