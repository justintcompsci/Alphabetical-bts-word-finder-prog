#include <iostream>
#include <new>
#include<iomanip>
#include"CircularLinkedQueue.h"
using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE


class BST
{
public:
	/***** Function Members *****/
	BST();
	/*------------------------------------------------------------------------
	  Construct a BST object.

	  Precondition:  None.
	  Postcondition: An empty BST has been constructed.
	 -----------------------------------------------------------------------*/

	bool empty() const;
	/*------------------------------------------------------------------------
	  Check if BST is empty.

	  Precondition:  None.
	  Postcondition: Returns true if BST is empty and false otherwise.
	 -----------------------------------------------------------------------*/

	bool search(const string & item) const;
	/*------------------------------------------------------------------------
	  Search the BST for item.

	  Precondition:  None.
	  Postcondition: Returns true if item found, and false otherwise.
	 -----------------------------------------------------------------------*/

	void insert(const string & item, const int & numLine);
	/*------------------------------------------------------------------------
	  Insert item into BST.

	  Precondition:  None.
	  Postcondition: BST has been modified with item inserted at proper
		  position to maintain BST property.
	------------------------------------------------------------------------*/

	void remove(const string & item);
	/*------------------------------------------------------------------------
	  Remove item from BST.

	  Precondition:  None.
	  Postcondition: BST has been modified with item removed (if present);
		  BST property is maintained.
	  Note: remove uses private auxiliary function search2() to locate
			the node containing item and its parent.
   ------------------------------------------------------------------------*/

	void graph(ostream & out) const;
	/*------------------------------------------------------------------------
	  Graphic output of BST.

	  Precondition:  ostream out is open.
	  Postcondition: Graphical representation of BST has been output to out.
	  Note: graph() uses private auxiliary function graphAux().
   ------------------------------------------------------------------------*/

	void inorder(ostream & out) const;
	/*------------------------------------------------------------------------
	  Inorder traversal of BST.

	  Precondition:  ostream out is open.
	  Postcondition: BST has been inorder traversed and values in nodes
		  have been output to out.
	  Note: inorder uses private auxiliary function inorderAux().
   ------------------------------------------------------------------------*/

   //--- ADD PROTOTYPES OF preorder() AND postorder() HERE
	void preorder(ostream & out) const;
	/*----------------------------------------------------------------------
	Preorder traversal of BST.

	Precondition:  ostream out is open.
	Postcondition : BST has been preorder traversed and values in nodes
	have been output to out.
	----------------------------------------------------------------------*/
	void  postorder(ostream & out) const;
	/*----------------------------------------------------------------------
		Postorder traversal of BST.

		Precondition:  ostream out is open.
		Postcondition : BST has been postorder traversed and values in nodes
		have been output to out.
	----------------------------------------------------------------------*/

	//--- ADD PROTOTYPE OF DESTRUCTOR HERE
	~BST();
	/*--------------------------------------------------------------------
	Destructor of BST.

	 Precondition: BST is nonempty.
	 Postcondition: the value of the pointer pointing on to the node
	 will be removed unless the BST is empty. Hence will pop up an error
	message.
	---------------------------------------------------------------------*/

	//--- ADD PROTOTYPE OF COPY CONSTRUCTOR HERE
	BST(const BST & orig);
	/*-------------------------------------------------------------------
	Copy constructor of BST

	 Precondition: original is BST to be copied and is recieved as a const
	 reference parameter.
	 Postcondition: A copy of the orig has been constructed.
  --------------------------------------------------------------------*/

	//--- ADD PROTOTYPE OF ASSIGNMENT OPERATOR HERE
	const BST& operator=(const BST&);
	/*------------------------------------------------------------------
	Assignment operator of BST

	Precondition: rhs is the BST to be assigned and is recieved as a const
	reference parameter.
	Postcondition: The current BST becomes a copied of the rhs and reference
	is returned.
	--------------------------------------------------------------------*/

private:
	/***** Node class *****/
	class BinNode
	{
	public:
		string data; //string
		Queue<int> nums;
		BinNode * left;
		BinNode * right;

		// BinNode constructors
		// Default -- data part is default DataType value; both links are null.
		BinNode()
			: left(0), right(0)
		{}

		// Explicit Value -- data part contains item; both links are null.
		BinNode(string item)
			: data(item), left(0), right(0)
		{}

	};// end of class BinNode declaration

	typedef BinNode * BinNodePointer;

	/***** Private Function Members *****/

	void search2(const string & item, bool & found,
		BinNodePointer & locptr, BinNodePointer & parent) const;
	/*------------------------------------------------------------------------
	  Locate a node containing item and its parent.

	  Precondition:  None.
	  Postcondition: locptr points to node containing item or is null if
		  not found, and parent points to its parent.#include <iostream>
	------------------------------------------------------------------------*/

	void inorderAux(ostream & out,
		BinNodePointer subtreePtr) const;
	/*------------------------------------------------------------------------
	  Inorder traversal auxiliary function.

	  Precondition:  ostream out is open; subtreePtr points to a subtree
		  of this BST.
	  Postcondition: Subtree with root pointed to by subtreePtr has been
		  output to out.
	------------------------------------------------------------------------*/

	void preorderAux(ostream & out,
		BinNodePointer subtreePtr) const;
	/*------------------------------------------------------------------------
	Preorder traversal auxiliary function.

	Precondition:  ostream out is open; subtreePtr points to a subtree
	of this BST.
	Postcondition: Subtree with root pointed to by subtreePtr has been
	output to out.
	------------------------------------------------------------------------*/

	void postorderAux(ostream & out,
		BinNodePointer subtreePtr) const;
	/*------------------------------------------------------------------------
	Preorder traversal auxiliary function.

	Precondition:  ostream out is open; subtreePtr points to a subtree
	of this BST.
	Postcondition: Subtree with root pointed to by subtreePtr has been
	output to out.
	------------------------------------------------------------------------*/

	void destroy(BinNodePointer subtreePtr);
	/*------------------------------------------------------------------------
	Destory function.

	Precondition:  ostream out is open; subtreePtr points to a subtree
	of this BST.
	Postcondition: Subtree with root pointed to by subtreePtr has been
	output to out.
	------------------------------------------------------------------------*/

	void copyTree(BinNodePointer origRoot, BinNodePointer & subtreeRoot);
	/*------------------------------------------------------------------------
	Copy tree function.

	Precondition:  ostream out is open; subtreePtr points to a subtree
	of this BST.
	Postcondition: Subtree with root pointed to by subtreePtr has been
	output to out.
	------------------------------------------------------------------------*/

	void graphAux(ostream & out, int indent,
		BinNodePointer subtreeRoot) const;
	/*------------------------------------------------------------------------
	  Graph auxiliary function.

	  Precondition:  ostream out is open; subtreePtr points to a subtree
		  of this BST.
	  Postcondition: Graphical representation of subtree with root pointed
		  to by subtreePtr has been output to out, indented indent spaces.
	------------------------------------------------------------------------*/

	/***** Data Members *****/
	BinNodePointer myRoot;

}; // end of class template declaration

//--- Definition of constructor
 inline BST::BST()
	: myRoot(0)
{}

//--- Definition of empty()
bool BST::empty() const
{
	return myRoot == 0;
}

//--- Definition of search()

bool BST::search(const string & item) const
{
	BST::BinNodePointer locptr = myRoot;
	bool found = false;
	while (!found && locptr != 0)
	{
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
			found = true;
	}
	return found;
}

//--- Definition of insert()
inline void BST::insert(const string & item, const int & numLine)
{
	BST::BinNodePointer
		locptr = myRoot,   // search pointer
		parent = 0;        // pointer to parent of current node
	bool found = false;     // indicates if item already in BST
	while (!found && locptr != 0)
	{
		parent = locptr;
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
			found = true;
	}
	if (!found)
	{                                 // construct node containing item
		locptr = new(nothrow) BST::BinNode(item);
		locptr->nums.enqueue(numLine);

		if (locptr == 0)
		{
			cerr << "*** Out of memory -- terminating program ***\n";
			exit(1);
		}

		if (parent == 0)               // empty tree
			myRoot = locptr;
		else if (item < parent->data)  // insert to left of parent
			parent->left = locptr;
		else                           // insert to right of parent
			parent->right = locptr;
	}
	else
	{
		locptr->nums.enqueue(numLine); //calling our locptr into enqueue
	}

}

//--- Definition of remove()
void BST::remove(const string & item)
{
	bool found;                      // signals if item is found
	BST::BinNodePointer
		x,                            // points to node to be deleted
		parent;                       //    "    " parent of x and xSucc
	search2(item, found, x, parent);

	if (!found)
	{
		cout << "Item not in the BST\n";
		return;
	}
	//else
	if (x->left != 0 && x->right != 0)
	{                                // node has 2 children
	   // Find x's inorder successor and its parent
		BST::BinNodePointer xSucc = x->right;
		parent = x;
		while (xSucc->left != 0)       // descend left
		{
			parent = xSucc;
			xSucc = xSucc->left;
		}

		// Move contents of xSucc to x and change x 
		// to point to successor, which will be removed.
		x->data = xSucc->data;
		x = xSucc;
	} // end if node has 2 children

	// Now proceed with case where node has 0 or 2 child
	BST::BinNodePointer
		subtree = x->left;             // pointer to a subtree of x
	if (subtree == 0)
		subtree = x->right;
	if (parent == 0)                  // root being removed
		myRoot = subtree;
	else if (parent->left == x)       // left child of parent
		parent->left = subtree;
	else                              // right child of parent
		parent->right = subtree;
	delete x;
}

//--- Definition of graph()
inline void BST::graph(ostream & out) const
{
	graphAux(out, 0, myRoot);
}

//--- Definition of search2()
void BST::search2(const string & item, bool & found,
	BinNodePointer & locptr,
	BinNodePointer & parent) const
{
	locptr = myRoot;
	parent = 0;
	found = false;
	while (!found && locptr != 0)
	{
		if (item < locptr->data)       // descend left
		{
			parent = locptr;
			locptr = locptr->left;
		}
		else if (locptr->data < item)  // descend right
		{
			parent = locptr;
			locptr = locptr->right;
		}
		else                           // item found
			found = true;
	}
}


//--- Definition of graphAux()
#include <iomanip>

void BST::graphAux(ostream & out, int indent,
	BinNodePointer subtreeRoot) const
{
	if (subtreeRoot != 0)
	{
		graphAux(out, indent + 8, subtreeRoot->right);
		out << setw(indent) << " " << subtreeRoot->data << endl;
		graphAux(out, indent + 8, subtreeRoot->left);
	}
}

//--- Definition of inorder()
inline void BST::inorder(ostream & out) const
{
	inorderAux(out, myRoot);
}

//--- Definition of inorderAux()
void BST::inorderAux(ostream & out,
	BinNodePointer subtreeRoot) const
{
	if (subtreeRoot != 0)
	{
		inorderAux(out, subtreeRoot->left);  // L operation
		out << subtreeRoot->data;
		cout <<" "; //here for spacing the BST and circular queue
		subtreeRoot->nums.display(out);
		out << endl;                         // V operation
		inorderAux(out, subtreeRoot->right);   // R operation
	}
}

//--- Defintion of preorder()
inline void BST::preorder(ostream & out) const
{
	preorderAux(out, myRoot);
}
//--- Defintion of preorderAux()
void BST::preorderAux(ostream & out,
	BinNodePointer subtreeRoot) const
{
	if (subtreeRoot != 0)
	{
		out << subtreeRoot->data << " "; //V
		preorderAux(out, subtreeRoot->left);//L
		preorderAux(out, subtreeRoot->right);// R
	}
}
//--- Defintion of postorder()
inline void BST::postorder(ostream & out) const
{
	postorderAux(out, myRoot);
}
//--- Defintion of postorderAux()
void BST::postorderAux(ostream & out,
	BinNodePointer subtreeRoot) const
{
	if (subtreeRoot != 0)
	{
		postorderAux(out, subtreeRoot->left); //L
		postorderAux(out, subtreeRoot->right); //R
		out << subtreeRoot->data << " "; //V
	}
}
//--- Defintion of ~BST()
inline BST::~BST()
{

	destroy(myRoot);
	cerr << "\nNode destroyed\n";
}
//--- Defintion of destroy()
inline void BST::destroy(BinNodePointer subtreeRoot)
{
	if (subtreeRoot)
	{
		destroy(subtreeRoot->left);
		destroy(subtreeRoot->right);
		delete subtreeRoot;
	}

}
//--- Defintion of BST()
inline BST::BST(const BST & orig)
{

	copyTree(orig.myRoot, myRoot);

}
//--- Defintion of copyTree
inline void BST::copyTree(BinNodePointer origRoot, BinNodePointer & subtreeRoot)
{
	if (origRoot == NULL) {
		subtreeRoot = NULL;
	}
	else
	{
		subtreeRoot = new BinNode(origRoot->data);
		copyTree(origRoot->left, subtreeRoot->left);
		copyTree(origRoot->right, subtreeRoot->right);
	}
}
//--- Defintion of operator=()
const BST& BST:: operator=(const BST & difftree)
{
	if (this != &difftree)
	{
		if (myRoot != NULL)
			destroy(myRoot);

		if (difftree.myRoot == NULL)
			myRoot = NULL;
		else
			copyTree(difftree.myRoot, myRoot);
	}
	return *this;
}

#endif
