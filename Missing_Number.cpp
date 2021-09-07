/*
author:Karan
created:07.06.2021 14:58:42
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int getMissingNo(int a[], int n)
{
    // xor of all the elements in array
    int x1 = a[0];
 
    // xor of all the elements from 1 to n
    int x2 = 1;
 
    for (int i = 1; i < n-1; i++)
        x1 = x1 ^ a[i];
 
    for (int i = 2; i <= n; i++)
        x2 = x2 ^ i;
 
    return (x1 ^ x2);
}
 
int main()
{
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0; i < n; i++)
        cin>>arr[i];
    
    int miss = getMissingNo(arr, n);
    cout << miss;
}