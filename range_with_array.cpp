#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll i,j,k,l,m,n,q,s=0;
	cin>>n>>m>>k;
	ll arr[100010],dp[100010],prx[100010];
	for(i=1;i<=n;i++) cin>>arr[i];
	vector<ll> v[100010];
	j=1;
	for(i=1;i<=m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		v[i].push_back(a);
		v[i].push_back(b);
		v[i].push_back(c);
		j++;
	//	dp[a]++;
	//	dp[b+1]--;
	}
	while(k--)
	{
		ll x,y;
		cin>>x>>y;
		dp[x]++;
		dp[y+1]--;
	}
	for(i=1;i<=m;i++)
	{
		if(i>1) dp[i]=dp[i]+dp[i-1];
		prx[v[i][0]]+=dp[i]*v[i][2];
		prx[v[i][1]+1]-=dp[i]*v[i][2];
	}
	for(i=1;i<=n;i++)
	{
		if(i>1) prx[i]+=prx[i-1];
		cout<<arr[i]+prx[i]<<" ";
	}
	
	
	
}
