/*
author:Karan
created:30.07.2021 20:53:04
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


void solve() {
    
    long double w,h;
    cin>>w>>h;
    long double x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    long double height,width;
    cin>>width>>height;
    if((width+abs(x2-x1)>w) && (height+abs(y2-y1)>h)) {
        cout<<-1<<endl;
    }
    else {
        long double mn=1e9+7;
        long double kk=width+abs(x2-x1);
        long double pp=height+abs(y2-y1);
        if(width+abs(x2-x1)<=w) {
            long double xtemp=w-width;
            long double xtmp=width;
            mn=min(mn,max((long double) 0,max(x1,x2)-xtemp));
            mn=min(mn,max((long double) 0,xtmp-min(x1,x2)));
        }
        if(height+abs(y2-y1)<=h) {
            long double ytemp=h-height;
            long double ytmp=height;
            mn=min(mn,max((long double) 0,max(y1,y2)-ytemp));
            mn=min(mn,max((long double) 0,ytmp-min(y1,y2)));
        }
        cout<<fixed;
        cout<<setprecision(9);
        cout<<mn<<endl;
    }
   
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    long double t;
    cin>>t;
    while(t--) {
        solve();
    }
}