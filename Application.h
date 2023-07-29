#ifndef Application_h
#define Application_h
#include "base.h"
#include <iostream>
using namespace std;

class Application {
private:
	Base* tree = nullptr;
public:
	void build_tree();
	int exec_app();
};
#endif
