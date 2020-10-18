#include "ETNodeConst.h"
float ETNodeConst::Calculate() 
{
	return this->constant;
}

float ETNodeConst::Calculate(float x)
{
	return this->Calculate();
}

ETNodeConst::ETNodeConst() 
{
	this->parent = nullptr;
	this->constant = 0;
}

ETNodeConst::ETNodeConst(float constant, ETNode* parent)
{
	this->constant = constant;
	this->parent = parent;
}
void ETNodeConst::heilda()
{

}