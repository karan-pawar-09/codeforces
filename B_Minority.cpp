/*
    author:Karan
    created:31.01.2022 20:15:13
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

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    if(n==1 or n==2) {
        cout<<"0"<<endl;
    } else {
        int maxi=0;
        int a=0;
        int b=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') {
                a++;
            } else {
                b++;
            }
            if(a!=b) {
                maxi=max(maxi,min(a,b));
            }
        }
        cout<<maxi<<endl;
    }
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