#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.size();
    int k=-1;
    for(int i=0;i<n;i++) {
        if((s[i]-'0')%2==0) {
            if(s[i]<s[n-1]) {
                k=i;
                break;
            }
            else{
                k=i;
            }
        }
    }
    if(k==-1) {
        cout<<k<<endl;
    }
    else{
        char temp=s[k];
            s[k]=s[n-1];
            s[n-1]=temp;
        cout<<s<<endl;
    }
}