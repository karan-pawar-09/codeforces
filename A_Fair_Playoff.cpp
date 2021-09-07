/*
author:Karan
created:04.06.2021 20:06:04
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        vector<int> s(4);
        for(int i=0;i<4;i++) {
            cin>>s[i];
        }
        int m1=max(s[0],s[1]);
        int m2=max(s[2],s[3]);
        if(m1<m2) {
            swap(m1,m2);
        }
        sort(all(s));
        if(m1==s[3]&&m2==s[2]) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }   
}