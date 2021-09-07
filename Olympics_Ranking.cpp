/*
author:Karan
created:12.08.2021 22:29:04
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

// bool greater_int(int g1,int s1,int b1,int g2,int s2,int b2 ) {
//     if(g1>g2) return true;
//     else if(g1==g2) {
//         if(s1>s2) return true;
//         else if(s1==s2) {
//             if(b1>b2) return true;
//         }
//     }
//     return false;
// }
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int g1,s1,b1,g2,s2,b2;
        cin>>g1>>s1>>b1>>g2>>s2>>b2;
        ((s1+g1+b1)>(s2+g2+b2))?cout<<"1"<<endl:cout<<"2"<<endl;
    }
}