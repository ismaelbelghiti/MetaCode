#ifndef EMPTY_VISITOR_H
#define EMPTY_VISITOR_H

#include "MetaCodeAST/Visitors/AbstractVisitor.h"

class EmptyVisitor : public AbstractVisitor {
public:
   //Type
   virtual void VisitType(Type * type);

   //Variable
   virtual void VisitVariable(Variable* variable);   

   //Expression
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

   //Statement
   virtual void VisitIf(If * ifNode);

   virtual void VisitElseIf(ElseIf * elseIfNode);

   virtual void VisitElse(Else * elseNode);

   virtual void VisitDeclaration(Declaration * decl);

   virtual void VisitFor(For * forNode);

   virtual void VisitFunctionDeclaration(FunctionDeclaration * functionDecl);

   virtual void VisitIncludeLib(IncludeLib* includeLib);

   virtual void VisitWhile(While* whileNode);
   
   virtual void VisitMain(Main* mainNode);

   virtual void VisitPrint(Print * print);
};


#endif
