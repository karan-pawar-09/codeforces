#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    string winner;
    if(a>b) {
        cout<<"Takahashi"<<endl;
    }
    else if(b>a) {
        cout<<"Aoki"<<endl;
    }
    else {
        if(c==0) {
            cout<<"Aoki"<<endl;
        }
        else {
            cout<<"Takahashi"<<endl;
        }
    }
}