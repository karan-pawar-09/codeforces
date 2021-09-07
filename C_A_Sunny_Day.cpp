#include<bits/stdc++.h>
using namespace std;
#define ll long long
int distance(int x1, int y1, int x2, int y2) 
{ 
    return (ceil((double)sqrt(pow(x2 - x1, 2) +  
                pow(y2 - y1, 2) * 1.0))); 
} 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> y(n);
    int a,b;
    for(int i=0;i<n;i++) {        
        cin>>x[i]>>y[i];
    }
    int min_distance=(int)1e9+5;
    for(int i=-100;i<=100;i++) {
        for(int j=-100;j<=100;j++) {
            int maxireq=0;
            for(int k=0;k<n;k++) {
               maxireq=max(maxireq,distance(i,j,x[k],y[k]));
            }
            min_distance=min(min_distance,maxireq);
        }
    }
    cout<< min_distance<<endl;
}