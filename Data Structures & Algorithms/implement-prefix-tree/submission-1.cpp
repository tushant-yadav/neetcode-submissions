class PrefixTree {
private:
    bool wordEnd;
    vector<PrefixTree*> letters;    
public:
        
    PrefixTree() :
        wordEnd(false),
        letters(26,nullptr){}
    
    
    void insert(string word, int i = 0) {
        if(word.size() == i){
            wordEnd = true;
            return;
        }
        int idx = word[i]-'a';
        if(letters[idx] == nullptr){
            letters[idx] = new PrefixTree(); 
        }
        letters[idx]->insert(word, i+1);
    }

    PrefixTree* helper(string word){
        PrefixTree* itr = this;
        for(char i : word){
            int idx = i-'a';
            if(itr->letters[idx] == nullptr) return nullptr;
            itr = itr->letters[idx];
        }
        return itr;
    }
    
    bool search(string word) {
        PrefixTree* node  = helper(word);
        return node!=nullptr && node->wordEnd;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* node  = helper(prefix);
        return node!=nullptr;
    }
};
