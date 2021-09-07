#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r;
    long double x,y;
    cin>>r;
    cin>>x>>y;
    long double dist=sqrt((x*x)+(y*y));
    long double a=dist/r;
    int k=ceil(dist);
    if(dist<r) {
        cout<<"2"<<endl;
    }
    else {
        cout<<ceil(a)<<endl;
    }    
} 