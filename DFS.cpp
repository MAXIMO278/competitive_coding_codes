#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll> graph[250000];
vector<bool> sta;
stack<ll> st;
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

int main()
{
	ll i,j,k,e,u,v;
	cin>>n>>e;
	for(i=0;i<e;i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(i=1;i<=n+3;i++)
	{
		sta.push_back(false);
	}
	dfs(1);
}
