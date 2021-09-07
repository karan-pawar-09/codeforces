#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.size();
    char largest=s[0];
    for(int i=0;i<n;i++) {
        if(s[i]>largest) {
            largest=s[i];
        }
    }
    int freq=0;
    for(int i=0;i<n;i++) {
        if(s[i]==largest) {
            freq++;
        }
    }
    for(int i=0;i<freq;i++) {
        cout<<largest;
    }
}