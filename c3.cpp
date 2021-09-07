#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
    int n,k;
    cin>>n>>k;
    int arr[n];
    int sum[n/2];
    int ww=0;
    int i=0,j=n-1;
        while(i<=j) {
            sum[i]=arr[i]+arr[j];
            if()
            i++;j++;
        }

      //  int ans[2*k]={0};
      
        vector<int> ans((2*k),0);
        for(int q=0;q<n/2;q++) {
            ans[sum[q]]++;
        }
        int r=*(max_element(ans.begin(),ans.end()));

    }
}