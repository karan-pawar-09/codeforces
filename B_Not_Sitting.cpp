/*
    author:Karan
    created:15.01.2022 20:21:23
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

void kk(int p) {
    if(p%2) {
        int x=p/2;
        cout<<x<<" "; 
        for(int i=0;i<(p/2);i++) {
            x++;
            cout<<x<<" ";
            cout<<x<<" ";
        }
    } else {
        int x=(p)/2;
        cout<<x<<" ";
        cout<<x<<" ";
        for(int i=0;i<(p-1)/2;i++) {
            x++;
            cout<<x<<" ";
            cout<<x<<" ";
        }
    }
}
void solve() {
    int n,m;
    cin>>n>>m;
    int x=(n/2)+(m/2);
    if(n==1) {
        kk(m);
    } 
    else if(m==1) {
        kk(n);
    }
    else {
    if(n%2 and m%2) {
        cout<<x<<" ";
        int r=1;
        int c=1;
        int kp=1;
        int loops=max((n-1)/2,(m-1)/2);
        int lps=min((n-1)/2,(m-1)/2);
        for(int i=1;i<=loops;i++) {
            int a=min(r*2,2*(n-2));
            int b=min(c*2,2*(m-2));
            if(r>=(n) ) {
                b=0;               
            } 
            if(c>=(m)) a=0;
            x++;
            for(int j=0;j<a+b;j++) {
                cout<<x<<" ";
            }
            x++;
            for(int i=0;i<4;i++) {
                cout<<x<<" ";
            }
            r+=2;
            c+=2;
        }   
    } else if(n%2 and m%2==0) {
        cout<<x<<" ";
        cout<<x<<" ";
        int r=1;
        int c=2;
        int kp=1;
        int loops=max((n-1)/2,(m-1)/2);
        int lps=min((n-1)/2,(m-1)/2);
        for(int i=1;i<=loops;i++) {
            int a=min(r*2,2*(n-2));
            int b=min(c*2,2*(m-2));
            if(r>=(n) ) {
                b=0;               
            } 
            if(c>=m) a=0;
            x++;
            for(int j=0;j<a+b;j++) {
                cout<<x<<" ";
            }
            x++;
            for(int i=0;i<4;i++) {
                cout<<x<<" ";
            }
            r+=2;
            c+=2;
        } 
    }
    else if(n%2==0 and m%2) {
        cout<<x<<" ";
        cout<<x<<" ";
        int r=2;
        int c=1;
        int kp=1;
        int loops=max((n-1)/2,(m-1)/2);
        int lps=min((n-1)/2,(m-1)/2);
        for(int i=1;i<=loops;i++) {
            int a=min(r*2,2*(n-2));
            int b=min(c*2,2*(m-2));
            if(r>=(n) ) {
                b=0;               
            } 
            if(c>=m) a=0;
            x++;
            for(int j=0;j<a+b;j++) {
                cout<<x<<" ";
            }
            x++;
            for(int i=0;i<4;i++) {
                cout<<x<<" ";
            }
            r+=2;
            c+=2;
        } 
    } else {
        x--;
        cout<<x<<" ";
        cout<<x<<" ";
        cout<<x<<" ";
        cout<<x<<" ";
        int r=2;
        int c=2;
        int kp=1;
        int loops=max((n-1)/2,(m-1)/2);
        int lps=min((n-1)/2,(m-1)/2);
        for(int i=1;i<=loops;i++) {
            int a=min(r*2,2*(n-2));
            int b=min(c*2,2*(m-2));
            if(r>=(n) ) {
                b=0;               
            } 
            if(c>=m) a=0;
            x++;
            for(int j=0;j<a+b;j++) {
                cout<<x<<" ";
            }
            x++;
            for(int i=0;i<4;i++) {
                cout<<x<<" ";
            }
            r+=2;
            c+=2;
        } 
    }
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}