/*
author:Karan
created:18.08.2021 20:36:09
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define sz(a) ((ll)(a.size()))

// set<ll> s;
// set<ll> st;

// void build(string str,ll len,char first,char second) {
//     if(sz(str)>len) return;
//     if(sz(str)&&str[0]=='0') return;
//     if(sz(str)==len) {
//         s.insert(stoll(str));
//         return;
//     }
//     string p,q;
//     p=q=str;
//     p.push_back(first);
//     q.push_back(second);
//     build(p,len,first,second);
//     build(q,len,first,second);
// }
// bool isGood(ll n) {
//     string s;
//     s=to_string(n);
//     map<char,ll> M;
//     for(ll i=0;i<sz(s);i++) {
//         M[s[i]]++;
//     }
//     return sz(M)<=2;
// }

// int32_t main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     for(ll len=1;len<=11;len++) {
//         for(char i='0';i<='9';i++) {
//             for(char j=i+1;j<='9';j++) {
//                 build("",len,i,j);
//             }
//         }
//     }
//     for(ll len=1;len<=11;len++) {
//         for(char i='1';i<='9';i++) {
//             string no;
//             for(int j=1;j<=len;j++) {
//                 no.push_back(i);
//             }
//             st.insert(stoll(no));
//         }
//     }
//     ll t;
//     cin>>t;
//     while(t--) {
//         ll n,k;
//         cin>>n>>k;
//         string str=to_string(n);
//         if(k==1) {
//             cout<<*st.lower_bound(n)<<endl;
//         }
//         else {
//             if(isGood(n)){
//                 cout<<n<<endl;
//             }
//             else {
//                 cout<<*s.lower_bound(n)<<endl;
//             }
//         }
//     }
// }

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