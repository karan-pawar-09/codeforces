#include<stdio.h>

int main() {
    uint32_t a[10] = {1,2,3,4,5,6,7,8,9,0};
    uint32_t *b = (
        a+ sizeof(a[0]) *(*(a+1))
    );
    printf("%d", *b);
}