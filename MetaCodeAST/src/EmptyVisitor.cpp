#include "MetaCodeAST.h"


void EmptyVisitor::VisitType(Type * type) {}

void EmptyVisitor::VisitVariable(Variable* variable) {}   

void EmptyVisitor::VisitExprFromInt(ExprFromInt* exprFromInt) {}   

void EmptyVisitor::VisitExprFromBool(ExprFromBool* exprFromBool) {}

void EmptyVisitor::VisitExprFromVariable(ExprFromVariable* exprFromVariable) {}

void EmptyVisitor::VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) {}

void EmptyVisitor::VisitMinus(Minus* minus) {}

void EmptyVisitor::VisitNegation(Negation* negation) {}

void EmptyVisitor::VisitAddition(Addition * addition) {}

void EmptyVisitor::VisitMultiplication(Multiplication * multiplication) {}
   
void EmptyVisitor::VisitSubstraction(Substraction * substraction) {}

void EmptyVisitor::VisitEuclidianDivision(EuclidianDivision * euclDiv) {}

void EmptyVisitor::VisitModulus(Modulus * modulus) {}

void EmptyVisitor::VisitAnd(And * andNode) {}

void EmptyVisitor::VisitOr(Or * orNode) {}

void EmptyVisitor::VisitIf(If * ifNode) {}

void EmptyVisitor::VisitElseIf(ElseIf * elseIfNode) {}

void EmptyVisitor::VisitElse(Else * elseNode) {}

void EmptyVisitor::VisitDeclaration(Declaration * decl) {}

void EmptyVisitor::VisitFor(For * forNode) {}

void EmptyVisitor::VisitFunctionDeclaration(FunctionDeclaration * functionDecl) {}

void EmptyVisitor::VisitIncludeLib(IncludeLib* includeLib) {}

void EmptyVisitor::VisitWhile(While* whileNode) {}
   
void EmptyVisitor::VisitMain(Main* mainNode) {}

void EmptyVisitor::VisitPrint(Print * print) {}
