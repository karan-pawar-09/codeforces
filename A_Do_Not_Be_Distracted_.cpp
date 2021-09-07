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
        int n;
        cin>>n;
        string s;
        cin>>s;
        string ss;
        ss+=s[0];
        vector<bool> used(26,false);
        ss+=s;
        s=ss;
        bool ans=true;
        used[s[0]-'A']=true;
        for(int i=1;i<s.size();i++) {
            if(s[i]!=s[i-1]) {
                int k=s[i]-'A';
                if(used[k]) {
                    ans=false;
                    break;
                }
                else {
                    used[k]=true;
                }
            }            
        }
        if(ans) {
            cout<<"YES"<<endl;

        }
        else {
            cout<<"NO"<<endl;
        }
    }
}