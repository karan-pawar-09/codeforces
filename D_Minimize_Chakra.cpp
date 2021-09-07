#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll n,x,y;
        cin>>n>>x>>y;
        deque<int> a(n);
        deque<int>  b(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
        }
        int skip=0;
        ll price =0;
        
        for(int i=0;i<n;i++) {
            skip=0;
            for(int j=0;j<a.size();j++) {
                if(b[i]==a[j]) {
                    a.erase(a.begin(),a.begin()+j+1);
                    j=0;
                    if(skip==0) {
                        price+=0;
                    }
                    else if(skip==1) {
                        price+=min(x,y);
                    }
                    else{
                        price+=min(y,x*skip);
                    }
                    break;
                }
                else {
                    skip++;
                }
            }
        }
        cout<<price<<endl;
    }
}