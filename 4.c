// Advent of Code 2016: Day 4 Part 1&2
// Yi Xiao (yxxiaoyx)
// 04-12-2016

#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

// resets array to all 0s
void clearArray(int array[], int size) {
    int i;       
    for (i = 0; i < size; i++) {
        array[i] = 0;
    }
}

int main(int argc, char *argv[]) {

    // Part 1 vars
    int alphabet[26];       // letter frequency buffer
    int id[3] = {0};        // room ID buffer
    int common[5] = {0};    // buffer for the 5 most common letters
    int sum = 0;
    int index = -1;
    int max = 0;
    int match = FALSE;
    int ch;
    int i,j;

    // Part 2 vars
    int str[128];   // room name buffer
    int len = 0;    // room name length 
    int idnum = 0;  // room ID

    while ((ch = getchar()) != EOF) {

        // resets all buffers/counters to 0 
        // at start of reading each line
        i = 0;
        j = 0;
        clearArray(alphabet, 26);
        clearArray(str, 128);

        // reads in room name and ID
        while (ch != '[') {
            if (isalpha(ch)) {
                alphabet[ch-'a'] += 1;
                str[j] = ch;
                j++;
            } else if (isdigit(ch)) {
                id[i] = ch-'0';
                i++;
            } else if (ch == '-') {
                j++;
            }
            ch = getchar();
        }
        len = j;

        // finds the 5 most common letters
        for (j = 0; j < 5; j++) {

            for (i = 0; i < 26; i++) {
                if (alphabet[i] > max) {
                    max = alphabet[i];
                    index = i;
                }
            }
            
            common[j] = index;
            alphabet[index] = 0;
            max = 0;
        }
    
        // reads in checksum and compares with the 5 most common letters
        ch = getchar();
        if (ch - 'a' == common[0]) {
            match = TRUE;
        }
        j = 1;

        while ((ch = getchar()) != ']' && match == TRUE) {
            if (ch - 'a' != common[j]) {
                match = FALSE;
            }
            j++;
        }

        // deciphers names of real rooms and calculates sum of ID
        if (match == TRUE) {

            // Part 1: sums up the ID
            idnum = id[0]*100 + id[1]*10 + id[2];
            sum += idnum;

            // Part 2: deciphers the names
            for (j = 0; j < len; j++) {
                if (str[j] != 0) {
                    str[j] = (str[j] - 'a' + idnum) % 26 + 'a';
                } else {
                    str[j] = ' ';
                }

                // prints deciphered room name to stdout
                putchar(str[j]);
            }
            // prints room IDs
            printf(" %d\n", idnum);
        }

        // reads until end of line
        while (ch != '\n') {
            ch = getchar();
        }    
    }

    printf("Sum of real rooms = %d\n", sum);

    return 0;
}
