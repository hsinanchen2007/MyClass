/*

https://www.educative.io/courses/grokking-the-coding-interview/JYVW7l2L4EJ

Solution 
This problem follows the Binary Tree Path Sum pattern. We can follow the same DFS approach. 
There will be a few differences:

    1. At every step, we need to find the height of both children of the current node. For this, 
    we will make two recursive calls similar to DFS.
    2. The height of the current node will be equal to the maximum of the heights of its left or 
    right children, plus ‘1’ for the current node.

    3. The tree diameter at the current node will be equal to the height of the left child plus 
    the height of the right child plus ‘1’ for the current node: diameter = leftTreeHeight + 
    rightTreeHeight + 1. To find the overall tree diameter, we will use a class level variable. 
    This variable will store the maximum diameter of all the nodes visited so far, hence, eventually, 
    it will have the final tree diameter.

Time complexity
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes 
in the tree. This is due to the fact that we traverse each node once.

Space complexity
The space complexity of the above algorithm will be O(N) in the worst case. This space will be 
used to store the recursion stack. The worst case will happen when the given tree is a linked 
list (i.e., every node has only one child).

*/

using namespace std;

#include <iostream>
#include <vector>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class TreeDiameter {
 public:
  static int findDiameter(TreeNode *root) {
    int treeDiameter = 0;
    calculateHeight(root, treeDiameter);
    return treeDiameter;
  }

 private:
  static int calculateHeight(TreeNode *currentNode, int &treeDiameter) {
    if (currentNode == nullptr) {
      return 0;
    }

    int leftTreeHeight = calculateHeight(currentNode->left, treeDiameter);
    int rightTreeHeight = calculateHeight(currentNode->right, treeDiameter);

    // if the current node doesn't have a left or right subtree, we can't have
    // a path passing through it, since we need a leaf node on each side
    if (leftTreeHeight != 0 && rightTreeHeight != 0) {
      // diameter at the current node will be equal to the height of left subtree +
      // the height of right sub-trees + '1' for the current node
      int diameter = leftTreeHeight + rightTreeHeight + 1;

      // update the global tree diameter
      treeDiameter = max(treeDiameter, diameter);
    }

    // height of the current node will be equal to the maximum of the heights of
    // left or right subtrees plus '1' for the current node
    return max(leftTreeHeight, rightTreeHeight) + 1;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
  root->left->left = nullptr;
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  root->right->left->right->left = new TreeNode(10);
  root->right->right->left->left = new TreeNode(11);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
}
