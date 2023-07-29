#include "Application.h"
#include "cl.h"

void Application::build_tree() {
	string root_name;
	cin >> root_name;
	this->tree = new Base(nullptr, root_name, 1); this->tree->input_tree();
	return;
}
int Application::exec_app() {
	cout << "Object tree" << endl;
	string num;
	cin >> num;
	this->tree->print_tree();
	Base* pointer = nullptr;
	while (num != "//") {
		pointer = this->tree->get_node(num);
		cout << endl << num;
		if (pointer)
			cout << " Object name: " << pointer->get_name();
		else
			cout << " Object not found";
		cin >> num;
	}
	delete this->tree;
	return 0;
}
