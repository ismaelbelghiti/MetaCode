#ifndef PRINT_H
#define PRINT_H

#include "Expression.h"

/*
class Printable : public CodeNode {
public:
   virtual bool isExpression() = 0;

   virtual std::string GetString() { return std::string(); b}

   virtual TypedExpression* GetTypedExpression() { return 0 };
};

class PrintableFromExpression : public Printable {
public:
   PrintableFromExpression(TypedExpression * typedExpr) { 
      m_typedExpression = typedExpr;
   }

   virtual bool isExpression() { return true; }

   virtual Expression* GetExpression() { return m_expr; }
};

class PrintableFromString : public Printable {
public:
   virtual bool isExpression() { return false; }
};
*/

class Print : public CodeNode {
public:
   Print(int nbArgs) {
      
   }
};


#endif
