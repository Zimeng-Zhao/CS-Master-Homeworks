#include<iostream>
using namespace std;

class Vertex{ // class vertex with the required properties to be in a binary tree
    public:
    Vertex* leftchild;
    Vertex* rightchild;
    int key;

    Vertex(int val){
        key = val;
        leftchild = NULL;
        rightchild = NULL;
    }
};

class BST{ //class for binary search tree that utilizes the vertex class
    public:
    Vertex* root = NULL;

    void BST_Insert(int key){
        Vertex* newVertex = new Vertex(key);
        // implement the insert function for Binary search tree insert operation
        if(root == NULL){
            root = newVertex;
        }
        else{
            Vertex* curr = root;
            while(true){
                if(key < curr->key){
                    if(curr->leftchild == NULL){
                        curr->leftchild = newVertex;
                        break;
                    }
                    else{
                        curr = curr->leftchild;
                    }
                }
                else{// key > curr.key
                    if(curr->rightchild == NULL){
                        curr->rightchild = newVertex;
                        break;
                    }
                    else{
                        curr = curr->rightchild;
                    }
                }
            }
        }

    }

    void BST_Inorder_Traversal (Vertex* v){
        // implement inorder traversal of the binary search tree to print the inorder traversal output
        if (v == NULL){
            return;
        }
        BST_Inorder_Traversal(v->leftchild);
        cout << v->key << " ";
        BST_Inorder_Traversal(v->rightchild);
    }

    void BST_Tree_Sort(int values[],int length){
        for(int i = 0; i < length; i++){
            BST_Insert(values[i]);
        }
        BST_Inorder_Traversal(root);

    }
};

int main(){
    BST B1;

    int array[100];
    for(int i = 0 ; i < 100 ; i++){ // sample for generating random array
        array[i] = rand()%1000;
    }

    for (int i = 0; i < 100; i++) {
        B1.BST_Insert(array[i]); // inserting the array elements to the BST
    }

    B1.BST_Tree_Sort(array,100); // printing the elements of the array in the sorted way

    return 0;
}
