#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class trieNode
{
	public:
	trieNode** children;
	ll weight;
	
	trieNode()
	{
		children=new trieNode*[26];
		for(ll i=0;i<26;i++)
		{
			children[i]=NULL;
		}
		weight=0;
	}	
};

void insert(string s, ll weight,trieNode* root)
{
	if(s.empty()) return;
	ll index=s[0]-'a';
	trieNode* child;
	if(root->children[index])
	{
		child=root->children[index];
	}
	else
	{
		child=new trieNode();
		root->children[index]=child;
	}
	
	if(root->weight< weight)
	{
		root->weight=weight;
	}
	insert(s.substr(1),weight,child);
}

ll searchBest(string s, trieNode* root)
{
	ll bestWeight=-1;
	trieNode* current=root;
	for(ll i=0;i<s.length();i++)
	{
		ll index=s[i]-'a';
		trieNode* child=current->children[index];
		if(child)
		{
			current=child;
			bestWeight=child->weight;
		}
		else
		{
			return -1;
		}
	}
	return bestWeight;
}

int main()
{
	ll n,q;
	cin>>n>>q;
	trieNode* root=new trieNode();
	for(ll i=0;i<n;i++)
	{
		string s;
		cin>>s;
		ll weight;
		cin>>weight;
		insert(s,weight,root);
	}
	for(ll i=0;i<q;i++)
	{
		string pre;
		cin>>pre;
		cout<<searchBest(pre,root)<<"\n";
	}
	
}
