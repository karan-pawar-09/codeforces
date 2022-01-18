/*
    author:Karan
    created:07.01.2022 13:08:11
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
    unordered_map<string,int> M;
    string s;
    cin>>s;
    for(int i=0;i<n;i++) {
        if(s[i]>='a' and s[i]<='z') {
            string temp;
            temp+=s[i];
            M[temp]++;
            for(int j=i+1;j<n;j++) {
                if(s[j]>='a' and s[j]<='z') {
                    temp+=s[j];
                    M[temp]++;
                }
                else {
                    break;
                }
            }
        }
    }
    string ans;
    int maxi=0;
    for(auto x:M) {
        if(x.first.size()*x.second>maxi) {
            maxi=x.first.size()*x.second;
            ans=x.first;
        }
    }
    cout<<ans<<endl;
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