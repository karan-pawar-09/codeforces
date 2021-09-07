/*
author:Karan
created:03.08.2021 11:34:37
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
    ll q;
    cin>>q;
    ll add=0;
    map<ll,ll> M;
    set<ll> s;
    while(q--) {
        ll query;
        cin>>query;
        if(query==1) {
            ll no;
            cin>>no;
            no-=add;
            M[no]++;
            s.insert(no);
        }
        else if(query==2) {
            ll no;
            cin>>no;
            add+=no;
        }
        else {
            ll no=*s.begin();
            cout<<no+(add)<<endl;
            M[no]--;
            if(M[no]==0) {
                s.erase(no);
            }
        }
    }
}