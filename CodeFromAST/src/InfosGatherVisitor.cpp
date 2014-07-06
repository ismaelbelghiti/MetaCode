#include "CodeFromAST/InfosGatherVisitor.h"

InfosGatherVisitor::InfosGatherVisitor(IStatement* root) {
   Call(root,0);
}

void InfosGatherVisitor::VisitIf(If * ifNode) {
   VisitBloc(ifNode->GetBloc(),GetCurrentLevel());
}

void InfosGatherVisitor::VisitElseIf(ElseIf * elseIfNode) {
   VisitBloc(elseIfNode->GetBloc(), GetCurrentLevel());
}

void InfosGatherVisitor::VisitElse(Else * elseNode) {
   VisitBloc(elseNode->GetBloc(), GetCurrentLevel());
}

void InfosGatherVisitor::VisitDeclaration(Declaration * decl) {
   // do nothing
}

void InfosGatherVisitor::VisitFor(For * forNode) {
   VisitBloc(forNode->GetBloc(), GetCurrentLevel());
}

void InfosGatherVisitor::VisitFunctionDecaration(FunctionDeclaration * functionDecl) {
   VisitBloc(functionDecl->GetBloc(), GetCurrentLevel());
}

void InfosGatherVisitor::VisitIncludeLib(IncludeLib* includeLib) {
   // do nothing
}

void InfosGatherVisitor::VisitPrintableFromString(PrintableFromString * printStr) {
   // do nothing
}

void InfosGatherVisitor::VisitPrintableFromExpression(PrintableFromExpression * printExpr) {
   // do nothing
}

void InfosGatherVisitor::VisitPrint(Print * print) {
   // do nothing
}

void InfosGatherVisitor::VisitWhile(While* whileNode) {
   VisitBloc(whileNode->GetBloc(), GetCurrentLevel());
}
   
void InfosGatherVisitor::VisitMain(Main* mainNode) {
   VisitBloc(mainNode->GetBloc(), GetCurrentLevel());
}

int InfosGatherVisitor::GetIndentLevel(IStatement* statement) {
   return m_indentLevel[statement];
}


// private:

void InfosGatherVisitor::VisitBloc(IBloc* bloc, int currentLevel) {
   for(int iStatement = 0; iStatement < bloc->GetNbStatements(); iStatement++) 
      Call(bloc->GetStatement(iStatement), currentLevel+1);
}

int InfosGatherVisitor::GetCurrentLevel() {
   return m_callIndentLevel.back();
}

void InfosGatherVisitor::Call(IStatement* statement, int indentLevel) {
   m_indentLevel[statement] = indentLevel; 
   m_callIndentLevel.push_back(indentLevel);
   m_activeParent.push_back(statement);
   statement->Visit(this);
   m_callIndentLevel.pop_back();
   m_activeParent.pop_back();
}

/*


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


int InfosGatherVisitor::GetIndentLevel(CodeNode* codeNode) {
   return m_indentLevel[codeNode];
}


//private:
void InfosGatherVisitor::VisitBinaryOperation(BinaryOperation* binOp) {
   Call(binOp->GetLeftExpr(),0);
   Call(binOp->GetRightExpr(),0);
}


*/
