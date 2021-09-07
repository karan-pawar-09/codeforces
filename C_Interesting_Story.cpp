/*
author:Karan
created:23.07.2021 21:30:45
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

char c;

bool comperator(string s, string t) {
    int n=s.size();
    int m=t.size();
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(s[i]==c) {
            cnt++;
        }
    }
    int cnt1=0;
   
    for(int i=0;i<m;i++) {
        if(t[i]==c) {
            cnt1++;
        }
    }
    return (2*cnt-(n))>(2*cnt1-(m));
}
int mxcount(string s,char kk) {
    int n=s.size();
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(s[i]==kk) {
            cnt++;
        }
    }
    return cnt;
}

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
        vector<string> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int ans=0;
        for(c='a';c<='e';c++) {
            sort(all(arr),comperator);
            int chars=0;
            int extra=0;
            int i=0;
            for(i;i<n;i++) {
                int kk=mxcount(arr[i],c);;
                chars+=kk;
                extra+=(arr[i].size()-kk);
                if(chars<=extra) {
                    break;
                }
            }
            ans=max(ans,i);
        }
        
        
        cout<<ans<<endl;
    }
}