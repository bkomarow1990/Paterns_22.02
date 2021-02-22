#include <iostream>
#include "TreeRype.h"
using namespace std;
int main() {
	TreeFactory factory;
	TreeType* tt = factory.getTreeType("oak", "green");
	tt->draw(1, 1);
	Forest forest;
	forest.plantTree(3, 4, "oak", "green");
	forest.plantTree(2, 6, "oak", "green");
	forest.draw();
	return 0;
}