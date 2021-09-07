#include<bits/stdc++.h>
using namespace std;
long long arr[101];
void rhombus() {
    arr[0]=1;
    for(int i=1;i<101;i++) {
        arr[i]=arr[i-1]+(i+1)+(i)*2+i-1;
    }
}
int main() {
    rhombus();
    int a;
    cin>>a;
    cout<<arr[a-1];
}