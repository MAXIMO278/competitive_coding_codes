#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf=1E9+7;

void build(ll segtree[],ll input[],ll low, ll high,ll pos)
{
	if(low==high)
	{
		segtree[pos]=input[low];return;
	}
	ll mid=(low+high)/2;
	build(segtree,input,low,mid,2*pos+1);
	build(segtree,input,mid+1,high,2*pos+2);
	segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
}

int query_min(ll segtree[],ll qlow,ll qhigh,ll low,ll high,ll pos)
{
	if(qlow<=low && qhigh>=high) //total overlap
	{
		return segtree[pos];
	}
	
	if(qlow>high || qhigh<low) //no overlap
	{
		return inf;
	}
	ll mid=(low+high)/2;
	return(min(query_min(segtree,qlow,qhigh,low,mid,2*pos+1),query_min(segtree,qlow,qhigh,mid+1,high,2*pos+2)));
	
}

int main()
{
	ll low,high,pos,i,j,k,n,q;
	cin>> n;// size of the input array
	ll input[n];
	for(i=0;i<n;i++) cin>>input[i];
	ll segtree[4*n];
	for(i=0;i<4*n;i++) segtree[i]=INT_MAX;
	cin>>q;
	build(segtree,input,0,n-1,0);
	while(q--)
	{
		ll qlow,qhigh;
		cin>>qlow>>qhigh;
		cout<<query_min(segtree,qlow,qhigh,0,n-1,0)<<endl;
	}
	
}
