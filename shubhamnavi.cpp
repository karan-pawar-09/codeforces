/*
    author:Karan
    created:19.08.2022 18:18:21
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
    vector<int> freq(150,0);
    for(auto x: s) {
        freq[x]++;
    }
    vector<int> cur(150, 0);
    string ans;
    for(int i=0;i<s.size();i++) {
        cur[s[i]]++;
        if(freq[s[i]]%2) {
            int no = freq[s[i]]/2;
            no++;
            if(cur[s[i]]==no) {

            } else {
                ans+=s[i];
            }
        } else {
            int no = freq[s[i]]/2;
            if((cur[s[i]] == no) || (cur[s[i]] == (no+1))) {

            } else {
                ans+=s[i];
            }
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
    //cin>>t;
    while(t--) {
        solve();
    }
}