#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for(int i=a; i<b; i++)
#define ff first
#define ss second
// T.C -> O(nlogn)
struct Node{
    int key;
    Node *left, *right;
    Node(int data){
        key = data;
        left = right = NULL;
    }
};

void getVerticalOrder(Node *root, int hdis, map<int, vi> &m){
    if(!root)
        return;

    m[hdis].push_back(root->key);

    getVerticalOrder(root->left, hdis - 1, m);
    getVerticalOrder(root->right, hdis + 1, m);
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(5);
    root->right = new Node(6);

    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->left = new Node(17);
    root->right->right = new Node(18);

    root->right->right->left = new Node(20);

    int hdis = 0;//Horizontal Distance
    map<int, vi> m;

    getVerticalOrder(root, hdis, m);

    map<int, vi> :: iterator it;

    for(it = m.begin(); it != m.end(); it++){
        cout << "Level " << it->ff << " : ";
        for(int i=0; i < (it->ss).size(); i++){
            cout << (it->ss)[i] << " ";
        }
        cout << endl;
    }
}
