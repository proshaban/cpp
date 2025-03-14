#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        left=right = NULL;
    }
};


/*
=======================================================================================================
1. Build BST
=======================================================================================================
*/

Node* insert(Node* root, int a)
{
    if(root==NULL)
    {
        root = new Node(a);
        return root;
    }

    if(a < root->data)
    {
        root->left = insert(root->left, a);
    }
    else 
    {
        root->right = insert(root->right,a);
    }
    return root;
}

Node* buildBST(int arr[], int n)
{
    Node* root = NULL;

    for(int i=0;i<n;i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
} 


/*
=======================================================================================================
2. Print Inorder & preorder 
=======================================================================================================
*/

void inorder(Node* root)
{
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


/*
=======================================================================================================
3. Serch if a key is presented 
=======================================================================================================
*/


bool search(Node* root, int key)
{
    if(root == NULL) return false;

    if(root->data == key ) return true;

    if(root->data < key) return search(root->right,key);

    else return search(root->left , key);
}


/*
=======================================================================================================
4. Inorder Sucessor of a node. It's the left most node on right subtree
======================================================================================================
*/

Node* getInOrderSuccessor(Node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

/*
=======================================================================================================
4. Delete a node in BST 
======================================================================================================
*/

Node* delNode(Node* root, int val)
{
    if(root == NULL) return NULL;

    if(val < root->data )
    {
        root->left = delNode(root->left , val);
    }
    else if( val > root->data)
    {
        root->right = delNode(root->right , val);
    }
    else {
        //root = val

        //case 1: 0 children
        if(root->left == NULL && root->right ==NULL) 
        {
            delete root;
            return NULL;
        }

        //case 2: 1 Child
        if(root->left == NULL || root->right == NULL)
        {
            return root->left == NULL ? root->right : root->left;
        }

        //case 3: 2 children 

        Node * IS = getInOrderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data);
        return root;
    }

    return root;
}


/*
=======================================================================================================
6. Print in given range
======================================================================================================
*/

void printIntRange(Node* root, int start , int end)
{
    if(root == NULL) return;

    if(root->data >= start && root->data <= end)
    {
        cout<<root->data<<" ";
        printIntRange(root->left, start, end);
        printIntRange(root->right, start , end);
    }
    else if(root->data < start) printIntRange(root->right, start , end);

    else printIntRange(root->left,start,end);
}


/*
=======================================================================================================
7. Print root to leaf paths  
======================================================================================================
*/

void pathHelper(Node* root, vector<int>&path)
{
    if(root == NULL) return;
    path.push_back(root->data);

    //check if leaf node 
    if(root->left == NULL && root->right == NULL )
    {
        //print path
        for(auto i: path) cout<<i<<" ";
        cout<<endl;
        path.pop_back();
        return;
    }

    pathHelper(root->left,path);
    pathHelper(root->right,path);
    
    path.pop_back();
}


void rootToLeafPath(Node*root)
{
    vector<int>path;
    pathHelper(root, path);
}


/*
=======================================================================================================
8. Validate BST 
======================================================================================================
*/

bool validateHelper(Node*root, Node*min, Node* max)
{
    if(root==NULL) return true;

    if(min != NULL && root->data < min->data) return false;

    if(max != NULL && root->data > max->data) return false;

    return validateHelper(root->left, min, root) 
    && validateHelper(root->right, root, max);

}

bool isValidBST(Node * root)
{
    return validateHelper(root, NULL, NULL);
}



/*
=======================================================================================================
9. Buid Balanced BST from Sorted Array  
======================================================================================================
*/

Node* buildBSTFromSorted(int arr[], int st , int end)
{
    if(st > end) return NULL;

    int mid = st + (end-st) / 2;

    Node* curr = new Node(arr[mid]);

    curr->left = buildBSTFromSorted(arr, st , mid-1);
    curr->right = buildBSTFromSorted(arr, mid+1, end);

    return curr;
}



int main()
{
    // arr[6]= {5, 1, 3, 4, 2, 7};
    //int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    
    int arr[7]= {3, 4, 5, 6, 7, 8, 9};

    Node* root = buildBSTFromSorted(arr,0,6);
    
    preorder(root);

    cout<<endl;
}