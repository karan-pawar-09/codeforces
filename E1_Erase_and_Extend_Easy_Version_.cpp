/*
author:Karan
created:18.06.2021 21:46:09
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s+=s;
    for(int i=0;i<1;i++) {
        for(int j=i+1;j<s.size();j++) {
            if(s[i]<s[j]) {
                s.erase(j);
                break;
            }
            else if(s[i]==s[j]) {
                int p=i;
                int q=j;
                bool ans=false;
                while(q<s.size()) {
                    if(s[p%j]<s[q]) {
                        ans=true;
                    }
                    if(s[p]>s[q]) {
                        break;
                    }
                    p++;
                    q++;
                }
                if(ans) {
                    s.erase(j);
                }
            }
        }
    }
    string t=s;
    while(s.size()<k) {
        s+=t;
    }
    cout<<s.erase(k)<<endl;
}