#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int i=0;
    while((k+(5*i))<=240&&i<=n){
        k+=(5*i);
        i++;
    }
    cout<<i-1;
}
