//Node Declaration(AVL Tree)

struct avl_node
{
    int data;
    struct avl_node *left;                          //declaring a node for left side insertion
    struct avl_node *right;                         //declaring a node for right side insertion
}*root;
//Right- Right Rotation

avl_node *avlTree::rr_rotation(avl_node *parent)
{
	avl_node *temp;                                 //creating a temporary node
    temp = parent->right;                           //storing the value from the right side of the parent node
    parent->right = temp->left;                     //replacing the value on the right side with the value on the left side
    temp->left = parent;                            //replacing the value on the left side with the parent node
    return temp;                                    //returning the modified node
}

//Left- Left Rotation

avl_node *avlTree::ll_rotation(avl_node *parent)
{
    avl_node *temp;                                 //creating a temporary node
    temp = parent->left;                            //storing the value from the left side of the parent node
    parent->left = temp->right;                     //replacing the value on the left side with the value on the right side
    temp->right = parent;                           //replacing the value on the right side with the parent node
    return temp;                                    //returning the modified node
}
//BST 
struct node
{
    int info;
    struct node *left;								//declaring a node for left side insertion
    struct node *right;								//declaring a node for right side insertion
}*rootbs;

//Class Declaration
 
class BST
{
    public:
        void insert(node*,node*);					//method to insert node
        void display(node *, int);					//method to display node
        BST()
        {
            rootbs = NULL;							//initializing to NULL
        }
};

//Inserting Element into the Tree
 
void BST::insert(node *tree, node *newnode)
{
    if (rootbs == NULL)								//if the tree is empty
    {
        rootbs = new node;							//creating new node
        rootbs->info = newnode->info;				//store the value in the data
        rootbs->left = NULL;						//making the left value null
        rootbs->right = NULL;						//making the right value null
        cout<<"Root Node is Added"<<endl;
        return;
    }
    if (tree->info == newnode->info)				//if input value already in the tree
    {
        cout<<"Element already in the tree"<<endl;
        return;
    }
    if (tree->info > newnode->info)					//if input is lesser than the tree value
    {
        if (tree->left != NULL)						//if the left of the tree value is NULL
        {
            insert(tree->left, newnode);			//perform insert operation on the left node
        }
        else
        {
            tree->left = newnode;					//create a new node on the left
            (tree->left)->left = NULL;				//make the left of the left of the tree value NULL
            (tree->left)->right = NULL;				//make the right of the left of the tree value NULL
            cout<<"Node Added To Left"<<endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)					//if the right of the tree value is NULL
        {
            insert(tree->right, newnode);			//perform insert operation on the right node
        }
        else
        {
            tree->right = newnode;					//create a new node on the left
            (tree->right)->left = NULL;				//make the left of the right of the tree value NULL
            (tree->right)->right = NULL;			//make the right of the right of the tree value NULL
            cout<<"Node Added To Right"<<endl;
            return;
        }
    }
}

//Display Tree Structure
 
void BST::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)								//if the tree is not empty
    {
        display(ptr->right, level+1);				//perform the display operation for the right side value
        cout<<endl;
        if (ptr == rootbs)							//if the value is the root value
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
        }
        cout<<ptr->info;							//print the value
        display(ptr->left, level+1);				//perform the display operation for the left side value
    }
}
struct nodebt {
    int n; 											// n < M No. of keys in node will always less than order of B tree
    int keys[M-1]; 									//array of keys
    struct nodebt *p[M];							//(n+1 pointers will be in use)
}*rootbt=NULL;

enum KeyStatus { Duplicate,SearchFailure,Success,InsertIt,LessKeys };

void insert(int key);								//insert method	declaration
void display(struct nodebt *rootbt,int);			//display method declaration
enum KeyStatus ins(struct nodebt *r, int x, int* y, struct nodebt** u);		//Keystatus Ins method declaration
int searchPos(int x,int *key_arr, int n);			//searching method declaration
void eatline(void);									//eatLine method declaration

//Insert Element into the tree

void insert(int key)
{
    struct nodebt *newnode;
    int upKey;
    enum KeyStatus value;
    value = ins(rootbt, key, &upKey, &newnode);		//input value to be added to the tree
    if (value == Duplicate)							//if value already in the tree
        cout<<endl<<"Key already available\n";
    if (value == InsertIt)							//if value to be inserted
    {
        struct nodebt *uproot = rootbt;
        rootbt=new struct nodebt;					//new node created
        rootbt->n = 1;
        rootbt->keys[0] = upKey;
        rootbt->p[0] = uproot;
        rootbt->p[1] = newnode;
    }
}

//KeyStatus Insert

enum KeyStatus ins(struct nodebt *ptr, int key, int *upKey,struct nodebt **newnode)
{
    struct nodebt *newPtr, *lastPtr;
    int pos, i, n,splitPos;
    int newKey, lastKey;
    enum KeyStatus value;
    if (ptr == NULL)								//if node is NULL
    {
        *newnode = NULL;
        *upKey = key;
        return InsertIt;
    }
    n = ptr->n;
    pos = searchPos(key, ptr->keys, n);				//obtaining the position
    if (pos < n && key == ptr->keys[pos])
        return Duplicate;
    value = ins(ptr->p[pos], key, &newKey, &newPtr);
    if (value != InsertIt)
        return value;

    if (n < M - 1)									//if keys in node is less than M-1 where M is order of B tree
    {
        pos = searchPos(newKey, ptr->keys, n);		//obtaining the position

        for (i=n; i>pos; i--)						//shifting the key and pointer right for inserting the new key
        {
            ptr->keys[i] = ptr->keys[i-1];
            ptr->p[i+1] = ptr->p[i];
        }

        ptr->keys[pos] = newKey;					//key is inserted at exact location
        ptr->p[pos+1] = newPtr;
        ++ptr->n; 									//incrementing the number of keys in node
        return Success;
    }

    if (pos == M - 1)								//if keys in nodes are maximum and position of node to be inserted is last
    {
        lastKey = newKey;
        lastPtr = newPtr;
    }
    else 											//if keys in node are maximum and position of node to be inserted is not last
    {
        lastKey = ptr->keys[M-2];
        lastPtr = ptr->p[M-1];
        for (i=M-2; i>pos; i--)
        {
            ptr->keys[i] = ptr->keys[i-1];
            ptr->p[i+1] = ptr->p[i];
        }
        ptr->keys[pos] = newKey;
        ptr->p[pos+1] = newPtr;
    }
    splitPos = (M - 1)/2;
    (*upKey) = ptr->keys[splitPos];

    (*newnode)=new struct nodebt;					//right node after split
    ptr->n = splitPos;								//no. of keys for left splitted node
    (*newnode)->n = M-1-splitPos;					//no. of keys for right splitted node
    for (i=0; i < (*newnode)->n; i++)
    {
        (*newnode)->p[i] = ptr->p[i + splitPos + 1];
        if(i < (*newnode)->n - 1)
            (*newnode)->keys[i] = ptr->keys[i + splitPos + 1];
        else
            (*newnode)->keys[i] = lastKey;
    }
    (*newnode)->p[(*newnode)->n] = lastPtr;
    return InsertIt;
}
