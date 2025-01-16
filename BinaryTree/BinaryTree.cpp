#include <bits/stdc++.h>
using namespace std;
/*
=======================================================================================================
01. Creating a Tree using preorder
=======================================================================================================
*/

// creating a tree node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// building tree by preorder
static int idx = -1;
Node *buildTree(vector<int> nodes)
{
    idx++;
    if (nodes[idx] == -1)
        return NULL;

    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

/*
=======================================================================================================
02. Print tree using Preorder , Inorder and Postorder
=======================================================================================================
*/

// print by Preorder (Root , Left , Right)

void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// print by Inorder (Left , Root , Right)

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// print by Postorder (Left , Right , Root)

void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

/*
=======================================================================================================
02. Level Order Traversal (BFS - Breadth First Search). Printing each level
=======================================================================================================
*/

void levelorder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> Q;
    Q.push(root);
    Q.push(NULL);

    while (!Q.empty())
    {
        Node *curr = Q.front();
        Q.pop();

        if (curr == NULL)
        {
            cout << endl;
            if (Q.empty())
            {
                break;
            }
            else
            {
                Q.push(NULL);
            }
        }
        else
        {
            cout << curr->data << " ";

            if (curr->left)
            {
                Q.push(curr->left);
            }

            if (curr->right)
            {
                Q.push(curr->right);
            }
        }
    }

    cout << endl;
}


/*
=======================================================================================================
03. Height of a Binary Tree
=======================================================================================================
*/

int treeHeight(Node* root)
{
    if(root == NULL) return 0;
    int leftH = treeHeight(root->left);
    int rightH = treeHeight(root->right);
    return max(leftH, rightH)+1;
}


/*
=======================================================================================================
04. Count all nodes Binary Tree
=======================================================================================================
*/

int countNodes(Node* root)
{
    if(root == NULL) return 0;

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
 
    return leftCount+rightCount+1;
}


/*
=======================================================================================================
04. sum of all nodes Binary Tree
=======================================================================================================
*/

int sumNodes(Node* root)
{
    if(root == NULL) return 0;

    int leftSum = sumNodes(root->left);
    int rightSum = sumNodes(root->right);

    return leftSum + rightSum + root->data;
}


int main()
{

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);

    cout << "sum of all nodes  :"<< sumNodes(root)<<endl;

    return 0;
}