#include "MetaCodeAST.h"
#include "utils.h"

int main() {
   // an example of composed airthmetic expression
   IExpression* arithExpr = new Multiplication(
      new ParenthesizedExpr(
	 new Substraction(
	    new ExprFromVariable(new Variable("x",cInt)),
	    new ExprFromInt(3)
	 )
      ),
      new ParenthesizedExpr(
	 new Addition(
	    new ExprFromVariable(new Variable("y",cInt)),
	    new ExprFromInt(3)
	 )
      )
   );


   //an example of composed boolean expression
   IExpression* boolExpr = new And(
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

   // creation of a print statement
   Print* print = create_print(
      Print::ENDLINE,
      new PrintableFromString("Hello"),
      new PrintableFromExpression(new ExprFromInt(42))
   );

   // creation of a bloc
   Bloc* bloc = create_bloc(
      new Declaration( new Variable("iLine",cInt), arithExpr),
      print
   );
   
   // creation of a for loop
   For* forLoop = new For(
      new Variable("iCow",cInt),
      new Range(Range::DECREASING, new ExprFromInt(8), new ExprFromInt(2)),
      bloc
   );

   // creation of a while loop
   While* whileLoop = new While(
      boolExpr,
      bloc
   );

   // creation of an if statement
   If* ifStatement = new If(
      boolExpr,
      bloc
   );
   
   // creation of a function declaration
   

   ifStatement->PrintDebug();
   std::cout << std::endl;


   return 0;
}
