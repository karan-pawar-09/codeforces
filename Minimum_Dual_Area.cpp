/*
author:Karan
created:05.06.2021 18:13:30
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<pair<ll,ll>> arx(n);
        vector<pair<ll,ll>> ary(n);
        vector<ll> X(n);
        vector<ll> Y(n);
        map<ll,vector<ll>> Mx;
        map<ll,vector<ll>> My;
        for(ll i=0;i<n;i++) {
            cin>>arx[i].first>>arx[i].second;
            X[i]=arx[i].first;
            Y[i]=arx[i].second;
            ary[i].first=arx[i].second;
            ary[i].second=arx[i].first;
            Mx[ary[i].first].push_back(ary[i].second);
            My[arx[i].first].push_back(arx[i].second);
        }
        vector<pair<ll,ll>> ymax,xmax,xmin,ymin;
        for(auto x:Mx) {
            xmax.push_back({x.first, *max_element(all(x.second))});
            xmin.push_back({x.first, *min_element(all(x.second))});
        }
        for(auto y:My) {
            ymax.push_back({y.first, *max_element(all(y.second))});
            ymin.push_back({y.first, *min_element(all(y.second))});
        }
        
        vector<ll> xmaxinc(xmax.size()),xmininc(xmax.size());
        xmaxinc[0]=xmax[0].second;
        xmininc[0]=xmin[0].second;
        for(ll i=1;i<xmax.size();i++) {
            xmaxinc[i]=max(xmax[i].second,xmaxinc[i-1]);
            xmininc[i]=min(xmin[i].second,xmininc[i-1]);
        }
        vector<ll> xmaxdec(xmax.size()),xmindec(xmax.size());
        xmaxdec[xmaxdec.size()-1]=xmax[xmax.size()-1].second;
        xmindec[xmax.size()-1]=xmin[xmax.size()-1].second;
        for(ll i=xmax.size()-2;i>=0;i--) {
            xmaxdec[i]=max(xmax[i].second,xmaxdec[i+1]);
            xmindec[i]=min(xmin[i].second,xmindec[i+1]);
        }
        ll xmx=*max_element(all(X));
        ll xmn=*min_element(all(X));
        ll ymx=*max_element(all(Y));
        ll ymn=*min_element(all(Y));
        ll ans=(xmx-xmn)*(ymx-ymn);
        for(ll i=0;i<xmax.size()-1;i++) {
            ans=min(ans,(xmax[i].first-xmax[0].first)*(xmaxinc[i]-xmininc[i])+(xmax[xmax.size()-1].first-xmax[i+1].first)*(xmaxdec[i+1]-xmindec[i+1]));
        }
        for(ll i=xmax.size()-1;i>0;i--) {
            ans=min(ans,(xmax[i-1].first-xmax[0].first)*(xmaxinc[i-1]-xmininc[i-1])+(xmax[xmax.size()-1].first-xmax[i].first)*(xmaxdec[i]-xmindec[i]));
        }
        vector<ll> ymaxinc(ymax.size()),ymininc(ymax.size());
        ymaxinc[0]=ymax[0].second;
        ymininc[0]=ymin[0].second;
        for(ll i=1;i<ymax.size();i++) {
            ymaxinc[i]=max(ymax[i].second,ymaxinc[i-1]);
            ymininc[i]=min(ymin[i].second,ymininc[i-1]);
        }
        vector<ll> ymaxdec(ymax.size()),ymindec(ymax.size());
        ymaxdec[ymax.size()-1]=ymax[ymax.size()-1].second;
        ymindec[ymax.size()-1]=ymin[ymin.size()-1].second;
        for(ll i=ymax.size()-2;i>=0;i--) {
            ymaxdec[i]=max(ymax[i].second,ymaxdec[i+1]);
            ymindec[i]=min(ymin[i].second,ymindec[i+1]);
        }
        for(ll i=0;i<ymax.size()-1;i++) {
            ans=min(ans,(ymax[i].first-ymax[0].first)*(ymaxinc[i]-ymininc[i])+(ymax[ymax.size()-1].first-ymax[i+1].first)*(ymaxdec[i+1]-ymindec[i+1]));
        }
        for(ll i=ymax.size()-1;i>0;i--) {
            ans=min(ans,(ymax[i-1].first-ymax[0].first)*(ymaxinc[i-1]-ymininc[i-1])+(ymax[ymax.size()-1].first-ymax[i].first)*(ymaxdec[i]-ymindec[i]));
        }
        cout<<ans<<endl;
    }   
}