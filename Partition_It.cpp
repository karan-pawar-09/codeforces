/*
    author:Karan
    created:17.11.2021 21:18:55
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

const int mx=1e5+10;
bool is_prime[mx+1];

void solve() {
    int n,k;
    cin>>n>>k;
    set<int> s;
    for(int i=2;i<=n;i++) {
        s.insert(i);
    }
    int p=1;
    vector<int> ans;
    ans.push_back(1);
    for(int i=(n/2)+1;i<=n;i++) {       
        if(is_prime[i]) {
            ans.push_back(i);
            s.erase(i);
        }        
    }    
    if(ans.size()>=k) {
        cout<<"Yes"<<endl;
        for(int i=0;i<k;i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    } 
    else if(ans.size()>=(n-k)) {
        cout<<"Yes"<<endl;
        int p=0;
        for(auto x:s) {
            cout<<x<<" ";
            p++;
        }
        for(int i=0;i<(k-p);i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    mset(is_prime,true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= mx; i++) {
        if (is_prime[i] && (long long)i * i <= mx) {
            for (int j = i * i; j <= mx; j += i)
                is_prime[j] = false;
        }
    }
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}