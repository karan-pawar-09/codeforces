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
        int cnt=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') {
                cnt++;
            }
        }
        if(s[0]=='0'||s.back()=='0'||cnt%2) {
            cout<<"NO"<<endl;
            continue;
        }
        string a,b;
        int k=0;
        bool switchk=true;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') {
                if((k*2)<cnt) {
                    a.push_back('(');
                }
                else {
                    a.push_back(')');
                }
                b.push_back(a.back());
                k++;
            }
            else {
                if(switchk) {
                    a.push_back('(');
                    b.push_back(')');
                }
                else {
                    a.push_back(')');
                    b.push_back('(');
                }
                switchk=!switchk;
            }
        }
        cout<<"YES"<<endl<<a<<endl<<b<<endl;
    }
}