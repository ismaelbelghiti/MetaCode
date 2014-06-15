#ifndef PRINTER_VISITOR_H
#define PRINTER_VISITOR_H

#include "MetaCodeAST/AbstractVisitor.h"

class PrinterVisitor : public AbstractVisitor {
public:
   virtual void VisitExprFromInt(ExprFromInt* exprFromInt);

   virtual void VisitExprFromBool(ExprFromBool* exprFromBool);

   virtual void VisitExprFromVariable(ExprFromVariable* exprFromVariable);

   virtual void VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr);

   virtual void VisitMinus(Minus* minus);

   virtual void VisitNegation(Negation* negation);

   virtual void VisitBinaryOperation(BinaryOperation* binaryOp);

};

#endif
