#include "CodeFromAST/PrinterVisitor.h"

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

   PrinterVisitor* printer = new PrinterVisitor();
   arithExpr->Visit(printer);
   std::cout << std::endl;
   boolExpr->Visit(printer);
   std::cout << std::endl;

   return 0;
}

