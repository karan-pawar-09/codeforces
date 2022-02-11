/*
    author:Karan
    created:26.01.2022 20:04:53
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
    int n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    vector<int> nos;
    int cur=0;
    if(s[0]=='0') cur++;
    for(int i=1;i<n;i++) {
        if(s[i]=='1') {
            nos.push_back(cur);
            cur=0;
        } else {
            cur++;
        }
    }
    vector<int> pre(n),post(n);
    int temp=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='1') {
            pre[i]=temp;
            temp=0;
        } else {
            temp++;
        }
    }
    temp=0;
    for(int i=n-1;i>=0;i--) {
        if(s[i]=='1') {
            post[i]=temp;
            temp=0;
        } else {
            temp++;
        }
    }
    if(cur>0) {
        nos.push_back(cur);
    }
    int p=0;
    int ans=0;
    for(auto y:nos) {
        ans+=y/x;
    }
    for(int i=0;i<n;i++) {
        if(s[i]=='1') {
            if(((pre[i]+post[i]+1)/x) > ((pre[i]/x)+(post[i]/x))) {
                p=1;
            }
        }
    }
    cout<<ans+p<<endl;
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