class Node{
public:
    Node* arr[26];
    bool isend;

    Node(){
        for(int i=0;i<26;i++){
            arr[i] = NULL;
        }
        isend = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(char ch:word){
            int idx = ch-'a';
            if(temp->arr[idx] == NULL){
                temp->arr[idx] = new Node();
            }
            temp = temp->arr[idx];
        }
        temp->isend = true;
    }
    
    bool search(string word) {
        Node* temp = root;

        for(char ch:word){
            int idx = ch-'a';
            if(temp->arr[idx] == NULL){
                return false;
            }
            temp = temp->arr[idx];
        }

        return temp->isend;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char ch:prefix){
            int idx = ch-'a';
            if(temp->arr[idx] == NULL) return false;

            temp = temp->arr[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */