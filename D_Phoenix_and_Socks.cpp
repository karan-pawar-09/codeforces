/*
author:Karan
created:28.05.2021 10:45:05
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,l,r;
        cin>>n>>l>>r;
        vector<int> c(n);
        vector<int> left(n+1);
        vector<int> right(n+1);
        for(int i=0;i<n;i++) {
            cin>>c[i];
            if(i<l) {
                left[c[i]]++;
            }
            else {
                right[c[i]]++;
            }
        }
        int cost=0;
        for(int i=0;i<=n;i++) {
            int mn=min(left[i],right[i]);
            left[i]-=mn;
            right[i]-=mn;
            l-=mn;
            r-=mn;
        }
        if (l<r){
            swap(left,right);
            swap(l,r);
        }
        for(int i=0;i<=n;i++) {
            int diff=min((left[i]/2)*2,l-r);
            cost+=diff/2;
            l-=diff;
        }
        cost+=(l-r)/2+(l+r)/2;
        cout<<cost<<endl;
    }
}