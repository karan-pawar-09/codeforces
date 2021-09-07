#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,d;
        cin>>n>>d;
        vector<int>arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int risk=0;
        int notrisk=0;
        for(int i=0;i<n;i++) {
            if(arr[i]<=9||arr[i]>=80) {
                risk++;
            }
            else {
                notrisk++;
            }
        }
        if(risk==0||notrisk==0) {
            cout<<ceil((float)n/d)<<endl;
        }
        else {
            cout<<ceil((float)risk/d)+ceil((float)notrisk/d)<<endl;
        }
    }
}