/*
author:Karan
created:29.08.2021 20:05:15
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
        int c,d;
        cin>>c>>d;
        int diff=abs(c-d);
        if(c==0 and d==0) {
            cout<<0<<endl;
        }
        else {
            if(diff%2) {
                cout<<-1<<endl;
            }
            else {
                if((c==d) || (c==-d)) {
                    cout<<1<<endl;
                }
                else
                    cout<<2<<endl;
            }
        }
    }
}