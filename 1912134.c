#include<stdio.h>
int arr[10000][1000];
void fibonacci(int n) {
    int k=1;
	while(k<n) {
        int carry=0;
		for(int j=999;j>=0;j--) {
            int a=arr[k][j]+arr[k-1][j]+carry;
			carry=a/10;
			a = a%10;
			arr[k+1][j]=a;
		}
		k++;
	}
	int i=0;
	while(arr[n][i]==0 && i<1000) {
		i++;
    }
	for(;i<1000;i++) {
		printf("%d",arr[n][i]);
	}
	printf("\n");
}
int main() {
    int t;   
    while(t--){
        arr[1][999]=1;
        int n;
        scanf("%d",&n);
        fibonacci(n);
    }
	return 0;
}
