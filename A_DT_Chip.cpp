#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> arr(n,vector<int> (m,1));
    while(q--) {
        int a,x1,y1,x2,y2;
        cin>>a>>x1>>y1>>x2>>y2;
        x1--;y1--;x2--;y2--;
        if(a==1) {            
            for(int i=x1;i<=x2;i++) {
                arr[i][y1]=0;
                arr[i][y2]=0;
            }
            for(int i=y1;i<=y2;i++) {
                arr[x1][i]=0;
                arr[x2][i]=0;
            }
        }
        else {
            bool ans=true;
            for(int i=x1;i<=x2;i++) {
                if(arr[i][y1]==0) {
                    ans=false;
                    break;
                }
            }
            for(int i=y1;i<=y2;i++) {
                if(arr[x2][i]==0) {
                    ans=false;
                    break;
                }
            }
            bool answer=true;
            for(int i=y1;i<=y2;i++) {
                if(arr[x1][i]==0) {
                    answer=false;
                    break;
                }
            }
            for(int i=x1;i<=x2;i++) {
                if(arr[i][y2]==0) {
                    answer=false;
                    break;
                }
            }
            if(ans||answer) {
                cout<<"YES"<<endl;
            }
            else {
                cout<<"NO"<<endl;
            }
        }
    }
}