// Advent of Code 2016: Day 2 Part 1
// Yi Xiao (yxxiaoyx)
// 03-12-2016

#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

// returns the minimum row/col index allowed for a certain col/row
int min(int n) {
    return abs(n)-2;
}

// returns the maximum row/col index allowed for a certain col/row
int max(int n) {
    return 2-abs(n); 
}

int main(int argc, char *argv[]) {
    int row = 0;
    int col = 0;
    int ch;

    // reads input
    while ((ch = getchar()) != EOF) {

        // processes one line of input at a time
        while (ch != '\n' && ch != EOF) {

            // moves in the grid
            if (ch == 'U') {
                if (row < max(col)) {  // max row index allowed for current col
                    row += 1;
                }
            } else if (ch == 'D') {
                if (row > min(col)) {
                    row -= 1;
                }
            } else if (ch == 'L') {
                if (col > min(row)) {
                    col -= 1;
               }
            } else if (ch == 'R') {
                if (col < max(row)) {
                    col += 1;
              }
            }

            ch = getchar();
        }

        // prints location of the digit in the grid
        // It is then much faster to visually locate the digit 
        // than works it out by code.
        printf("row = %d, col = %d\n", row, col);
    }

    return 0;
}
