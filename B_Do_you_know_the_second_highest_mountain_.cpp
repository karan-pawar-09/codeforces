/*
authot:Karan
created:16.05.2021 17:14:30
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,string>> input(n);
    for(int i=0;i<n;i++) {
        cin>>input[i].second>>input[i].first;
    }
    sort(all(input));
    cout<<input[n-2].second<<endl;
}