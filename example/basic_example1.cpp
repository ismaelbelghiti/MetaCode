#include "../MetaCodeAST/MetaCodeAST.h"

int main()
{

   // an example of composed airthmetic expression
   Expression* arithExpr = new Multiplication(
      new ParenthesizedExpr(
	 new Substraction(
	    new ExprFromVariable(new Variable("x")),
	    new ExprFromInt(3)
	 )
      ),
      new ParenthesizedExpr(
	 new Addition(
	    new ExprFromVariable(new Variable("y")),
	     new ExprFromInt(3)
	 )
      )
   );

   //an example of composed boolean expression
   Expression* boolExpr = new And(
      new ExprFromBool(true),
      new Negation( 
	 new ParenthesizedExpr(
	    new Or(
               new ExprFromVariable(new Variable("isPair",cBool)),
	       new ExprFromBool(false)
	    )
	 )   
      )
   );

   // creation of a bloc
   const int nbNodesOfBloc = 3;
   CodeNode** codeNodeOfBloc = new CodeNode*[nbNodesOfBloc];
   codeNodeOfBloc[0] = new ExprFromInt(42);
   codeNodeOfBloc[1] = arithExpr;
   codeNodeOfBloc[2] = boolExpr;
   Bloc* bloc = new Bloc(codeNodeOfBloc, nbNodesOfBloc);
      
   // creation of a for loop
   For* forLoop = new For(
      new Variable("iCow"),
      new Range(Range::DECREASING, new ExprFromInt(8), new ExprFromInt(2)),
      bloc
   );

   forLoop->PrintDebug();
   std::cout << std::endl;
   return 0;
}
