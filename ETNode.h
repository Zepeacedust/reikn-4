#pragma once
class ETNode
{
public:
	ETNode* parent;
	virtual float Calculate();
	virtual float Calculate(float x);
	virtual void heilda();
};

