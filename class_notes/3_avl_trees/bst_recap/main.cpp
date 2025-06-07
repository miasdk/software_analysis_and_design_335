#include<iostream>
#include"binary_search_tree.h"


int main()
{
    BinarySearchTree bst1;
    bst1.insert(50);
    bst1.insert(30);
    bst1.insert(70);
    bst1.insert(20);
    bst1.insert(40);
    bst1.insert(60);
    bst1.insert(80);
    bst1.insert(15);
    bst1.insert(10);
    bst1.insert(35);

    BinarySearchTree bst2;
    bst2.insert(150);
    bst2.insert(130);
    bst2.insert(170);
    bst2.insert(120);
    bst2.insert(140);
    bst2.insert(160);
    bst2.insert(180);
    bst2.insert(115);
    bst2.insert(110);
    bst2.insert(135);


    //BinarySearchTree bst2(bst1);
    //BinarySearchTree bst2(std::move(bst1));
    // bst2.deleteNode(40);
    // bst2.insert(47);
    //bst2=bst1;
    bst2=std::move(bst1);

    std::cout<<"Level Order: "<<std::endl;
    bst1.breadthFirstSerachTraversal();
    std::cout<<std::endl;


    std::cout<<"Level Order: "<<std::endl;
    bst2.breadthFirstSerachTraversal();
    std::cout<<std::endl;

    //std::cout<<"found: "<<bst2.search(117)<<std::endl;
    return 0;
}