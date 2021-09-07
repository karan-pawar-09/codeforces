#include<bits/stdc++.h>
using namespace std;
#define ll long long

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
        for(int i=n-1;i>=0;i--) {
            if((s[i]-'0')%2) {
                break;
            } 
            else {
                s.pop_back();
                continue;
            }
        }
        int sum=0;
        for(int i=0;i<s.size();i++) {
            sum+=(s[i]-'0');
        }
        while(s[0]=='0') {
            s.erase(s.begin());
        }
        if(sum%2==0) {
            if(s.size())
                cout<<s<<endl;
            else{
                cout<<"-1"<<endl;
            }
                
        }
        else{
            bool can=false;
            for(int i=0;i<s.size()-1;i++) {
                if((s[i]-'0')%2) {
                    can=true;
                    s.erase(s.begin()+i);
                    break;
                }
            }
            while(s[0]=='0') {
                s.erase(s.begin());
            }
            if(can&&s.size()!=0) {
                cout<<s<<endl;
            }
            else {
                cout<<"-1"<<endl;
            }
        }
    }
}