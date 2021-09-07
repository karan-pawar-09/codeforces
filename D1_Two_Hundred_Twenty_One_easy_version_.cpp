/*
author:Karan
created:27.08.2021 16:36:07
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
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        vector<int> odd(n+1,0);
        for(int i=1;i<=n;i++) {
            if(i%2) {
                if(s[i-1]=='-') {
                    odd[i]=1;
                }
                else {
                    odd[i]=-1;
                }
            }
            else {
                if(s[i-1]=='+') {
                    odd[i]=1;
                }
                else {
                    odd[i]=-1;
                }
            }
        }
        for(int i=1;i<=n;i++) {
            odd[i]+=odd[i-1];
        }
        int l,r;
        while(q--) {
            cin>>l>>r;
            if(l>r) {
                swap(l,r);
            }
            if(odd[r]-odd[l-1]==0) {
                cout<<0<<endl;
            }
            else if((odd[r]-odd[l-1])%2) {
                cout<<1<<endl;
            }
            else {
                cout<<2<<endl;
            }
        }
    }
}