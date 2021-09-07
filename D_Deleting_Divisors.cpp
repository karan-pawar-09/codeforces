/*
author:Karan
created:19.06.2021 00:03:43
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
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        if(n%2) {
            cout<<"Bob"<<endl;
        }
        else {
            int a=1;
            int pow=0;
            while(a<n) {
                a*=2;
                pow++;
            }
            if(a==n&&pow%2) {
                cout<<"Bob"<<endl;
            }
            else {
                cout<<"Alice"<<endl;
            }
        }
    }   
}