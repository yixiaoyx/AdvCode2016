// Advent of Code 2016: Day 6 Part 1
// Yi Xiao (yxxiaoyx)
// 06-12-2016

#include <stdio.h>

#define LENGTH 8            // length of message
#define NUM_LETTER 26

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

// finds the most frequent letter
int findMax(int m[]) {
    int i;
    int index;
    int max = -1;
    for (i = 0; i < NUM_LETTER; i++) {
        if (max < m[i]) {
            max = m[i];
            index = i;
        } 
    }
    return index;
}

int main(int argc, char *argv[]) {

    Alpha msg[LENGTH];  // message buffer
    initMsg(msg);

    int chr = 0;
    int i;

    // reads input
    while ((chr = getchar()) != EOF) {
       i = 0;           // resets counter at start of each line

       // counts frequency
       while (chr != '\n') {
            msg[i].alph[chr-'a'] += 1;
            i++;
            chr = getchar();
       }
    }

    // finds the most frequent letter in each column
    for (i = 0; i < LENGTH; i++) {
        msg[i].ch = findMax(msg[i].alph) + 'a';
    }

    printMsg(msg);

    return 0;
}
