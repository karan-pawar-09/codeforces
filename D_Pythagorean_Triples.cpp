/*
author:Karan
created:28.05.2021 17:05:21
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
        int n;
        cin>>n;
        int answer=0;
        for(int i=3;i*i-(((i*i)-1)/2)<=n;i+=2) {
            if(((i*i)-1)%2==0) {
                if(((i*i)-1)/2>=i) {
                    int c=i*i-(((i*i)-1)/2);
                    if(c>=((i*i)-1)/2) {
                        answer++;
                    }
                }
            }
        }
        cout<<answer<<endl;
    }
}