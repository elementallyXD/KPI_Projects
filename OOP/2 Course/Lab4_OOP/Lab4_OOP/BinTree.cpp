#include "BinTree.h"

// default constructor
BinTree::BinTree() 
{
	root = NULL;
	CountElements = 0;
}

// default destructor
BinTree::~BinTree() {
	DestroyTree(root);
}

// function destroys the tree
void BinTree::DestroyTree(TreeNode *node) {
	if (node) 
	{
		DestroyTree(node->left);
		DestroyTree(node->right);
		delete node;
	}
	else return;
}

// function read data from csv file to the tree, return 1 if success and 0 if error
int BinTree::ReadInfo(const char *csv) {
	FILE *CSV;
	TreeNode node;
	if ((CSV = fopen(csv, "r")) == NULL) return 0;
	
	char str[512];
	while (fgets(str, 512, CSV)) {
		sscanf(str, "%[A-z0-9]; %d; %[A-z0-9];%f", &(node.m_Destination), &(node.m_Flight), &(node.m_Passengername), &(node.m_Flightdate));
		AddTicket(str);
	}
	
	fclose(CSV);
	return 1;
}

/* function that build the tree according to data from csv file, the return type is void,
function adds ticket to the tree */
void BinTree::AddTicket(TreeNode node, TreeNode **root) {
	if (*root == NULL) 
	{
		*root = new TreeNode(node);
		return;
	}

	if (node.m_Flight < (*root)->m_Flight) AddTicket(node, &(*root)->left);
	else if (node.m_Flight > (*root)->m_Flight) AddTicket(node, &(*root)->right);
}

// function parsing the string, returns a node with parsing data
TreeNode BinTree::Parser(char* str) 
{
	TreeNode node;
	if (str == NULL) exit(1);
	sscanf(str, "%[A-z0-9]; %d; %[A-z0-9];%f", &(node.m_Destination), &(node.m_Flight), &(node.m_Passengername), &(node.m_Flightdate));
	return node;
}

// function parsing the parametrs, returns a node with parsing data
TreeNode BinTree::Parser(const char *str, int fl, const char *str2, float date)
{
	TreeNode node;
	if (str == nullptr)  return NULL;
	if (str2 == nullptr) return NULL;
	if (fl < 0)			 return NULL;
	if (date <= 0)		 return NULL;

	strcpy((node.m_Destination), str);
	node.m_Flight = fl;
	strcpy((node.m_Passengername),str2);
	node.m_Flightdate = date;

	return node;
}

// function that prints the tree, print all tickets
void BinTree::ShowTree(direction ord, TreeNode *root) 
{
	if (root != NULL) 
	{
		if (ord == UP)  ShowTree(ord, root->left);
		else			ShowTree(ord, root->right);

		printf("Destination = %s;\tFlight = %d;\tPassanger = %s;\tDate = %.2f;\n", (root->m_Destination), (root->m_Flight), (root->m_Passengername), (root->m_Flightdate));
		
		if (ord == UP)  ShowTree(ord, root->right);
		else			ShowTree(ord, root->left);
	}
}

// function prints a ticket with the required parameters
void BinTree::Get_Ticket(TreeNode* root, int nmb, float date)
{
	if (nmb == 0)     return;
	if (date == 0.0)  return;
	if (root == NULL) return;
	
	if (root != NULL)
	{
		Get_Ticket(root->left, nmb, date);
		if ((nmb == root->m_Flight) && (date == root->m_Flightdate))
		{
			printf("Destination = %s;\tFlight = %d;\tPassanger = %s;\tDate = %.2f;\n", root->m_Destination, root->m_Flight, root->m_Passengername, root->m_Flightdate);
			DelNode(nmb);
		}
		Get_Ticket(root->right, nmb, date);
	}
	
}

// function is seaching more right node in the tree, returns a Flight information in the node 
int BinTree::MostRight(TreeNode *root) 
{
	while (root->right != NULL)
		root = root->right;
	return root->m_Flight;
}

// function delete node in the tree, returns the pointer to deleted node
TreeNode* BinTree::DelNode(TreeNode **root, int v) {
	if (*root == NULL)
		return NULL;
	if (v < 0)
		return NULL;

	if ((*root)->m_Flight == v) 
	{
		if ((*root)->left == NULL && (*root)->right == NULL) {
			delete *root;
			return NULL;
		}

		if ((*root)->left != NULL && (*root)->right == NULL) {
			TreeNode *ptrnode = (*root)->left;
			delete (*root);
			return ptrnode;
		}

		if ((*root)->left == NULL && (*root)->right != NULL) {
			TreeNode *ptrnode = (*root)->right;
			delete (*root);
			return ptrnode;
		}
		(*root)->m_Flight = MostRight((*root)->left);
		(*root)->left = DelNode(&(*root)->left, (*root)->m_Flight);
		return *root;
	}

	if (v < (*root)->m_Flight) 
	{
		(*root)->left = DelNode(&(*root)->left, v);
		return *root;
	}
	if (v >(*root)->m_Flight)
	{
		(*root)->right = DelNode(&(*root)->right, v);
		return *root;
	}
	return NULL;
}
