#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    const int inf=1e9+7;
    
    int x[8]={1,1,2,2,-1,-1,-2,-2};
    int y[8]={-2,2,1,-1,2,-2,-1,1};
    
    bool isGood(int i,int j,vector<vector<bool>> &visited,int N) {
        if(i<1||i>N||j<1||j>N||visited[i][j]) return false;
        return true;
    }

    void bfs(int i,int j,vector<vector<bool>> &visited,vector<vector<int>> &dist,int N) {
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        while(q.size()) {
            pair<int,int> p=q.front();
            q.pop();
            for(int ii=0;ii<8;ii++) {
                int ix=p.first+x[ii];
                int jy=p.second+y[ii];
                if(isGood(ix,jy,visited,N)) {
                    visited[ix][jy]=true;
                    q.push({ix,jy});
                    dist[ix][jy]=dist[p.first][p.second]+1;
                }
            }
        }
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<bool>> visited(N+1,vector<bool> (N+1,false));
	    vector<vector<int>> dist(N+1,vector<int> (N+1,inf));
	    dist[KnightPos[0]][KnightPos[1]]=0;
	    // for(int i=0;i<=N;i++) {
	    //     for(int j=0;j<=N;j++) {
	    //         cout<<dist[i][j]<<" ";
	    //     }
	    //     cout<<endl;
	    // }
        bfs(KnightPos[0],KnightPos[1],visited,dist,N);
	    return dist[TargetPos[0]][TargetPos[1]];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}