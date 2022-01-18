ll n=batteries.size();        
sort(batteries.begin(),batteries.end());
vector<ll> ar=batteries;
ll sum=0;
for(ll i=0;i<n-k;i++) {
    sum+=batteries[i];
}
for(ll i=n-k;i<n-1;i++) {
    ll no=i+1-(n-k);
    ll diff=batteries[i+1]-batteries[i];
    ll req=diff*no;
    if(sum>=req) {
        sum-=(batteries[i+1]-batteries[i])*(i+1-(n-k));
        batteries[i]=batteries[i+1];                
    } else {
        batteries[i]+=sum/no;
        sum=0;
    }
}
if(sum>0) {
    batteries[n-1]+=sum/k;
}
ll extra=0;
ll indx=n-1;
ll no=0;
for(ll i=n-1;i>=n-k;i--) {
    if(ar[i]!=batteries[i]) {
        indx=i;
        break;
    } else {
        extra+=batteries[i];
        no++;
    }
}
ll ans=batteries[indx];        
return ans;