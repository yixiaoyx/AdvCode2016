// Advent of Code 2016: Day 3 Part 2
// Yi Xiao (yxxiaoyx)
// 03-12-2016
 
#include <stdio.h>

int main(int argc, char *argv[]) {

    // each array stores one line of input
    int a[3] = {0};
    int b[3] = {0};
    int c[3] = {0};
    int tri = 0;
    int i;

    // reads input
    while (scanf("%d %d %d", &a[0], &a[1], &a[2]) != EOF) {
        scanf("%d %d %d", &b[0], &b[1], &b[2]);
        scanf("%d %d %d", &c[0], &c[1], &c[2]);

        // checks whether the sides can contruct a triangle
        for (i = 0; i < 3; i++) {
            if (a[i]+b[i]>c[i] && a[i]+c[i]>b[i] && b[i]+c[i]>a[i]) {
                tri += 1;
            }
        }
    }
    
    // prints the total number of possible triangles
    printf("%d\n", tri);

    return 0;
}
