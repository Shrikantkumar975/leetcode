/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s;
        
        queue<TreeNode*> q;
        q.push(root);
        s+=to_string(root->val) + ",";

        while(!q.empty()){
            TreeNode* a = q.front();
            q.pop();

            if(a->left==nullptr){
                s+="#,";
            }else{
                s+=to_string(a->left->val)+ ",";
                q.push(a->left);
            }

            if(a->right==nullptr){
                s+="#,";
            }else{
                s+=to_string(a->right->val) + ",";
                q.push(a->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;
        vector<int> ans;
        string s="";
        int flag = 0;
        for(char c: data){
            if(c=='#') flag=1;
            else if(c==',' && flag==1){
                ans.push_back(-1001);
                flag=0;
                continue;
            }else if(c==','){
                ans.push_back(stoi(s));
                s="";
            }else{
                s+=c;
            }
        }

        int i=0;
        TreeNode* root = new TreeNode(ans[i++]);
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty() && i<ans.size()){
                TreeNode* node =  q.front();
                q.pop();

                if(ans[i]==-1001){
                    node->left = nullptr;
                    i++;
                }else{
                    TreeNode* newNode =  new TreeNode(ans[i++]);
                    node->left = newNode;
                    q.push(node->left);
                }

                if(ans[i]==-1001){
                    node->right = nullptr;
                    i++;
                }else{
                    TreeNode* newNode =  new TreeNode(ans[i++]);
                    node->right = newNode;
                    q.push(node->right);
                }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;