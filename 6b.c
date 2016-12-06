// Advent of Code 2016: Day 6 Part 2
// Yi Xiao (yxxiaoyx)
// 06-12-2016

#include <stdio.h>
#include <limits.h>

#define LENGTH 8            // length of message
#define NUM_LETTER NUM_LETTER

typedef struct _alphabet {
    int alph[NUM_LETTER];   // letter frequency count
    int ch;                 // decoded char
} Alpha;

// initializes all freq counts to 0
void initMsg(Alpha msg[]) {
    int i, j;
    for (i = 0; i < LENGTH; i++) {
        for (j = 0; j < NUM_LETTER; j++) {
            msg[i].alph[j] = 0;
        }
        msg[i].ch = 0;
    }

}

// prints decoded message
void printMsg(Alpha msg[]) {
    int i;
    for (i = 0; i < LENGTH; i++) {
        putchar(msg[i].ch);
    }
    printf("\n");
}

// finds the least frequent letter
int findMin(int m[]) {
    int i;
    int index;
    int min = INT_MAX;
    for (i = 0; i < NUM_LETTER; i++) {
        if (min > m[i]) {
            min = m[i];
            index = i;
        } 
    }
    return index;
}

int main(int argc, char *argv[]) {

    Alpha msg[LENGTH];      // message buffer
    initMsg(msg);

    int chr = 0;
    int i;

    // reads input
    while ((chr = getchar()) != EOF) {
       i = 0;

       // counts frequency
       while (chr != '\n') {
            msg[i].alph[chr-'a'] += 1;
            i++;
            chr = getchar();
        }
    }

    // finds the least frequent letter in each column
    for (i = 0; i < LENGTH; i++) {
        msg[i].ch = findMin(msg[i].alph) + 'a';
    }

    printMsg(msg);

    return 0;
}
