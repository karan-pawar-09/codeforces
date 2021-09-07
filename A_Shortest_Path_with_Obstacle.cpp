/*
author:Karan
created:11.07.2021 11:54:18
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
    while(t-- ) {
        int a,b;
        cin>>a>>b;
        int x,y ;
        cin>>x>>y;
        int g,f;
        cin>>g>>f;
        int ans;
        if(a==x||b==y) {
            if(a==x) {
                if(g==a) {
                    if(f>min(b,y)&&f<max(b,y))
                        ans=abs(b-y)+2;
                        else
                        ans=abs(b-y);
                }
                else {
                    ans=abs(b-y);
                }
            }
            else {
                if(f==b) {
                    if(g>min(a,x)&&g<max(a,x))
                        ans=abs(a-x)+2;
                        else {
                            ans=abs(a-x);
                        }
                }
                else {
                    ans=abs(a-x);
                }
            }
        }
        else {
            ans=abs(a-x)+abs(b-y);
        }
        cout<<ans<<endl;
    }
}