#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin>>n;
    int sum1=0;
    int sum2=0;
    int sum3=0;
    while(n--) {
        int a;
        cin>>a;
        sum1+=a;
        int b;
        cin>>b;
        sum2+=b;
        int c;
        cin>>c;
        sum3+=c;
    }
    if(sum1==0&&sum2==0&&sum3==0) {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}