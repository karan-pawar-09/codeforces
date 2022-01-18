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
    string s;
};

ll randomNumber(ll a,ll b) {    
    return a + (rand() % b);
}

string randomString(const ll len) {   
 
    string tmp_s;
    static const char alphanum[] =
        "1234567890";
        // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        // "abcdefghijklmnopqrstuvwxyz";
    
    // srand( (unsigned) time(NULL) * getpid());
    tmp_s.reserve(len);
    for (ll i = 0; i < len; ++i) {
        if(i==0) {
            tmp_s += alphanum[rand() % (sizeof(alphanum) - 2)];
        }
        else
            tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];    
    }
    
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
vector<ll> randomArray(const ll n, ll x) {
    vector<ll> ans(n);
    for(ll i=0;i<n;i++) {
        ll p=randomNumber(1,x-1);
        ans[i]=p;
    }
    return ans;
}
testcase generateTestCase() {
    testcase randomTest;
    randomTest.n = randomNumber(2,15);
    randomTest.s = randomString(randomTest.n);
    return randomTest;
}


ll bruteForce(testcase T) {
    string s=T.s;
    ll n=s.size();
    set<ll,greater<ll>> ans;
    for(ll i=0;i<n-1;i++) {
        ll a=s[i]-'0';
        ll b=s[i+1]-'0';
        string mid=to_string(a+b);
        ans.insert(stoll(s.substr(0,i)+mid+s.substr(i+2)));
    }
    return *ans.begin();
}

ll optimizedSolution(testcase T) {
    string s=T.s;
    ll n=s.size();
    bool done=false;
    for(ll i=n-2;i>=0;i--) {
        ll a=s[i]-'0';
        ll b=s[i+1]-'0';
        if((a+b)>=10) {
            string temp=to_string(a+b);
            s[i]=temp[0];
            s[i+1]=temp[1];
            done=true;
            break;
        }
    }
    ll index=0;
    if(!done) {
        ll a=s[0]-'0';
        ll b=s[1]-'0';
        s[1]=to_string(a+b)[0];
        return stoll(s.substr(1));
    } else {
        return stoll(s);
    }
}

bool debugger(ll &t){
    testcase random = generateTestCase();
    // cout<<random.s<<" ";
    ll answ1 = bruteForce(random);
    ll answ2 = optimizedSolution(random);
    if(answ1 != answ2) {
        cout<<"WA on testcase "<<t<<endl;
        cout<<random.s<<endl;
        cout<<answ1<<" "<<answ2<<endl;
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