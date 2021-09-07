/*
author:Karan
created:22.07.2021 20:21:04
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        string temp=s;
        string temp1=s;
        for(int i=1;i<=10;i++) {
            if(i%2) {
                if(s[i-1]=='?') {
                    temp[i-1]='1';
                }
            }
            else {
                if(s[i-1]=='?') {
                    temp[i-1]='0';
                }
            }
        }
        for(int i=1;i<=10;i++) {
            if(i%2) {
                if(s[i-1]=='?') {
                    temp1[i-1]='0';
                }
            }
            else {
                if(s[i-1]=='?') {
                    temp1[i-1]='1';
                }
            }
        }
        int first=0;
        int second=0;
        int ans1;
        for(int i=1;i<=10;i++) {
            if(temp[i-1]=='1') {
                if(i%2) {
                    first++;
                }
                else {
                    second++;
                }
            }            

            int firstrem;
            int secondrem;
            
            if(i%2) {
                firstrem=(10-i)/2;
                secondrem=((10-i)/2)+1;
            }
            else {
                firstrem=(10-i)/2;
                secondrem=(10-i)/2;
            }
            ans1=i;
            if(first-second>secondrem) {
                break;
            }
        }
        first=0;
        second=0;
        int ans2;
        for(int i=1;i<=10;i++) {
            if(temp1[i-1]=='1') {
                if(i%2) {
                    first++;
                }
                else {
                    second++;
                }
            }            

            int firstrem;
            int secondrem;
            
            if(i%2) {
                firstrem=(10-i)/2;
                secondrem=((10-i)/2)+1;
            }
            else {
                firstrem=(10-i)/2;
                secondrem=(10-i)/2;
            }
            ans2=i;
            if(second-first>firstrem) {
                break;
            }
        }
        cout<<min(ans1,ans2)<<endl;
    }
}