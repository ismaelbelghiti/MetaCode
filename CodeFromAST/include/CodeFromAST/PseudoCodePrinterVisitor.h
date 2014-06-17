#ifndef PSEUDOCODE_PRINTER_VISITOR_H
#define PSEUDOCODE_PRINTER_VISITOR_H

#include "MetaCodeAST/AbstractVisitor.h"

class PseudoCodePrinterVisitor : public AbstractVisitor {
public:
   virtual void VisitExprFromInt(ExprFromInt* exprFromInt);

   virtual void VisitExprFromBool(ExprFromBool* exprFromBool);

   virtual void VisitExprFromVariable(ExprFromVariable* exprFromVariable);

   virtual void VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr);

   virtual void VisitMinus(Minus* minus);

   virtual void VisitNegation(Negation* negation);

   virtual void VisitAddition(Addition * addition);

   virtual void VisitMultiplication(Multiplication * multiplication);

   virtual void VisitSubstraction(Substraction * substraction);

   virtual void VisitEuclidianDivision(EuclidianDivision * euclDiv);

   virtual void VisitModulus(Modulus * modulus);

   virtual void VisitAnd(And * andNode);

   virtual void VisitOr(Or * orNode);

   virtual void VisitBloc(Bloc* bloc);

   virtual void VisitIf(If * ifNode);

   virtual void VisitElseIf(ElseIf * elseIfNode);

   virtual void VisitElse(Else * elseNode);

   virtual void VisitDeclaration(Declaration * decl);

   virtual void VisitRange(Range * range);

   virtual void VisitFor(For * forNode);

   virtual void VisitFunction(Function * function);

   virtual void VisitSignature(Signature * signature);

   virtual void VisitFunctionDeclaration(FunctionDeclaration * functionDecl);

   virtual void VisitIncludeLib(IncludeLib* includeLib);

   virtual void VisitPrintableFromString(PrintableFromString * printStr);

   virtual void VisitPrintableFromExpression(PrintableFromExpression * printExpr);

   virtual void VisitPrint(Print * print);

   virtual void VisitType(Type * type);

   virtual void VisitVariable(Variable* variable);

   virtual void VisitWhile(While* whileNode);
   
   virtual void VisitMain(Main* mainNode);

private:
   virtual void VisitBinaryOperation(BinaryOperation* binOp, std::string opString);
};

#endif
