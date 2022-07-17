// Given a binary tree, print that binary tree in vertical order. Vertical order is -


// Print the nodes which are at same vertical order in same line separated by space. Print different levels in different lines.
// Order of different levels in different lines is not important. But in one level, print the element in pre-order format.
// Input Format :
// Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place
// Output Format :
// Required output in given format
// Sample Input :
// 1 2 3 4 5 6 7 -1 8 -1 -1 -1 -1 -1 -1 -1 -1
// Sample Output :
// 7 
// 3 
// 4 
// 2 8 
// 1 5 6 

#include<iostream>
#include <queue>
#include<cmath>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

};

void findMinMax(BinaryTreeNode<int>* node, int *min, int *max, int hd)
    {
        // Base case
        if (node == NULL) return;

        // Update min and max
        if (hd < *min)  *min = hd;
        else if (hd > *max) *max = hd;

        // Recur for left and right subtrees
        findMinMax(node->left, min, max, hd-1);
        findMinMax(node->right, min, max, hd+1);
    }

void printVerticalLine(BinaryTreeNode<int>* node, int line_no, int hd)
{
    if (node == NULL) return;

    if (hd == line_no)
        cout << node->data << " ";

    printVerticalLine(node->left, line_no, hd-1);
    printVerticalLine(node->right, line_no, hd+1);
}

void printBinaryTreeVerticalOrder(BinaryTreeNode<int>* root) {	 
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    for (int line_no = min; line_no <= max; line_no++)
    {
        printVerticalLine(root, line_no, 0);
        cout << endl;
    } 	

}


BinaryTreeNode<int>* takeInputLevelWise() {
    int data;
//  cout << "Enter root : ";
    cin >> data;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);

    queue<BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()) {
        BinaryTreeNode<int> *current = pendingNodes.front();
        pendingNodes.pop();

        int leftData, rightData;
    //  cout << "Enter left child of : " << current -> data << " : ";
        cin >> leftData;

        if(leftData != -1) {
            BinaryTreeNode<int> *left = new BinaryTreeNode<int>(leftData);
            current -> left = left;
            pendingNodes.push(left);
        }

    //  cout << "Enter right child of  " << current -> data << " : ";
        cin >> rightData;

        if(rightData != -1) {
            BinaryTreeNode<int> *right = new BinaryTreeNode<int>(rightData);
            current -> right = right;
            pendingNodes.push(right);
        }
    }
    return root;

}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBinaryTreeVerticalOrder(root);
    return 0;
}
