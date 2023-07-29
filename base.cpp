#include "base.h"
#include "cl.h"
#include <string>

Base::Base(Base* parent, string name, int status) {
	this->parent = parent;
	this->name = name;
	this->status = status;
}

void Base::set_Name(string name) {
	this->name = name;
}
string Base::get_name() {
	return this->name;
}

Base* Base::find_node(string name)
{
	if (name == this->name) {
		return this;
	}
	else if (!this->children.empty()) {
		Base* buffer;
		for (auto child : this->children) {
			buffer = child->find_node(name);
			if (buffer) return buffer;
		}
	}
	return nullptr;
}
Base* Base::get_node(string way)
{
	Base* current_parent = nullptr;
	Base* child = nullptr;
	string name_;
	if (way[0] == '/' && way[1] == '/') {
		name_ = way.substr(2);
		child = this->find_node(name_);
	}
	else {
		name_ = way.substr(1, way.find('/', 1) - 1); way.erase(0, way.find('/', 1));
		if (this->name == name_ && way == "")
		{
			child = this;
		}
		else if (this->name == name_ && way != "")
		{
			current_parent = this;
			while (way != "") {
				name_ = way.substr(1, way.find('/', 1) - 1); way.erase(0, way.find('/', 1));
				child = nullptr;
				for (auto child_itr : current_parent -> children) {
					if (child_itr->name == name_) {
						child = child_itr;
						break;
					}
				}
				current_parent = child;
				if(!child) break;
			}
		}
	}
	return child;
}

void Base::input_tree() {
	string parent_name, cl_name;
	int cl_status, cl_class;
	Base* current_parent = this;
	while (true) {
		cin >> parent_name;
		if (parent_name == "endtree")
			break;
		cin >> cl_name >> cl_class >> cl_status; current_parent = this->get_node(parent_name); get_node(parent_name);
		if (cl_class == 2)
			current_parent->children.push_back(new Cl_2(current_parent, cl_name, cl_status)); else if (cl_class == 3)
			current_parent->children.push_back(new Cl_3(current_parent, cl_name, cl_status)); else if (cl_class == 4)
			current_parent->children.push_back(new Cl_4(current_parent, cl_name, cl_status)); else if (cl_class == 5)
			current_parent->children.push_back(new Cl_5(current_parent, cl_name, cl_status)); else if (cl_class == 6)
			current_parent->children.push_back(new Cl_6(current_parent, cl_name, cl_status));
	}
}

void Base::print_nodes_status()
{
	cout << "The object " << this->name;
	if (this->status > 0) cout << " is ready";
	else cout << " is not ready";
	for (auto child : this->children) {
		cout << endl;
		child->print_nodes_status();
	}
	return;
}
void Base::print_tree(int level) {
	if (this->parent == nullptr) cout << string(level * 4, ' ') << this->name;
	else cout << endl << string(level * 4, ' ') << this->name; 
	for (auto child : this->children) child->print_tree(level + 1);
	return;
}
