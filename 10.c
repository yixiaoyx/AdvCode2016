// Advent of Code 2016: Day 10 Part 1 & 2
// Yi Xiao (yxxiaoyx)
// 10-12-2016

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define HIGH 61         // Part 1 value to find
#define LOW 17          // Part 1 value to find
#define NUM_BOTS 210    // total number of bots

int isEmpty(int bots[NUM_BOTS][2]);
int gives(int num, int bot, char *words, int bots[NUM_BOTS][2]);

int main(int argc, char *argv[]) {

    char word[7];                   // single word buffer
    int bot = 0;                    // bot number buffer
    int temp = 0;                   // temp value buffer

    int index = 0;                  // index of the current bot who gives
    int validInd[NUM_BOTS] = {0};   // indices of all bots that can give

    int high = 0;                   // high number of a bot
    int low = 0;                    // low number of a bot

    int bots[NUM_BOTS][2] = {{0, 0}};   // all bots
    char str[64];                       // line buffer for file search
    FILE *instructs;                    // instruction file

    // gets initial values for bots
    instructs = fopen("10.in", "r");

    while (fscanf(instructs, "%s", words) != EOF) {

        if (strcmp(words, "value")==0) {
            fscanf(instructs, "%d %*s %*s %*s %d", &temp, &bot);
            if (bots[bot][0] == 0)
                bots[bot][0] = temp;
            else
                bots[bot][1] = temp;
        }
    }

    fclose(instructs);

    // finds the starting bot (ie. has two chips)
    int i;
    for (i = 0; i < NUM_BOTS; i++) {
        if (bots[i][0] != 0 && bots[i][1] != 0)
            index = i; 
    }
    i = 0;

    // bots giving chips
    while (!isEmpty(bots)) {
        instructs = fopen("10.in", "r");

        // search in file for current bot
        while (fgets(str, 63, instructs) != NULL) {
            sscanf(str, "%*s %d %s", &bot, words); 
            
            if (bot == index && strcmp(words, "gives") == 0) {
                
                // compares on-hand values of current bot
                if (bots[index][0] < bots[index][1]) {
                    high = bots[index][1];
                    low = bots[index][0];
                } else {
                    high = bots[index][0];
                    low = bots[index][1];
                }

                // Part 1 result
                if (high == HIGH && low == LOW)
                    printf("bot %d compares %d and %d\n", index, HIGH, LOW);
                
                // empties on-hand values of current bot
                bots[index][0] = 0;
                bots[index][1] = 0;

                // gives low number
                sscanf(str, "%*s %*d %*s %*s %*s %s %d", words, &bot);
                temp = gives(low, bot, words, bots); 
                if (temp != -1) {
                    validInd[i] = temp;
                    i++;
                }
                
                // gives high number
                sscanf(str, "%*s %*d %*s %*s %*s %*s %*d %*s %*s %*s %s %d", 
                        words, &bot);
                temp = gives(high, bot, words, bots); 
                if (temp != -1) {
                    validInd[i] = temp;
                    i++;
                }        

                // pushes and pops indices of bots with two chips
                int j;
                int found = FALSE;
                for (j = i-1; j >= 0 && found == FALSE; j--) {
                    if (validInd[j] != index) {
                        index = validInd[j];
                        found = TRUE;
                        validInd[j] = 0;
                        i--;
                    }
                }
            }
        }
        fclose(instructs);
    }


    return 0;
}

// checks if all bots have empty hands
int isEmpty(int bots[NUM_BOTS][2]) {
    int i;
    int isIt = TRUE;
    
    for (i = 0; i < NUM_BOTS && isIt == TRUE; i++) {
        if (bots[i][0] != 0 || bots[i][1] != 0)
            isIt = FALSE;
    }

    return isIt;
}

// gives a chip to another bot
// returns index of the receiving bot if it now has two chips on hand
// returns -1 if otherwise 
int gives(int num, int bot, char *words, int bots[NUM_BOTS][2]) {
    int index = -1;

    if (strcmp(words, "bot") == 0) {
        if (bots[bot][0] == 0) {
            bots[bot][0] = num;
        } else {
            bots[bot][1] = num;
            index = bot;
        }  

    // Part 2 result
    } else if (strcmp(words, "output") == 0) {
        if (bot == 0 || bot == 1 || bot == 2)
            printf("output %d: %d\n", bot, num);
    }

    return index;
}
