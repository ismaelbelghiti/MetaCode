#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Variable.h"

class Expression : public CodeNode {
public:
   virtual Type* GetType() = 0;
};

class ExprFromInt : public Expression {
public:
   ExprFromInt(int value);

   virtual int GetValue();

   virtual Type* GetType();

   virtual void PrintDebug(int level = 0);

private:
   int m_value;
};

class ExprFromBool : public Expression {
public:
   ExprFromBool(int value);

   virtual bool GetValue();

   virtual Type* GetType();

   virtual void PrintDebug(int level = 0);

private:
   bool m_value;
};

class ExprFromVariable : public Expression {
public:
   ExprFromVariable(Variable* variable);

   Variable* GetVariable();

   virtual Type* GetType();

   virtual void PrintDebug(int level = 0);

private:
   Variable* m_variable;
};

/////////////////////
// Unary Operation //
/////////////////////

class UnaryOperation : public Expression {
public:
   UnaryOperation(Expression* expr);

   virtual Expression* GetExpression();

private:
   Expression* m_expr;
};

class ParenthesizedExpr : public UnaryOperation {
public:
   ParenthesizedExpr(Expression* expr);

   virtual Type* GetType();

   virtual void PrintDebug(int level = 0);

private:
   Expression* m_expr;
};

class Minus : public UnaryOperation {
public:
   Minus(Expression* expr);

   virtual Type* GetType();

   virtual void PrintDebug(int level = 0);
};

class Negation : public UnaryOperation {
public:
   Negation(Expression* expr);

   virtual Type* GetType();

   virtual void PrintDebug(int level = 0);
};

//////////////////////
// Binary Operation //
//////////////////////

class BinaryOperation : public Expression {
public:
   BinaryOperation(Expression* leftExpr, Expression* rightExpr);

   Expression* GetLeftExpr();

   Expression* GetRightExpr();
   
   virtual std::string GetSymbol() = 0;

   virtual void PrintDebug(int level = 0);

private:
   Expression *m_leftExpr, *m_rightExpr;
};

class Addition : public BinaryOperation {
public:
   Addition(Expression* leftExpr, Expression* rightExpr);
   
   virtual Type* GetType();

   virtual std::string GetSymbol();
};

class Multiplication : public BinaryOperation {
public:
   Multiplication(Expression* leftExpr, Expression* rightExpr);

   virtual Type* GetType();

   virtual std::string GetSymbol();
};

class Substraction : public BinaryOperation {
public:
   Substraction(Expression* leftExpr, Expression* rightExpr);

   virtual Type* GetType();

   virtual std::string GetSymbol();
};

class EuclidianDivision : public BinaryOperation {
public:
   EuclidianDivision(Expression* leftExpr, Expression* rightExpr);

   virtual Type* GetType();

   virtual std::string GetSymbol();
};


class Modulus : public BinaryOperation {
public:
   Modulus(Expression* leftExpr, Expression* rightExpr);

   virtual Type* GetType();

   virtual std::string GetSymbol();
};

class And : public BinaryOperation {
public:
   And(Expression* leftExpr, Expression* rightExpr);

   virtual Type* GetType();

   virtual std::string GetSymbol();
};

class Or : public BinaryOperation {
public:
   Or(Expression* leftExpr, Expression* rightExpr);

   virtual Type* GetType();

   virtual std::string GetSymbol();
};

#endif
