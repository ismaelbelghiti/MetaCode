#ifndef WHILE_H
#define WHILE_H

#include "MetaCodeAST/InterfaceType.h"


class While : public IStatement {
public:
   While(IExpression *condExpr, IBloc* bloc);

   virtual IExpression* GetCondition();

   virtual IBloc* GetBloc();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

   virtual IStatement* TransformStatement(AbstractStatementTransformer* transformer);

private:
   IExpression *m_condExpr;
   IBloc* m_bloc;
};

#endif
