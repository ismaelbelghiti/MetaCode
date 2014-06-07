#include "../MetaCodeAST/MetaCodeAST.h"

int main()
{
   Variable* v = new Variable("myVariable");
   CodeNode* e = new ExprFromVariable(v);
   e->PrintDebug();
   std::cout << std::endl;
   return 0;
}
