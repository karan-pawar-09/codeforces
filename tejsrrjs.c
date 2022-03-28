#include<stdio.h>
#include<math.h>

const int inf = 1e9 + 10;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n], b[m];
    for (int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0;i < m;i++) {
        scanf("%d", &b[i]);
    }
    int c[n];
    int res[n];
    int used[100000];
    int freq[100000];
    int pro[100000];
    for (int i = 0;i < 100000;i++) {
        used[i] = 0;
        freq[i] = 0;
        pro[i] = inf;
    }
    for (int i = 0;i < n;i++) {
        freq[a[i]]++;
    }
    int index = 0;
    for (int i = 0;i < m;i++) {
        while (freq[b[i]]--) {
            used[b[i]] = 1;
            c[index++] = b[i];
        }
    }
    int indx = 0;


    for (int i = 0;i < n;i++) {
        if (!used[a[i]]) {
            pro[indx++] = a[i];
        }
    }
    mergeSort(pro, 0, n - 1);
    indx = 0;
    while (index < n) {
        c[index] = pro[indx++];
        index++;
    }
    for (int i = 0;i < n;i++) {
        printf("%d ", c[i]);
    }


}