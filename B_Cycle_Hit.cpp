/*
author:Karan
created:26.07.2021 16:22:20
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
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    map<string,int> M;
    M[s1]++;
    M[s2]++;
    M[s3]++;
    M[s4]++;
    bool ans=true;
    if(M.find("H")==M.end()) {
        ans=false;
    }
    if(M.find("2B")==M.end()) {
        ans=false;
    }
    if(M.find("3B")==M.end()) {
        ans=false;
    }
    if(M.find("HR")==M.end()) {
        ans=false;
    }
    ans?cout<<"Yes"<<endl:cout<<"No"<<endl;
}