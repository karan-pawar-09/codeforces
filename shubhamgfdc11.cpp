/*
    author:Karan
    created:06.01.2022 12:30:28
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

bool isGood(int n) {
    string s=to_string(n);
    int k=0;
    for(int i=0;i<s.size();i++) {
        k+=s[i]-'0';
    }
    return (k%2==0);
}
int32_t main() {
    int n;
    cin>>n;
    int res=0;
    for(int i=0;i<=n;i++) {
        if(isGood(i)) {
            res++;
        }
    }
    cout<<res;
}