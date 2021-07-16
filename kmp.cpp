class Solution {
public:
    typedef int ll;
    int strStr(string st, string pt) {
        if(st.size()<pt.size()) return -1;
        if(st.size()==0 || pt.size()==0) return 0;
        ll i,j,k,n=st.size(),m=pt.size();
        vector<ll> lps(m,0);
        i=0;
        j=1;
        while(j<m){
            if(pt[i]==pt[j]){
                i++;
                lps[j]=i;
                j++;
            }
            else{
                if(i==0){
                    lps[j]=i;
                    j++;
                }
                else{
                    i=lps[i-1];
                }
            }
        }
      
        i=0;j=0;
        while(j<n){
            if(st[j]==pt[i]){
                i++;
                j++;
            }
            if(i==m) return j-i;
            else if(j<n && st[j]!=pt[i]){
                if(i!=0) i=lps[i-1];
                else{
                    j++;
                }
            }
        }
        
        return -1;
    }
};
