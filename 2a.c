// Advent of Code 2016: Day 2 Part 1
// Yi Xiao (yxxiaoyx)
// 03-12-2016
 
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {

    // defines '5' as Row 0 Col 0
    int row = 0;
    int col = 0;
    int ch;

    // reads input
    while ((ch = getchar()) != EOF) {

        // processes one line of input at a time
        while (ch != '\n' && ch != EOF) {

            // moves in the grid
            if (ch == 'U') {
                if (row < 1) {
                    row += 1;               
                }
            } else if (ch == 'D') {
                if (row > -1) {
                    row -= 1;
                }
            } else if (ch == 'L') {
                if (col > -1) {
                    col -= 1;
                }
            } else if (ch == 'R') {
                if (col < 1) {
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
