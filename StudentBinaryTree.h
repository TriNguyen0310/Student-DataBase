#ifndef STUDENTBINARYTREE_H
#define STUDENTBINARYTREE_H
#include <string>
#include <iostream>
#include "Student.h"

using namespace std;

//Binary Tree written by Noah
template<typename T>
class TreeNode {
  public:
  
    T element;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode<T>* parent;

    T getElement(){
      return element;
    }

    TreeNode() {
      left = nullptr;
      right = nullptr;
      parent = nullptr;
    }

    TreeNode(const T& e) {
      this->element = e;
      left = nullptr;
      right = nullptr;
      parent = nullptr;
    }

    TreeNode(const T& e, TreeNode &node) {
      this->element = e;
      left = nullptr;
      right = nullptr;
      parent = &node;
    }

    void operator=(TreeNode* node){
      this->element = node->getElement();
      this->left = node->left;
      this->right = node->right;
      this->parent = node->parent;
    }

    void operator=(TreeNode node){
      this->element = node.getElement();
      this->left = node.left;
      this->right = node.right;
      this->parent = node.parent;
    }
};

template<typename T>
class Tree {
  public:

    Tree(){
    }

    Tree(const T& node){
      TreeNode<T>* stump = new TreeNode<T>(node);
      this->stump = stump;
    }

    virtual ~Tree(){
      clear();
    }
  
    TreeNode<T> getStump(){
      TreeNode<T>* temp = stump;
      return *temp;
    }

    void clear(){
      if(this->stump->left != nullptr){
        clear(*this->stump->left);
      }
      if(this->stump->right != nullptr){
        clear(*this->stump->right);
      }
      this->stump = nullptr;
      this->size = 0;
    }

    void clear(TreeNode<T>& treenode){
      if(treenode.left != nullptr){
        clear(*treenode.left);
      }
      if(treenode.right != nullptr){
        clear(*treenode.right);
      }
      TreeNode<T>* temp = &treenode;
      delete temp;
    }

    void addFirst(T& leaf){
      stump = new TreeNode<T>(leaf);
      stump->parent = stump;
    }

    void add(T& leaf){
      if(size == 0){
        addFirst(leaf);
        size++;
      } else {
        if(leaf < stump->element){
          addLeft(*stump, leaf);
        } else {
          addRight(*stump, leaf);
        }
      }
    }

    void addNode(TreeNode<T>& node, T& leaf){
      if(leaf < node.element){
        addLeft(node, leaf);
      } else {
        addRight(node, leaf);
      }
    }

    void addLeft(TreeNode<T>& node, T& leaf){
      if(node.left == nullptr){
        //cout << "\n\n" << leaf.getLast_name();
        //cout << " <- " << node.element.getLast_name();
        //cout << "\n";
        TreeNode<T>* newNode = new TreeNode<T>(leaf, node);
        node.left = newNode;
        size++;
      } else {
        addNode(*node.left, leaf);
      }
    }

    void addRight(TreeNode<T>& node, T& leaf){
      if(node.right == nullptr){
        //cout << "\n\n" << setw(12) << node.element.getLast_name();
        //cout << " -> " << leaf.getLast_name();
        //cout << "\n";
        TreeNode<T>* newNode = new TreeNode<T>(leaf, node);
        node.right = newNode;
        size++;
      } else {
        addNode(*node.right, leaf);
      }
    }

    int getSize(){
      return this->size;
    }

  private:
    TreeNode<T>* stump;
    int size;
};

void initBinaryTree(Tree<Student>* tree, const LinkedList<Student> list){
  for(int i = 0; i < list.getSize(); i++){
    Student stud = list.get(i);
    tree->add(stud);
  }
}

LinkedList<Student> traverse(Tree<Student>* tree){
  int input = 0;
  TreeNode<Student> current;
  LinkedList<Student> list;
  current = tree->getStump();

  do{

    Student s = current.getElement();
    Student t;
    Student k;
    if(current.left != nullptr){
      t = current.left->getElement();

    } else {

      t.setID(0);
      t.setFirst_name("Branch");
      t.setLast_name("End of");
    
    }
    if(current.right != nullptr){
      k = current.right->getElement();

    } else {

      k.setID(0);
      k.setFirst_name("Branch");
      k.setLast_name("End of");
    }
    //cout << "\x1B[2J\x1B[H";
    cout << "\x1B[2J\x1B[H" << "\n" << setw(20) << "ID: " << s.getID() << " - " << s.getLast_name() << ", " << s.getFirst_name() << "\n\n" << setw(40) << "/                  \\\n\n" << "ID: " << t.getID() << " - " << t.getLast_name() << ", " << t.getFirst_name() << setw(12) << "ID: " << k.getID() << " - " << k.getLast_name() << ", " << k.getFirst_name() << "\n\n1: Left\n2: Right\n3: Up\n4: Select Student\n5: Exit\n-> ";
    
    if(input == 4){
      cout << "\n Successfully Added\n-> ";
    }

    cin >> input;
    switch(input){
      case(1):
        if(current.left != nullptr){
          current = current.left;
        } else {
          cout << "Error: End of Branch";
        }
        break;
      case(2):
        if(current.right != nullptr){
          current = current.right;
        } else {
          cout << "Error: End of Branch";
        }
        break;
      case(3):
        current = current.parent;
        break;
      case(4):
        list.add(s);
        break;
    }
  } while (input != 5);
  return list;
}

LinkedList<Student> binaryTreeSearch(Tree<Student>* tree){
  
  LinkedList<Student> temp;
  string input = "last_name";
  TreeNode<Student> current;
  current = tree->getStump();
  cout << "\nPlease enter last name of student: ";
  cin >> input;
  
  for_each(input.begin(), input.end(), [](char & c) {
        c = ::tolower(c);
  });
  
  bool atEnd = false;
  do{
    Student s = current.getElement();
    string lastname = s.getLast_name();

    if(s.getLast_name() == input){
      temp.add(s);
    }
    if(s.getLast_name() > input){
      if(current.left != nullptr){
          current = current.left;
        } else {
          atEnd = true;
        }
    } else {
      if(current.right != nullptr){
        current = current.right;
      } else {
        atEnd = true;
      }
    }
  } while (atEnd == false);
  return temp;
}
#endif