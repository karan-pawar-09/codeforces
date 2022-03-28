#include<stdio.h>
#include<math.h>

int isPerfectSquare(int number) {
    int iVar;
    float fVar;
    fVar = sqrt((double)number);
    iVar = fVar;
    if (iVar == fVar)
        return 1;
    else
        return 0;
}

int main() {
    int n;
    int is_prime[110];
    for (int i = 0;i < 110;i++) {
        is_prime[i] = 1;
    }
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= 100; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 100; j += i)
                is_prime[j] = 0;
        }
    }
    scanf("%d", &n);
    int arr[100];
    for (int i = 0;i < 100;i++) {
        arr[i] = -1;
    }
    int p = n;
    int i = 0;
    while (p) {
        arr[i] = p % 10;
        p /= 10;
        i++;
    }
    i--;
    int x = i;
    int sumprime = 0;
    int sumother = 0;
    for (int j = x;j >= 0;j--) {
        if (is_prime[(x - j + 1)]) {
            sumprime += arr[j];
        }
        else {
            sumother += arr[j];
        }
    }
    if ((isPerfectSquare((5 * sumprime * sumprime) + 4) || isPerfectSquare((5 * sumprime * sumprime) - 4)) &&
        (isPerfectSquare((5 * sumother * sumother) + 4) || isPerfectSquare((5 * sumother * sumother) - 4))) {
        printf("Yes");
    }
    else {
        printf("No");
    }

}