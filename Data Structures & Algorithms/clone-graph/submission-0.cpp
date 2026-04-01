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

class Solution {
    Node * DFS(Node* node,unordered_map<Node*, Node*> &visited){
        if(node== NULL)return NULL;
        if(visited.find(node)!=visited.end()){
            return visited[node];
        }
        Node * temp=new Node(node->val);
        visited[node]=temp;
        for(int i=0;i<node->neighbors.size();i++){
            if(visited.find(node->neighbors[i])!=visited.end()){
                temp->neighbors.push_back(visited[node->neighbors[i]]);
            }
            else{
                temp->neighbors.push_back(DFS(node->neighbors[i],visited));
            }
        }
        return temp;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visited;
        return DFS(node,visited);
    }
};
