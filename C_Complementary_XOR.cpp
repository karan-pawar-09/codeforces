/*
    author:Karan
    created:08.11.2022 00:23:41
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

bool kk(string &s, string &t, int n, bool ff) {
    int count = 0;
    vector<int> dp(n, 0);
    for(int i=0;i<n;i++) {
        if(s[i]=='1') {
            count++;
            dp[i]--;
        }
    }
    bool ans = true;
    for(int i=0;i<n;i++) {
        if(t[i]=='1') {
            if((count-dp[i])%2 == 0) {
                ans = false;
            }
        } else {
            if((count-dp[i])%2 == 1) {
                ans = false;
            }
        }
    }
    if(ans) {
        cout<<"YES"<<endl;
        if(ff) {
            cout<<count<<endl;
            for(int i=0;i<n;i++) {
                if(s[i]=='1') {
                    cout<<i+1<<" "<<i+1<<endl;
                }
            }
        } else {
            cout<<count+1<<endl;
            cout<<1<<" "<<n<<endl;
            for(int i=0;i<n;i++) {
                if(s[i]=='1') {
                    cout<<i+1<<" "<<i+1<<endl;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t;
    cin>>t;
    string p;
    for(auto x: s) {
        if(x=='1') {
            p.push_back('0');
        } else {
            p.push_back('1');
        }
    }
    int count1=0;
    int count2=0;
    for(auto x: s) {
        if(x=='1') {
            count1++;
        }
    }
    for(auto x: t) {
        if(x=='1') {
            count2++;
        }
    }
    if(count1==0) {
        if(count2==0) {
            cout<<"YES"<<endl;
            cout<<0<<endl;
            return;
        } else if(count2==n) {
            cout<<"YES"<<endl;
            cout<<3<<endl;
            cout<<1<<" "<<n<<endl;
            cout<<1<<" "<<1<<endl;
            cout<<2<<" "<<n<<endl;
            return;
        }
    } else if(count1==n) {
        if(count2 == n) {
            cout<<"YES"<<endl;
            cout<<2<<endl;
            cout<<1<<" "<<1<<endl;
            cout<<2<<" "<<n<<endl;
            return;
        } else if(count2 == 0) {
            cout<<"YES"<<endl;
            cout<<1<<endl;
            cout<<1<<" "<<n<<endl;
            return;
        } 
    }
    
    if(kk(s, t, n, true)) {
        return;
    }
    cout<<p<<endl;
        cout<<t<<endl;
    if(kk(p, t, n, false)) {
        
        return;
    } 
    cout<<"NO"<<endl;
    return;
    
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