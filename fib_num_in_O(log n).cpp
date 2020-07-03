#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void multiply(ll a[2][2],ll m[2][2])
{
	ll fv=a[0][0]*m[0][0]+a[0][1]*m[1][0];
	ll sv=a[0][0]*m[0][1]+a[0][1]*m[1][1];
	ll tv=a[1][0]*m[0][0]+a[1][1]*m[1][0];
	ll fov=a[1][0]*m[0][1]+a[1][1]*m[1][1];
	a[0][0]=fv;
	a[0][1]=sv;
	a[1][0]=tv;
	a[1][1]=fov;
}
void power(ll a[2][2],ll n)
{
	if(n==0 || n==1) return;
	power(a,n/2);
	multiply(a,a);
	if(n%2!=0)
	{
		ll m[2][2]={{1,1},{1,0}};
		multiply(a,m);
	}
}
ll fib(ll n)
{
	ll a[2][2]={{1,1},{1,0}};
	if(n==0) return 0;
	power(a,n-1);
	return a[0][0];
}
int main()
{
	ll n;
	cin>>n;
	cout<<fib(n)<<endl;
}
