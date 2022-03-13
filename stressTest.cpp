/*
author:Karan
created:23.08.2021 22:20:42
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


vector<ll> getFinalElement(vector<ll> arr) {
    stack<ll> s;
    ll n = arr.size();
    for (ll i = 0;i < n;i++) {
        if (arr[i] > 0) {
            s.push(arr[i]);
        }
        else {
            while (s.size() and s.top() < abs(arr[i]) and s.top() >= 0) {
                s.pop();
            }
            if (s.size() and s.top() == abs(arr[i])) s.pop();
            else if (s.size() == 0 or (s.size() and s.top() < 0)) {
                s.push(arr[i]);
            }
        }
    }
    vector<ll> ans;
    while (s.size()) {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<ll> getFinalElementShu(vector<ll>arr) {
    stack<ll>s;
    for (ll i = 0;i < arr.size();i++)
    {
        while (1)
        {
            if (s.size() == 0)
            {
                s.push(arr[i]);
                break;
            }
            ll x = s.top();
            if (!(x > 0 && arr[i] < 0))
            {
                s.push(arr[i]);
                break;
            }
            else
            {
                if (abs(x) > abs(arr[i]))
                    break;
                else if (abs(x) == abs(arr[i]))
                {
                    s.pop();
                    break;
                }
                else
                {

                    s.pop();
                }
            }
        }
    }
    vector<ll>ans;
    while (!s.empty())
    {
        ll x = s.top();
        s.pop();
        ans.push_back(x);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//------------------------------------------------------------------------------------------------------------//
struct testcase {
    ll n;
    vector<ll> v;
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
    randomTest.n = randomNumber(1, 10);
    randomTest.v = randomArray(randomTest.n, 10);
    return randomTest;
}


vector<ll>  bruteForce(testcase T) {
    ll n = T.n;
    vector<ll> arr = T.v;
    return  getFinalElement(arr);
}

vector<ll>  optimizedSolution(testcase T) {
    ll n = T.n;
    vector<ll> arr = T.v;
    return getFinalElementShu(arr);
}

bool debugger(ll& t) {
    testcase random = generateTestCase();
    // cout<<random.s<<" ";
    vector<ll>  answ1 = bruteForce(random);
    vector<ll>  answ2 = optimizedSolution(random);
    if (answ1 != answ2) {
        cout << "WA on testcase " << t << endl;
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