
#include <bits/stdc++.h>
using namespace std;

long long negprod(long long arr[], long long n)
{
    long long  pos = 1, neg = 0;
    for (long long i = 0; i < n; i++) {
        if (arr[i] > 0)
            arr[i] = 1;
        else
            arr[i] = -1;

        if (i > 0)
            arr[i] *= arr[i - 1];


        if (arr[i] == 1)
            pos++;
        else
            neg++;
    }

    return (pos*neg);
}

int main()
{   long long n;cin>>n;
    long long arr[n] ;
    for(long long i=0;i<n;i++){cin>>arr[i];}
    long long k=(n*(n+1))/2;
    long long t = negprod(arr, n);
    cout<<t<<" ";
    cout << (k-t);

    return 0;
}
