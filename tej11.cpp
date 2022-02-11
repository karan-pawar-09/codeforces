/*
    author:Karan
    created:03.02.2022 11:08:51
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

int freq[(int)1e5+10];
int arr[(int)1e5+10];
int n;
int func() {
    for(int i=0;i<1e5+10;i++) freq[i]=0;
    int mx=arr[0];
    for(int i=0;i<n;i++) {
        freq[arr[i]]++;
        mx=max(mx,arr[i]);
    }
    return freq[mx];
}

int32_t main() {
    int k;
    n=0;
    while(1) {
        cin>>k;
        if(k==-1) {
            break;
        } else {            
            arr[n]=k;
            n++;
        }
    }
    cout<<func()<<endl;
}