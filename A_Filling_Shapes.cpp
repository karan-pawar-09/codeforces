#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n; 
    (n%2)?(cout<<"0"<<endl):cout<<((int)(pow(2,(n/2))+.3))<<endl;
}