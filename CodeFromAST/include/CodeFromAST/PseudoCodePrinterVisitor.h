#ifndef PSEUDOCODE_PRINTER_VISITOR_H
#define PSEUDOCODE_PRINTER_VISITOR_H

#include "MetaCodeAST.h"
#include "CodeFromAST/InfosGatherVisitor.h"

class PseudoCodePrinterVisitor : public AbstractVisitor {
public:
   PseudoCodePrinterVisitor(IStatement* root);
   
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

   virtual void VisitIf(If * ifNode);

   virtual void VisitElseIf(ElseIf * elseIfNode);

   virtual void VisitElse(Else * elseNode);

   virtual void VisitDeclaration(Declaration * decl);

   virtual void VisitFor(For * forNode);

   virtual void VisitFunctionDeclaration(FunctionDeclaration * functionDecl);

   virtual void VisitIncludeLib(IncludeLib* includeLib);

   virtual void VisitPrint(Print * print);

   virtual void VisitType(Type * type);

   virtual void VisitVariable(Variable* variable);

   virtual void VisitWhile(While* whileNode);
   
   virtual void VisitMain(Main* mainNode);

private:
   virtual void VisitBloc(IBloc* bloc);

   virtual void VisitBinaryOperation(BinaryOperation* binOp, std::string opString);
   
   virtual int GetIndentLevel(IStatement* statement);

   InfosGatherVisitor* m_info;
};

#endif
