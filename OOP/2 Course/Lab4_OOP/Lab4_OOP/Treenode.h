#pragma once
class TreeNode
{
	public:
		friend class BinTree;

		TreeNode();
		TreeNode(char*);
		TreeNode *left;
		TreeNode *right;
		~TreeNode();
	
		char m_Destination[127];
		int m_Flight;
		char m_Passengername[127];
		float m_Flightdate;
};
