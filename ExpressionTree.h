#pragma once
#include "ETNode.h"
#include <string>
using namespace std;
class ExpressionTree
{
public:
	ETNode* root;
	ExpressionTree();
	ExpressionTree(string input);
	ExpressionTree(ETNode* newRoot);
	/*
	ExpressionTree operator+(ExpressionTree* other);
	ExpressionTree operator-(ExpressionTree* other);
	ExpressionTree operator*(ExpressionTree* other);
	ExpressionTree operator/(ExpressionTree* other);
	ExpressionTree operator^(ExpressionTree* other);
	*/
};
