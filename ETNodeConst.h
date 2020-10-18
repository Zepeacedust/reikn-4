#pragma once
#include "ETNode.h"
class ETNodeConst :
	public ETNode
{
private:
	float constant;

public:
	ETNodeConst();
	ETNodeConst(float constant, ETNode* parent);
	float Calculate();
	float Calculate(float x);
	void heilda();

};