/*
author:Karan
created:20.08.2021 23:16:31
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define sz(a) ((ll)(a.size()))

string ans;
bool findno;

void build(string str,ll len,int k,int distinct,string &no) {
    string kk=no.substr(0,sz(str));
    if(distinct>k || (str.size()&&(stoll(str)<stoll(no.substr(0,str.size())))) || findno) return;

    if(sz(str)>=len) {
        ans=str;
        findno=true;
        return;
    }
    
    for(char d='0';d<='9';d++) {
        string p=str;
        p.push_back(d);
        int dist=distinct;
        if(str.find(d)==string::npos) {
            dist++;
        }
        build(p,len,k,dist,no);
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n,k;
        cin>>n>>k;
        findno=false;
        string str=to_string(n);
        build("",str.size(),k,0,str);
        cout<<ans<<endl;
    }
}