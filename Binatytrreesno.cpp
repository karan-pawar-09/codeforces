#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> no() {
    static vector<ll>arr(1000,0);
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<1000;i++) {
        for(int j=1;j<=i;j++) {
            arr[i]+=arr[j-1]*arr[i-j];
        }
    }
    return arr;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> arr=no();
    for(int i=0;i<=6;i++) {
        cout<<arr[i]<<" ";
    }
}

