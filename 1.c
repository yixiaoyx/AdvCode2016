// Advent of Code 2016: Day 1 Part 1&2
// Yi Xiao (yxxiaoyx)
// 03-12-2016 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

// prints Part 2 answer 
int foundIt(int dist) {
    printf("Visited point: dist = %d\n", dist);
    return TRUE;
}

int main(int argc, char *argv[]) {

    // Part 1 vars:
    int ch = 0;  // stores input
    int dir = 0; // 0 = north
    int hor = 0; // horizontal coordinate 
    int ver = 0; // vertical coordinate

    // Part 2 vars:
    int coord[10000][2] = {{0,0}}; // buffer array storing every point visited
    int i = 0;
    int j, k;
    int found = FALSE;

    // Part 1: calculate destination
    while ((ch = getchar()) != EOF) {

        if (ch == 'R' || ch == 'L') {

            // processes input for direction
            if (ch == 'R') {
                dir = (dir + 1) % 4;
            } else if (ch == 'L') {
                dir = (dir - 1) % 4;
            }

            // processes input for moves
            scanf("%d,", &ch);
            if (dir == 1 || dir == -3) {  // east
                hor += ch;
            } else if (dir == 2 || dir == -2) {  // south
                ver += ch;
            } else if (dir == 3 || dir == -1) {  // west
                hor -= ch;
            } else if (dir == 0) {  // north
                ver -= ch;
            }

            // Part 2: find the point that was visited twice
            // outer loop: search in points in previous moves
            for (j = 0; j < i && found == FALSE; j++) {
                // inner loop: traverses points in current move
                for (k = 0; k < ch && found == FALSE; k++) {

                    if (dir == 1 || dir == -3) {  // east
                        if (coord[j][1] == ver) {
                            if (coord[j][0] == hor - k) {
                                found = foundIt(abs(hor-k)+abs(ver));
                            }
                        }
                    } else if (dir == 2 || dir == -2) {  // south
                        if (coord[j][0] == hor) {
                            if (coord[j][1] == ver - k) {
                                found = foundIt(abs(hor)+abs(ver-k));
                            }
                        }
                    } else if (dir == 3 || dir == -1) {  // west
                        if (coord[j][1] == ver) {
                            if (coord[j][0] == hor + k) {
                                found = foundIt(abs(hor+k)+abs(ver));
                            }
                        }
                    } else if (dir == 0) {  // north
                        if (coord[j][0] == hor) {
                            if (coord[j][1] == ver + k) {
                                found = foundIt(abs(hor)+abs(ver+k));
                            }
                        }
 
                    }
                }
            }

            // If current move does not contain visited point, store the current move
            if (found == FALSE) {
                for (j = 0; j < ch; j++) {
                    if (dir == 1 || dir == -3) {  // east
                        coord[i+j][0] = hor - j;
                        coord[i+j][1] = ver;
                    } else if (dir == 2 || dir == -2) {  // south
                        coord[i+j][0] = hor;
                        coord[i+j][1] = ver - j;
                    } else if (dir == 3 || dir == -1) {  // west
                        coord[i+j][0] = hor + j;
                        coord[i+j][1] = ver;
                    } else if (dir == 0) {  // north
                        coord[i+j][0] = hor;
                        coord[i+j][1] = ver + j;
                    }
               }
            }
           i += ch;
        }
    }

    // prints Part 1 answer
    printf("Destination: dist = %d\n", abs(hor)+abs(ver));

    return 0;
}
