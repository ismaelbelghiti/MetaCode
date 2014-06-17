#include "CodeFromAST/InfosGatherVisitor.h"

InfosGatherVisitor::InfosGatherVisitor(CodeNode* root) {
   Call(root,0);
}

void InfosGatherVisitor::VisitExprFromInt(ExprFromInt* exprFromInt) {}

void InfosGatherVisitor::VisitExprFromBool(ExprFromBool* exprFromBool) {}

void InfosGatherVisitor::VisitExprFromVariable(ExprFromVariable* exprFromVariable) {}

void InfosGatherVisitor::VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) {
   Call(parenthesizedExpr->GetExpression(),0);
}

void InfosGatherVisitor::VisitMinus(Minus* minus) {
   Call(minus->GetExpression(),0);
}

void InfosGatherVisitor::VisitNegation(Negation* negation) {
   Call(negation->GetExpression(),0);
}

void InfosGatherVisitor::VisitAddition(Addition * addition) {
   VisitBinaryOperation(addition);
}

void InfosGatherVisitor::VisitMultiplication(Multiplication * multiplication) {
   VisitBinaryOperation(multiplication);
}

void InfosGatherVisitor::VisitSubstraction(Substraction * substraction) {
   VisitBinaryOperation(substraction);
}

void InfosGatherVisitor::VisitEuclidianDivision(EuclidianDivision * euclDiv) {
   VisitBinaryOperation(euclDiv);
}

void InfosGatherVisitor::VisitModulus(Modulus * modulus) {
   VisitBinaryOperation(modulus);
}

void InfosGatherVisitor::VisitAnd(And * andNode) {
   VisitBinaryOperation(andNode);
}

void InfosGatherVisitor::VisitOr(Or * orNode) {
   VisitBinaryOperation(orNode);
}

void InfosGatherVisitor::VisitBloc(Bloc* bloc) {
   for(int iCodeNode = 0; iCodeNode < bloc->GetNbCodeNodes(); iCodeNode++) 
      Call(bloc->GetCodeNode(iCodeNode),GetCurrentLevel()+1);
}

void InfosGatherVisitor::VisitIf(If * ifNode) {
   Call(ifNode->GetCondition(),0);
   Call(ifNode->GetBloc(),GetCurrentLevel());
}

void InfosGatherVisitor::VisitElseIf(ElseIf * elseIfNode)  {
   Call(elseIfNode->GetCondition(),0);
   Call(elseIfNode->GetBloc(),GetCurrentLevel());
}

void InfosGatherVisitor::VisitElse(Else * elseNode) {
   Call(elseNode->GetBloc(),GetCurrentLevel());
}

void InfosGatherVisitor::VisitDeclaration(Declaration * decl) {
   Call(decl->GetVariable(),0);
   Call(decl->GetExpression(),0);
}

void InfosGatherVisitor::VisitRange(Range * range) {
   Call(range->GetStart(),0);
   if(range->IncludedEndIsDefined())
      Call(range->GetIncludedEnd(),0);
   else 
      Call(range->GetExcludedEnd(),0);
}

void InfosGatherVisitor::VisitFor(For * forNode) {
   Call(forNode->GetVariable(),0);
   Call(forNode->GetRange(),0);
   Call(forNode->GetBloc(),GetCurrentLevel());
}

void InfosGatherVisitor::VisitFunction(Function * function) {
   //todo
}

void InfosGatherVisitor::VisitSignature(Signature * signature) {
   //todo
}

void InfosGatherVisitor::VisitFunctionDeclaration(FunctionDeclaration * functionDecl) {
   //todo
}

void InfosGatherVisitor::VisitIncludeLib(IncludeLib* includeLib) {
   //todo
}

void InfosGatherVisitor::VisitPrintableFromString(PrintableFromString * printStr) {}

void InfosGatherVisitor::VisitPrintableFromExpression(PrintableFromExpression * printExpr) {
   Call(printExpr->GetExpression(),0);
}

void InfosGatherVisitor::VisitPrint(Print * print) {
   for(int iPrintable = 0; iPrintable < print->GetNbPrintables(); iPrintable++)
      Call(print->GetPrintable(iPrintable),0);
}

void InfosGatherVisitor::VisitType(Type * type) {
   std::cout << type->GetName();
}

void InfosGatherVisitor::VisitVariable(Variable* variable)  {
}

void InfosGatherVisitor::VisitWhile(While* whileNode) {
   Call(whileNode->GetCondition(),0);
   Call(whileNode->GetBloc(),GetCurrentLevel());
}
   
void InfosGatherVisitor::VisitMain(Main* mainNode) {
   //todo
}


//private:
void InfosGatherVisitor::VisitBinaryOperation(BinaryOperation* binOp) {
   Call(binOp->GetLeftExpr(),0);
   Call(binOp->GetRightExpr(),0);
}

int InfosGatherVisitor::GetCurrentLevel() {
   return m_callIndentLevel.back();
}

void InfosGatherVisitor::Call(CodeNode* codeNode, int indentLevel) {
   m_indentLevel[codeNode] = indentLevel; 
   std::cout << indentLevel << std::endl;

   m_callIndentLevel.push_back(indentLevel);
   m_activeParent.push_back(codeNode);
   codeNode->Visit(this);
   m_callIndentLevel.pop_back();
   m_activeParent.pop_back();
}
