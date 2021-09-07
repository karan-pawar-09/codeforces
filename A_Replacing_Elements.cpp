#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,d;
        cin>>n>>d;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        bool magic=false;
        if(arr[0]+arr[1]<=d){
            magic=true;
        }
        bool already=true;
        for(int i=0;i<n;i++) {
            if(arr[i]>d) {
                already=false;
            }
        }
        if(already||magic) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}