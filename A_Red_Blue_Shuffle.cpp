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
        string q;
        cin>>q;
        int nq=0;
        int ns=0;
        for(int i=0;i<n;i++) {
            if(s[i]>q[i]) {
                ns++;
            }
            else if(q[i]>s[i]) {
                nq++;
            }
        }
        if(ns>nq) {
            cout<<"RED"<<endl;
        }
        else if(nq>ns) {
            cout<<"BLUE"<<endl;
        }
        else {
            cout<<"EQUAL"<<endl;
        }
    }
}