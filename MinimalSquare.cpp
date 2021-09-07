#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b;
        cout<<max((2*(min(a,b)))*(2*(min(a,b))),max(a,b)*max(a,b))<<endl;
    }
}