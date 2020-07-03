#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll modpow(ll base, ll exp, ll modulus) {
  base %= modulus;
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result%modulus;}

int main()
{
	ll n,q,i,j;
	cin>>n>>q;
	ll arr[n],sum[n+1];
	for(i=1;i<=n;i++)
	{cin>>arr[i];
	}
	sum[0]=arr[0];
	for(i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+arr[i];
	}
	while(q--)
	{
		ll l1,r1,l2,r2,a=1,b=1,c,k=0;
		cin>>l1>>r1>>l2>>r2>>c;
		ll x=sum[r1]-sum[l1-1];
		ll y=sum[r2]-sum[l2-1];
		if(y==0){
		
			cout<<"No -1"<<endl;
		
		continue;
		}
		for(i=1;i<=y;i++)
		{
			b=b*x;
			if(b/10>0){k=1;break;
			}	
		}
		if(k==0)
		{cout<<"No -1"<<endl;continue;
		}
		a=modpow(x,y,100);
		a=a/10;
		if(a==c)
		{
			cout<<"Yes "<<a<<endl;
		}
		else
		{
			cout<<"No "<<a<<endl;
		}
	}
}
