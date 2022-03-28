#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define min(X, Y) (((X) < (Y)) ? (X) : (Y))

void final_string(int ones, int zeros, int x, int y) {
    while (ones > 0 || zeros > 0) {
        for (int i = 0;i < min(x, zeros);i++) {
            printf("0");
        }
        zeros -= x;
        for (int i = 0;i < min(y, ones);i++) {
            printf("1");
        }
        ones -= y;
    }
}
int main() {
    char str[1000];
    int x, y;
    scanf("%s", str);
    scanf("%d %d", &x, &y);
    int ones = 0;
    int zeros = 0;
    for (int i = 0;str[i] != '\0';i++) {
        if (str[i] == '1') ones++;
        else zeros++;
    }
    final_string(ones, zeros, x, y);
}