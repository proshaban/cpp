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


/*
=======================================================================================================
05. Diameter of  Binary Tree

    It is the longest path between two nodes in a tree
=======================================================================================================
*/

//Method 1: O(N*N)

int diameterOFTree1(Node * root)
{
    if(root==NULL) return 0;

    //currHeight will carry condition in which the diameter is passing through root. 
    // in this case diameter is height for left and right + 1
    int CurrHeight = treeHeight(root->left) + treeHeight(root->right)+1;

    int leftHeight = diameterOFTree1(root->left);
    int rightHeight = diameterOFTree1(root->right);

    return (max(CurrHeight, max(leftHeight , rightHeight)));
}

//Method 2 : 0(N)

pair<int,int>diam2(Node* root)
{
    if(root == NULL) return make_pair(0,0);

    pair<int,int>leftInfo = diam2(root->left);
    pair<int,int>rightInfo = diam2(root->right);

    int currDiam = leftInfo.second + rightInfo.second + 1;

    int finalDiam = max(currDiam , max(leftInfo.first , rightInfo.second));

    int finalHeight = max(leftInfo.second , rightInfo.second)+1;

    return make_pair(finalDiam, finalHeight);
}


/*
=======================================================================================================
06. Is Tree - B is a sub-tree of Tree - A


    a. Find subRoot in main Tree
    b. if subRoot is found then check for identical else find for left & right root
=======================================================================================================
*/


bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    if (root1->data != root2->data) return false;

    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}


bool isSubTree(Node* root, Node* subRoot)
{

    if(root==NULL && subRoot == NULL ) return true;

    if(root == NULL || subRoot == NULL ) return false;

    if(root->data == subRoot->data)
    {
        //check for identical

        if(isIdentical(root, subRoot))
        {
            return true;
        }
    }

    bool checkLeft = isSubTree(root->left, subRoot);
    if(!checkLeft)
    {
        return isSubTree(root->right , subRoot);
    }

    return true; 
}


/*
=======================================================================================================
06. TOp view of binary tree 
=======================================================================================================
*/

void topView(Node* root)
{
    queue<pair<Node * , int>> Q;
    map<int,int>mp;

    Q.push(make_pair(root, 0));

    while(!Q.empty())
    {
        pair<Node* , int > curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if(mp.count(currHD)==0) 
            mp[currHD] = currNode->data;

        /*
            if we wanted to store bottom view
            mp[currHD] = currNode->data;
        */
        
        if(currNode->left != NULL) 
        {
            pair<Node * , int> left = make_pair(currNode->left , currHD-1);
            Q.push(left);
        }

        if(currNode->left != NULL) 
        {
            pair<Node * , int> right = make_pair(currNode->right , currHD-1);
            Q.push(right);
        }
    }

    //print data
    for(auto i: mp)
    {
        cout<<i.second<<" ";
    }
    cout<<endl;
}


int main()
{

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);

    Node *subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);


    cout << "is sub tree ?  :" << isSubTree(root, subRoot)<<endl;

    return 0;
}