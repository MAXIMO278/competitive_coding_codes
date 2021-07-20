#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf=1E9+7;
ll segtree[10000];

void build(ll input[],ll low, ll high,ll pos)
{
	if(low==high)
	{
		segtree[pos]=input[low];return;
	}
	ll mid=(low+high)/2;
	build(input,low,mid,2*pos+1);
	build(input,mid+1,high,2*pos+2);
	segtree[pos]=segtree[2*pos+1]+segtree[2*pos+2];
}

int query_sum(ll qlow,ll qhigh,ll low,ll high,ll pos)
{
	if(qlow<=low && qhigh>=high) //total overlap
	{
		return segtree[pos];
	}
	
	if(qlow>high || qhigh<low) //no overlap
	{
		return 0;
	}
	ll mid=(low+high)/2;
	return(query_sum(qlow,qhigh,low,mid,2*pos+1)+query_sum(qlow,qhigh,mid+1,high,2*pos+2));
	
}
void update(ll dif,ll id,ll low,ll high,ll pos){
    if(id<low || id>high){
        return;
    }
    segtree[pos]=segtree[pos]+dif;
    if(low==high) return;
    ll mid=(low+high)/2;
    update(dif,id,low,mid,2*pos+1);
    update(dif,id,mid+1,high,2*pos+2);
}

int main()
{
	ll low,high,pos,i,j,k,n,q;
	cin>> n;// size of the input array
	ll input[n];
	for(i=0;i<n;i++) cin>>input[i];
	
	for(i=0;i<4*n;i++) segtree[i]=0;
	cin>>q;
	build(input,0,n-1,0);
	while(q--)
	{
		ll qlow,qhigh;
		cin>>qlow>>qhigh;
		cout<<query_sum(qlow,qhigh,0,n-1,0)<<endl;
	}
    cout<<"-----"<<endl;
    cin>>q;
    while(q--){
        ll id,nw;
        cin>>id>>nw;
        ll dif=nw-input[id];
        input[id]=nw;
        update(dif,id,0,n-1,0);
        ll qlow,qhigh;
		cin>>qlow>>qhigh;
		cout<<query_sum(qlow,qhigh,0,n-1,0)<<endl;
        
    }
	
}
