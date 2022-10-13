#include <stdio.h>

int f(int n) {
    static int i = 1;
    if(n>=5) 
    return n;
    n = n+i;
    i++;
    return f(n);
}
int main()
{
    int x=10, y=15;
    x^=y^=x^=y;
    printf("%d %d", x, y);
}