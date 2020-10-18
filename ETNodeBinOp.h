#pragma once
#include "ETNode.h"
class ETNodeBinOp :
	public ETNode
{
private:
	float (*operation)(float, float);
	ETNode* firstVar;
	ETNode* lastVar;
public:
	float Calculate();
	float Calculate(float x);
	ETNodeBinOp();
	ETNodeBinOp(float (*operation)(float, float), ETNode* firstNode, ETNode* secondNode, ETNode* parent);
	void heilda();

};