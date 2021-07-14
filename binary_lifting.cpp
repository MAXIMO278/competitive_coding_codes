https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

class TreeAncestor {
public:
    typedef int ll;
    ll lg=21;
    ll i,j;
    vector<vector<ll>> up;
    vector<ll> dpt;
    TreeAncestor(int n, vector<int>& parent) {
        parent[0]=0;
        up=vector<vector<ll>>(n, vector<ll>(lg,0));
        dpt=vector<ll>(n);
        for(i=0;i<n;i++){
            up[i][0]=parent[i];
            if(i!=0){
                dpt[i]=dpt[parent[i]]+1;
            }
            for(j=1;j<lg;j++){
               up[i][j]=up[up[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(k>dpt[node]) return -1;
        
        for(i=lg-1;i>=0;i--){
            if(k>=(1<<i)){
                node=up[node][i];
                k=k-(1<<i);
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
