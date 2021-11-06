/*
    author:Karan
    created:03.11.2021 12:36:47
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
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int l=0;
    int r=0;
    int u=0;
    int d=0;
    int ver=0;
    int hor=0;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='L') {
            hor--;
        }
        else if(s[i]=='R') {
            hor++;
        }
        else if(s[i]=='U') {
            ver--;
        }
        else {
            ver++;
        }
        l=min(l,hor);
        r=max(r,hor);
        u=min(u,ver);
        d=max(d,ver);
        if(abs(l)+r+1>m or abs(u)+d+1>n) {
            if(s[i]=='L') {
                l++;
            }
            else if(s[i]=='R') {
                r--;
            }
            else if(s[i]=='U') {
                u++;
            }
            else {
                d--;
            }
            break;
        }
    }
    cout<<abs(u)+1<<" "<<abs(l)+1<<endl;
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

