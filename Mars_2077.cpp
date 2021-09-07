/*
author:Karan
created:05.06.2021 19:58:42
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<ll> parent;
vector<ll> size;
vector<ll> in,out;
ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(ll v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        in[a]=min(in[a],in[b]);
        out[a]=max(out[a],out[b]);
        in[b]=in[a];
        out[b]=out[a];
        parent[b] = a;
        size[a] += size[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    parent.resize(n);
    size.resize(n);
    in.resize(n,INT_MAX);
    out.resize(n,INT_MAX);
    vector<pair<ll,ll>> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;        
    }
    sort(all(arr));
    for(int i=0;i<n;i++) {
        make_set(i);
        in[i]=arr[i].first;
        out[i]=arr[i].second;
    }
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            find_set(i);
            find_set(j);
                if(out[parent[j]]<in[parent[i]]) {                    
                    union_sets(i,j);                    
                }
        }
    }
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            find_set(i);
            find_set(j);
                if(out[parent[j]]<in[parent[i]]) {                    
                    union_sets(i,j);                    
                }
        }
    }
    set<ll> s;
    for(ll i=0;i<n;i++) {
        s.insert(parent[i]);
    }
    cout<<(int)s.size()<<endl;
}