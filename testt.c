#include<stdio.h>

int main() {
    auto int a = 0x0A;
    static int p;
    p += ~(!a++ <<2) || ++p && a >> 2;
    p = (a = p) & p;
    printf("%d", p^2);
}