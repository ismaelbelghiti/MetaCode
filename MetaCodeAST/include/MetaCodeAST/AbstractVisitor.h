#ifndef ABSTRACT_VISITOR_H
#define ABSTRACT_VISITOR_H

#include "MetaCodeAST/Expression.h"

class AbstractVisitor {
public:
   virtual void VisitExprFromInt(ExprFromInt* exprFromInt) = 0;

   virtual void VisitExprFromBool(ExprFromBool* exprFromBool) = 0;

   virtual void VisitExprFromVariable(ExprFromVariable* exprFromVariable) = 0;

   virtual void VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) = 0;

   virtual void VisitMinus(Minus* minus) = 0;

   virtual void VisitNegation(Negation* negation) = 0;

   virtual void VisitBinaryOperation(BinaryOperation* binaryOp) = 0;

};

#endif

