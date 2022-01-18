/*
    author:Karan
    created:16.01.2022 20:13:11
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
    bool done=false;
    for(int i=n-2;i>=0;i--) {
        int a=s[i]-'0';
        int b=s[i+1]-'0';
        int p=a+b;
        int x=10;
        if(p >= x) {
            string temp=to_string(p);
            s[i]=temp[0];
            s[i+1]=temp[1];
            done=true;
            break;
        }
    }
    int index=0;
    if(!done) {
        int a=s[0]-'0';
        int b=s[1]-'0';
        s[1]=to_string(a+b)[0];
        for(int i=1;i<n;i++) cout<<s[i];
        cout<<endl;
    } else {
        cout<<s<<endl;
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
