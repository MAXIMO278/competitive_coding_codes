//CODER:::::::::MAXIMO278
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

//BFS GRAPH//
//ll n;
vector<ll> graph[250000];
vector<bool> sta;
queue<ll> st;
void bfs(int n)
{
	cout<<n<<" ";
	st.push(n);
	sta[n]=true;
	while(!st.empty()){
		st.pop();
	for(ll i=0;i<graph[n].size();i++)
	{
		if(sta[graph[n][i]]==false)
		{
			sta[graph[n][i]]=true;
			bfs(graph[n][i]);
		}
	}
}
}

//bfs()//
//DFS TREE//
int dfst(int x, int pred, int y)
{
   int mm = 0;

   for (int i:v[x])
   if (i!=pred){
       int z = dfst(i, x, y);
       mm = max(mm, z+1);
   }

   if (mm>=y || x==1) {ans++; mm = -1;}

   return mm;
}
//int x=dfst()//


//DFS GRAPH//
void dfs(int n)
{
	cout<<n<<" ";
	st.push(n);
	sta[n]=true;
	while(!st.empty()){
		st.pop();
	for(ll i=0;i<graph[n].size();i++)
	{
		if(sta[graph[n][i]]==false)
		{
			sta[graph[n][i]]=true;
			dfs(graph[n][i]);
		}
	}
}
}

//dfs()//


//nCr MOD m//

 
int fact(ll a, ll b){
    ll result = 1;
    for(int i=0;i<b;++i){
        result *= a;
        a--;
        result %= MOD;
    }
    return result;
}
 
int mpow(ll x, ll n){
    ll result = 1;
    while( n != 0 ) {
        if (n & 1) result = result*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return result % MOD;
}
 
int combination(ll a, ll b) {
    ll result = fact(a, b) % MOD;
    result *= mpow(fact(b, b), MOD-2) % MOD;
    return result % MOD;
}
 
 
//int x=combination(n,r) ;//nCr//


//a^b mod m//

ll modpow(ll base, ll exp) {
  base %= MOD;
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result%MOD;}
  
  //int x=modpow(a,b); //a^b %MOD//

int main()
{
	 ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
}
