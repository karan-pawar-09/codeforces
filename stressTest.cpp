/*
author:Karan
created:23.08.2021 22:20:42
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'



stack<ll> calc(stack<ll> a, ll k) {
    stack<ll> temp;
    temp.push(k);
    if(a.size()) {
        ll p = a.top();    
        temp.push(p);
    }
    return temp;
}
stack<ll> calc1() {
    stack<ll> st;
    return st;
}



ll find(vector<ll> arr) {
    ll n = arr.size();
    stack<ll> str, stl;
    set<ll> ans;
    ll maxi = 0;
    if(arr[n-1] > arr[n-2]) {
        stl.push(arr[n-2]);
        maxi = arr[n-1];
        ans.insert(arr[n-1]- arr[n-2]);
    } else {
        str.push(arr[n-1]);
        maxi = arr[n-2];
        ans.insert(arr[n-2] - arr[n-1]);
    }
    for(int i=n-3;i>=0;i--) {
        if(arr[i] >= maxi) {
            ans.insert(arr[i] - maxi);
            while(stl.size()) {
                ans.insert(arr[i] - stl.top());
                stl.pop();
            }
            maxi = arr[i];
        } else {
            while(stl.size() && arr[i] >= stl.top()) {
                ans.insert(arr[i] - stl.top());
                stl.pop();
            }
            if(stl.size()) {
                ans.insert(stl.top() - arr[i]);
            } else {
                ans.insert(maxi - arr[i]);
            }
            stl.push(arr[i]);
        }
    }
   return ans.size();
}


//------------------------------------------------------------------------------------------------------------//
struct testcase {
    ll n;
    vector<ll> arr;
};

ll randomNumber(ll a, ll b) {
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
        if (i == 0) {
            tmp_s += alphanum[rand() % (sizeof(alphanum) - 2)];
        }
        else
            tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

vector<vector<ll>> randomMatrix(const ll n) {
    srand(time(0));
    vector<vector<ll>> ans(n);
    for (ll i = 0;i < n;i++) {
        ll p = randomNumber(1, 9);
        ans[i].push_back(p);
        for (ll j = 0;j < p;j++) {
            ll q = randomNumber(1, 10);
            ans[i].push_back(q);
        }
    }

    return ans;
}
vector<ll> randomArray(const ll n, ll x) {
    vector<ll> ans(n);
    for (ll i = 0;i < n;i++) {
        ll p = randomNumber(1, x - 1);
        // ll x=randomNumber(0,2);   //for -ve no
        // if(x==0) p=-p;
        ans[i] = p;
    }
    return ans;
}
testcase generateTestCase() {
    testcase randomTest;
    randomTest.n = randomNumber(2, 10);
    randomTest.arr = randomArray(randomTest.n, 10);
    return randomTest;
}


ll  bruteForce(testcase T) {
    ll n = T.n;
    vector<ll> arr = T.arr;
    set<int> s;
    for(ll i=0;i<n-1;i++) {
        for(ll j=i+1;j<n;j++) {
            ll maxi = 0;
            ll secondmaxi = 0;
            for(ll k = i; k <= j;k++) {
                if(arr[k] >= maxi) {
                    secondmaxi = maxi;
                    maxi = arr[k];
                } else {
                    secondmaxi = max(secondmaxi, arr[k]);
                }
            }
            //cout<<i<<" "<<j<<" -> "<<maxi<<" "<<secondmaxi<<endl;
            s.insert(maxi-secondmaxi);
        }
    }
    return s.size();
}

ll  optimizedSolution(testcase T) {
    ll n = T.n;
    vector<ll> arr = T.arr;
    ll temp = find(arr);
    
    return temp;
}

bool debugger(ll& t) {
    testcase random = generateTestCase();
    // cout<<random.s<<" ";
    ll  answ1 = bruteForce(random);
    ll  answ2 = optimizedSolution(random);
    if (answ1 != answ2) {
        cout << "WA on testcase " << t << endl;
        
        cout<<answ1<<" "<<answ2<<endl;
        cout<<random.n<<endl;
        for(auto x: random.arr) {
            cout<<x<<" ";
        }
        return false;
    }
    else {
        cout << "AC on testcase " << t << endl;
        cout << endl;
        return true;
    }
}


bool solve(ll& t) {
    if (!debugger(t)) {
        return false;
    }
    else {
        return true;
    }
}

int32_t main() {
    ll t;
    cin >> t;
    for (ll i = 1;i <= t;i++) {
        if (!solve(i)) break;
    }
    return 0;
}