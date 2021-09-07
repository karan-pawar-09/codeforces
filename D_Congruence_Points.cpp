/*
author:Karan
created:26.06.2021 18:58:59
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
    int n;
    cin>>n;
    vector<pair<int,int>> a(n),b(n);
    vector<pair<bool,bool>> apos(n),bpos(n);
    for(int i=0;i<n;i++) {
        cin>>a[i].first>>a[i].second;
        if(a[i].first>=0) apos[i].first=true;
        else apos[i].first=false;

        if(a[i].second>=0) apos[i].second=true;
        else apos[i].second=false;
    }
    for(int i=0;i<n;i++) {
        cin>>b[i].first>>b[i].second;
        if(b[i].first>=0) bpos[i].first=true;
        else bpos[i].first=false;

        if(b[i].second>=0) bpos[i].second=true;
        else bpos[i].second=false;
    }
    if(apos[0].first==bpos[0].first) {
        if(apos[0].second==bpos[0].second) {

        }
        else {
            for(int i=0;i<n;i++) {
                int k=b[i].first;
                b[i].first=-b[i].second;
                b[i].second=k;
            }
        }
    }
    else {
        if(apos[0].second==bpos[0].second) {
            for(int i=0;i<n;i++) {
                int k=-b[i].first;
                b[i].first=b[i].second;
                b[i].second=k;
            }
        }
        else {
            for(int i=0;i<n;i++) {
                int k=-b[i].first;
                b[i].first=-b[i].second;
                b[i].second=k;
            }
        }
    }
    
    int diffx=a[0].first-b[0].first;
    
    int diffy=a[0].second-b[0].second;

    for(int i=0;i<n;i++) {
        b[i].first+=diffx;
        b[i].second+=diffy;
    }
    bool ans=true;
    for(int i=0;i<n;i++) {
        if((a[i].first!=b[i].first)||(a[i].second!=b[i].second)) {
            ans=false;
            break;
        }
    }
    ans?cout<<"Yes"<<endl:cout<<"No"<<endl;
}