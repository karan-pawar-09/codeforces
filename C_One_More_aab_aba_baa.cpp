/*
author:Karan
created:21.08.2021 17:39:25
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

set<string> strings;

void permute(string a, int l, int r) {
    if (l == r)
        strings.insert(a);
    else {
        for (int i = l; i <= r; i++) {
            swap(a[l], a[i]);
            permute(a, l+1, r);
            swap(a[l], a[i]);
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string s;
    int k;
    cin>>s>>k;
    permute(s,0,s.size()-1);
    int p=1;
    for(auto x:strings) {
        if(p==k) {
            cout<<x<<endl;
            break;
        }
        p++;
    }
}