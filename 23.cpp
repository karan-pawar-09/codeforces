#include<bits/stdc++.h>
using namespace std;

int pos(int arr[],int n){
    int p=0;
    int neg=0;
    int res;
    for(int i=0;i<n;i++){
        if(arr[i]>0)
            p++;
        if(arr[i]<0)
            neg++;
    }
    res = pow(2,p);
    if(n>0)
        res=res*pow(2,neg-1);
    res--;
    return res;
}

int main() {
    int a;
    cin>> a;
    int arr[a];
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }
    cout<<pos(arr,a);
}
