#include "CodeFromAST/PrinterVisitor.h"

// Some Utilities
int count_args() { return 0; }

template<typename T, typename ...Args>
int count_args(T head, Args... args ) { return 1 + count_args(args...); }

template<typename Q, typename T>
void fill_array_from_args(Q** array, T* head) { array[0] = head; }

template<typename Q, typename T, typename ...Args>
void fill_array_from_args(Q** array, T* head, Args... args) {
   array[0] = head;
   fill_array_from_args(array+1, args...);
}

template<typename ...Args>
Bloc* create_bloc(Args... args) {
   int nb = count_args(args...);
   CodeNode** codeNode = new CodeNode*[nb];
   fill_array_from_args(codeNode, args...);
   return new Bloc(codeNode, nb);
}

template<typename ...Args>
Print* create_print(bool withEndline, Args... args) {
   int nb = count_args(args...);
   Printable** printable = new Printable*[nb];
   fill_array_from_args(printable, args...);
   return new Print(printable, nb, withEndline);
}

template<typename ...Args>
Signature* create_signature(Args... args) {
   int nb = count_args(args...);
   Variable** variable = new Variable*[nb];
   fill_array_from_args(variable, args...);
   return new Signature(variable, nb);
}
// End Utilities


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

   // creation of a print statement
   Print* print = create_print(
      Print::ENDLINE,
      new PrintableFromString("Hello"),
      new PrintableFromExpression(new ExprFromInt(42))
   );

   // creation of a bloc
   Bloc* bloc = create_bloc(
      new Declaration( new Variable("iLine"), arithExpr),
      print
   );
   
   // creation of a for loop
   For* forLoop = new For(
      new Variable("iCow"),
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

   // creation of a second bloc
   Bloc* bloc2 = create_bloc(
      forLoop,
      whileLoop,
      ifStatement
   );

   AbstractVisitor* visitor = new PrinterVisitor();

   bloc2->Visit(visitor);
   std::cout << std::endl;

   return 0;
}

