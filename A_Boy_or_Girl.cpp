#include<bits/stdc++.h>
using namespace std;
int main() {
    string a;
    cin>>a;
    set<char> ans;
    for(int i=0,n=a.size();i<n;i++) {
        ans.insert(a[i]);
    }
    if(ans.size()%2!=1) {
        cout<<"CHAT WITH HER!";
    }
    else {
        cout<<"IGNORE HIM!";
    }
}