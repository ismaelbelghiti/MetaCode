#include "MetaCodeAST.h"

//Type
void BasicVisitor::VisitType(Type * type) {
   ProcessType(type); 
}
void BasicVisitor::ProcessType(Type * type) {}

//Variable
void BasicVisitor::VisitVariable(Variable* variable) {
   ProcessVariable(variable); 
}
void BasicVisitor::ProcessVariable(Variable* variable) {}   

//Expression
void BasicVisitor::VisitExprFromInt(ExprFromInt* exprFromInt) {
   ProcessExprFromInt(exprFromInt);
}   
void BasicVisitor::ProcessExprFromInt(ExprFromInt* exprFromInt) {}

void BasicVisitor::VisitExprFromBool(ExprFromBool* exprFromBool) {
   ProcessExprFromBool(exprFromBool);
}
void BasicVisitor::ProcessExprFromBool(ExprFromBool* exprFromBool) {}

void BasicVisitor::VisitExprFromVariable(ExprFromVariable* exprFromVariable) {
   ProcessExprFromVariable(exprFromVariable);
}
void BasicVisitor::ProcessExprFromVariable(ExprFromVariable* exprFromVariable) {}

void BasicVisitor::VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) {
   ProcessParenthesizedExpr(parenthesizedExpr);
   parenthesizedExpr->GetExpression()->Visit(this);
}
void BasicVisitor::ProcessParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) {}

void BasicVisitor::VisitMinus(Minus* minus) {
   ProcessMinus(minus);
   minus->GetExpression()->Visit(this);
}
void BasicVisitor::ProcessMinus(Minus* minus) {}

void BasicVisitor::VisitNegation(Negation* negation) {
   ProcessNegation(negation);
   negation->GetExpression()->Visit(this);
}
void BasicVisitor::ProcessNegation(Negation* negation) {}

void BasicVisitor::VisitAddition(Addition * addition) {
   ProcessAddition(addition);
   VisitBinaryOperationChildren(addition);
}
void BasicVisitor::ProcessAddition(Addition * addition) {}

void BasicVisitor::VisitMultiplication(Multiplication * multiplication) {
   ProcessMultiplication(multiplication);
   VisitBinaryOperationChildren(multiplication);
}
void BasicVisitor::ProcessMultiplication(Multiplication * multiplication) {}
   
void BasicVisitor::VisitSubstraction(Substraction * substraction) {
   ProcessSubstraction(substraction);
   VisitBinaryOperationChildren(substraction);
}
void BasicVisitor::ProcessSubstraction(Substraction * substraction) {}

void BasicVisitor::VisitEuclidianDivision(EuclidianDivision * euclDiv) {
   ProcessEuclidianDivision(euclDiv);
   VisitBinaryOperationChildren(euclDiv);
}
void BasicVisitor::ProcessEuclidianDivision(EuclidianDivision * euclDiv) {}

void BasicVisitor::VisitModulus(Modulus * modulus) {
   ProcessModulus(modulus);
   VisitBinaryOperationChildren(modulus);
}
void BasicVisitor::ProcessModulus(Modulus * modulus) {}

void BasicVisitor::VisitAnd(And * andNode) {
   ProcessAnd(andNode);
   VisitBinaryOperationChildren(andNode);
}
void BasicVisitor::ProcessAnd(And * andNode) {}

void BasicVisitor::VisitOr(Or * orNode) {
   ProcessOr(orNode);
   VisitBinaryOperationChildren(orNode);
}
void BasicVisitor::ProcessOr(Or * orNode) {}


// Statement
void BasicVisitor::VisitIf(If * ifNode) {
   ProcessIf(ifNode);
   ifNode->GetCondition()->Visit(this);
   VisitBlocStatements(ifNode->GetBloc());
}
void BasicVisitor::ProcessIf(If * ifNode) {}

void BasicVisitor::VisitElseIf(ElseIf * elseIfNode) {
   ProcessElseIf(elseIfNode);
   elseIfNode->GetCondition()->Visit(this);
   VisitBlocStatements(elseIfNode->GetBloc());   
}
void BasicVisitor::ProcessElseIf(ElseIf * elseIfNode) {}

void BasicVisitor::VisitElse(Else * elseNode) {
   ProcessElse(elseNode);
   VisitBlocStatements(elseNode->GetBloc());
}
void BasicVisitor::ProcessElse(Else * elseNode) {}

void BasicVisitor::VisitDeclaration(Declaration * decl) {
   ProcessDeclaration(decl);
   decl->GetVariable()->Visit(this);
   decl->GetExpression()->Visit(this);
}
void BasicVisitor::ProcessDeclaration(Declaration * decl) {}   

void BasicVisitor::VisitFor(For * forNode) {
   ProcessFor(forNode);
   forNode->GetVariable()->Visit(this);
   forNode->GetRange()->GetStart()->Visit(this);
   if(forNode->GetRange()->IncludedEndIsDefined())
      forNode->GetRange()->GetIncludedEnd()->Visit(this);
   else
      forNode->GetRange()->GetExcludedEnd()->Visit(this);
   VisitBlocStatements(forNode->GetBloc());
}
void BasicVisitor::ProcessFor(For * forNode) {}

void BasicVisitor::VisitFunctionDeclaration(FunctionDeclaration * functionDecl) {
   ProcessFunctionDeclaration(functionDecl);
   functionDecl->GetVariable()->Visit(this);
   
}
void BasicVisitor::ProcessFunctionDeclaration(FunctionDeclaration * functionDecl) {}

void BasicVisitor::VisitIncludeLib(IncludeLib* includeLib) {
   ProcessIncludeLib(includeLib);
}
void BasicVisitor::ProcessIncludeLib(IncludeLib* includeLib) {}

void BasicVisitor::VisitWhile(While* whileNode) {
   ProcessWhile(whileNode);
   whileNode->GetCondition()->Visit(this);
   VisitBlocStatements(whileNode->GetBloc());
}
void BasicVisitor::ProcessWhile(While* whileNode) {}
   
void BasicVisitor::VisitMain(Main* mainNode) {
   ProcessMain(mainNode);
   VisitBlocStatements(mainNode->GetBloc());
}
void BasicVisitor::ProcessMain(Main* mainNode) {}

void BasicVisitor::VisitPrint(Print * print) {
   ProcessPrint(print);
   for(int iPrintable = 0; iPrintable < print->GetNbPrintables(); iPrintable++)
      if(print->GetPrintable(iPrintable)->IsExpression())
	 print->GetPrintable(iPrintable)->GetExpression()->Visit(this);
}
void BasicVisitor::ProcessPrint(Print * print) {}


// private:

void BasicVisitor::VisitBinaryOperationChildren(BinaryOperation* binOp) {
   binOp->GetLeftExpr()->Visit(this);
   binOp->GetRightExpr()->Visit(this);
}

void BasicVisitor::VisitBlocStatements(IBloc* bloc) {
   for(int iStatement = 0; iStatement < bloc->GetNbStatements(); iStatement++) {
      bloc->GetStatement(iStatement)->Visit(this);
   }
}

