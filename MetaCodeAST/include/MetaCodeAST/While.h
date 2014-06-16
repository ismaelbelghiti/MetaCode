#ifndef WHILE_H
#define WHILE_H

#include "Expression.h"
#include "Bloc.h"

class While : public CodeNode {
public:
   While(Expression *condExpr, Bloc* bloc);

   virtual Expression* GetCondition();

   virtual Bloc* GetBloc();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   Expression *m_condExpr;
   Bloc* m_bloc;
};

#endif
