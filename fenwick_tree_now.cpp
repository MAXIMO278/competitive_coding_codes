#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void update(ll index,ll value,ll* BIT,ll n)
{
	for(;index<=n;index+=(index & (-index)))
	{
		BIT[index]+=value;
	}
}
ll query(ll index,ll* BIT)
{
	ll sum=0;
	for(;index>0;index-=index&(-index))
	{
		sum+=BIT[index];
	}
	return sum;
}
int main()
{
	ll n,i;
	cin>>n;
	ll arr[n+1];
	ll BIT[n+1];
	memset(BIT,0,sizeof(BIT));
	memset(arr,0,sizeof(arr));
	//take the inputs
	for(i=1;i<=n;i++) 
	{
		cin>>arr[i];
		update(i,arr[i],BIT,n);
	}
	// query: l and r
	ll l,r;
	cin>>l>>r;
	cout<<query(r,BIT)-query(l-1,BIT)<<endl;
}
