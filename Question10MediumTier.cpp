//Ryan Howse
//6/30/2021
//BST Construction
//I got the insertion function correct but the removal function
//was much more complicated than I expected, consulted help, comments explain

#include <vector>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

	//inserting a new value into the tree
  BST &insert(int val) {
    bool search = true;
		BST *currentNode = this;
		//if the root is empty then this won't work, so return
		if(currentNode == NULL){
			return *this;
		}
		while(search){
			if(currentNode->value > val){
				//go left
				if(currentNode->left == NULL){
					//add the val
					BST *temp = new BST(val);
					currentNode->left = temp;
					search = false;
				}
				else{
					currentNode = currentNode->left;
				}
			}
			else{
				//go right
				if(currentNode->right == NULL){
					//add the val
					BST *temp = new BST(val);
					currentNode->right = temp;
					search = false;
				}
				else{
					currentNode = currentNode->right;
				}
			}
		}
    return *this;
  }

	//find if a value is contained within the tree
  bool contains(int val) {
    BST *currentNode = this;
		while (currentNode != nullptr){
			if(val < currentNode->value){
				currentNode = currentNode->left;
			}
			else if(val > currentNode->value){
				currentNode = currentNode->right;
			}
			else{
				return true;
			}
		}
		return false;
  }

	//remove a value from the tree and reconnect everything
  BST &remove(int val, BST *parentNode = nullptr) {
		BST *currentNode = this;
		while(currentNode != nullptr){
			//find the value, keeping track of the previous node as we go
			if(val < currentNode->value){
				parentNode = currentNode;
				currentNode = currentNode->left;
			}
			else if(val > currentNode->value){
				parentNode = currentNode;
				currentNode = currentNode->right;
			}
			//here we have found the element to remove
			else{
				//if there's a node on either side, find the minimum value that is greater than the current value
				//and replace the current value with it
				//this esures that the tree remains valid
				//after that, remove the replaced value, as it has moved
				if(currentNode->left != nullptr && currentNode->right != nullptr){
					currentNode->value = currentNode->right->getMinValue();
					currentNode->right->remove(currentNode->value, currentNode);
				}
				//if the target value is the root node
				else if(parentNode == nullptr){
					if(currentNode->left != nullptr){
						currentNode->value = currentNode->left->value;
						currentNode->right = currentNode->left->right;
						currentNode->left = currentNode->left->left;
					}
					else if(currentNode->right != nullptr){
						currentNode->value = currentNode->right->value;
						currentNode->left = currentNode->right->left;
						currentNode->right = currentNode->right->right;
					}
					else{
						//single node tree, do nothing
					}
				}
				else if(parentNode->left == currentNode){
					//the parent left node becomes the current left node, if the left node
					//is not a nullptr
					//if it is, the current right node becomes the parent left node
					//see c++ conditional ternary operator for more information
					parentNode->left = currentNode->left != nullptr ? currentNode->left : currentNode->right;
				}
				else if(parentNode->right == currentNode){
					parentNode->right = currentNode->left != nullptr ? currentNode->left : currentNode->right;
				}
				break;
			}
		}
    return *this;
	}
	
	//this is a helper function for the removal function
	//that finds the minimum value attached to a node
	int getMinValue(){
		if(left == nullptr){
			return value;
		}
		else{
			return left->getMinValue();
		}
	}
};
