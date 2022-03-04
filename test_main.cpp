#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<int, std::string>  m;
    m.insert(std::make_pair<int, std::string>(5, "five"));
    m.insert(std::make_pair<int, std::string>(3, "three"));
    m.insert(std::make_pair<int, std::string>(2, "two"));
    m.insert(std::make_pair<int, std::string>(20, "twenty"));
    m.insert(std::make_pair<int, std::string>(9, "five"));
    m.insert(std::make_pair<int, std::string>(-6, "five"));
    m.insert(std::make_pair<int, std::string>(15, "five"));
    m.insert(std::make_pair<int, std::string>(10, "five"));
    m.insert(std::make_pair<int, std::string>(-20, "five"));
    m.insert(std::make_pair<int, std::string>(7, "five"));
    m.insert(std::make_pair<int, std::string>(-13, "five"));

    // std::map<int, std::string>::iterator j(&(std::pair<int, std::string>(3, "three")));


    



    for (std::map<int, std::string>::iterator i = m.begin(); i != m.end(); i++)
        std::cout<<  i->first << std::endl;
    return 0;
}



Node* deleteNode(Node* root, int key)
{
     
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater
    // than the root's key, then it lies
    // in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then
    // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            Node *temp = root->left ? root->left : root->right;
 
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            *root = *temp; // Copy the contents of
                           // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);
 
            // Copy the inorder successor's
            // data to this node
            root->key = temp->key;
 
            // Delete the inorder successor
            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    // If the tree had only one node
    // then return
    if (root == NULL)
    return root;
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));
 
    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalance(root);
 
    // If this node becomes unbalanced,
    // then there are 4 cases
 
    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}