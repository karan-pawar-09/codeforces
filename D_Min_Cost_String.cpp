#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    string s;
    for(int i=0;i<k;i++) {
        s+='a'+i;
        for(int j=i+1;j<k;j++) {
            s+='a'+i;
            s+='a'+j;
        }
    }
    while(s.size()<n) {
        s+=s;
    }
    s.resize(n);
    cout<<s<<endl;
}