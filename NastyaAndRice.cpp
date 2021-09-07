#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,a,b,c,d;
        cin>>n>>a>>b>>c>>d;
        int maxGrn=(a+b)*n;
        int minSac=(c-d);
        int minGrn=(a-b)*n;
        int maxSac=(c+d);
        if((maxGrn<minSac)||(minGrn>maxSac)) {
            cout<<"No"<<endl;
        }
        else {
            cout<<"Yes"<<endl;
        }
    }
}