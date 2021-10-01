#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void levelOrder(Node *root){
    if(!root)
        return;

    queue <Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node *node = q.front();
        q.pop();
        if(node){
            cout << node->data << " ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            cout << endl;
        }
    }
}

// void RlevelOrder(Node *root){
//     if(!root)
//         return;

//     queue <Node*> q;
//     q.push(root);
//     q.push(NULL);
    
//     while(!q.empty()){
//         Node *node = q.front();
//         q.pop();
//         if(node){
//             cout << node->data << " ";
//             if(node->right)
//                 q.push(node->right);
//             if(node->left)
//                 q.push(node->left);
//         }
//         else if(!q.empty()){
//             q.push(NULL);
//             cout << endl;
//         }
//     }
// }

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    levelOrder(root);
    cout << endl;
    // RlevelOrder(root);
}
