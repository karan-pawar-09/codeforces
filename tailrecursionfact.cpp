/*
author:Karan
created:12.06.2021 17:14:18
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int fact(int n,int p) {
    if(n==1) {
        return p;
    }
    else {
        return fact(n-1,p*n);
    }
}
int fact(int a) {
    return fact(a,1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    cout<<fact(n)<<endl;
}