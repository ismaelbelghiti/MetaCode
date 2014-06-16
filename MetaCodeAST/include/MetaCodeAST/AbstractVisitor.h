#ifndef ABSTRACT_VISITOR_H
#define ABSTRACT_VISITOR_H

#include "MetaCodeAST.h"

class AbstractVisitor {
public:
   virtual void VisitExprFromInt(ExprFromInt* exprFromInt) = 0;

   virtual void VisitExprFromBool(ExprFromBool* exprFromBool) = 0;

   virtual void VisitExprFromVariable(ExprFromVariable* exprFromVariable) = 0;

   virtual void VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) = 0;

   virtual void VisitMinus(Minus* minus) = 0;

   virtual void VisitNegation(Negation* negation) = 0;

   virtual void VisitBinaryOperation(BinaryOperation* binaryOp) = 0;

   virtual void VisitBloc(Bloc* bloc) = 0;

   virtual void VisitIf(If * ifNode) = 0;

   virtual void VisitElseIf(ElseIf * elseIfNode) = 0;

   virtual void VisitElse(Else * elseNode) = 0;

   virtual void VisitDeclaration(Declaration * decl) = 0;

   virtual void VisitRange(Range * range) = 0;

   virtual void VisitFor(For * forNode) = 0;

   virtual void VisitFunction(Function * function) = 0;

   virtual void VisitSignature(Signature * signature) = 0;

   virtual void VisitFunctionDeclaration(FunctionDeclaration * functionDecl) = 0;

   virtual void VisitIncludeLib(IncludeLib* includeLib) = 0;

   virtual void VisitPrintableFromString(PrintableFromString * printStr) = 0;

   virtual void VisitPrintableFromExpression(PrintableFromExpression * printExpr) = 0;

   virtual void VisitPrint(Print * print) = 0;

   virtual void VisitType(Type * type) = 0;

   virtual void VisitVariable(Variable* variable) = 0;

   virtual void VisitWhile(While* whileNode) = 0;
   
   virtual void VisitMain(Main* mainNode) = 0;
};

#endif

