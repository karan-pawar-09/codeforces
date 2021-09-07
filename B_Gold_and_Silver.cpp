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
    string s;
    cin>>s;
    ll k=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='0') {
            k++;
        }
    }
    if(k%2) {
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
    }
}