struct Node {
    vector<Node*> links;
    bool terminal;
    Node() {
        links=vector<Node*>(26,NULL);
        terminal=0;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    void insert(string word) {
        Node* x=root;
        for (int i=0; i<word.size(); ++i) {
            int idx=word[i]-'a';
            if (x->links[idx]==NULL) {
                x->links[idx]=new Node();
            }
            x=x->links[idx];
        }
        x->terminal=1;
    }
    bool search(string word) {
        Node* x=root;
        for (int i=0; i<word.size(); ++i) {
            int idx=word[i]-'a';
            if (x->links[idx]==NULL) return 0;
            x=x->links[idx];
        }
        return x->terminal;
    }
    bool startsWith(string prefix) {
        Node* x=root;
        for (int i=0; i<prefix.size(); ++i) {
            int idx=prefix[i]-'a';
            if (x->links[idx]==NULL) return 0;
            x=x->links[idx];
        }
        return 1;
    }
};