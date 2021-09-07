#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        string t;
        cin>>t;
        set<char> ss;
        set<char> tt;
        for(int i=0,n=s.size();i<n;i++) {
            ss.insert(s[i]);
        }
        for(int i=0,n=t.size();i<n;i++) {
            tt.insert(t[i]);
        }
        bool flag = true;
        set<char>::iterator it;
        set<char>::iterator is;
        vector<char> a;
        vector<char> b;        
        for(is=ss.begin();is!=ss.end();is++) {
             a.push_back(*is);
        }
        for(it=tt.begin();it!=ss.end();it++) {
             b.push_back(*it);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(ss.size()!=tt.size()) {
            flag=false;
        }
        else{
            for(int i=0,n=a.size();i<n;i++) {
                if(a[i]!=b[i]) {
                    flag=false;
                    break;
                }
            }
        }
        if(flag) {
            cout<<"1"<<endl;
        } 
        else {
            cout<<"0"<<endl;
        }       
    }
}