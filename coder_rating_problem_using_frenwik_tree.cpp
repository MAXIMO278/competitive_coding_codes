#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct coder
{
	ll x,y,index;
};

bool operator<(coder A, coder B)
{
	if(A.x==B.x) return(A.y<B.y);
	return A.x<B.x;
}
ll bit[100001];
void update(ll y)
{
	for(;y<=100000;y+=y&(-y))
	{
		bit[y]++;
	}
}
ll query(ll y)
{
	ll value=0;
	for(;y>0;y-=y&(-y))
	{
		value+=bit[y];
	}
	return value;
}
int main()
{
	ll n,i,j;
	cin>>n;
	coder arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i].x>>arr[i].y;
		arr[i].index=i;
	}
	sort(arr,arr+n);
	ll ans[n];
	for(i=0;i<n;)
	{
		ll endIndex=i;
		while(endIndex<n && arr[endIndex].x==arr[i].x && arr[endIndex].y==arr[endIndex].y) endIndex++;
		for(j=i;j<endIndex;j++) ans[arr[j].index]=query(arr[j].y);
		for(j=i;j<endIndex;j++) update(arr[j].y);
		i=endIndex;
	}
	for(i=0;i<n;i++) cout<<ans[i]<<" ";
}

