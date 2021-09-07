#include<bits/stdc++.h>
using namespace std;
int eea(int a,int b,int &x,int &y) {
    if(b==0) {
        x=1;
        y=0;
        return a;
    }   
    int xa,ya;
    int d=eea(b,a%b,xa,ya);
    x=ya;
    y=xa-ya*(a/b);
    return d;
    
}
int main() {
    int x,y;
    int gcd=eea(23,100,x,y);
    cout<<(x%100+100)%100<<endl;
}