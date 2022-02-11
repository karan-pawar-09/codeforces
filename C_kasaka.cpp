/*
    author:Karan
    created:30.01.2022 18:27:12
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

bool is_palindrome(string s) {
    if(s.size()==0 or s.size()==1) return true;
    int n=s.size();
    for(int i=0;i<n/2;i++) {
        if(s[i]!=s[s.size()-1-i]) return false;
    }
    return true;
}
void solve() {
    string s;
    cin>>s;
    int n=s.size();
    int k=n;
    int pp=0;
    for(int i=n-1;i>=0;i--) {
        if(s[i]!='a') break;
        else {
            k=i;
            pp++;
        }
    }
    string res;
    int x=0;
    for(int i=0;i<pp;i++) {
        if(s[i]=='a') {
            x++;
        } else {
            break;
        }
    }
    for(int i=x;i<k;i++) {
        res.push_back(s[i]);
    }
    if(is_palindrome(res))
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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