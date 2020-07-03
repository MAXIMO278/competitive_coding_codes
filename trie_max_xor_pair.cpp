#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

ll findMaxXor(trieNode* head,ll* arr, ll n)
{
	ll max_xor=INT_MIN;
	for(ll i=0;i<n;i++)
	{
		ll value=arr[i];
		trieNode* curr=head;
		ll curr_xor=0;
		for(ll j=31;j>=0;j--)
		{
			ll b=(value>>j)&1;
			if(b==0)
			{
				if(curr->right)
				{
					curr_xor+=pow(2,j);
					curr=curr->right;
				}
				else
				{
					curr=curr->left;
				}
			}
			else
			{
				if(curr->left)
				{
					curr_xor+=pow(2,j);
					curr=curr->left;
				}
				else
				{
					curr=curr->right;
				}
			}
		}
		if(curr_xor>max_xor) max_xor=curr_xor;
	}
	return max_xor;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll i,j,b,n;
		cin>>n;
		ll arr[n+1];
		for(i=0;i<n;i++) cin>>arr[i];
		trieNode* head=new trieNode();
		for(i=0;i<n;i++)
		{
			insert(arr[i],head);
		}
		cout<<findMaxXor(head,arr,n)<<endl;
	}
}
