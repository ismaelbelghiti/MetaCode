#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Variable.h"

class Expression : public CodeNode {};

class ExprFromInt : public Expression {
public:
   ExprFromInt(int value) { m_value = value; }

   int GetValue() { return m_value; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << GetValue();
   }

private:
   int m_value;
};

class ExprFromVariable : public Expression {
public:
   ExprFromVariable(Variable* variable) { m_variable = variable; }

   Variable* GetVariable() { return m_variable; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      GetVariable()->PrintDebug();
   }

private:
   Variable* m_variable;
};

#endif
