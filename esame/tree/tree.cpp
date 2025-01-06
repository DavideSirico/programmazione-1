#include <iostream>
using namespace std;
typedef struct tree {
  int info;
  struct tree * left;
  struct tree * right;
} tree;

typedef struct _list {
  int info;
  struct _list * next;
} list;

void insert(tree * & result, const int num) {
    if (result == NULL) {
        result = new tree;
        *result = {num, NULL, NULL};
    } else if (result->info > num) {
        insert(result->left, num);
    } else {
        insert(result->right, num);
    }
}
void print_tree(const tree * root, int spazio = 0){
    if (root != NULL) {
        spazio++;
        print_tree(root->right, spazio);

        for (int i = 1; i < spazio; i++) std::cout<<"  ";
        std::cout<<root->info<<"\n";
        print_tree(root->left, spazio);
    }
}

void delete_tree(tree * & root) {
    if (root != NULL) {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
        root = NULL;
    }
}

void inorder(tree * root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->info << " ";
    inorder(root->right);
}

void preorder(tree * root) {
    if (root == nullptr)
        return;
    cout << root->info << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(tree * node) {
    if (node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->info << " ";
}

// Function to delete the deepest node in binary tree
void delet_deepest(tree * root, tree* dNode) {
    queue<tree*> q;
    q.push(root);

    tree * curr;
    while (!q.empty()) {
        curr = q.front();
        q.pop();

        // If current node is the deepest
          // node, delete it
        if (curr == dNode) {  
            curr = nullptr;
            delete (dNode);
            return;
        }

        // Check the right child first
        if (curr->right) {
          
            // If right child is the deepest
              // node, delete it
            if (curr->right == dNode) {
                curr->right = nullptr;
                delete (dNode);
                return;
            } 
            q.push(curr->right);
        }

        // Check the left child
        if (curr->left) {
          
            // If left child is the deepest 
              // node, delete it
            if (curr->left == dNode) {
                curr->left = nullptr;
                delete (dNode);
                return;
            } 
            q.push(curr->left);
        }
    }
}

// Function to delete the node with the given key
tree* deletion(tree* root, int key) {
  
    // If the tree is empty, return null
    if (root == nullptr)
        return nullptr;

    // If the tree has only one node
    if (root->left == nullptr && root->right == nullptr) {
      
        // If the root node is the key, delete it
        if (root->info == key)
            return nullptr;
        else
            return root;
    }

    queue<tree*> q;
    q.push(root);

    tree * curr;
    tree * keyNode = nullptr;

    // Level order traversal to find the deepest
      // node and the key node
    while (!q.empty()) {
        curr = q.front();
        q.pop();

        // If current node is the key node
        if (curr->info == key)
            keyNode = curr;

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }

    // If key node is found, replace its data
      // with the deepest node
    if (keyNode != nullptr) {
      
          // Store the data of the deepest node
        int x = curr->info;  
      
          // Replace key node data with deepest
          // node's data
        keyNode->info = x;  
      
          // Delete the deepest node
        delet_deepest(root, curr);  
    }
    return root;
}

tree* InsertNode(tree* root, int data) {
    // If the tree is empty, assign new
      // node address to root
    if (root == nullptr) {
        root = new tree;
        root->info = data;
        return root;
    }

    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<tree*> q;
    q.push(root);

    while (!q.empty()) {
      
          // Fron a front element in queue
        tree* curr = q.front();
        q.pop();
        
          // First check left if left is null 
          // insert node in left otherwise chaeck for right
        if (curr->left != nullptr)
            q.push(curr->left);
        else {
            curr->left->info = data;
            return root;
        }
    
        if (curr->right != nullptr)
            q.push(curr->right);
        else {
            curr->right->info = data;
            return root;
        }
    }
}


// Inorder traversal to store elements of the
// tree in sorted order
void storeInorder(tree* root, list* &nodes) {
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree
    storeInorder(root->left, nodes);

    // Store the node data
    list* newNode = new list;
    newNode->info = root->info;
    newNode->next = nodes;
    nodes = newNode;

    // Traverse the right subtree
    storeInorder(root->right, nodes);
}

// Function to build a balanced BST from a sorted linked list
tree* buildBalancedTree(list* &nodes, int start, int end) {
    // Base case
    if (start > end) {
        return nullptr;
    }

    // Get the middle element and make it the root
    int mid = (start + end) / 2;

    // Recursively build the left subtree
    tree* leftChild = buildBalancedTree(nodes, start, mid - 1);

    // Allocate memory for root and assign the middle element
    tree* root = new tree;
    root->info = nodes->info;
    root->left = leftChild;

    // Move to the next element in the list
    nodes = nodes->next;

    // Recursively build the right subtree
    root->right = buildBalancedTree(nodes, mid + 1, end);

    return root;
}

// Function to balance a BST
tree* balanceBST(tree* root) {
    list* nodes = nullptr;

    // Store the nodes in sorted order
    storeInorder(root, nodes);

    // Count the number of nodes in the list
    int n = 0;
    list* temp = nodes;
    while (temp != nullptr) {
        n++;
        temp = temp->next;
    }

    // Build the balanced tree from the sorted nodes
    return buildBalancedTree(nodes, 0, n - 1);
}

int main() {
    /*
    alberi
        - visite
        - togliere un elemento
        - aggiungere un elemento
        bilanciare
        fare la somma degli elementi sottostanti
        controllare se un elemento esiste
    */

    return 0;
}