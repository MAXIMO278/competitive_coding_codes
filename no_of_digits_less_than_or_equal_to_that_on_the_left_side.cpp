#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>



using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
/*
 execution in cmd of windows: g++ p1.cpp -op1
  
  
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
const ll MOD=1e9+7;
#define io { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define cer cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#define cs ll t;cin>>t;while(t--)
#define cs1 ll t;t=1;while(t--)
int main()
{
   
    
        io;
        //////////////////////////////////
        cs1{
                ll i,j,k,s=1,p=0,q=0,r=0,n,m;
                cin>>n;
                vll v(n);
                for(i=0;i<n;i++) cin>>v[i];
                vll dp(n,1);
                stack<ll> st;
                st.push(0);
                for(i=1;i<n;i++){
                    ll a=0;
                    //if(v[st.top()]<=v[i]){dp[i]+=dp[st.top()]}
                    while( st.size()!=0 && v[st.top()]<=v[i] ){
                        dp[i]+=dp[st.top()];st.pop();
                    }
                   // if()
                    st.push(i);
                    
                }
                for(i=0;i<n;i++) cout<<dp[i]<<" ";
        }
        //////////////////////////////////
       // cer;
}
