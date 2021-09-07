/*
author:Karan
created:18.06.2021 11:37:17
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

#define item long long
// struct item {
//     ll seg,pref,suf,sum;
// };
struct segtree {
    ll size;
    vector<item> items;
    item NEUTRAL_ELEMENT=(ll)INT_MIN;
    item merge(item a,item b) {
        return max(a,b);
    }
    item single(ll v) {
        return v;       
    }
    void init(ll n) {
        size=1;
        while(size<n) {
            size*=2;
        }
        items.resize(2*size);
    }
    int build(vector<ll> &a,ll x,ll lx,ll rx) {
        if(rx-lx==1) {
            if(lx<((ll)a.size())) {
                items[x]=single(a[lx]);
            }
            return 1;
        }
        ll m=lx+(rx-lx)/2;
        int c=build(a,2*x+1,lx,m);
        int b=build(a,2*x+2,m,rx);
        if(c) {
            items[x]=items[2*x+1]|items[2*x+2];
            return 0;
        }
        else{
            items[x]=items[2*x+1]^items[2*x+2];
            return 1;
        }
    }
    void build(vector<ll> &a) {
        build(a,0,0,size);
    }
    int set(ll i,ll v,ll x,ll lx,ll rx) {
        if(rx-lx==1) {
            items[x]=single(v);
            return 1;
        }
        ll m=lx+(rx-lx)/2;
        int a;
        if(i<m) {
            a=set(i,v,2*x+1,lx,m);
        }
        else {
            a=set(i,v,2*x+2,m,rx);
        }
        if(a) {
            items[x]=items[2*x+1]|items[2*x+2];
            return 0;
        }
        else {
            items[x]=items[2*x+1]^items[2*x+2];
            return 1;
        }
    }
    void set(ll i,ll v) {
        set(i,v,0,0,size);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,m;
    cin>>n>>m;
    n=(1<<n);
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    segtree st;
    st.init(n);
    st.build(arr);
    while(m--) {
        ll a,b;
        cin>>a>>b;
        a--;
        st.set(a,b); 
        cout<<st.items[0]<<endl;           
    }
}