void dfs(ll n){
        vis[n]=1;
        for(ll i=0;i<edge[n].size();i++){
            
            if(vis[edge[n][i]]==0) dfs(edge[n][i]);
        }
    }

// no use of stack
