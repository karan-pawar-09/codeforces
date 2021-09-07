#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
long double calcRad(long double x0,long double x1,long double y0,long double y1) {
    return sqrt(abs((y1-y0)*(y1-y0))+abs((x1-x0)*(x1-x0)));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double x0,y0,xk,yk;
    long double n;
    long double PI=3.141592653589;
    cin>>n;
    cin>>x0>>y0;
    cin>>xk>>yk;
    long double x1=(x0+xk)/2;
    long double y1=(y0+yk)/2;
    long double theta=2*PI/n;
    long double r=calcRad(x0,x1,y0,y1);
    // long double x=x1+(x0-x1)*cos(theta)+(y1-y0)*sin(theta);
    // long double y=y1+(x0-x1)*sin(theta)+(y0-y1)*cos(theta);
    long double theta1=atan(abs((y0-y1)/(x0-x1)));
    if(((y0-y1)/(x0-x1))>=0) {
        if(y1>y0) {
            theta1+=PI;
        }
    }
    else {
        if(x1>x0) {
            theta1+=PI/2;
        }
        else {
            theta1+=3*PI/2;
        }
    }
    cout<<(long double)cos(5*PI/6)<<endl;
    long double angle=theta1+theta;    
    while(angle>=2*PI) {
        angle-=2*PI;
    }
    cout<<fixed;
    cout<<setprecision(11);

    cout<<r*cos(angle)+x1<<" "<<r*sin(angle)+y1;
    
}