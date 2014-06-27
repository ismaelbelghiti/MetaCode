#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "MetaCodeAST/InterfaceType.h"

class ExprFromInt : public IExpression {
public:
   ExprFromInt(int value);

   virtual int GetValue();

   virtual IType* GetType();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   int m_value;
};

class ExprFromBool : public IExpression {
public:
   ExprFromBool(bool value);

   virtual bool GetValue();

   virtual IType* GetType();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   bool m_value;
};

class ExprFromVariable : public IExpression {
public:
   ExprFromVariable(IVariable* variable);

   IVariable* GetVariable();

   virtual IType* GetType();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   IVariable* m_variable;
};

/////////////////////
// Unary Operation //
/////////////////////

class UnaryOperation : public IExpression {
public:
   UnaryOperation(IExpression* expr);

   virtual IExpression* GetExpression();

private:
  IExpression* m_expr;
};

class ParenthesizedExpr : public UnaryOperation {
public:
   ParenthesizedExpr(IExpression* expr);

   virtual IType* GetType();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
  IExpression* m_expr;
};

class Minus : public UnaryOperation {
public:
   Minus(IExpression* expr);

   virtual IType* GetType();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);
};

class Negation : public UnaryOperation {
public:
   Negation(IExpression* expr);

   virtual IType* GetType();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);
};

//////////////////////
// Binary Operation //
//////////////////////

class BinaryOperation : public IExpression {
public:
   BinaryOperation(IExpression* leftExpr,IExpression* rightExpr);

  IExpression* GetLeftExpr();

  IExpression* GetRightExpr();
   
   virtual std::string GetSymbol() = 0;

   virtual void PrintDebug(int level = 0);

private:
  IExpression *m_leftExpr, *m_rightExpr;
};

class Addition : public BinaryOperation {
public:
   Addition(IExpression* leftExpr,IExpression* rightExpr);
   
   virtual IType* GetType();

   virtual std::string GetSymbol();

   virtual void Visit(AbstractVisitor* visitor);
};

class Multiplication : public BinaryOperation {
public:
   Multiplication(IExpression* leftExpr,IExpression* rightExpr);

   virtual IType* GetType();

   virtual std::string GetSymbol();

   virtual void Visit(AbstractVisitor* visitor);
};

class Substraction : public BinaryOperation {
public:
   Substraction(IExpression* leftExpr,IExpression* rightExpr);

   virtual IType* GetType();

   virtual std::string GetSymbol();

   virtual void Visit(AbstractVisitor* visitor);
};

class EuclidianDivision : public BinaryOperation {
public:
   EuclidianDivision(IExpression* leftExpr,IExpression* rightExpr);

   virtual IType* GetType();

   virtual std::string GetSymbol();

   virtual void Visit(AbstractVisitor* visitor);
};


class Modulus : public BinaryOperation {
public:
   Modulus(IExpression* leftExpr,IExpression* rightExpr);

   virtual IType* GetType();

   virtual std::string GetSymbol();

   virtual void Visit(AbstractVisitor* visitor);
};

class And : public BinaryOperation {
public:
   And(IExpression* leftExpr,IExpression* rightExpr);

   virtual IType* GetType();

   virtual std::string GetSymbol();

   virtual void Visit(AbstractVisitor* visitor);
};

class Or : public BinaryOperation {
public:
   Or(IExpression* leftExpr,IExpression* rightExpr);

   virtual IType* GetType();

   virtual std::string GetSymbol();

   virtual void Visit(AbstractVisitor* visitor);
};

#endif
