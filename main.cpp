#include "Application.h"
#include "base.h"
int main()
{
  Application Application_ob;
  Application_ob.build_tree();
  return (Application_ob.exec_app());
}
