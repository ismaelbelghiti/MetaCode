#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include "MetaCodeAST/InterfaceType.h"

class If : public IStatement {
public:
   If(IExpression *condExpr, IBloc* bloc);

   virtual IExpression* GetCondition();

   virtual IBloc* GetBloc();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   IExpression *m_condExpr;
   IBloc* m_bloc;
};


class ElseIf : public IStatement {
public:
   ElseIf(IExpression *condExpr, IBloc* bloc);

   virtual IExpression* GetCondition();

   virtual IBloc* GetBloc();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   IExpression *m_condExpr;
   IBloc* m_bloc;
};


class Else : public IStatement {
public:
   Else(IBloc* bloc);

   virtual IBloc* GetBloc();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   IExpression *m_condExpr;
   IBloc* m_bloc;
};

#endif
