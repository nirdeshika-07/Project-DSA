#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
#include<cstdlib>
#include<stdlib.h>
#define M 3
using namespace std;

//Node Declaration(AVL Tree)

struct avl_node
{
    int data;
    struct avl_node *left;                          //declaring a node for left side insertion
    struct avl_node *right;                         //declaring a node for right side insertion
}*root;
class avlTree
{
    public:
        int height(avl_node *);                     //integer method for height of the avl tree
        int diff(avl_node *);                       //integer method for difference between left and right side heights
        avl_node *rr_rotation(avl_node *);          //method for RR rotation
        avl_node *ll_rotation(avl_node *);          //method for LL rotation
        avl_node *lr_rotation(avl_node *);          //method for LR rotation
        avl_node *rl_rotation(avl_node *);          //method for RL rotation
        avl_node *balance(avl_node *);              //method to balance the tree
        avl_node *insert(avl_node *, int );         //method to insert the elements into the tree
        void display(avl_node *, int);              //method to display the tree

        avlTree()                                   //constructor to initialize the node to NULL
        {
            root = NULL;
        }
};

//Height of AVL Tree

int avlTree::height(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);         //height towards the left of the tree
        int r_height = height (temp->right);        //height towards the right of the tree
        int max_height = max (l_height, r_height);  //choosing the max value between the left and right heights
        h = max_height + 1;                         //adding 1 to the max height obtained
    }
    return h;
}

//Height Difference

int avlTree::diff(avl_node *temp)
{
    int l_height = height (temp->left);             //height towards the left of the tree
    int r_height = height (temp->right);            //height towards the right of the tree
    int b_factor= l_height - r_height;              //difference between the left and right heights
    return b_factor;
}

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
//Left - Right Rotation
 
avl_node *avlTree::lr_rotation(avl_node *parent)
{
    avl_node *temp;                                 //creating a temporary node
    temp = parent->left;                            //storing the value from the left side of the parent node
    parent->left = rr_rotation (temp);              //performing RR rotation on the node and storing it on the left side
    return ll_rotation (parent);                    //performing LL rotation and returning the modified node
}

//Right- Left Rotation

avl_node *avlTree::rl_rotation(avl_node *parent)
{
    avl_node *temp;                                 //creating a temporary node
    temp = parent->right;                           //storing the value from the right side of the parent node
    parent->right = ll_rotation (temp);             //performing LL rotation on the node and storing it on the right side
    return rr_rotation (parent);                    //performing RR rotation and returning the modified node
}

//Balancing AVL Tree

avl_node *avlTree::balance(avl_node *temp)
{
    int bal_factor = diff (temp);                   //retrieving the height difference value
    if (bal_factor > 1)                             //if height difference is greater than 1
    {
        if (diff (temp->left) > 0)                  //if height difference on left node is greater than 0
            temp = ll_rotation (temp);              //perform LL rotation
        else
            temp = lr_rotation (temp);              //perform RR rotation
    }
    else if (bal_factor < -1)                       //if height difference is lesser than -1
    {
        if (diff (temp->right) > 0)                 //if height difference on right node is greater than 0
            temp = rl_rotation (temp);              //perform RL rotation
        else
            temp = rr_rotation (temp);              //perform RR rotation
    }
    return temp;
}

//Insert Element into the tree
 
avl_node *avlTree::insert(avl_node *root, int value)
{
    if (root == NULL)                               //if the tree is empty
    {
        root = new avl_node;                        //add a new node to the root
        root->data = value;                         //store the value in the data
        root->left = NULL;                          //making the left value null
        root->right = NULL;                         //making the right value null
        return root;                                //return the added node
    }
    else if (value < root->data)                    //if the input value is lesser than the root value
    {
        root->left = insert(root->left, value);     //go towards the left side and check the root again (insert operation)
        root = balance (root);                      //balance the tree with the new added node
    }
    else if (value >= root->data)                   //if the input value is greater than the root value
    {
        root->right = insert(root->right, value);   //go towards the right side and check the root again (insert operation)
        root = balance (root);                      //balance the tree with the new added node
    }
    return root;
}


//Display AVL Tree

void avlTree::display(avl_node *ptr, int level)
{
    int i;
    if (ptr!=NULL)                                  //if the tree is not empty
    {
        display(ptr->right, level + 1);             //perform the display operation for the right side value
        printf("\n");
        if (ptr == root)                            //if the value is the root value
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;                            //print the value
        display(ptr->left, level + 1);              //perform the display operation for the left side value
    }
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
//Display Btree

void display(struct nodebt *ptr, int blanks)
{
	if (ptr)
    {
        int i;
        for(i=1; i<=blanks; i++)
            cout<<" ";
        for (i=0; i < ptr->n; i++)
            cout<<ptr->keys[i]<<" ";
        cout<<"\n";
        for (i=0; i <= ptr->n; i++)
            display(ptr->p[i], blanks+10);
    }
}

//Search for the position

int searchPos(int key, int *key_arr, int n)
{
    int pos=0;
    while (pos < n && key > key_arr[pos])
        pos++;
    return pos;
}

//EatLine

void eatline(void) 
{
  	char c;
  	cout<<" ";
  	while(c=getchar()!='\n');
}

int main()
{
	system("cls");
  	avlTree a;            //creating an object of avlTree class
  	BST bst;              //creating an object of BST class
  	node *temp;           //creating an temporary node
 	cout<<"\t\t\t\t\tTHE TREE REPRESENTATION"<<endl<<endl;
 	while(1)
 	{
  		int c,n,e;
  		cout<<endl<<"\t\t\t\t\t1. ENTER THE NUMBER FOR AVL TREE";
  		cout<<endl<<"\t\t\t\t\t2. ENTER THE NUMBER FOR B-TREE";
  		cout<<endl<<"\t\t\t\t\t3. ENTER THE NUMBER FOR BINARY SEARCH TREE";
  		cout<<endl<<"\t\t\t\t\t4. DISPLAY THE NUMBER FOR AVL TREE";
  		cout<<endl<<"\t\t\t\t\t5. DISPLAY THE NUMBER FOR B-TREE";
  		cout<<endl<<"\t\t\t\t\t6. DISPLAY THE NUMBER FOR BINARY SEARCH TREE";
  		cout<<endl<<"\t\t\t\t\t7. EXIT";
  		cout<<endl<<"\t\t\t\t\tWhat would you like to do? ";    				//Displaying the options to the user
  		cin>>c;
  		switch(c)
  		{
   			case 1: 
			   	cout<<endl<<"How many elements do you want to enter for AVL tree: ";      //If user chooses to enter, ask how many elements they want to enter?
           		cin>>e;
           		for(int i=0;i<e;i++)
           		{
            		cout<<endl<<"Enter the number: ";                        //Taking in the input values
   					cin>>n;
            		//avl insertion
            		root=a.insert(root,n);
           		}
            	break;

   			case 2:
   				cout<<endl<<"How many elements do you want to enter for B-tree: ";      //If user chooses to enter, ask how many elements they want to enter?
           		cin>>e;
           		for(int i=0;i<e;i++)
           		{
            		cout<<endl<<"Enter the number: ";                        //Taking in the input values
   					cin>>n;
            		//btree insertion
            		eatline();
            		insert(n);
           		}
            	break;
           		
			case 3: 
				cout<<endl<<"How many elements do you want to enter for BST: ";      //If user chooses to enter, ask how many elements they want to enter?
           		cin>>e;
           		for(int i=0;i<e;i++)
           		{
            		cout<<endl<<"Enter the number: ";                        //Taking in the input values
   					cin>>n;
            		//bst insertion
            		temp=new node;
            		temp->info=n;
            		bst.insert(rootbs,temp);
           		}
            	break;
            
			case 4: 
				//AVL display
           		cout<<endl<<endl<<endl<<" \t\tAVL TREE: "<<endl;
           		a.display(root,1);
           		cout<<endl;
				break;
				
            case 5: 
            	//Btree display
           		cout<<endl<<endl<<endl<<"\t\t BTREE: "<<endl;
           		display(rootbt,0);
           		cout<<endl;
				break;
            
            case 6: 
            	//BST display
           		cout<<endl<<endl<<endl<<"\t\t BST: "<<endl;
           		bst.display(rootbs,1);
           		cout<<endl;
				break;
            
            case 7: 
            	exit(1);
            	break;	
            
   			default: 
			   	cout<<endl<<"Wrong input";      //If they enter an invalid option
   		}
  	}
  	return 0;
}
