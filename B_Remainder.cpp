#include<bits/stdc++.h>
using namespace std;
#define ll long long

int mod(string s, int a) { 
    int res = 0;  
    for (int i = 0; i < s.length(); i++) {
         res = (res*10 + (int)s[i] - '0') %a; 
    }
    return res; 
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        string s;
        int n;
        cin>>s>>n;
        cout<<mod(s,n)<<endl;
    }
}