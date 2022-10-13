/*
    author:Karan
    created:26.07.2022 09:16:06
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif



pair<string, int> preprocess(string transaction) {
    string temp = "";
    int breaking = -1;
    for(int i=0; i<transaction.size()-1; i++) {
        if(transaction[i]=='-' && transaction[i+1]=='>') {
            breaking = i;
            break;
        }
    }
    return {transaction.substr(0, breaking), stoi(transaction(breaking+1))};
} 

map<string, int> solve() {
    int n;
    cin>>n;
    vector<string> transactions(n);
    for(int i=0;i<n;i++) {
        cin>>transactions[i];
    }
    map<string, int> accounts;
    for(int i=0; i<n; i++) {
        pair<string, int> accoutninfo = preprocess(transactions[i]);
        accounts[accoutninfo.first] += accoutninfo.second;
    }
    return accounts;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        map<string, int> temp = solve();
        for(auto x: temp) {
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
}