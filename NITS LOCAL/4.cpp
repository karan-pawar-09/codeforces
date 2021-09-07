#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int m=0;int e=0;int o=0;int w=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='m') {
            m++;
        }
        else if (s[i]=='e') {
            e++;
        }
        else if (s[i]=='o') {
            o++;
        }
        else if(s[i]=='w'){
            w++;
        }
        int arr[m];
        int arr1[e];
        int arr2[o];
        int arr3[w];
        int sum=0;
        for(int i=1;i<=m;i++) {
            arr[i-1]=i;
        }
        for(int i=1;i<=e;i++) {
            arr1[i-1]=i;
        }
        for(int i=1;i<=o;i++) {
            arr2[i-1]=i;
        }
        for(int i=1;i<=w;i++) {
            arr3[i-1]=i;
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<e;j++) {
                for(int k=0;k<o;k++) {
                    for(int l=0;l<w;i++) {
                        if(arr1[j]>arr2[k]) {
                            // sum+=(arr[i]%1000000007*arr1[j]%1000000007*arr2[k]%1000000007*arr3[l]%1000000007)%1000000007;
                            // sum%1000000007;
                            sum+=arr[i]*arr1[j]*arr2[k]*arr3[l];
                        }
                    }
                }
            }
        }
        cout<<sum;
    }
}