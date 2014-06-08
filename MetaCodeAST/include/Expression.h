#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Variable.h"

class Expression : public CodeNode {
public:
   virtual Type* GetType() = 0;
};

class ExprFromInt : public Expression {
public:
   ExprFromInt(int value) { m_value = value; }

   virtual int GetValue() { return m_value; }

   virtual Type* GetType() { return cInt; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << GetValue();
   }

private:
   int m_value;
};

class ExprFromBool : public Expression {
public:
   ExprFromBool(int value) { m_value = value; }

   virtual bool GetValue() { return m_value; }

   virtual Type* GetType() { return cBool; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      if(m_value)
	 std::cout << "True";
      else
	 std::cout << "False";
   }
private:
   bool m_value;
};

class ExprFromVariable : public Expression {
public:
   ExprFromVariable(Variable* variable) { m_variable = variable; }

   Variable* GetVariable() { return m_variable; }

   virtual Type* GetType() { return GetVariable()->GetType(); }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      GetVariable()->PrintDebug();
   }

private:
   Variable* m_variable;
};

/////////////////////
// Unary Operation //
/////////////////////

class UnaryOperation : public Expression {
public:
   UnaryOperation(Expression* expr) { m_expr = expr; }

   virtual Expression* GetExpression() { return m_expr; }

private:
   Expression* m_expr;
};

class ParenthesizedExpr : public UnaryOperation {
public:
   ParenthesizedExpr(Expression* expr) : UnaryOperation(expr) { }

   virtual Type* GetType() { return GetExpression()->GetType(); }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << "(";
      GetExpression()->PrintDebug();
      std::cout << ")";
   }

private:
   Expression* m_expr;
};

class Minus : public UnaryOperation {
public:
   Minus(Expression* expr) : UnaryOperation(expr) {}

   virtual Type* GetType() { return GetExpression()->GetType(); }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << "-";
      GetExpression()->PrintDebug();
   }
};

class Negation : public UnaryOperation {
public:
   Negation(Expression* expr) : UnaryOperation(expr) {}

   virtual Type* GetType() { return cBool; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << "!";
      GetExpression()->PrintDebug();
   }
};

//////////////////////
// Binary Operation //
//////////////////////

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
   
   virtual Type* GetType() { return GetLeftExpr()->GetType(); }

   virtual std::string GetSymbol() { return "+"; }
};

class Multiplication : public BinaryOperation {
public:
   Multiplication(Expression* leftExpr, Expression* rightExpr) 
      : BinaryOperation(leftExpr,rightExpr) {}

   virtual Type* GetType() { return GetLeftExpr()->GetType(); }

   virtual std::string GetSymbol() { return "*"; }
};

class Substraction : public BinaryOperation {
public:
   Substraction(Expression* leftExpr, Expression* rightExpr) 
      : BinaryOperation(leftExpr,rightExpr) {}

   virtual Type* GetType() { return GetLeftExpr()->GetType(); }

   virtual std::string GetSymbol() { return "-"; }
};

class EuclidianDivision : public BinaryOperation {
public:
   EuclidianDivision(Expression* leftExpr, Expression* rightExpr) 
      : BinaryOperation(leftExpr,rightExpr) {}

   virtual Type* GetType() { return cInt; }

   virtual std::string GetSymbol() { return "/"; }
};


class Modulus : public BinaryOperation {
public:
   Modulus(Expression* leftExpr, Expression* rightExpr) 
      : BinaryOperation(leftExpr,rightExpr) {}

   virtual Type* GetType() { return cInt; }

   virtual std::string GetSymbol() { return "%"; }
};

class And : public BinaryOperation {
public:
   And(Expression* leftExpr, Expression* rightExpr) 
      : BinaryOperation(leftExpr,rightExpr) {}

   virtual Type* GetType() { return cBool; }

   virtual std::string GetSymbol() { return "&&"; }
};

class Or : public BinaryOperation {
public:
   Or(Expression* leftExpr, Expression* rightExpr) 
      : BinaryOperation(leftExpr,rightExpr) {}

   virtual Type* GetType() { return cBool; }

   virtual std::string GetSymbol() { return "||"; }
};

#endif
