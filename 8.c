// Advent of Code 2016: Day 8 Part 1 & 2
// Yi Xiao (yxxiaoyx)
// 08-12-2016

#include <stdio.h>
#include <string.h>

#define ON 1
#define OFF 0
#define WIDE 50
#define TALL 6 

int turnON(int screen[WIDE][TALL], int w, int t, int sum);
void rotateRow(int screen[WIDE][TALL], int row, int step);
void rotateCol(int screen[WIDE][TALL], int col, int step);
void printScreen(int screen[WIDE][TALL]);

int main(int argc, char *argv[]) {

    int screen[WIDE][TALL] = {{OFF, OFF}};  // initialize screen
    char instruct[7];                       // instruction buffer
    int rect[2] = {0};                      // rect dimension buffer
    int rotate[2] = {0};                    // rotation value buffer
    int sum = 0;                            // counts ON pixels

    // reads input
    while (scanf("%s", instruct) != EOF) {
        
        // rect action
        if (strcmp(instruct, "rect") == 0) {
            scanf("%dx%d", &rect[0], &rect[1]);
            sum = turnON(screen, rect[0], rect[1], sum); 
 
        // rotate action
        } else if (strcmp(instruct, "rotate") == 0) {
            scanf("%s", instruct);

            // rotate row
            if (strcmp(instruct, "row") == 0) {
                scanf("%*c%*c%*c%d %*s %d", &rotate[0], &rotate[1]);
                rotateRow(screen, rotate[0], rotate[1]);
            
            // rotate column
            } else if (strcmp(instruct, "column") == 0) {
                scanf("%*c%*c%*c%d %*s %d", &rotate[0], &rotate[1]);
                rotateCol(screen, rotate[0], rotate[1]);
            }
        }   
    }

    // print Part 1 result
    printf("%d\n", sum);

    // print Part 2 result (the screen)
    printScreen(screen);

    return 0;
}

// turn on pixels in specified rect
int turnON(int screen[WIDE][TALL], int w, int t, int sum) {
    int i, j;
    for (i = 0; i < w; i++) { 
        for (j = 0; j < t; j++) { 
            if (screen[i][j] == OFF) {
                screen[i][j] = ON;
                sum++;
            }
        }
    }
    return sum;
}

// rotate row
void rotateRow(int screen[WIDE][TALL], int row, int step) {
    int temp;
    int i, j;

    for (j = 0; j < step; j++) {
        temp = screen[WIDE-1][row];

        for (i = WIDE-1; i > 0; i--)
            screen[i][row] = screen[i-1][row];

        screen[0][row] = temp;
    }

}

// rotate column
void rotateCol(int screen[WIDE][TALL], int col, int step) {
    int temp;
    int i, j;

    for (j = 0; j < step; j++) {
        temp = screen[col][TALL-1];

        for (i = TALL-1; i > 0; i--)
            screen[col][i] = screen[col][i-1];

        screen[col][0] = temp;
    }   
}

// print final screen
void printScreen(int screen[WIDE][TALL]) {
    int i, j;
    for (i = 0; i < TALL; i++) {
        for (j = 0; j < WIDE; j++) {
            if (screen[j][i] == OFF)
                printf(".");
            else
                printf("#");
        }
        printf("\n");
    }
}
