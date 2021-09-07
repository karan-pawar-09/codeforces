#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++) 

int maxSubArraySum(int a[], int size) 
{ 
    int max1 = INT_MIN, max2 = 0; 
  
    fo(i,size) 
    { 
        max2 = max2 + a[i]; 
        if (max1 < max2) 
            max1 = max2; 
  
        if (max2 < 0) 
            max2 = 0; 
    } 
    return max1; 
} 

int main() {
    int n;
    cin>>n;
    int arr[n];
    int ar[n]; 
    int sum=0;
    fo(i,n) {
        cin>>arr[i];
        if(arr[i]==0) {
            ar[i]=1;
        }
        else {
            ar[i]=-1;
        }
        sum+=arr[i];
    }
int a= maxSubArraySum(ar,n);
cout<<a+sum;  
    
    
}