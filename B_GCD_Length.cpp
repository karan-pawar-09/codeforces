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
        int a,b,c;
        cin>>a>>b>>c;
        string ansa="1";
        string ansb="1";
        for(int i=0;i<a-1;i++){
            ansa+="0";
        }
        for(int i=0;i<b-1;i++) {
            ansb+="0";
        }
        ansa[a-c]='1';
        cout<<ansa<<" "<<ansb<<endl;
    }
}