// Advent of Code 2016: Day 5 Part 1
// Yi Xiao (yxxiaoyx)
// 05-12-2016

#include <stdio.h>
#include <openssl/md5.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// checks if MD5 digest in hex starts with five 0s
int isFiveZero (char *str) {
    int is = FALSE;

    if (str[0] == '0') {
        is = TRUE;
    }

    int i;
    for (i = 1; i < 5 && is == TRUE; i++) {
        if (str[i] != '0') {
            is = FALSE;
        }
    }

    return is;
}

int main(int argc, char *argv[]) {

    char *str = "abbhdwsy"; // input
    char buffer[32];
    unsigned char digest[MD5_DIGEST_LENGTH];
    char md5str[33];        // MD5 digest in hex

    int i = 0;
    int j;
    int index = 0;          // to be appended to input 

    while (i < 8) {
        // constructs string with input and increasing index
        sprintf(buffer, "%s%d", str, index);

        // hashes with MD5
        MD5((unsigned char *)buffer, strlen(buffer), digest);
   
        // converts digest to hex
        for (j = 0; j < 16; j++) {
            sprintf(&md5str[j*2], "%02x", (unsigned int)digest[j]);
        }

        // finds and prints password
        if (isFiveZero(md5str)) {
            printf("%s %s %c\n", buffer, md5str, md5str[5]); 
            i++;
        }

        index++;
    }

    return 0;
}
