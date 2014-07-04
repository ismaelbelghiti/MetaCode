#ifndef BASIC_VISITOR_H
#define BASIC_VISITOR_H

#include "MetaCodeAST/Visitors/AbstractVisitor.h"

// Basic Visitors run a DFS on the AST calling a method of the form ProcessX(X* x) 
// at each node (where X denotes the dynamic type of the node). These processing
// methods are defined as doing nothing, but we can overide them to get what you want.
// For example, if you want a visitor that display all Variable occurences of your AST
// you just have to inherit from BasicVisitor and overide ProcessVariable(Variable* variable).


class BasicVisitor : public AbstractVisitor {
public:
   //Type
   virtual void VisitType(Type * type);
   virtual void ProcessType(Type * type);

   //Variable
   virtual void VisitVariable(Variable* variable);   
   virtual void ProcessVariable(Variable* variable);   

   //Expression
   virtual void VisitExprFromInt(ExprFromInt* exprFromInt);   
   virtual void ProcessExprFromInt(ExprFromInt* exprFromInt);

   virtual void VisitExprFromBool(ExprFromBool* exprFromBool);
   virtual void ProcessExprFromBool(ExprFromBool* exprFromBool);

   virtual void VisitExprFromVariable(ExprFromVariable* exprFromVariable);
   virtual void ProcessExprFromVariable(ExprFromVariable* exprFromVariable);

   virtual void VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr);
   virtual void ProcessParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr);

   virtual void VisitMinus(Minus* minus);
   virtual void ProcessMinus(Minus* minus);

   virtual void VisitNegation(Negation* negation);
   virtual void ProcessNegation(Negation* negation);

   virtual void VisitAddition(Addition * addition);
   virtual void ProcessAddition(Addition * addition);

   virtual void VisitMultiplication(Multiplication * multiplication);
   virtual void ProcessMultiplication(Multiplication * multiplication);
   
   virtual void VisitSubstraction(Substraction * substraction);
   virtual void ProcessSubstraction(Substraction * substraction);

   virtual void VisitEuclidianDivision(EuclidianDivision * euclDiv);
   virtual void ProcessEuclidianDivision(EuclidianDivision * euclDiv);

   virtual void VisitModulus(Modulus * modulus);
   virtual void ProcessModulus(Modulus * modulus);

   virtual void VisitAnd(And * andNode);
   virtual void ProcessAnd(And * andNode);

   virtual void VisitOr(Or * orNode);
   virtual void ProcessOr(Or * orNode);

   //Statement
   virtual void VisitIf(If * ifNode);
   virtual void ProcessIf(If * ifNode);

   virtual void VisitElseIf(ElseIf * elseIfNode);
   virtual void ProcessElseIf(ElseIf * elseIfNode);

   virtual void VisitElse(Else * elseNode);
   virtual void ProcessElse(Else * elseNode);

   virtual void VisitDeclaration(Declaration * decl);
   virtual void ProcessDeclaration(Declaration * decl);   

   virtual void VisitFor(For * forNode);
   virtual void ProcessFor(For * forNode);

   virtual void VisitFunctionDeclaration(FunctionDeclaration * functionDecl);
   virtual void ProcessFunctionDeclaration(FunctionDeclaration * functionDecl);

   virtual void VisitIncludeLib(IncludeLib* includeLib);
   virtual void ProcessIncludeLib(IncludeLib* includeLib);

   virtual void VisitWhile(While* whileNode);
   virtual void ProcessWhile(While* whileNode);
   
   virtual void VisitMain(Main* mainNode);
   virtual void ProcessMain(Main* mainNode);

   virtual void VisitPrint(Print * print);
   virtual void ProcessPrint(Print * print);

private:
   virtual void VisitBinaryOperationChildren(BinaryOperation* binOp);

   virtual void VisitBlocStatements(IBloc* bloc);
};




#endif
