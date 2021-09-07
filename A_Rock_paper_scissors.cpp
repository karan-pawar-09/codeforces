/*
author:Karan
created:06.06.2021 17:40:13
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
    int x,y;
    cin>>x>>y;
    if(x==y) {
        cout<<x<<endl;
    }   
    else {
        for(int i=0;i<3;i++) {
            if(i!=x&&i!=y) {
                cout<<i<<endl;
                break;
            }
        }
    }
}