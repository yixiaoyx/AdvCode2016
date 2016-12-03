// Advent of Code 2016: Day 3 Part 1
// Yi Xiao (yxxiaoyx)
// 03-12-2016
 
#include <stdio.h>

int main(int argc, char *argv[]) {
    int a, b, c;
    int tri = 0;

    // checks whether the sides can construct a triangle
    while (scanf("%d %d %d", &a, &b, &c) != EOF) {
        if (a+b>c && a+c>b && b+c>a) {
            tri += 1;
        }
    }
    
    printf("%d\n", tri);

    return 0;
}
