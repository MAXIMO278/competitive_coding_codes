#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <iomanip>
#include <climits>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000000000000000000
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
struct tree
{
    ll s,ps,ss;
};
tree query(tree sg[],ll l,ll r,ll x,ll y,ll i)
{
    tree k;
    k.s=k.ps=k.ss=0;
    if(l>=x && r<=y) return sg[i];
    if(y<l || x>r) return k;
    ll m=(l+r)/2;
    tree lt=query(sg,l,m,x,y,2*i+1);
    tree rt=query(sg,m+1,r,x,y,2*i+2);
    k.s=lt.s+rt.s;
    k.ps=max(lt.ps,lt.s+rt.ps);
    k.ss=max(lt.ss+rt.s,rt.ss);
    return k;
}
void build(tree sg[],ll a[],ll n,ll l,ll r,ll i)
{
    if(l==r) sg[i].s=sg[i].ps=sg[i].ss=a[l];
    else
    {
        ll m=(l+r)/2;
        build(sg,a,n,l,m,2*i+1);
        build(sg,a,n,m+1,r,2*i+2);
        sg[i].s=sg[2*i+1].s+sg[2*i+2].s;
        sg[i].ps=max(sg[2*i+1].ps,sg[2*i+1].s+sg[2*i+2].ps);
        sg[i].ss=max(sg[2*i+2].ss,sg[2*i+1].ss+sg[2*i+2].s);
    }
}
void update(tree sg[],ll l,ll r,ll i,ll x,ll y)
{
    if(l==r) sg[i].s=sg[i].ps=sg[i].ss=y;
    else
    {
        ll m=(l+r)/2;
        if(x<=m) update(sg,l,m,2*i+1,x,y);
        else update(sg,m+1,r,2*i+2,x,y);
        sg[i].s=sg[2*i+1].s+sg[2*i+2].s;
        sg[i].ps=max(sg[2*i+1].ps,sg[2*i+1].s+sg[2*i+2].ps);
        sg[i].ss=max(sg[2*i+2].ss,sg[2*i+1].ss+sg[2*i+2].s);
    }
}
int main()
{
    fast_io;
    Test{ll n,i,m,x,y;
        cin>>n>>m;
        ll a[n+5];
        for(i=0;i<n;i++) cin>>a[i];
        tree sg[3*n];
        build(sg,a,n,0,n-1,0);
        while(m--)
        {
            char ch;
            cin>>ch>>x>>y;
            //cout<<ch;
            if(ch=='U') update(sg,0,n-1,0,x-1,y);
            else
            {
                x--,y--;
                ll ans=query(sg,0,n-1,x,y,0).s;
                if(x>0) ans+=query(sg,0,n-1,0,x-1,0).ss;
                if(y<n) ans+=query(sg,0,n-1,y+1,n-1,0).ps;
                cout<<ans<<ln;
            }
        }}
    return 0;
}
