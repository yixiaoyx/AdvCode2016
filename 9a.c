// Advent of Code 2016: Day 9 Part 1
// Yi Xiao (yxxiaoyx)
// 09-12-2016

#include <stdio.h>

int main(int argc, char *argv[]) {

    int repeat = 0;     // repeating times
    int len = 0;        // length of string to repeat
    int total_len = 0;  // final decompressed length
    int ch;
    int i;

    // reads input
    while ((ch = getchar()) != EOF) {
        if (ch != '\n' && ch != ' ') {
            total_len++;
        }

        // decompresses
        if (ch == '(') {
            total_len--;
            scanf("%dx%d", &len, &repeat);
            for (i = 0; i <= len; i++) {  // needs to skip ')'
                getchar();
            }
            total_len += len * repeat;
        }
    }

    // prints result
    printf("final length = %d\n", total_len);

    return 0;
}
