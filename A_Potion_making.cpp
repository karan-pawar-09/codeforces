/*
authot:Karan
created:16.05.2021 13:31:58
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int k;
        cin>>k;
        int p=100;
        cout<<100/(__gcd(p,k))<<endl;
    }
}