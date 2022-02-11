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
    vector<ll> v;
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
    randomTest.n = randomNumber(1,10);
    randomTest.v = randomArray(randomTest.n,10);
    return randomTest;
}


bool bruteForce(testcase T) {
    ll n=T.n;
    vector<ll> arr=T.v;
    ll odd=0,even=0;
    ll indx=0;
    for(ll i=0;i<n;i++) {
        if(arr[i]%2) {
            indx=i+1;
            odd++;
        } else {
            even++;
        }
    }
    if(odd==0) {
        return false;
    }
    return true;
}

bool optimizedSolution(testcase T) {
    ll n=T.n;
    vector<ll> arr=T.v;
    ll odd=0,even=0;
    ll indx=0;
    for(ll i=0;i<n;i++) {
        if(arr[i]%2) {
            indx=i+1;
            odd++;
        } else {
            even++;
        }
    }
    if(odd==0) {
        return false;
    }
    ll res=0;
    ll res1=0;
    for(ll i=0;i<n;i++) {
        if(i%2==0) {
            if(arr[i]%2) {
                res++;
            }
        } else {
            if(arr[i]%2==0) {
                res++;
            }
        }
    }
    for(ll i=0;i<n;i++) {
        if(i%2) {
            if(arr[i]%2) {
                res1++;
            }
        } else {
            if(arr[i]%2==0) {
                res1++;
            }
        }
    }
    // cout<<min(res1,res)<<endl;
    vector<pair<ll,ll>> ar;
     if(res<=res1) {        
        for(ll i=0;i<n;i++) {
            if(i%2==0) {
                if(arr[i]%2) {
                    if(i<=1) {
                        ar.push_back({i+1,indx});
                    } else {
                        ar.push_back({i+1,2});
                    }
                }
            } else {
                if(arr[i]%2==0) {
                    if(i<=1) {
                        ar.push_back({i+1,indx});
                    } else {
                        ar.push_back({i+1,2});
                    }
                }
            }
        }
    } else {
        for(ll i=0;i<n;i++) {
            if(i%2) {
                if(arr[i]%2) {
                    if(i<1) {
                        ar.push_back({i+1,indx});
                    } else {
                        ar.push_back({i+1,1});
                    }
                }
            } else {
                if(arr[i]%2==0) {
                    if(i<1) {
                        ar.push_back({i+1,indx});
                    } else {
                        ar.push_back({i+1,1});
                    }
                }
            }
        }
    }
    // assert(ar.size()==min(res,res1));
    for(auto x:ar) {
        arr[x.first-1]=arr[x.first-1] ^ arr[x.second-1];
        // cout<<x.first<<" "<<x.second<<endl;
    }
    bool ans=true;
    for(ll i=0;i<n-1;i++) {
        if((arr[i]|arr[i+1])%2 == (arr[i]&arr[i+1])%2) {
            ans=false;
            break;
        }
    }
    return ans;
}

bool debugger(ll &t){
    testcase random = generateTestCase();
    // cout<<random.s<<" ";
    bool answ1 = bruteForce(random);
    bool answ2 = optimizedSolution(random);
    if(answ1 != answ2) {
        cout<<"WA on testcase "<<t<<endl;
        cout<<random.n<<endl;
        for(auto x:random.v) {
            cout<<x<<" ";
        }
        cout<<endl;
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