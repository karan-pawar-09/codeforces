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
        int a=0;
        for(int i=0;i<n-1;i++) {
            if(s[i]==s[i+1]) {
                a++;
            }
        }
        cout<<(a+1)/2<<endl;
    }
}