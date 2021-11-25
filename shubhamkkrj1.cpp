
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() { 
    string s;
    cin>>s;
    int no=0;
    for(auto x:s) {
        if(x=='+' or x=='-' or x=='*' or x=='/' or x=='%') {
            no++;
        }
    }
    string ans;
    for(int i=0;i<no;i++) {
        ans.push_back(')');
    }
    int t=0;
    for(int i=s.size()-1;i>0;i--) {
        ans.push_back(s[i]);
        char x=s[i-1];
        if(x=='+' or x=='-' or x=='*' or x=='/' or x=='%') {
            if(t==0) t++;
            else {
                ans.push_back('(');
                t++;
            }
        }        
    }
    ans.push_back(s[0]);
    ans.push_back('(');
    reverse(all(ans));
    cout<<ans<<endl;
}