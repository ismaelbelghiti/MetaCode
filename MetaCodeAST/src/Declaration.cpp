#include "MetaCodeAST/Declaration.h"

Declaration::Declaration(Variable* variable, Expression* expr) {     
   m_variable = variable;
   m_expr = expr;
}

Variable* Declaration::GetVariable() {
   return m_variable;
}

Expression* Declaration::GetExpression() {
   return m_expr;
}

void Declaration::PrintDebug(int level) {
   printIndent(level);
   GetVariable()->GetType()->PrintDebug();
   std::cout << " ";
   GetVariable()->PrintDebug();
   std::cout << " = ";
   GetExpression()->PrintDebug();
}


