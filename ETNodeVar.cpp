#include "ETNodeVar.h"

ETNodeVar::ETNodeVar() 
{
	this->parent = nullptr;
}

ETNodeVar::ETNodeVar(ETNode* parent)
{
	this->parent = parent;
}

float ETNodeVar::Calculate() 
{
	return 0;
}

float ETNodeVar::Calculate(float x) 
{
	return x;
}
void ETNodeVar::heilda() 
{

}