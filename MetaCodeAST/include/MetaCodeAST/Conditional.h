#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include "Expression.h"
#include "Bloc.h"

class If : public CodeNode {
public:
   If(Expression *condExpr, Bloc* bloc);

   virtual Expression* GetCondition();

   virtual Bloc* GetBloc();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   Expression *m_condExpr;
   Bloc* m_bloc;
};


class ElseIf : public CodeNode {
public:
   ElseIf(Expression *condExpr, Bloc* bloc);

   virtual Expression* GetCondition();

   virtual Bloc* GetBloc();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   Expression *m_condExpr;
   Bloc* m_bloc;
};


class Else : public CodeNode {
public:
   Else(Bloc* bloc);

   virtual Bloc* GetBloc();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   Expression *m_condExpr;
   Bloc* m_bloc;
};

#endif
