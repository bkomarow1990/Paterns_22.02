#pragma once
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
class TreeType
{
public:
	string name;
	string color;
	TreeType(const string& name, const string& color)
	:name(name),color(color){

	}
	void draw(int x, int y) {
		cout << "Draw on canvas " << name <<" and color: "<< color<<" with points "<<x <<" "<<y<< endl;
	}

private:

};
class Tree {
public:
	int x, y;
	TreeType& type;
	Tree(const int&x,const int& y , TreeType & type)
		:x(x),y(y),type(type)
	{

	}
	void draw() {
		type.draw(x, y);
	}
private:
};
class TreeFactory {
public:
	deque<TreeType * > tree_types;
	TreeType* getTreeType(const string& name, const string& color) {
		auto it = find_if(begin(tree_types), end(tree_types),
			[&](TreeType* temp) {return temp->name == name and temp->color == color; }
			);
	
	if (it!=end(tree_types))
	{
		return *it;
	}
	auto tree_type = new TreeType(name, color);
	tree_types.push_back(tree_type);
	return tree_type;
	}
};
class Forest {
public:
	TreeFactory factory;
	deque<Tree*> forest;
	Tree* plantTree(const int& x, const int& y, const string& name, const string& color) {
		Tree* tree = new Tree(x, y, *factory.getTreeType(name, color));
		forest.push_back(tree);
		return tree;
	}
	void draw(){
		for (auto& i : forest)
		{
			i->draw();
		}
	}
private:
};