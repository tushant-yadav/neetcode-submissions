class PrefixTree {
    bool wordEnd = false;
    vector<PrefixTree*> letter;
public:
    PrefixTree() :
        wordEnd(false),
        letter(26,nullptr){}
    
    void insert(string word, int i=0) {
        if(word.size()==i){
            wordEnd = true;
            return;
        }
        int idx = word[i]-'a';
        if(letter[idx]==nullptr){
            letter[idx] = new PrefixTree();
        }
        letter[idx]->insert(word,i+1);
    }

    PrefixTree* helper(string word){
        PrefixTree* itr = this;

        for(char i:word){
            int idx = i-'a';
            if(itr->letter[idx]==nullptr){
                return nullptr;
            }
            itr = itr->letter[idx];
        }
        return itr;
    }
    
    bool search(string word) {
        PrefixTree* node = helper(word);
        return node!=nullptr && node->wordEnd;
    }
    
    bool startsWith(string prefix) {
        return (helper(prefix)!=nullptr);
    }
};
