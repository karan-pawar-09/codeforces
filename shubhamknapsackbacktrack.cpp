/*
author:Karan
created:29.06.2021 21:37:43
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

struct item {
    int cost;
    int weight;
};

vector<int> ans;

int Knapsack(struct item arr[],int cap,int n) {
    int dp[n+1][cap+1];
    item ar[n+1][cap+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=cap;j++) {
            dp[i][j]=0;
            ar[i][j]={0,0};
        }
    }
    ar[0][0]={-1,-1};
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=cap;j++) {
            dp[i][j] = dp[i-1][j];
            ar[i][j]={i-1,j};
            if(j>=arr[i-1].weight) {
                int ans =  dp[i-1][j-arr[i-1].weight] + arr[i-1].cost ;
                if(ans>dp[i-1][j]) {
                    dp[i][j] = ans;
                    ar[i][j]={i-1,j-arr[i-1].weight};
                }
            }

        }
    }
    for(item i=ar[n][cap];;i=ar[i.cost][i.weight]) {
        if(i.weight==-1&&i.cost==-1) {
            break;
        }
        if(i.weight!=ar[i.cost][i.weight].weight+1) {
            if(dp[i.cost][i.weight]-dp[ar[i.cost][i.weight].cost][ar[i.cost][i.weight].weight]!=0)
            ans.push_back(dp[i.cost][i.weight]-dp[ar[i.cost][i.weight].cost][ar[i.cost][i.weight].weight]);
        }
    }
    return dp[n][cap];

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int cap;
    cin>>cap;
    int n;   cin>>n;    //No. of items
    item arr[n];
    for(int i=0;i<n;i++)
        cin>> arr[i].cost>>arr[i].weight;
    
    cout<<Knapsack(arr,cap,n)<<endl;
    for(auto x:ans) {
        cout<<x<<" ";
    }
    cout<<endl;
}
