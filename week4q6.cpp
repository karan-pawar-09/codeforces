/*
author:Karan
created:13.06.2021 11:01:48
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

class Point
{
    public:
    ll x, y;
};

int compareX(const void* a, const void* b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}
long double dist(Point p1, Point p2) {
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                (p1.y - p2.y)*(p1.y - p2.y)
            );
}
 
long double bruteForce(Point P[], ll n)
{
    long double min = FLT_MAX;
    for (ll i = 0; i < n; ++i)
        for (ll j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

long double min(long double x, long double y) {
    return (x < y)? x : y;
}
long double stripClosest(Point strip[], ll size, long double d) {
    long double min = d;  
    qsort(strip, size, sizeof(Point), compareY);
    for (ll i = 0; i < size; ++i)
        for (ll j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
    return min;
}
long double closestUtil(Point P[], ll n) {
    if (n <= 3)
        return bruteForce(P, n);
    ll mid = n/2;
    Point midPoint = P[mid];
    long double dl = closestUtil(P, mid);
    long double dr = closestUtil(P + mid, n - mid);
    long double d = min(dl, dr);
    Point strip[n];
    ll j = 0;
    for (ll i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;
    return min(d, stripClosest(strip, j, d) );
}

long double closest(Point P[], ll n) {
    qsort(P, n, sizeof(Point), compareX);
    return closestUtil(P, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll s,p,a,b;
    cin>>s;
    Point arr[s];
    for(ll i=0;i<s;i++) {
        cin>>a>>b;
        arr[i]={a,b};
    }
    cout<<setprecision(10);
    cout<<fixed;
    cout<<(long double)closest(arr,s);
}