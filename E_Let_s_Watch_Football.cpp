#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    int ans;
    int total=a*c;
    ans=ceil((float)total/b);
    cout<<ans-c<<endl;
}