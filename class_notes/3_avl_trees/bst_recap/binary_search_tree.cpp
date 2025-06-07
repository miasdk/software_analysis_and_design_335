#include<iostream>
#include<queue>
#include"binary_search_tree.h"


BinarySearchTree::BinarySearchTree():root_(nullptr){}


BinarySearchTree::BinarySearchTree(const BinarySearchTree& other)
{
    root_=copyTree(other.root_);
}


BinarySearchTree::BinarySearchTree(BinarySearchTree&& other)
{
    root_=other.root_;
    other.root_=nullptr;
}


BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& other)
{
    destroy(root_);
    root_=copyTree(other.root_);
    return *this;
}


BinarySearchTree& BinarySearchTree::operator=(BinarySearchTree&& other)
{
    destroy(root_);
    root_=other.root_;
    other.root_=nullptr;
    return *this;
}


BinarySearchTree::~BinarySearchTree()
{
    destroy(root_);
    root_=nullptr;
}


//post order example
void BinarySearchTree::destroy(Node* curr_del)
{
    if(!curr_del) return;

    destroy(curr_del->left_);
    destroy(curr_del->right_);

    delete curr_del;
    curr_del=nullptr;
}


Node* BinarySearchTree::insert(Node* start, int val)
{
     if (!root_) 
    {
        root_= new Node(val);
        return root_;
    }

    if (!start) return new Node(val);  // found position to insert

    else if (val < start->data_) start->left_ = insert(start->left_, val);  

    else if (val > start->data_) start->right_ = insert(start->right_, val); 
    
    return start;
}


//inorder example
void BinarySearchTree::printTree(Node* start)
{
    if (!start) return;

    printTree(start->left_);
    std::cout<<start->data_<<" -> ";
    printTree(start->right_);
}


Node* BinarySearchTree::search(Node* start, int val)
{
    Node* curr=start;
    while (curr)
    {
        if(val < curr->data_) curr=curr->left_;

        else if (val > curr->data_) curr=curr->right_;

        else return curr; // val==curr->data_, so we found node
    }

    return nullptr;
}


Node* BinarySearchTree::deleteNode(Node* start, int val)
{
    if(!start) return nullptr;

    else if(val < start->data_) start->left_=deleteNode(start->left_,val);

    else if(val > start->data_) start->right_=deleteNode(start->right_,val); 
    
    else
    {
        if(start->left_ && start->right_)//two children
        {
            Node* min_node = findMin( start->right_ );
            start->data_ = min_node->data_;
            start->right_ = deleteNode( start->right_, start->data_ );
        }


       else //at most one children
       {
            Node* save_spot=start->left_?start->left_:start->right_;
            delete start;
            return save_spot;
       } 

    }

    return start;
}


Node* BinarySearchTree::findMin(Node* start)
{
    if(!start) return nullptr;
    
    while(start->left_) start=start->left_;

    return start;
}


void BinarySearchTree::breadthFirstSerachTraversal()
{
    std::queue<Node*> q;
    if(root_)    q.push(root_);
    int nodes_per_level=1;
    while(!q.empty())
    {
        for(int i =0; i<nodes_per_level;i++)
        {
            Node* n = q.front();
            q.pop();
            std::cout<<n->data_<<"->";
            if(n->left_) q.push(n->left_);
            if(n->right_) q.push(n->right_);
        }
        nodes_per_level=q.size();
        std::cout<<std::endl;
    }
}


//preorder example
Node* BinarySearchTree::copyTree(Node* start)
{
    if(!start) return nullptr;

    Node* n=new Node(start->data_);
    n->left_=copyTree(start->left_);
    n->right_=copyTree(start->right_);
    return n;
}


bool BinarySearchTree::insert(int val)
{
    return insert(root_,val);
}


void BinarySearchTree::printTree()
{
    printTree(root_);
}


bool BinarySearchTree::deleteNode(int val)
{
    return deleteNode(root_,val);
}


int BinarySearchTree::findMin()
{
    return findMin(root_)->data_;
}


bool BinarySearchTree::search(int val)
{
   return search(root_,val);
}
