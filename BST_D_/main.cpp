#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};
// create a node
struct node* NewNode (int data){
    struct node* Node =(struct node*)malloc(sizeof(struct node));
    Node->key=data;
    Node->left= NULL;
    Node->right= NULL;
  return Node;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
// if root is null
    if (root==NULL){
        return ;

    }
    else {
        traverseInOrder(root->left);
         printf("%d " , root->key);
        traverseInOrder(root->right);

    }

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node==NULL){
        struct node* new1=NewNode(key);
        return new1;
    }
    else {
         if (key > node->key)   {
            node->right=insertNode(node->right, key);
         }
         else if (key < node->key){

            node->left=insertNode(node->left, key);
         }


         return node;


    }



}



struct node *FindMin(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL) {
    current = current->left;
  }
  return current;
}


// Deleting a node from the binary tree
struct node *deleteNode(struct node *root, int key) {

  if (root == NULL) {
    return root;
  }
// find the root node which want to delete using recursion

  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  }

  else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  }
// when find the root
  else {
 // when root has no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
//when root has two child
    struct node *temp = FindMin(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
