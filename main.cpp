#include "Vigur.h"
#include <iostream>
#include "ExpressionTree.h"
using namespace std;
int main() 
{
	Vigur v1 = Vigur(1, 3);
	v1.prenta();
	cout << "Lengd: " << v1.lengd() << endl;
	cout << "Halli: " << v1.halli() << endl;
	Vigur vþ = v1.þvervigur();
	cout << "Þvervigur: ";
	vþ.prenta();
	cout << "Stefnuhorn: " << v1.stefnuhorn() << endl;
	Vigur v2 = Vigur(-3, 1);
	cout << "Horn milli vigra: " << v2.horn(v1) << endl;
	Vigur v3 = v1 + v2;
	cout << "Summa: ";
	v3.prenta();
	string expression;
	cout << "sladu inn marglidu" << endl;
	cin >> expression;
	ExpressionTree tree = ExpressionTree(expression);
	int x1, x2;
	cout << "Sladu inn nedri mork x" << endl;
	cin >> x1;
	cout << "Sladu inn efri mork x" << endl;
	cin >> x2;
	tree.root->heilda();
	cout << "svaedi undir marglidu: " << tree.root->Calculate(x2) - tree.root->Calculate(x1) << endl;
	return 0;
}