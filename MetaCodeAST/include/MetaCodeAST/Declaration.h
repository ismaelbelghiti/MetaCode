#ifndef DECLARATION_H
#define DECLARATION_H

#include "Expression.h"

class Declaration : public CodeNode {
public:
   Declaration(Variable* variable, Expression* expr) {     
      m_variable = variable;
      m_expr = expr;
   }

   virtual Variable* GetVariable() { return m_variable; }

   virtual Expression* GetExpression() { return m_expr; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      GetVariable()->GetType()->PrintDebug();
      std::cout << " ";
      GetVariable()->PrintDebug();
      std::cout << " = ";
      GetExpression()->PrintDebug();
   }

private:
   Variable* m_variable;
   Expression* m_expr;
};

#endif
