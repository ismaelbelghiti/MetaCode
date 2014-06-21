#include "CodeFromAST/EmptyVisitor.h"

void EmptyVisitor::VisitExprFromInt(ExprFromInt* exprFromInt) {
}

void EmptyVisitor::VisitExprFromBool(ExprFromBool* exprFromBool) {
}

void EmptyVisitor::VisitExprFromVariable(ExprFromVariable* exprFromVariable) {
}

void EmptyVisitor::VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) {
}

void EmptyVisitor::VisitMinus(Minus* minus) {
}

void EmptyVisitor::VisitNegation(Negation* negation) {
}

void EmptyVisitor::VisitAddition(Addition * addition) {
}

void EmptyVisitor::VisitMultiplication(Multiplication * multiplication) {
}

void EmptyVisitor::VisitSubstraction(Substraction * substraction) {
}

void EmptyVisitor::VisitEuclidianDivision(EuclidianDivision * euclDiv) {
}

void EmptyVisitor::VisitModulus(Modulus * modulus) {
}

void EmptyVisitor::VisitAnd(And * andNode) {
}

void EmptyVisitor::VisitOr(Or * orNode) {
}

void EmptyVisitor::VisitBloc(Bloc* bloc) {
}

void EmptyVisitor::VisitIf(If * ifNode) {
}

void EmptyVisitor::VisitElseIf(ElseIf * elseIfNode)  {
}

void EmptyVisitor::VisitElse(Else * elseNode) {
}

void EmptyVisitor::VisitDeclaration(Declaration * decl) {
}

void EmptyVisitor::VisitRange(Range * range) {
}

void EmptyVisitor::VisitFor(For * forNode) {
}

void EmptyVisitor::VisitFunction(Function * function) {
}

void EmptyVisitor::VisitSignature(Signature * signature) {
}

void EmptyVisitor::VisitFunctionDeclaration(FunctionDeclaration * functionDecl) {
}

void EmptyVisitor::VisitIncludeLib(IncludeLib* includeLib) {
}

void EmptyVisitor::VisitPrintableFromString(PrintableFromString * printStr) {
}

void EmptyVisitor::VisitPrintableFromExpression(PrintableFromExpression * printExpr) {
}

void EmptyVisitor::VisitPrint(Print * print) {
}

void EmptyVisitor::VisitType(Type * type) {
}

void EmptyVisitor::VisitVariable(Variable* variable)  {
}

void EmptyVisitor::VisitWhile(While* whileNode) {
}
   
void EmptyVisitor::VisitMain(Main* mainNode) {
}

int EmptyVisitor::GetIndentLevel(CodeNode* codeNode) {
}

