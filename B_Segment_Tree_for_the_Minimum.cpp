/*
author:Karan
created:04.09.2021 13:30:13
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

struct item{
    int m,c;
};

struct segtree {
	int size;
	vector<item> arr;
    item merge(item item1 , item item2) {
        if(item1.m < item2.m) {
            return item1;
        }
        else if(item1.m > item2.m) {
            return item2;
        }
        else {
            return {item1.m,item1.c+item2.c};
        }
    }
    item single(int v) {
        return {v,1};
    }
    item NEUTRAL_ELM={INT_MAX,0};

	void init(int n) {
		size=1;
		while(size<n) size*=2;
		arr.assign(2*size,0);
	}	
	void build(vector<int> &a,int x,int lx,int rx) {
		if(rx - lx == 1) {
			if(lx < (int)a.size()) {
				arr[x]=single(a[lx]);
			}
			return;
		}
		int m=lx+(rx-lx)/2;
		build(a,2*x+1,lx,m);
		build(a,2*x+2,m,rx);
		arr[x]=merge(arr[2*x+1],arr[2*x+2]);
	}
	void build(vector<int> &a) {
		build(a,0,0,size);
	}	
	void set(int i,int v, int x,int lx,int rx) {
		if(rx-lx == 1) {
			arr[x]=single(v);
			return;
		}
		int m=lx+(rx-lx)/2;
		if(i<m) {
			set(i,v,2*x+1,lx,m);
		}
		else {
			set(i,v,2*x+2,m,rx);
		}
		arr[x]=merge(arr[2*x+2],arr[2*x+1]);
	}
	void set(int i, int v) {
		set(i,v,0,0,size);
	}	
	item sum(int l,int r, int x, int lx ,int rx) {
		if(l>=rx or r<=lx) return NEUTRAL_ELM;
		else if(l<=lx and r>=rx) return arr[x];
		int m = lx+(rx-lx)/2;
		item sum1 = sum(l,r,2*x+1,lx,m);
		item sum2 = sum(l,r,2*x+2,m,rx);
		return merge(sum1,sum2);
	}
	item sum(int l, int r) {
		return sum(l,r,0,0,size);
	}
};

void solve() {
	int n,m;
	cin>>n>>m;
	vector<int> arr(n);
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	segtree st;
	st.init(n);
	st.build(arr);
	while(m--) {
		int op,a,b;
		cin>>op>>a>>b;
		if(op==1) {
			st.set(a,b);
		}
		else {
			cout<<st.sum(a,b)<<endl;
		}
	}
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}
