#include "MetaCodeAST.h"
#include "utils.h"

class MyVisitor : public BasicVisitor {
   virtual void ProcessVariable(Variable* var) {
      std::cout << var->GetName() << std::endl;
   }

   virtual void ProcessDeclaration(Declaration* declaration) {
      std::cout << "declaration" << std::endl;
   }
};

int main()
{

   IStatement* prog = new For(new Variable("iCow",cInt), new Range(Range::DECREASING, new ExprFromInt(8), new ExprFromInt(2)),
   create_bloc(
      new Declaration(new Variable("nbCells",cInt),new ExprFromInt(2)),
      new While(new ExprFromBool(true),
      create_bloc(
	 new Declaration(new Variable("ste",cInt), new ExprFromInt(21))
      ))
   ));

   MyVisitor* vis = new MyVisitor();

   prog->Visit(vis);

   return 0;
}
