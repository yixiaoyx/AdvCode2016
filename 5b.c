// Advent of Code 2016: Day 5 Part 2
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

    char *str = "abbhdwsy";       // input
    char buffer[32];
    unsigned char digest[MD5_DIGEST_LENGTH];
    char md5str[33];              // MD5 digest in hex

    int i = 0;
    int j;
    int index = 0;                // index to be appended to input
    int pos = 0;                  // position/index in password
    int psw[8] = {0};             // password

    while (i < 8) {
        // constructs string with input and increasing index
        sprintf(buffer, "%s%d", str, index);
        
        // hashes with MD5
        MD5((unsigned char *)buffer, strlen(buffer), digest);
    
        // converts digest to hex
        for (j = 0; j < 16; ++j) {
            sprintf(&md5str[j*2], "%02x", (unsigned int)digest[j]);
        }

        // finds password
        if (isFiveZero(md5str)) {

            // 5th number is position index
            pos = md5str[5] - '0';

            // 6th number is password
            // checks if position is valid, stores password in array
            if (pos >= 0 && pos < 8 && psw[pos] == 0) {
                printf("%s %s %c\n", buffer, md5str, md5str[6]);
                psw[pos] = md5str[6];
                i++;
            }
        }

        index++;
    }

    // prints password
    for (i = 0; i < 8; i++) {
        printf("%c", (char)psw[i]);
    }
    printf("\n");

    return 0;
}
