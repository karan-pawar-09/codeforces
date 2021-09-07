/*
author:Karan
created:02.06.2021 09:21:20
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,u,r,d,l;
        int U,R,D,L;
        bool final=false;
        cin>>n>>U>>R>>D>>L;
        {
            u=U;r=R;d=D;l=L;
            bool ans=true;
            if(r>0&&u>0) {
                r--;
                u--;
            }
            if(d>0&&r>0) {
                r--;
                d--;
            }
            if(d>0&&l>0) {
                d--;
                l--;
            }
            if(l>0&&u>0) {
                u--;
                l--;
            }
            if(u!=0&&u>n-2) {
                ans=false;
            }
            if(d!=0&&d>n-2) {
                ans=false;
            }
            if(l!=0&&l>n-2) {
                ans=false;
            }
            if(r!=0&&r>n-2) {
                ans=false;
            }
            final|=ans;
        }
        {
            u=U;r=R;d=D;l=L;
            bool ans=true;
            if(d>0&&r>0) {
                r--;
                d--;
            }
            if(d>0&&l>0) {
                d--;
                l--;
            }
            if(l>0&&u>0) {
                u--;
                l--;
            }
            if(r>0&&u>0) {
                r--;
                u--;
            }
            if(u!=0&&u>n-2) {
                ans=false;
            }
            if(d!=0&&d>n-2) {
                ans=false;
            }
            if(l!=0&&l>n-2) {
                ans=false;
            }
            if(r!=0&&r>n-2) {
                ans=false;
            }
            final|=ans;
        }
        {
            u=U;r=R;d=D;l=L;
            bool ans=true;            
            if(d>0&&l>0) {
                d--;
                l--;
            }
            if(l>0&&u>0) {
                u--;
                l--;
            }
            if(r>0&&u>0) {
                r--;
                u--;
            }
            if(d>0&&r>0) {
                r--;
                d--;
            }
            if(u!=0&&u>n-2) {
                ans=false;
            }
            if(d!=0&&d>n-2) {
                ans=false;
            }
            if(l!=0&&l>n-2) {
                ans=false;
            }
            if(r!=0&&r>n-2) {
                ans=false;
            }
            final|=ans;
        }
        {
            u=U;r=R;d=D;l=L;
            bool ans=true;            
            
            if(l>0&&u>0) {
                u--;
                l--;
            }
            if(r>0&&u>0) {
                r--;
                u--;
            }
            if(d>0&&r>0) {
                r--;
                d--;
            }
            if(d>0&&l>0) {
                d--;
                l--;
            }
            if(u!=0&&u>n-2) {
                ans=false;
            }
            if(d!=0&&d>n-2) {
                ans=false;
            }
            if(l!=0&&l>n-2) {
                ans=false;
            }
            if(r!=0&&r>n-2) {
                ans=false;
            }
            final|=ans;
        }
        final?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
}