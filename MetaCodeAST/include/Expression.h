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

class ParenthesizedExpr : public Expression {
public:
   ParenthesizedExpr(Expression* expr) { m_expr = expr; }

   Expression* GetExpression() { return m_expr; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << "(";
      GetExpression()->PrintDebug();
      std::cout << ")";
   }

private:
   Expression* m_expr;
};

class BinaryOperation : public Expression {
public:
   BinaryOperation(Expression* leftExpr, Expression* rightExpr) {
      m_leftExpr = leftExpr;
      m_rightExpr = rightExpr;
   }

   Expression* GetLeftExpr() { return m_leftExpr; }

   Expression* GetRightExpr() { return m_rightExpr; }
   
   virtual std::string GetSymbol() = 0;

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      GetLeftExpr()->PrintDebug();
      std::cout << " " << GetSymbol() << " ";
      GetRightExpr()->PrintDebug();
   }

private:
   Expression *m_leftExpr, *m_rightExpr;
};

class Addition : public BinaryOperation {
public:
   Addition(Expression* leftExpr, Expression* rightExpr) 
      : BinaryOperation(leftExpr,rightExpr) {}
   
   virtual std::string GetSymbol() { return "+"; }
};

class Multiplication : public BinaryOperation {
public:
   Multiplication(Expression* leftExpr, Expression* rightExpr) 
      : BinaryOperation(leftExpr,rightExpr) {}

   virtual std::string GetSymbol() { return "*"; }
};

class Substraction : public BinaryOperation {
public:
   Substraction(Expression* leftExpr, Expression* rightExpr) 
      : BinaryOperation(leftExpr,rightExpr) {}

   virtual std::string GetSymbol() { return "-"; }
};

#endif
