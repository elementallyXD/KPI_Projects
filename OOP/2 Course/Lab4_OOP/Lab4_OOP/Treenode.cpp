#include "Treenode.h"

// default constructor for Node
TreeNode::TreeNode()
{
	m_Destination[0] = '\0';
	 m_Flight = 0;
	 m_Passengername[0]= '\0';
	 m_Flightdate= 0.0;
	left = nullptr;
	right = nullptr;
}

// constructor with parameter
TreeNode::TreeNode(char *str)
{
	left = nullptr;
	right = nullptr;

	if (str == nullptr)
	{
		m_Destination[0] = '\0';
		m_Passengername[0] = '\0';
		m_Flight = 0;
		m_Flightdate = 0.0;
		return;
	}
}

TreeNode::~TreeNode(void) {}//destructor