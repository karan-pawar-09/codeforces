#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        vector<int>::iterator mn = min_element(arr.begin(), arr.end());
        int sum=0;
        for(vector<int>::iterator i=arr.begin();i!=arr.end();i++) {
            if(i!=mn) {
                while(*i+*mn<=k) {
                    *i+=*mn;
                    sum++;
                }
            }
        }
        cout<<sum<<"\n";
    }
}