#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
/*
 execution in cmd of windows:
 
 
  c
  
  
  p1
 
 */
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
#define mem0(a)         memset(a,0,sizeof(a))
#define mem1(a)         memset(a,-1,sizeof(a))
#define all(v) v.begin(), v.end()
#define fsort(v) sort(all(v))  
#define rsort(v) sort(v.rbegin(),v.rend())
#define rev(v) reverse(all(v))
#define maxc(v) max_element(all(v))
#define minc(v) min_element(all(v))
#define sumv(v,x) accumulate(v.begin(),v.end(),x);
const ll mod = 1000000007;
const ll inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
#define io { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define cer cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#define cs ll t;cin>>t;while(t--)
#define cs1 ll t;t=1;while(t--)
vll graph[500],sta(500,0);
queue<ll> q;
void bfs(ll n){
    cout<<n<<" ";
    sta[n]=1;
    while(!q.empty()){
        
        q.pop();
        for(ll i=0;i<graph[n].size();i++){
            if(sta[graph[n][i]]==0){
                sta[graph[n][i]]=1;
                q.push(graph[n][i]);
            }
        }
       if(q.size()>=1) bfs(q.front());
    }
}
int main()
{
   
        io;
        //////////////////////////////////
        cs{
            ll i,j,k,l,s=0,p=0,n,m,e;
            cin>>n>>e;
            for(i=0;i<e;i++){
                ll x,y;
                cin>>x>>y;
                graph[x].pb(y);
                graph[y].pb(x);
            }
            q.push((ll)1);
            bfs(1);
            

        }
        //////////////////////////////////
       
}
