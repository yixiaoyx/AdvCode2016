// Advent of Code 2016: Day 7 Part 2
// Yi Xiao (yxxiaoyx)
// 07-12-2016
// This solution does not use regex.h.

#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

// resets string buffer to all 0s
void initBuffer(char buffer[]) {
    int i;
    for (i = 0; i < 33; i++) {
        buffer[i] = 0;
    }
}

// resets ABA buffer to all 0s  
void initABA(char aba[][2]) {
    int i, j;
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 2; j++) {
            aba[i][j] = 0;      
        }
    }
}

// gets all ABA segments in a string   
int checkABA(char str[], int size, int times, char aba[][2]) {
    int i;
    int j = times;
    for (i = 0; i < size-2; i++) {
        if (str[i] == str[i+2] && str[i] != str[i+1]) {
            aba[j][0] = str[i];
            aba[j][1] = str[i+1]; 
            j++;
        }
    }

    // returns total number of ABA segments so far
    return j;
}

// compares ABA segments inside [] and outside []
int compare(char in[][2], int inBAB, char ex[][2], int exABA) {
    int i,j;
    int found = FALSE;

    for (i = 0; i < inBAB && found == FALSE; i++) {
        for (j = 0; j < exABA && found == FALSE; j++) {
            if (in[i][0] == ex[j][1] && in[i][1] == ex[j][0]) {
                found = TRUE;
            }
        }
    }

    return found;
}

int main (int argc, char *agrv[]) {
    int ch;
    char buffer[33];
    int inBAB, exABA;   // counts segments matching pattern 
    int ssl = 0;
    int i;
    char in[64][2];     // buffer for ABA segments inside []
    char ex[64][2];     // buffer for ABA segments outside []

    // reads input
    while ((ch = getchar()) != EOF) {

        // resets all counters/buffers
        i = 0;
        initBuffer(buffer);
        initABA(in);
        initABA(ex);
        inBAB = 0;
        exABA = 0;

        // processes one line at a time
        while (ch != '\n') {

            // if reads letter, store in buffer
            if (isalpha(ch)) {
                buffer[i] = ch;
                i++;

            // if reads '[' process previous segment outside [] and reset buffer
            } else if (ch == '[') {
                exABA = checkABA(buffer, i, exABA, ex);
                initBuffer(buffer);
                i = 0;

            // if reads '[' process previous segment outside [] and reset buffer
            } else if (ch == ']') {
                inBAB = checkABA(buffer, i, inBAB, in);                   
                initBuffer(buffer);
                i = 0;           
            }

            ch = getchar();
        }
    
        // processes last section in line 
        exABA = checkABA(buffer, i, exABA, ex);

        // finds out if this line of IP supports SSL
        if (compare(in, inBAB, ex, exABA) == TRUE) {
            ssl++;
        }
    }

    // prints result
    printf("%d\n", ssl);

    return 0;
}
