#include<stdio.h>
#include<math.h>
#include<string.h>
int isvowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    else return 0;
}
int isgood(char s[], int n) {
    char prevchar = 'a';
    for (int i = 0;i < n;i++) {
        if (isvowel(s[i])) {
            if (s[i] >= prevchar) {
                prevchar = s[i];
            }
            else {
                return 0;
            }
        }
    }
    return 1;
}
int isworst(char s[], int n) {
    char prevchar = 'u';
    for (int i = 0;i < n;i++) {
        if (isvowel(s[i])) {
            if (s[i] <= prevchar) {
                prevchar = s[i];
            }
            else {
                return 0;
            }
        }
    }
    return 1;
}
int main() {
    char s[1000];
    scanf("%s", s);
    int n = strlen(s);
    if (isgood(s, n)) {
        printf("Good");
    }
    else if (isworst(s, n)) {
        printf("Worst");
    }
    else {
        printf("Bad");
    }
}