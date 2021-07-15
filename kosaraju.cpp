
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	typedef int ll;
	stack<ll> st,df;
	ll lv;
	vector<ll> v,vv,nv;
	
	void dfs(ll n,vector<ll> adj[]){
	    df.push(n);
	    v[n]=1;
	    while(df.size()>0){
	        df.pop();
	        for(ll i=0;i<adj[n].size();i++){
	            if(v[adj[n][i]]==0){
	                v[adj[n][i]]=1;
	                dfs(adj[n][i],adj);
	            }
	        }
	        st.push(n);
	    }
	}
	
	
	void dfs2(ll n,vector<ll> adj[]){
	    df.push(n);
	    nv[n]=1;
	    while(df.size()>0){
	        df.pop();
	        for(ll i=0;i<adj[n].size();i++){
	            if(nv[adj[n][i]]==0){
	                nv[adj[n][i]]=1;
	                dfs2(adj[n][i],adj);
	            }
	        }
	        
	    }
	}
	
    int kosaraju(int n, vector<int> adj[])
    {
        lv=0;
        v.resize(n+5);
        fill(v.begin(),v.end(),0);
        vv.resize(n);
        fill(vv.begin(),vv.end(),0);
        for(ll i=0;i<n;i++){
            if(v[i]==0){
                dfs(i,adj);
            }
        }
        vector<ll> edge[n+5];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<adj[i].size();j++){
                edge[adj[i][j]].push_back(i);
            }
        }
        ll s=0;
        nv.resize(n+5);
        fill(nv.begin(),nv.end(),0);
        while(st.size()){
            ll node=st.top();
            st.pop();
            
            if(nv[node]==1) continue;
            else{
                dfs2(node,edge);
                s++;
            }
        }
        
        return s;
    }
};
