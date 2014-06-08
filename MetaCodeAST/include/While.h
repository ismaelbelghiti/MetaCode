#ifndef WHILE_H
#define WHILE_H

#include "Expression.h"
#include "Bloc.h"

class While : public CodeNode {
public:
   While(Expression *condExpr, Bloc* bloc) {
      m_condExpr = condExpr;
      m_bloc = bloc;
   }

   virtual Expression* GetCondition() { return m_condExpr; }

   virtual Bloc* GetBloc() { return m_bloc; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << "While ";
      GetCondition()->PrintDebug();
      std::cout << std::endl;
      GetBloc()->PrintDebug(level);
   }

private:
   Expression *m_condExpr;
   Bloc* m_bloc;
};

#endif
