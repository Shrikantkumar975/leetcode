/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

Node* dfs(Node* node,Node* newNode,unordered_map<Node*,Node*> &mpp){

    for(auto neigh: node->neighbors){
        if(mpp.find(neigh)==mpp.end()){
            Node* newNe = new Node(neigh->val);
            mpp[neigh]=newNe;
            newNode->neighbors.push_back(newNe);
            dfs(newNode,neighbor,mpp);
        }else{
            newNode->neighbors.push_back(mpp[neigh]);
            dfs(newNode,neighbor,mpp);
        }
    }

    return newNode;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> mpp;
        Node* newNode = new Node(node->val);

        unordered_mpp[node]=newNode;
        dfs(node,newNode,mpp);

        return newNode;
    }
};