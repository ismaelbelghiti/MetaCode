#include "../MetaCodeAST/MetaCodeAST.h"

int main()
{
   CodeNode* codeNode = new Multiplication(
      new ExprFromInt(3),
      new ParenthesizedExpr(
	 new Addition(
	    new ExprFromVariable(new Variable("myVar")),
	    new ExprFromInt(3)
	 )
      )
   );

   codeNode->PrintDebug();
   std::cout << std::endl;
   return 0;
}
