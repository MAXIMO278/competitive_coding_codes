
https://leetcode.com/problems/stream-of-characters/

typedef int ll;
class Trie{
    Trie* children[26];
    bool end;
public:
    Trie(){
        for(ll i=0;i<26;i++) children[i]=nullptr;
        end=false;
    }
    void insert(string st){
        ll i,j;
        Trie *t=this;
        for(i=0;i<st.size();i++){
            if(t->children[st[i]-'a']==nullptr) t->children[st[i]-'a']=new Trie();
            t=t->children[st[i]-'a'];
        }
        t->end=true;
    }
    bool search(deque<char> dq){
        Trie* t=this;
        for(char c: dq){
            if(t->children[c-'a']==nullptr) return false;
            t=t->children[c-'a'];
            if(t->end==true) return true;
        }
        return false;
    }
};

class StreamChecker {
public:
    ll i,j,k;
    Trie t;
    deque<char> dq;
    StreamChecker(vector<string>& words) {
        for(i=0;i<words.size();i++){
            reverse(words[i].begin(),words[i].end());
            t.insert(words[i]);
        }
    }
    
    bool query(char letter) {
        dq.push_front(letter);
        return t.search(dq);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
