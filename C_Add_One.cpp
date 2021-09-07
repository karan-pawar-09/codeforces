#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mod=(ll)1e9+7;
    int t;
    cin>>t;
    while(t--) {
        ll n,m;
        cin>>n>>m;
        string s=to_string(n);        
        for(int i=0;i<m;i++) {
            vector<string> a(s.size());
            for(int j=0;j<s.size();j++) {
                int k=(int)(s[j]-'0');
                k++;
                a[j]=to_string(k);
            }
            s.clear();
            for(int j=0;j<a.size();j++) {
                s+=a[j];
            }
        }
        cout<<s.size()<<endl;
    }
}