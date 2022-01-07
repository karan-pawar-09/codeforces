/*
    author:Karan
    created:22.12.2021 20:11:37
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

bool isVovel(char c) {
    if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u') {
        return true;
    }
    return false;
}

bool isGood(char a, char b) {
    return isVovel(a)^isVovel(b);
}

const int inf=1e9+7;

void solve() {
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int ans=0;
    vector<int> freq(200,0);
    int qmark=0;
    int vovels=0;
    for(int i=0;i<n;i++) {
        if(s[i]!=t[i]) {
            if(s[i]=='?' or t[i]=='?') {
                if(s[i]!='?') {
                    freq[s[i]]++;
                    if(isVovel(s[i])) vovels++;
                } else {
                    freq[t[i]]++;
                    if(isVovel(t[i])) vovels++;
                }
                qmark++;
            }
            else {
                if(isGood(s[i],t[i])) ans+=1;
                else ans+=2;
            }
        }
    }
    int res=inf;
    for(int i=0;i<n;i++) {        
        if(isVovel(s[i])) {
            int xx=qmark-freq[s[i]];
            int vovels1=vovels-freq[s[i]];
            res=min(res,(xx-vovels1)+vovels1*2);
        } else {
            int xx=qmark-freq[s[i]];
            int vovels1=vovels;
            res=min(res,(xx-vovels1)*2+vovels1);
        } 
    }
    for(int i=0;i<n;i++) {
        if(isVovel(t[i])) {
            int xx=qmark-freq[t[i]];
            int vovels1=vovels-freq[t[i]];
            res=min(res,(xx-vovels1)+vovels1*2);
        } else {
            int xx=qmark-freq[t[i]];
            int vovels1=vovels;
            res=min(res,(xx-vovels1)*2+vovels1);
        }
    }
    cout<<ans+res<<endl;
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