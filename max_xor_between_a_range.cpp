//let you are given integer number X and you have to calculate the maximum xor of x and a number between L and R [L,R] in this range
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
#define io { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define cer cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#define cs ll t;cin>>t;while(t--)
#define cs1 ll t;t=1;while(t--)
class trieNode
{
    public:
        trieNode* left;
        trieNode* right;
};

void insert(ll n, trieNode* head)
{
    trieNode* curr=head;
    for(ll i=31;i>=0;i--)
    {
        ll b=(n>>i)&1;
        if(b==0)
        {
            if(!curr->left)
            {
                curr->left=new trieNode();
            }
            curr=curr->left;
        }
        else
        {
            if(!curr->right)
            {
                curr->right=new trieNode();
            }
            curr=curr->right;
        }
    }
}

ll calc(trieNode* head,ll x){
    ll ans=0;
    ll i,j,k=0,s=0,z=0;
    trieNode*cur=head;
    for(i=31;i>=0;i--){
        if((!cur->left && cur->right && k==0)) {
            ll n=(x>>i)&1;
            if(n==0){s=s+pow(2,i);}
            cur=cur->right;con;
        }
        else if((cur->left && !cur->right && k==0)) {
            ll n=(x>>i)&1;
            if(n==1){s=s+pow(2,i);}
            cur=cur->left;con;
        }
        if(cur->left && cur->right && k==0){
            
            ll n=(x>>i)&1;
            s=s+pow(2,i);
            if(n==1){k=1;
                cur=cur->left;
            }
            else {k=2;cur=cur->right;con;}
            con;
        }
        if(k==2){
            ll n=(x>>i)&1;
            if(n==1||z==1){
                s=s+pow(2,i);
                if(z==1) con;
                if(cur->right) {z=1;cur=cur->right;}
                else{cur=cur->left;}

            }
            else {
                if(cur->right){s=s+pow(2,i);cur=cur->right;}
                else{cur=cur->left;}
            }
        }
        if(k==1){
            ll n=(x>>i)&1;
            if(n==0||z==1){
                s=s+pow(2,i);
                if(z==1) con;
                if(cur->left) {z=1;cur=cur->left;}
                else{cur=cur->right;}

            }
            else {
                if(cur->left){s=s+pow(2,i);cur=cur->left;}
                else{cur=cur->right;}
            }
        }


    }
    return s;
}
int main()
{
   #ifndef ONLINE_JUDGE
        ifstream cin("in.in");
        ofstream cout("out.out");
    #endif
    
        io;
        //////////////////////////////////
        cs{
               ll i,j,k,l,r,s=0,x;
               cin>>x>>l>>r;
               trieNode* head=new trieNode();
               insert(l,head);
               insert(r,head);
               cout<<calc(head,x) nl;
             
        }
        //////////////////////////////////
        cer;
}
