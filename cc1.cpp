#include <iostream> 
#include <vector> 
using namespace std;
int main() {
    int n;
    cin>>n;
    int nv=0;
    int pv=0;
    vector<int> a;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        a.push_back(k);
    }
    for(int i=1;i<n;i++){
        for(int j=(i-1);j>=0;j--){
            if(a[i]<a[j]){
                a[j]=0;
            }      
        }
    }
    int ans =0;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            ans++;
        }
    }
    cout<<ans;
} 