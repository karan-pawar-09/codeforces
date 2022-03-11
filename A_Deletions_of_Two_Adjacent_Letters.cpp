/*
    author:Karan
    created:08.03.2022 20:06:18
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
    char c;
    cin>>c;
    bool ans=false;
    for(int i=0;i<s.size();i++) {
        if(s[i]== c) {
            if((i)%2==0 and (s.size()-i-1)%2==0) {
                ans=true;
            }
        }
    }
    ans?cout<<"YES"<<endl:cout<<"NO"<<endl;
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