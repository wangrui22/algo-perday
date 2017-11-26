/*You are given a string of n lines, each substring being n characters long. For example:

s = "abcd\nefgh\nijkl\nmnop"

We will study the "horizontal" and the "vertical" scaling of this square of strings.

A k-horizontal scaling of a string consists of replicating k times each character of the string (except '\n').

Example: 2-horizontal scaling of s: => "aabbccdd\neeffgghh\niijjkkll\nmmnnoopp"
A v-vertical scaling of a string consists of replicating v times each part of the squared string.

Example: 2-vertical scaling of s: => "abcd\nabcd\nefgh\nefgh\nijkl\nijkl\nmnop\nmnop"
Function scale(strng, k, v) will perform a k-horizontal scaling and a v-vertical scaling.

Example: a = "abcd\nefgh\nijkl\nmnop"
scale(a, 2, 3) --> "aabbccdd\naabbccdd\naabbccdd\neeffgghh\neeffgghh\neeffgghh\niijjkkll\niijjkkll\niijjkkll\nmmnnoopp\nmmnnoopp\nmmnnoopp"
Printed:

abcd   ----->   aabbccdd
efgh            aabbccdd
ijkl            aabbccdd
mnop            eeffgghh
                eeffgghh
                eeffgghh
                iijjkkll
                iijjkkll
                iijjkkll
                mmnnoopp
                mmnnoopp
                mmnnoopp
#Task:

Write function scale(strng, k, v) k and v will be positive integers. If strng == "" return "".*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

char* scale(char* strg, const int k, const int v) {
    //1 cal length
    char* tmp = strg;
    int size = 0;
    int pre_l = 0;
    while(*tmp != '\0') {
        if (*(tmp) != '\n') {
            ++pre_l;
        } else {
            size += (pre_l*k+1)*v;
            pre_l = 0;
        }
        ++tmp;

        if (*tmp == '\0' && pre_l != 0) {
            size += (pre_l*k+1)*v;
        }
    }

    if (size == 0) {
        return "";
    }

    //2 scale
    char* scale = (char*)malloc(size);
    char* cp = scale;
    pre_l = 0;
    while (*strg!='\0') {
        if (*strg!='\n') {
            ++pre_l;
            for (int j=0; j<k; ++j) {
                *(cp++) = *strg;
            }
            
        } else {
            *(cp) = '\n';
            char* cp_s = (cp-pre_l*k); 
            ++cp;
            for(int j=1; j<v; ++j) {
                memcpy(cp,cp_s, pre_l*k+1);
                cp += (pre_l*k+1);
            }
            pre_l=0;
        }
        ++strg;

        if (*strg == '\0' && pre_l != 0) {
            *(cp) = '\n';
            char* cp_s = (cp-pre_l*k); 
            ++cp;
            for(int j=1; j<v; ++j) {
                if (j == v-1) {
                    memcpy(cp,cp_s, pre_l*k);
                } else {
                    memcpy(cp,cp_s, pre_l*k+1);
                    cp += (pre_l*k+1);
                }
            }
        }
    }
    cp[size-1] = '\0';
    return scale;
}

int main(int argc, char* argv[]) {
    char d[] = "WgaB\nMmIn\nqJwv\nAhho";
    char s[] = "lxnT\nlxnT\nqiut\nqiut\nZZll\nZZll\nFElq\nFElq";
    char s2[] = "";
    
    printf("%d\n",(int)sizeof(s2));
    //scale(d,2,3);
    
    char* res = scale(d,2,1);
    printf("%s\n",res);
    // int i =0;
    // while (res[i]==s[i] && res[i] != '\0' && s[i] != '\0') {
    //     ++i;
    // }
    // int i = strlen(res);
    // int j = strlen(s);
    // if (0 != strcmp(s,res)) {
    //     printf("error");
    // }
    return 0;
}