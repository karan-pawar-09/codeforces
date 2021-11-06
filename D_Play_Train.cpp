/*
    author:Karan
    created:31.10.2021 13:41:38
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
    int n,q;
    cin>>n>>q;
    int nil=-1;
    vector<int> front(n+1,nil),back(n+1,nil);
    while(q--) {
        int a;
        cin>>a;
        if(a==1) {
            int b,c;
            cin>>b>>c;
            front[c]=b;
            back[b]=c;
        }
        else if(a==2) {
            int b,c;
            cin>>b>>c;
            front[c]=nil;
            back[b]=nil;
        }
        else {
            int b;
            cin>>b;
            while(front[b]!=nil) {
                b=front[b];
            }
            vector<ll> ans;
            while(b!=nil) {
                ans.push_back(b);
                b=back[b];
            }
            cout<<ans.size()<<" ";
            for(auto x:ans) cout<<x<<" ";
            cout<<endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}