/*
authot:Karan
created:19.05.2021 12:50:14
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll N=(ll)1e7+10;
vector<ll> sm;
vector<ll> ans;
void build() {
    sm.resize(N,0);
    ans.resize(N,-1);
    for(int i=1;i<N;i++) {
        for(int j=i;j<N;j+=i) {
            sm[j]+=i;
        }
    }
    for(int i=1;i<N;i++) {
        if(sm[i]<N&&ans[sm[i]]==-1) {
            ans[sm[i]]=i;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    build();
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
}