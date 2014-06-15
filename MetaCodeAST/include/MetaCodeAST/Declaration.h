#ifndef DECLARATION_H
#define DECLARATION_H

#include "Expression.h"

class Declaration : public CodeNode {
public:
   Declaration(Variable* variable, Expression* expr);

   virtual Variable* GetVariable();

   virtual Expression* GetExpression();

   virtual void PrintDebug(int level = 0);

private:
   Variable* m_variable;
   Expression* m_expr;
};

#endif
