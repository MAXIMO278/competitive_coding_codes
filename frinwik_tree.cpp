#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define nl <<"\n"
#define con continue
#define br break
#define vll vector<ll>
#define vpll vector<pair<ll,ll> >
ll mx=INT_MAX;
ll mi=INT_MIN;
const ll MOD=998244353;
const ll inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
#define io { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define cer cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

void update(ll index,ll value,ll *BIT,ll n)
{
	for(;index<=n;index+=index&(-index))
	{
		BIT[index]+=value;
	}
}

ll query(ll index,ll *BIT)
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
        io;
        //////////////////////////////////
		ll n;
		cin>>n;
		ll *arr=new ll[n+1];
		ll *BIT=new ll[n+1];
		for(ll i=0;i<=n;i++) BIT[i]=0;
		for(ll i=1;i<=n;i++)
		    {
			cin>>arr[i];
			update(i,arr[i],BIT,n);
			}
		// for range 5 to 2;
			cout<<query(5,BIT)-query(1,BIT) nl;
		// for range 5 to 1:
			cout<< query(5,BIT) nl;
		
		
		
        //////////////////////////////////
        cer;
}
