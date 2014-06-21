#include "CodeFromAST/CodeExpander.h"
#include "CodeFromAST/EmptyVisitor.h"

class ExpressionExpander : public EmptyVisitor {
public:

   ExpressionExpander(CodeExpander* codeExpander) {
      m_codeExpander = codeExpander;
   }

   virtual void VisitAddition(Addition* add) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(add->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(add->GetRightExpr());
      m_result = new Addition(left,right);
   }

   // TODO treat them all

   Expression* GetResult() {
      return m_result;
   };

private:
   CodeExpander* m_codeExpander;
   Expression* m_result;
};

Expression* CodeExpander::ExpandExpression(Expression* expr) {
   ExpressionExpander* exprExpander = new ExpressionExpander(this);
   expr->Visit(exprExpander);
   Expression* result = exprExpander->GetResult();
   delete exprExpander;
   return result;
}

