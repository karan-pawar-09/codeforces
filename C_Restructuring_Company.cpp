/*
author:Karan
created:10.06.2021 17:24:00
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const int mx=200000 + 5;
int parent[mx];
int magnitude[mx];
int nextpar[mx];

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

ll find_nxt_set(ll v) {
    if (v ==nextpar[v])
        return v;
    return nextpar[v] = find_nxt_set(nextpar[v]);
}

void make_set(ll v) {
    parent[v] = v;
    magnitude[v] = 1;
    nextpar[v]=v;
}

void union_sets(ll a, ll b) {
    a = find_nxt_set(find_set(a));
    b = find_nxt_set(find_set(b));
    if (a != b) {
        if (magnitude[a] < magnitude[b])
            swap(a, b);
        parent[b] = a;
        magnitude[a] += magnitude[b];
    }
}
void union_sets_next(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {        
        nextpar[b] = a;      
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        make_set(i);
    }
    while(q--) {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1) {
            union_sets(b,c);
        }
        else if(a==2) {
            for(int i=nextpar[find_nxt_set(b)];i<c;i=nextpar[find_nxt_set(i+1)]) {
                union_sets_next(i+1,i);        
            }
        }
        else {
            find_nxt_set(find_set(b))==find_nxt_set(find_set(c))?cout<<"YES"<<endl:cout<<"NO"<<endl;
        }
    }
}