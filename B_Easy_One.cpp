#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> arr(n,vector<ll> (m,0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    vector<ll> sumrows;
    vector<ll> sumcolumns;
    for(int i=0;i<n;i++) {
        ll sum=0;
        for(int j=0;j<m;j++) {
            sum+=arr[i][j];
        }
        sumrows.push_back(sum);
    }
    for(int j=0;j<m;j++) {
        ll sum=0;
        for(int i=0;i<n;i++) {
            sum+=arr[i][j];
        }
        sumcolumns.push_back(sum);
    }
    sort(all(sumrows));
    sort(all(sumcolumns));
    while(q--) {
        int l,r;
        cin>>l>>r;
        int no1=upper_bound(all(sumrows),r)-lower_bound(all(sumrows),l);
        int no2=upper_bound(all(sumcolumns),r)-lower_bound(all(sumcolumns),l);
        cout<<no1<<" "<<no2<<endl;
    }
}