/*
author:Karan
created:30.07.2021 21:46:38
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

string s;
int n,m;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    cin>>n>>m;
    cin>>s;
    vector<string> arr={"abc","acb","bac","bca","cab","cba"};
    vector<vector<int>> pref(6,vector<int> (n,0));
    for(int i=0;i<6;i++) {
        if(arr[i][0]==s[0]) {
            pref[i][0]=1;
        }
        for(int j=1;j<n;j++) {
            pref[i][j]=pref[i][j-1]+(s[j]==arr[i][j%3]);
        }
    }

    while(m--) {
        int a,b;
        cin>>a>>b;
        b--;
        a-=2;
        int ans=1e9+7;
        for(int i=0;i<6;i++) {
            int kk=0;
            kk=pref[i][b];
            if(a>=0) {
                kk-=pref[i][a];
            }
            kk=(b-a)-kk;
            ans=min(ans,kk);
        }
        cout<<ans<<endl;
    }
}