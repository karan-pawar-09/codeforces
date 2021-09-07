#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define endl '\n'
 
int n, m;
vector<vector<char>> arr;
vector<vector<bool>> visited;
vector<vector<bool>> visitedFinal;
vector<vector<char>> path;
vector<vector<int>> distM;
queue<pair<int, int>> ms;
pair<int, int> start;
vector<vector<int>> timeofus;
int a[4] = {-1, 0, 1, 0};
int b[4] = {0, 1, 0, -1};

bool isGood(int i, int j) {
    if (i < 0 || j >= m || i >= n || j < 0) {
        return false;
    }
    if (arr[i][j] == '#') {
        return false;
    }
    if (visited[i][j]) {
        return false;
    }
    return true;
}
bool isGood(int i, int j,int time) {
    if (i < 0 || j >= m || i >= n || j < 0) {
        return false;
    }
    if (arr[i][j] == '#') {
        return false;
    }
    if (visited[i][j]) {
        return false;
    }
    if(time>=distM[i][j]) {
        return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;    
    arr.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    path.resize(n, vector<char>(m, '#'));
    distM.resize(n,vector<int>(m,(int)1e9));
    timeofus.resize(n,vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'M') {
                arr[i][j] = '.';
                visited[i][j]=true;
                distM[i][j]=0;
                ms.push({i, j});
            }
            if (arr[i][j] == 'A') {
                arr[i][j] = '.';
                start = {i, j};
            }
        }
    }
    while(!ms.empty()) {
        pair<int,int> v;
        v=ms.front();
        ms.pop();
        visited[v.first][v.second]=true;
        for(int i=0;i<4;i++) {
            int p=v.first+a[i];
            int q=v.second+b[i];
            if(isGood(p,q)) {
                visited[p][q]=true;
                ms.push({p,q});
                distM[p][q]=distM[v.first][v.second]+1;
            }
        }
    }     
    queue<pair<int,int>> q;
    q.push(start);
    fill(all(visited),vector<bool>(m,false));
    visited[start.first][start.second]=true;
    path[start.first][start.second]='#';
    timeofus[start.first][start.second]=0;
    while(!q.empty()) {
        pair<int,int> u=q.front();
        q.pop();
        char c[4]={'U','R','D','L'};
        for(int i=0;i<4;i++) {
            pair<int,int> v=make_pair(u.first+a[i],u.second+b[i]);
            if(isGood(v.first,v.second,timeofus[u.first][u.second]+1)) {
                visited[v.first][v.second]=true;
                path[v.first][v.second]=c[i];
                q.push(v);
                timeofus[v.first][v.second]=timeofus[u.first][u.second]+1;
            }
        }
    }
    pair<int,int> end;
    bool found=false;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i==0||j==0||i==n-1||j==m-1) {
                if(visited[i][j]) {
                    end={i,j};
                    found=true;
                    break;
                }
            }
        }
        if(found) {
            break;
        }
    }
    string ans;
    if(found&&visited[end.first][end.second]) {
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
        reverse(all(ans));
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
    
}