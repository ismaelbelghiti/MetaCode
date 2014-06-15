#include "CodeFromAST/PrinterVisitor.h"

void PrinterVisitor::VisitExprFromInt(ExprFromInt* exprFromInt) {
   std::cout << exprFromInt->GetValue();
}

void PrinterVisitor::VisitExprFromBool(ExprFromBool* exprFromBool) {
   if(exprFromBool->GetValue())
      std::cout << "true";
   else
      std::cout << "false";
}

void PrinterVisitor::VisitExprFromVariable(ExprFromVariable* exprFromVariable) {
   std::cout << exprFromVariable->GetVariable()->GetName();
}

void PrinterVisitor::VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) {
   std::cout << "(";
   parenthesizedExpr->GetExpression()->Visit(this);
   std::cout << ")";
}

void PrinterVisitor::VisitMinus(Minus* minus) {
   std::cout << "-";
   minus->GetExpression()->Visit(this);
}

void PrinterVisitor::VisitNegation(Negation* negation) {
   std::cout << "!";
   negation->GetExpression()->Visit(this);
}

void PrinterVisitor::VisitBinaryOperation(BinaryOperation* binaryOp) {
   binaryOp->GetLeftExpr()->Visit(this);
   std::cout << binaryOp->GetSymbol();
   binaryOp->GetRightExpr()->Visit(this);
}
