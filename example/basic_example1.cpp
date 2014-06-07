#include "../MetaCodeAST/MetaCodeAST.h"

int main()
{
   CodeNode* codeNode = new Variable("myVariable");
   codeNode->PrintDebug();
   cout << endl;
   return 0;
}
