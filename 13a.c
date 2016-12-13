// Advent of Code 2016: Day 13 Part 1
// Yi Xiao (yxxiaoyx)
// 13-12-2016

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define WALL 1
#define SPACE 0
#define FAV 1350    // input: office designer's fav num
#define SIZE 52     // maze size
#define X 31        // Part 1 input: x of destination
#define Y 39        // Part 1 input: y of destination 

void getMaze(int maze[SIZE][SIZE]);
int isWall(int num);
int move(int maze[SIZE][SIZE]);
int isSpace(int maze[SIZE][SIZE], int x, int y, int poss[][3], int step, int steps[SIZE][SIZE], int i);

int main(int argc, char *argv[]) {
    int maze[SIZE][SIZE] = {{0}};

    getMaze(maze);
    printf("fewest steps to (%d, %d) is %d\n", X, Y, move(maze));

    return 0;
}

// generate maze
void getMaze(int maze[SIZE][SIZE]) {
    int num;
    int x, y;
    for (y = 0; y < SIZE; y++) {
        for (x = 0; x < SIZE; x++) {
            num = x*x + 3*x + 2*x*y + y + y*y + FAV;
            maze[x][y] = (isWall(num))? WALL : SPACE;
        }
    }
}

// count 1s in binary to decide if the location is wall
int isWall(int num) {
    int count = 0;
    while (num > 0) {
        if (num % 2 == 1)
            count++;
        num = num / 2;
    }

    if (count % 2 == 1)
        return TRUE;
    else
        return FALSE;
}

// move in maze to find all possible paths to destination
// then return steps of the shortest
int move(int maze[SIZE][SIZE]) {
    int step = 0;                   // interim step count
    int x = 1;
    int y = 1;
    int exhaust = FALSE;            // stop flag
    int i = 0;                      // possible move count
    int possible[128][3] = {{0}};   // all possible moves
    int steps[SIZE][SIZE] = {{0}};  // final step count 
    
    // set starting point to a non-zero value
    steps[x][y] = '0';

    while (exhaust == FALSE) {

        // search nearby locs for SPACE; add to possible moves; update steps
        i = (x > 0)? isSpace(maze, x-1, y, possible, step, steps, i) : i;
        i = (y > 0)? isSpace(maze, x, y-1, possible, step, steps, i) : i;
        i = isSpace(maze, x+1, y, possible, step, steps, i);
        i = isSpace(maze, x, y+1, possible, step, steps, i);

        // move one step if possible moves are not yet exhausted
        if (i > 0) {
            i--;
            x = possible[i][0];
            y = possible[i][1];
            step = possible[i][2];
        } else {
            exhaust = TRUE;
        }

    }

    return steps[X][Y];
}

// if loc is SPACE, add to possible moves
// count steps; store the smallest num of steps
int isSpace(int maze[SIZE][SIZE], int x, int y, int poss[][3], int step, int steps[SIZE][SIZE], int i) {
    if (maze[x][y]==SPACE && (steps[x][y]>step+1 || steps[x][y]==0)) {
        poss[i][0] = x;
        poss[i][1] = y;
        poss[i][2] = step + 1;
        steps[x][y] = step + 1;
        i++;
    }
    return i;
}

