#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
bool isFine(long double a,long double c) {
    return a*a+sqrt(a)>=c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double c;
    cin>>c;
    long double l=0;
    long double r=1e10;
    for(int i=0;i<100;i++) {
        long double m=l+(r-l)/2;
        if(isFine(m,c)) {
            r=m;
        }
        else{
            l=m;
        }
    }
    cout<<setprecision(20);
    cout<<r<<endl;
}