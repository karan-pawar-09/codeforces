/*
author:Karan
created:04.06.2021 14:43:36
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<ll> parent;
vector<ll> size;
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
    string s;
    cin>>s;
    parent.resize(26,-1);
    size.resize(26,0);
    for(ll i=0;i<26;i++) {
        make_set(i);
    }
    vector<vector<ll>> arr(26,vector<ll> (26,0));
    ll ans=0;
    for(ll i=0;i<n/2;i++) {
        if(s[i]!=s[n-i-1]) {
            ll a=s[i]-'a';
            ll b=s[n-1-i]-'a';
            arr[a][b]++;
            ans++;
        }
    }
    ll q;
    cin>>q;
    while(q--) {
        ll k;
        cin>>k;
        if(k==1) {
            char a,b;
            cin>>a>>b;
            union_sets(a-'a',b-'a');
        }
        else {
            for(ll i=0;i<26;i++) {
                for(ll j=0;j<26;j++) {
                    if(arr[i][j]!=0) {
                        if(find_set(i)==find_set(j)) {
                            ans-=arr[i][j];
                            arr[i][j]=0;
                        }
                    }
                }
            }
            cout<<max(ans,0LL)<<endl;
        }
    }
}