/*
    author:Karan
    created:29.12.2021 21:38:12
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans;
    set<string> st;
    ans+=s[0];
    for(int i=1;i<n;i++) {
        if(s[i]<s[i-1]) {
            ans+=s[i];
        } else if(s[i]==s[i-1]) {
            if(i==1) {
                break;
            } else {
                ans+=s[i];
            }
        }
        else {
            break;
        }
    }
    cout<<ans;
    reverse(all(ans));
    cout<<ans;
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