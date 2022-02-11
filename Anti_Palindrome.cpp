/*
    author:Karan
    created:02.02.2022 20:30:37
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
    if(n%2) {
        cout<<"NO"<<endl;
        return;
    }
    vector<int> freq(200,0);
    for(auto x:s) {
        freq[x]++;
    }
    vector<pair<int,char>> ar(200);
    for(char c='a'; c<='z';c++) {
        ar[c-'a'].first=freq[c];
        ar[c-'a'].second=c;
    }
    sort(all(ar),greater<pair<int,char>>());
    int cur=0;
    string ans;
    ans.resize(n);
    for(int i=0;i<n/2;i++) {
        ans[i]=ar[cur].second;
        freq[ans[i]]--;
        bool found=false;
        char req;
        for(int j=cur+1;j<200;j++) {
            if(ar[j].second>='a' and ar[j].second<='z' and ar[j].second!=ans[i]) {
                if(freq[ar[j].second]>0) {
                    req=ar[j].second;
                    freq[req]--;
                    found=true;
                    break;
                }
            }
            
        }
        for(int i=0;i<200;i++) {
            ar[i].first=0;
        }
        for(char c='a';c<='z';c++) {
            ar[c-'a'].first=freq[c];
            ar[c-'a'].second=c;
        }
        sort(all(ar),greater<pair<int,char>>());
        if(found)
            ans[n-1-i]=req;
        else {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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