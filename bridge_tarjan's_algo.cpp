class Solution {
public:
    typedef int ll;
    ll time;
    vector<ll> dis,low;
    vector<vector<ll>> bri;
    void dfs(ll n,ll pr,vector<ll> con[]){
        low[n]=dis[n]=time;
        time++;
        ll i;
        
        for(i=0;i<con[n].size();i++){
            if(con[n][i]==pr) continue;
            if(dis[con[n][i]]==-1){
                dfs(con[n][i],n,con);
               
                low[n]=min(low[n],low[con[n][i]]);
                if(low[con[n][i]]>dis[n]){
                    bri.push_back({con[n][i],n});
                }
            }
            else{
                low[n]=min(low[n],low[con[n][i]]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        ll i,j,k;
        vector<ll> con[n];
        for(i=0;i<conn.size();i++){
            con[conn[i][0]].push_back(conn[i][1]);
            con[conn[i][1]].push_back(conn[i][0]);
        }
        time=0;
        dis.resize(n);
        fill(dis.begin(),dis.end(),-1);
        low.resize(n);
        fill(low.begin(),low.end(),-1);
        dfs(0,-1,con);
        return bri;
    }
};
