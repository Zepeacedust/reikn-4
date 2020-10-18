#pragma once
class Vigur
{
public:
	Vigur();
	Vigur(float X, float Y);
	float x;
	float y;
	void prenta();
	float lengd();
	float halli();
	Vigur þvervigur();
	float stefnuhorn();
	float horn(Vigur v);
	float innfeldi(Vigur v);
	Vigur summa(Vigur v);
	Vigur operator+(Vigur other);
};

