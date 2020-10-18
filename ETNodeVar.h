#pragma once
#include "ETNode.h"
class ETNodeVar :
	public ETNode
{
public:
	ETNodeVar();
	ETNodeVar(ETNode* parent);
	float Calculate();
	float Calculate(float x);
	void heilda();
};