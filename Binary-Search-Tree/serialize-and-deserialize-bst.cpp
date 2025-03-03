string serialize(TreeNode* root) {
    string data;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto x=q.front();
        q.pop();
        if (x==NULL) { data+="N "; continue; }
        data+=to_string(x->val)+' ';
        q.push(x->left);
        q.push(x->right);
    }
    return data;
}
TreeNode* deserialize(string data) {
    if (data[0]=='N') return NULL;
    stringstream ss(data);
    string d;
    getline(ss,d,' ');
    TreeNode* root=new TreeNode(stoi(d));
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto x=q.front();
        q.pop();
        getline(ss,d,' ');
        if (d!="N") {
            x->left=new TreeNode(stoi(d));
            q.push(x->left);
        }
        getline(ss,d,' ');
        if (d!="N") {
            x->right=new TreeNode(stoi(d));
            q.push(x->right);
        }
    }
    return root;
}