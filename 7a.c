// Advent of Code 2016: Day 7 Part 1
// Yi Xiao (yxxiaoyx)
// 07-12-2016
// This solution does not use regex.h.

#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

// resets buffer to all 0s
void initBuffer(char buffer[]) {
    int i;
    for (i = 0; i < 33; i++) {
        buffer[i] = 0;
    }
}

// checks for patter ABBA in string
int checkABBA(char str[], int size) {
    int found = FALSE;
    int i;
    for (i = 0; i < size-3 && found == FALSE; i++) {
        if (str[i] == str[i+3] && str[i+1] == str[i+2] && str[i] != str[i+1]) {
            found = TRUE;
        }
    }

    return found;
}

int main (int argc, char *agrv[]) {

    int ch;
    char buffer[33];
    int inABBA, exABBA; 
    int tls = 0;    // total number of TLS-supporting IPs
    int i;

    // reads input
    while ((ch = getchar()) != EOF) {
        
        // resets all counters/buffers
        i = 0;
        initBuffer(buffer);
        inABBA = FALSE;
        exABBA = FALSE;

        // processes one line
        while (ch != '\n') {
            if (inABBA == FALSE) {

                // if reads letter, store in buffer
                if (isalpha(ch)) {
                    buffer[i] = ch;
                    i++;

                // if reads '[' process previous section outside [] and reset buffer
                } else if (ch == '[') {
                    if (exABBA == FALSE) {
                        exABBA = checkABBA(buffer, i);
                    }
                    initBuffer(buffer);
                    i = 0;

                // if reads ']' process previous section inside [] and reset buffer 
                } else if (ch == ']') {
                    if (inABBA == FALSE) {
                    inABBA = checkABBA(buffer,i);
                    }
                    initBuffer(buffer);
                    i = 0;           
                }
            }
                ch = getchar();
            }
       
        // processes last section outside [] 
        if (inABBA == FALSE && exABBA == FALSE) {
            exABBA = checkABBA(buffer, i);
        }

        // counts IPs that support TLS
        if (inABBA == FALSE && exABBA == TRUE) {
            tls++;
        }
    }

    // prints result
    printf("%d\n", tls);

    return 0;
}
