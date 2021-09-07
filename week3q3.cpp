/*
authot:Karan
created:21.05.2021 15:15:17
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d,m,n;
    cin>>d;
    cin>>m;
    cin>>n;
    vector<int> arr(n);
    vector<bool> station(1e5+7,false);
    for(int i=0;i<n;i++) {
        cin>>arr[i]; 
        station[arr[i]]=true;
    }
    int dist=0;
    int index=0;
    bool ans=true;
    int no=0;
    while(dist<d) {
        int l=dist;
        int r=dist+m;
        int i=r;
        if(r>=d) {
            break;
        }
        for(i;i>l;i--) {
            if(station[i]==true) {
                dist=i;
                no++;
                break;
            }
        }
        if(i==l) {
            ans=false;
            break;
        }
    }
    ans?cout<<no:cout<<-1<<endl;
}