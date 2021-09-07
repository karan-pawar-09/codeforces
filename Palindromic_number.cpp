/*
author:Karan
created:24.07.2021 16:26:37
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n,m,k,a,b,c;
        cin>>n>>m>>k;
        string s;
        cin>>s;
        map<pair<int,int>,int> M;
        for(int i=0;i<m;i++) {
            cin>>a>>b>>c;
            if(M.find({a,b})==M.end())
                M[{a,b}]=c;
            else
                M[{a,b}]=min(M[{a,b}],c);
        }
        bool possible=true;
        int ans=0;
        for(int i=0;i<n/2;i++) {
            if(s[i]!=s[n-1-i]) {
                int mini=1e9;
                if(M.find({s[i]-'0',s[n-1-i]-'0'})==M.end()) {
                    if(M.find({s[n-1-i]-'0',s[i]-'0'})==M.end()) {
                        possible=false;
                        break;
                    }
                    else {
                        mini=M[{s[n-1-i]-'0',s[i]-'0'}];
                    }
                    if(!possible) break;
                }
                else {
                    if(M.find({s[n-1-i]-'0',s[i]-'0'})==M.end()) {
                        mini=M[{s[i]-'0',s[n-1-i]-'0'}];
                    }
                    else {
                        mini=min(M[{s[i]-'0',s[n-1-i]-'0'}],M[{s[n-1-i]-'0',s[i]-'0'}]);
                    }
                }
                if(!possible) break;
                ans+=mini;
            }
            if(!possible) break;
        }
        if(!possible) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}