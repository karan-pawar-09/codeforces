
/*
author:Karan
created:02.06.2021 20:38:51
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
    int n=33;
    for(int i=0;i<n;i++) {
        string s;
        getline(cin,s);
        string k;
        k+='\"';
        k+=s;
        k+='\"';
        k+=",";
        cout<<k<<endl;
    }
}

