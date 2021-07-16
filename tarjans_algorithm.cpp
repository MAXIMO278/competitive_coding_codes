class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    typedef int ll;
    vector<ll> dis,low,in;
    stack<ll> stk;
    ll time;
    vector<vector<ll>> van;
    void dfs(ll n,vector<ll> adj[]){
        stk.push(n);
        dis[n]=low[n]=time;
        time++;
        ll i,j;
        in[n]=1;
        for(i=0;i<adj[n].size();i++){
            if(dis[adj[n][i]]==-1){
                dfs(adj[n][i],adj);
                low[n]=min(low[n],low[adj[n][i]]);
            }
            else if(in[adj[n][i]]==1){
               
                low[n]=min(low[n],dis[adj[n][i]]);
            }
        }
        
        if(low[n]==dis[n]){
            vector<ll> v;
            while(stk.top()!=n){
                v.push_back(stk.top());
                in[stk.top()]=0;
                stk.pop();
            }
            in[n]=0;
            v.push_back(n);
            sort(v.begin(),v.end());
            van.push_back(v);
            stk.pop();
        }
    }
    vector<vector<int>> tarjans(int n, vector<int> adj[])
    {
        //code here
        time=0;
        dis.resize(n);
        fill(dis.begin(),dis.end(),-1);
        low.resize(n);
        fill(low.begin(),low.end(),-1);
        in.resize(n);
        fill(in.begin(),in.end(),0);
        ll i,j;
        for(i=0;i<n;i++){
            if(dis[i]==-1){
                dfs(i,adj);
            }
        }
        sort(van.begin(),van.end());
        return van;
        
    }
};
