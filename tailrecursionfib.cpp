/*
author:Karan
created:12.06.2021 17:16:30
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int fib(int n,int p,int a,int b,int c) {
    if(p==n) {
        return c;
    }
    return fib(n,++p,b,c,b+c);
}
int fib(int a) {
    return fib(a,0,0,1,0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int a; 
    cin>>a;
    cout<<fib(a)<<endl;  
}