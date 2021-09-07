#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,b,g;
    cin>>n>>g>>b;
    vector<int>arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<int>myarr;
    double r=b;
    int no=1;
    int ans=0;
    while(no&&r<=(double)g) {
        no=0;
        sort(arr.begin(),arr.end());
        for(int i=n-1;i>=0;i--) {
            if(r>arr[i]) {
                no++;
                myarr.push_back(arr[i]);
                arr[i]=g+2000;
                break;
            }
        }
        int sum=0;
        for(int i=0;i<myarr.size();i++) {
            sum+=myarr[i];
        }
        r=((double)sum/myarr.size())+400;
        ans++;
    }
    if(r>(double)g) {
        cout<<ans<<endl;
    }
    else {
        cout<<"-1"<<endl;
    }
}