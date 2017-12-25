#pragma once
#include "Treenode.h"
#include <iostream>
#pragma warning (disable:4305)

typedef enum {UP, DOWN} direction;

class BinTree 
{	
	public:
		BinTree();
		~BinTree();
		int  ReadInfo(const char* csv);
		void DestroyTree(TreeNode* node);
		
		void AddTicket(char* str) 
		{
			TreeNode node = Parser(str);
			AddTicket(node, &root);
			CountElements++;
		}
		
		void AddTicket(const char *str, int fl, const char *str2, float date)
		{
			TreeNode node = Parser(str,fl,str2,date);
			AddTicket(node, &root);
			CountElements++;
		}

		void DelNode(int v)
		{
			DelNode(&root, v);
			CountElements--;
		}
		
		void Get_Ticket(int nmb, float date)
		{
			return Get_Ticket(root, nmb, date);
		}
	
		void ShowTree(direction ord)
		{ 
			ShowTree(ord, root);
		}

	private:
		TreeNode *root;
		unsigned int CountElements = 0;

		TreeNode *DelNode(TreeNode**root ,int v);
		TreeNode Parser(char*);
		TreeNode Parser(const char *str, int fl, const char *str2, float date);
		int  MostRight(TreeNode *root);
		void AddTicket(TreeNode node, TreeNode **root);
		void Get_Ticket(TreeNode* root, int nmb, float date);
		void ShowTree(direction, TreeNode*);
};