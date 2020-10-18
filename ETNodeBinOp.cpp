#include "ETNodeBinOp.h"
#include <typeinfo>
#include "ETNodeVar.h"
#include "ETNodeConst.h"
#include <iostream>
using namespace std;
float ETNodeBinOp::Calculate()
{
	return this->operation(this->firstVar->Calculate(), this->lastVar->Calculate());
}

float ETNodeBinOp::Calculate(float x)
{
	return this->operation(this->firstVar->Calculate(x), this->lastVar->Calculate(x));
}

ETNodeBinOp::ETNodeBinOp()
{
	this->parent    = nullptr;
	this->operation = nullptr;
	this->firstVar  = nullptr;
	this->lastVar   = nullptr;
}

ETNodeBinOp::ETNodeBinOp(float (*operation)(float, float), ETNode* firstNode, ETNode* secondNode, ETNode* parent)
{
	this->parent    = parent;
	this->operation = operation;
	this->firstVar  = firstNode;
	this->lastVar   = secondNode;
	this->firstVar->parent = this;
	this->lastVar->parent = this;
} 
void ETNodeBinOp::heilda()
{
	if (this->operation == powf)
	{
		//ég er ekki stoltur af þessu, en þetta er frekar fynndið og ég hef ekki tíma til að laga þetta.
		ETNode* tempnode = new ETNodeBinOp([](float a, float b) {return a + b; }, lastVar, new ETNodeConst(1, this), this->parent);
		ETNode* tempnode2 = new ETNodeBinOp(powf, this->firstVar, tempnode, this);
		this->firstVar = tempnode2;
		this->lastVar = tempnode;
		this->operation = [](float a, float b) { return a / b; };
	}
	else 
	{
		this->firstVar->heilda();
		this->lastVar->heilda();
	}
}