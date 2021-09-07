/*
author:Karan
created:17.08.2021 20:27:58
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {      
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;        
        int ans=0;
        int prev=-1e9;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') {
                if((i-prev)<=(k+1)) {
                    prev=min(prev+k,i+1);
                }
                else {
                    ans++;
                    prev=i+1;
                }
            }
        }
        cout<<ans<<endl;
    }     

}

