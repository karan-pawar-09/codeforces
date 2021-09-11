#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n;
    int maxtime;
    pair<ll,ll> start,end;
    vector<string> arr(n);
    for(ll i=0;i<n;i++) {        
        cin>>arr[i];
    }
    cin>>maxtime;
    m=arr[0].size();
    start={0,0};
    end={n-1,m-1};
    queue<pair<ll,ll>> q;
    vector<vector<bool>> used(n,vector<bool> (m,false));
    vector<vector<char>> path(n,vector<char> (m,'#'));
    vector<vector<int>> time(n,vector<int> (m,0));
    path[start.first][start.second]='#';
    used[start.first][start.second]=true;
    q.push({start.first,start.second});
    while(q.size()) {
        pair<ll,ll> u=q.front();
        q.pop();
        ll a[4]={-1,0,1,0};
        ll b[4]={0,1,0,-1};
        char c[4]={'U','R','D','L'};
        for(ll i=0;i<4;i++) {
            pair<ll,ll> v=make_pair(u.first+a[i],u.second+b[i]);
            if(v.first<0||v.first>=n||v.second<0||v.second>=m) {
                continue;
            }
            if(arr[v.first][v.second]=='#') {
                continue;
            }
            if(used[v.first][v.second]) {
                continue;
            }
            used[v.first][v.second]=true;
            path[v.first][v.second]=c[i];
            time[v.first][v.second]=time[u.first][u.second]+1;
            q.push(v);
        }             
    }
    if(used[end.first][end.second]) {
        if(time[end.first][end.second]<=maxtime) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    else {
        cout<<"NO"<<endl;
    }
}