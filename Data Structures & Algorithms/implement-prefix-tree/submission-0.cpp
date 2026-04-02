
class PrefixTree {
public:
    PrefixTree* child[26];
    bool isleaf;
    PrefixTree() {
        isleaf = false;
        for(int i = 0;i<26;i++){
            child[i] = NULL;
        }
    }
    
    void insert(string word) {
        int n = word.length();
        PrefixTree* itr=this;
        for(int i=0;i<n;i++){
            if(itr->child[word[i]-'a']==NULL){
                itr->child[word[i]-'a'] = new PrefixTree();
            }
            itr = itr->child[word[i]-'a'];
        }
        itr->isleaf=true;
    }
    
    bool search(string word) {
        int n = word.length();
        PrefixTree* itr = this;
        for(int i=0;i<n;i++){
            if(itr->child[word[i]-'a']!=NULL){
                itr = itr->child[word[i]-'a'];
            } 
            else return 0;
        }
        return itr->isleaf;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.length();
        PrefixTree* itr = this;
        for(int i=0;i<n;i++){
            if(itr->child[prefix[i]-'a']!=NULL){
                itr = itr->child[prefix[i]-'a'];
            } 
            else return 0;
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */