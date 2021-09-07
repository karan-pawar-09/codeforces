/*
author:Karan
created:12.06.2021 17:45:43
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void partition(vector<int> &arr, int left, int right, int &i, int &j) {
   if (right - left <= 1) {
      if (arr[right] < arr[left])
         swap(arr[right], arr[left]);
      i = left;
      j = right;
      return;
    }
    int mid = left;
    int pivot = arr[right];
    while (mid <= right) {
        if (arr[mid]<pivot)
            swap(arr[left++], arr[mid++]);
            else if (arr[mid]==pivot)
                mid++;
            else if (arr[mid] > pivot)
                swap(arr[mid], arr[right--]);
    }
    i = left-1;
    j = mid;
}
void quicksort(vector<int> &arr, int left, int right) {
   if (left >= right) //1 or 0 elements
      return;
   int i, j;
   partition(arr, left, right, i, j);
   quicksort(arr, left, i);
   quicksort(arr, j, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}