/*
author:Karan
created:23.08.2021 22:20:42
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'



//------------------------------------------------------------------------------------------------------------//
struct testcase{
    ll n;
    ll a;
    ll b;
};

ll randomNumber(ll a,ll b){    
    return a + (rand() % b);
}

string randomString(const ll len) {    
    string tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    srand( (unsigned) time(NULL) * getpid());
    tmp_s.reserve(len);
    for (ll i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];    
    
    return tmp_s;    
}

vector<vector<ll>> randomMatrix(const ll n) {
    srand( time(0));
    vector<vector<ll>> ans(n);   
    for(ll i=0;i<n;i++) {
        ll p=randomNumber(1,9);
        ans[i].push_back(p);
        for(ll j=0;j<p;j++) {
            ll q=randomNumber(1,10);
            ans[i].push_back(q);           
        }       
    }

    return ans;
}
vector<ll> randomArray(const ll n) {
    srand(time(0));
    vector<ll> ans(n);
    for(ll i=0;i<n;i++) {
        ll p=randomNumber(1,10);
        ans[i]=p;
    }
    return ans;
}
testcase generateTestCase(){
    srand( time(0));
    testcase randomTest;
    randomTest.n = randomNumber(1,1e3);
    randomTest.a = randomNumber(1,1e3);
    randomTest.b = randomNumber(1,1e3);
    return randomTest;
}


ll bruteForce(testcase T){
    ll a=T.a;
    ll b=T.b;
    ll n=T.n;
    ll ans=1e9+7;
    for(ll i=0;i<=n;i++) {
        ans=min(ans,max(i*a,(n-i)*b));
    }
    return ans;
}

ll optimizedSolution(testcase T){
    ll a=T.a;
    ll b=T.b;
    ll n=T.n;
    ll time=0;
    ll i=0 , curr = 0;  
    while(curr<n)
    {
        i++;
        curr = (i/a) + (i/b);
    }
    return i;
}

bool debugger(ll &t){
    testcase random = generateTestCase();
    ll ans1 = bruteForce(random);
    ll ans2 = optimizedSolution(random);
    if(ans1 != ans2) {
        cout<<"WA on testcase "<<t<<endl;
        // for(ll i=0;i<random.arr.size();i++) {
        //     for(ll j=0;j<random.arr.size();j++) {
        //         cout<<random.arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        cout<<random.n<<" -> "<<random.a<<" "<<random.b<<endl;
        return false;
    }
    else {
        cout<<"AC on testcase "<<t<<endl;
        return true;
    }
}


bool solve(ll &t){
    if(!debugger(t)) {
        return false;
    }
    else {
        return true;
    }
}

int32_t main() {
    ll t;
    cin>>t;
    for(ll i=1;i<=t;i++) {
        if(!solve(i)) break;
    }
    return 0;
}