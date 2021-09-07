#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    pair<ll,ll> start,end;
    vector<vector<char>> arr(n,vector<char> (m,0));
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) {
            cin>>arr[i][j];        
            if(arr[i][j]=='A') {
                start={i,j};
                arr[i][j]='.';
            }
            if(arr[i][j]=='B') {
                end={i,j};
                arr[i][j]='.';
            }
        }
    }
    queue<pair<ll,ll>> q;
    vector<vector<bool>> used(n,vector<bool> (m,false));
    vector<vector<char>> path(n,vector<char> (m,'#'));
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
            q.push(v);
        }             
    }
    string ans;
        if(used[end.first][end.second]) {
            for(ll i=end.first,j=end.second;path[i][j]!='#';) {
                ans+=path[i][j];
                if(path[i][j]=='U') {
                    i++;
                }
                else if(path[i][j]=='L') {
                    j++;
                }
                else if(path[i][j]=='D') {
                    i--;
                }
                else if(path[i][j]=='R') {
                    j--;
                }
                else {
                    break;
                }
            }
        }
        reverse(all(ans));
    if(used[end.first][end.second]) {
        cout<<"YES"<<endl;   
        system("Color 0A");
        cout<<ans.size()<<endl<<ans<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}

