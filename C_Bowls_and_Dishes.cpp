#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

multiset<int> balls;
int ans=0;

void recurse(int index,vector<int>c,vector<int>d,vector<int>A,vector<int>B,int k,int m) {
    if(index==k) {
        int temp=0;
        for(int i=0;i<m;i++) {            
            if(balls.count(A[i])&&balls.count(B[i])) {
                temp++;
            }
        }
        ans=max(temp,ans);
        return;
    }
    balls.insert(c[index]);
    recurse(index+1,c,d,A,B,k,m);
    balls.erase(balls.find(c[index]));
    balls.insert(d[index]);
    recurse(index+1,c,d,A,B,k,m);
    balls.erase(balls.find(d[index]));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int>A(m);
    vector<int>B(m);
    for(int i=0;i<m;i++) {
        cin>>A[i]>>B[i];
    }
    int k;
    cin>>k;
    vector<int>c(k);
    vector<int>d(k);
    for(int i=0;i<k;i++) {
       cin>>c[i]>>d[i];
    }
    recurse(0,c,d,A,B,k,m);
    cout<<ans<<endl;
}