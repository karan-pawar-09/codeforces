/*
    author:Karan
    created:10.01.2022 22:03:46
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

string s;
int n,k;

bool isGood(int m) {
    if(m==1) return true;
    int ans=0;
    vector<int> freq(26,0);
    int count=0;
    int res=0;
    for(int i=0;i<n;i++) {
        freq[s[i]-'a']++;
    }
    for(int i=0;i<26;i++) {
        count+=freq[i]/2;
        res+=freq[i]%2;
    }
    
    if(m%2==0) {
        int x=(2*count)/m;
        if(x>=k ) return true;
        else return false;
    } else {
        int x;
        if(res>=(k)) {
            x=(2*count)/(m-1);
        } else {
            x=(2*count)/m;
        }
        if(x>=k) return true;
        else return false;
    }

}
void solve() {
    cin>>n>>k;
    cin>>s;
    int l=1;
    int r=(n/k)+1;
    while(l+1<r) {
        int m= l+(r-l)/2;
        if(isGood(m)) l=m;
        else r=m;
    }
    cout<<l<<endl;
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