#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
bool isgood(string s) {
    int n=s.size();
    int ans=true;
    for(int i=0;i<n;i++) {
        if(s[i]!=s[n-1-i]) {
            ans=false;
            break;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    string s;
    s=to_string(n);
    vector<char> a(s.size());
    for(int i=0;i<s.size();i++) {
        a[i]=s[i];
    }
    for(int i=s.size()-1;i>=0;i--) {
        if(a[i]!='0') {
            break;
        }
        else{
            a.pop_back();
        }
    }
    s.clear();
    for(int i=0;i<a.size();i++)  {
        s+=a[i];
    }
    if(isgood(s)) {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}   