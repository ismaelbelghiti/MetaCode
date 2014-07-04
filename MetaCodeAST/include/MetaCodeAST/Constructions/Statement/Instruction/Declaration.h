#ifndef DECLARATION_H
#define DECLARATION_H

#include "MetaCodeAST/InterfaceType.h"

class Declaration : public IStatement {
public:
   Declaration(IVariable* variable, IExpression* expr);

   virtual IVariable* GetVariable();

   virtual IExpression* GetExpression();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

   virtual IStatement* TransformStatement(AbstractStatementTransformer* transformer);

private:
   IVariable* m_variable;
   IExpression* m_expr;
};

#endif
