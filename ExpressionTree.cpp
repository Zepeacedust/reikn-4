#include "ExpressionTree.h"
#include "ETNodeBinOp.h"
#include "ETNodeVar.h"
#include "ETNodeConst.h"
#include <iostream>
using namespace std;
bool isNumber(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && (std::isdigit(*it) ||*it == '.')) ++it;
	return !s.empty() && it == s.end();
}

ExpressionTree::ExpressionTree() 
{
	this->root = nullptr;
}

ExpressionTree::ExpressionTree(string input) 
{
	//ef allt er umkringt af sviga, eiða þeim sviga
	while (input[0] == '(' && input[input.length() - 1] == ')') 
	{
		input = input.substr(1, input.length() - 1);
	}
	int svigCount = 0;
	for (int i = 0; i < input.length(); i++) {
		switch (input[i])
		{
		case '(':
			svigCount += 1;
			break;
		case ')':
			svigCount -= 1;
			break;
		case '+':
			if (svigCount != 0) break;
			this->root = new ETNodeBinOp([](float a, float b) { return a + b; }, ExpressionTree(input.substr(0, i)).root, ExpressionTree(input.substr(i + 1)).root, nullptr);
			return;
		case '-':
			if (svigCount != 0) break;
			this->root = new ETNodeBinOp([](float a, float b) { return a - b; }, ExpressionTree(input.substr(0, i)).root, ExpressionTree(input.substr(i + 1)).root, nullptr);
			return;
		default:
			break;
		}

	}
	svigCount = 0;
	for (int i = 0; i < input.length(); i++) {
		switch (input[i])
		{
		case '(':
			svigCount += 1;
			break;
		case ')':
			svigCount -= 1;
			break;
		case '*':
			if (svigCount != 0) break;
			this->root = new ETNodeBinOp([](float a, float b) { return a * b; }, ExpressionTree(input.substr(0, i)).root, ExpressionTree(input.substr(i + 1)).root, nullptr);
			return;
		case '/':
			if (svigCount != 0) break;
			this->root = new ETNodeBinOp([](float a, float b) { return a / b; }, ExpressionTree(input.substr(0, i)).root, ExpressionTree(input.substr(i + 1)).root, nullptr);
			return;
		default:
			break;
		}
	}
	svigCount = 0;
	for (int i = 0; i < input.length(); i++) {
		switch (input[i])
		{
		case '(':
			svigCount += 1;
			break;
		case ')':
			svigCount -= 1;
			break;
		case '^':
			if (svigCount != 0) break;
			this->root = new ETNodeBinOp(powf, ExpressionTree(input.substr(0, i)).root, ExpressionTree(input.substr(i + 1)).root, nullptr);
			return;
		default:
			break;
		}
	}
	if (isNumber(input)) this->root = new ETNodeConst(stof(input), nullptr);
	else this->root = new ETNodeVar();
}
ExpressionTree::ExpressionTree(ETNode* newRoot)
{
	this->root = newRoot;
}
/*
ExpressionTree ExpressionTree::operator+(ExpressionTree* other)
{
	float (*add)(float, float) = [](float a, float b) { return a + b; };
	ETNodeBinOp* newroot = new ETNodeBinOp(add, this->root, other->root, nullptr);
	return ExpressionTree(newroot);
}
ExpressionTree ExpressionTree::operator-(ExpressionTree* other)
{
	float (*sub)(float, float) = [](float a, float b) { return a - b; };
	ETNodeBinOp* newroot = new ETNodeBinOp(sub, this->root, other->root, nullptr);
	return ExpressionTree(newroot);
}
ExpressionTree ExpressionTree::operator*(ExpressionTree* other)
{
	float (*mul)(float, float) = [](float a, float b) { return a * b; };
	ETNodeBinOp* newroot = new ETNodeBinOp(mul, this->root, other->root, nullptr);
	return ExpressionTree(newroot);
}
ExpressionTree ExpressionTree::operator/(ExpressionTree* other)
{
	float (*div)(float, float) = [](float a, float b) { return a / b; };
	ETNodeBinOp* newroot = new ETNodeBinOp(div, this->root, other->root, nullptr);
	return ExpressionTree(newroot);
}
ExpressionTree ExpressionTree::operator^(ExpressionTree* other)
{
	ETNodeBinOp* newroot = new ETNodeBinOp(powf, this->root, other->root, nullptr);
	return ExpressionTree(newroot);
}
*/