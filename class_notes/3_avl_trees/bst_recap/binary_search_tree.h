struct Node 
{
    int data_;             // Data stored in the node
    Node* left_;           // Pointer to the left child
    Node* right_;          // Pointer to the right child

    // Constructor to initialize a new node
    Node(int value):data_(value), left_(nullptr), right_(nullptr) {}
};

class BinarySearchTree
{
    private:
        Node* root_;

        Node* insert(Node* start, int val);
        void printTree(Node* start);
        Node* deleteNode(Node* start, int val);
        Node* findMin(Node* start);
        void destroy(Node* curr_del); //helper function for destructor 
        Node* copyTree(Node* start); //helper function for copy constructor
        Node* search(Node* start, int val);

    public:
        //big 5
        BinarySearchTree(); 
        ~BinarySearchTree(); 
        BinarySearchTree(const BinarySearchTree& other);
        BinarySearchTree(BinarySearchTree&& other); 
        BinarySearchTree& operator=(const BinarySearchTree& other);
        BinarySearchTree& operator=(BinarySearchTree&& other);

        //wrappers
        bool search(int val); 
        bool insert(int val); 
        void printTree(); 
        bool deleteNode(int val); 
        int findMin(); 
        void breadthFirstSerachTraversal();   
};