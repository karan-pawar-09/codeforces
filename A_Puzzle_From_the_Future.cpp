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
        string b;
        cin>>b;
        string a;
        a+='1';
        string ans;
        ans+=to_string((int)(a[0]-'0')+(int)(b[0]-'0'));
        for(int i=1;i<n;i++) {
            if(b[i]=='1') {
                if(ans[i-1]!='2') {
                    ans+='2';
                    a+='1';
                }
                else {
                    ans+='1';
                    a+='0';
                }
            }
            else {
                if(ans[i-1]!='1') {
                    ans+='1';
                    a+='1';
                }
                else {
                    ans+='0';
                    a+='0';
                }
            }
        }
        cout<<a<<endl;
    }
}