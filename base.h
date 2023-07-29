#ifndef Base_h
#define Base_h
#include <list>
#include <iostream>
using namespace std;

class Base {
protected:
	string name;
	int status;
	Base* parent;
	list <Base*> children;
public:
	Base(Base* parent, string name, int status); 
	Base* find_node(string name);
	Base* get_node(string way);
	void input_tree();
	void print_nodes_status();
	void print_tree(int level = 0);
	void set_Name(string name);
	string get_name();
};
#endif
