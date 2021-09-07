/*
author:Karan
created:01.08.2021 20:21:17
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
        int n;
        cin>>n;
        string s,t;
        cin>>s;
        cin>>t;
        int ans=0;
        vector<bool> used(n,false);
        for(int i=0;i<n;i++ ) {
            if(t[i]=='1') {
                if(s[i]=='1') {
                    bool done=false;
                    if(i-1>=0) {
                        if(!used[i-1]&&s[i-1]=='1') {
                            ans++;
                            s[i-1]='0';
                            done=true;
                            used[i-1]=true;
                        }
                        if(done) continue;
                    }
                    if(i+1<n) {
                        if(!used[i+1]&&s[i+1]=='1') {
                            ans++;
                            s[i+1]='0';
                            used[i+1]=true;
                        }
                    }
                }
                else {
                    used[i]=true;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}