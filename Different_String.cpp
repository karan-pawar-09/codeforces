/*
author:Karan
created:22.08.2021 21:51:27
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

set<string> st;
string str;
bool found;
void solve(string s, int i,int n) {
    if(i>n) return ;
    if(found) return;
    if(st.find(s)==st.end()) {
        str=s;
        found=true;
        return;
    }
    string ans;
    string p=s;
    string q=s;
    p.push_back('0');
    q.push_back('1');
    solve(p,i+1,n);
    solve(q,i+1,n);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        st.clear();
        found=false;
        vector<string> arr;
        string s;
        int one=0;
        int zero=0;
        for(int i=0;i<n;i++) {
            cin>>s;
            arr.push_back(s);
            if(s[0]=='0') {
                one++;
            }
            else {
                zero++;
            }
        }
        string ans=s;
        for(int len=0;len<=n;len++) {
            for(int i=0;i<n;i++) {
                st.insert(arr[i].substr(0,len));
            }
        }
        solve("",0,n);
        for(int i=str.size();i<n;i++) {
            str.push_back('1');
        }
        cout<<str<<endl;
    }
}