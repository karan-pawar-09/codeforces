#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isGood(long double t,vector<long double>x,vector<long double>v,ll n) {
    long double xmin=(x[0]-t*v[0]);
    long double xmax=(x[0]+t*v[0]);
    for(int i=1;i<n;i++) {
        if(xmin<(x[i]-t*v[i])) {
            xmin=(x[i]-t*v[i]);
        }
        if(xmax>(x[i]+t*v[i])) {
            xmax=(x[i]+t*v[i]);
        }
    }
    return xmin<=xmax;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<long double> x(n);
    vector<long double> v(n);
    for(int i=0;i<n;i++) {
        cin>>x[i]>>v[i];
    }
    long double l=0;
    long double r=1e10;
    for(int i=0;i<100;i++) {
        long double m=l+(r-l)/2;
        if(isGood(m,x,v,n)) {
            r=m;
        }
        else {
            l=m;
        }
    }
    cout<<setprecision(20);
    cout<<r<<endl;
}