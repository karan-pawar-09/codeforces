/*
author:Karan
created:13.07.2021 10:40:31
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
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> a(n),b(n);
        ll suma=0;
        ll sumb=0;
        for(ll i=0;i<n;i++) {
            cin>>a[i];
            suma+=a[i];
        }
        for(ll j=0;j<n;j++) {
            cin>>b[j];
            sumb+=b[j];
        }
        if(suma!=sumb) {
            cout<<-1<<endl;
        }
        else {
            ll no=0;
            queue<pair<ll,ll>> q1;
            queue<pair<ll,ll>> q2;
            vector<pair<ll,ll>> ans;
            for(ll i=0;i<n;i++) {
                if(a[i]-b[i]<0) {
                    q1.push({abs(a[i]-b[i]),i});
                }
                else if(a[i]-b[i]>0) {
                    q2.push({abs(a[i]-b[i]),i});
                }
            }
            while(q1.size()) {
                pair<ll,ll> no1=q1.front();
                pair<ll,ll> no2=q2.front();
                q1.pop();
                q2.pop();
                ll temp=min(no1.first,no2.first);
                if(temp==no1.first) {
                    for(ll z=0;z<temp;z++) {
                        ans.push_back({no2.second,no1.second});
                    }
                    if((no2.first-temp)>0)
                        q2.push({no2.first-temp,no2.second});
                }
                else {
                    for(ll z=0;z<temp;z++) {
                        ans.push_back({no2.second,no1.second});
                    }
                    if((no1.first-temp)>0)
                        q1.push({no1.first-temp,no1.second});
                }
            }
            cout<<ans.size()<<endl;
            for(auto x:ans) {
                cout<<x.first+1<<" "<<x.second+1<<endl;
            }
        }
    }
}