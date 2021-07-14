
//https://leetcode.com/problems/largest-component-size-by-common-factor/

class Solution {
public:
    typedef int ll;
    
    ll _find(ll x,vector<ll>& parents){
        if(parents[x]==-1){
            return x;
        }
        parents[x]=_find(parents[x],parents);
        return parents[x];
    }
    
    void _union(ll x,ll y,vector<ll>& parents){
        ll px=_find(x,parents);
        ll py=_find(y,parents);
        if(px!=py){
            parents[px]=py;
        }
    }
    
    int largestComponentSize(vector<int>& nums) {
        ll i,j,k,n=nums.size();
        vector<ll> parents(100002,-1);
        for(i=0;i<n;i++){
            for(j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    _union(j,nums[i],parents);
                    _union(j,nums[i]/j,parents);
                }
            }
        }
        ll count=0;
        unordered_map<ll,ll> mp;
        for(i=0;i<n;i++){
            ll pr=_find(nums[i],parents);
            count=max(count,1+mp[pr]);
            mp[pr]++;
        }
        return count;
    }
};
