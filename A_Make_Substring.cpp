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
        string p,s;
        cin>>s>>p;
        int ans=0;
        for(int i=0;i<s.size()-p.size()+1;i++) {
            int temp=0;
            for(int j=0;j<p.size();j++) {
                if(p[j]==s[i+j]) {
                    temp++;
                }
            }
            ans=max(temp,ans);
        }
        cout<<p.size()-ans<<endl;
    }
}