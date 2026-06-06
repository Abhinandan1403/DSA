class Node{
    public:
    vector<Node*>letters;
    bool flag ;

    Node(){
        letters.resize(26, NULL);
        flag = false;
    }

    bool contains(char ch){
        if(letters[ch-'a'] == NULL){
            return false ;
        }

        return true;
    }
};


class Trie {
private:
    Node* root ;


public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root ;
        for(int i = 0 ; i<word.size() ; i++){
            if(!curr->contains(word[i])){
                curr->letters[word[i]-'a'] = new Node();
            }
            curr = curr->letters[word[i]-'a'];
        }
        curr->flag = true ;
        return ;
    }
    
    bool search(string word) {
        Node* curr = root ;
        for(int i = 0 ; i<word.size() ; i++){
            if(!curr->contains(word[i])){
                return false ;
            }
            curr = curr->letters[word[i]-'a'];
        }
        return curr->flag ;
    }
    
    bool startsWith(string word) {
        Node* curr = root ;
        for(int i = 0 ; i<word.size() ; i++){
            if(!curr->contains(word[i])){
                return false ;
            }
            curr = curr->letters[word[i]-'a'];
        }
        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */