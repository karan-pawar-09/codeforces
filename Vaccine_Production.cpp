#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d1,v1,d2,v2,p;
    cin>>d1>>v1>>d2>>v2>>p;
    int day=0;
    int vacc=0;
    while(vacc<p) {
        day++;
        if(d1<=day) {
            vacc+=v1;
        }
        if(d2<=day) {
            vacc+=v2;
        }        
    }
    cout<<day<<endl;
}