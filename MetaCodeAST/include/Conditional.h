#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include "Expression.h"
#include "Bloc.h"

class If : public CodeNode {
public:
   If(Expression *condExpr, Bloc* bloc) {
      m_condExpr = condExpr;
      m_bloc = bloc;
   }

   virtual Expression* GetCondition() { return m_condExpr; }

   virtual Bloc* GetBloc() { return m_bloc; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << "If ";
      GetCondition()->PrintDebug();
      std::cout << std::endl;
      GetBloc()->PrintDebug(level);
   }

private:
   Expression *m_condExpr;
   Bloc* m_bloc;
};


class ElseIf : public CodeNode {
public:
   ElseIf(Expression *condExpr, Bloc* bloc) {
      m_condExpr = condExpr;
      m_bloc = bloc;
   }

   virtual Expression* GetCondition() { return m_condExpr; }

   virtual Bloc* GetBloc() { return m_bloc; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << "ElseIf ";
      GetCondition()->PrintDebug();
      std::cout << std::endl;
      GetBloc()->PrintDebug(level);
   }

private:
   Expression *m_condExpr;
   Bloc* m_bloc;
};


class Else : public CodeNode {
public:
   Else(Bloc* bloc) {}

   virtual Bloc* GetBloc() { return m_bloc; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << "Else " << std::endl;
      GetBloc()->PrintDebug(level);
   }

private:
   Expression *m_condExpr;
   Bloc* m_bloc;
};

#endif
