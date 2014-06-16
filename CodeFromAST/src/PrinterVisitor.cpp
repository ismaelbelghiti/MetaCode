#include "CodeFromAST/PrinterVisitor.h"

void PrinterVisitor::VisitExprFromInt(ExprFromInt* exprFromInt) {
   std::cout << exprFromInt->GetValue();
}

void PrinterVisitor::VisitExprFromBool(ExprFromBool* exprFromBool) {
   if(exprFromBool->GetValue())
      std::cout << "Vrai";
   else
      std::cout << "Faux";
}

void PrinterVisitor::VisitExprFromVariable(ExprFromVariable* exprFromVariable) {
   std::cout << exprFromVariable->GetVariable()->GetName();
}

void PrinterVisitor::VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) {
   std::cout << "(";
   parenthesizedExpr->GetExpression()->Visit(this);
   std::cout << ")";
}

void PrinterVisitor::VisitMinus(Minus* minus) {
   std::cout << "-";
   minus->GetExpression()->Visit(this);
}

void PrinterVisitor::VisitNegation(Negation* negation) {
   std::cout << "!";
   negation->GetExpression()->Visit(this);
}

void PrinterVisitor::VisitBinaryOperation(BinaryOperation* binaryOp) {
   binaryOp->GetLeftExpr()->Visit(this);
   std::cout << " " << binaryOp->GetSymbol() << " ";
   binaryOp->GetRightExpr()->Visit(this);
}

void PrinterVisitor::VisitBloc(Bloc* bloc) {
   for(int iCodeNode = 0; iCodeNode < bloc->GetNbCodeNodes(); iCodeNode++) {
      bloc->GetCodeNode(iCodeNode)->Visit(this);
      std::cout << std::endl;
   }
}

void PrinterVisitor::VisitIf(If * ifNode) {
   std::cout << "Si ";
   ifNode->GetCondition()->Visit(this);
   std::cout << std::endl;
}

void PrinterVisitor::VisitElseIf(ElseIf * elseIfNode)  {
   std::cout << "Sinon si ";
   elseIfNode->GetCondition()->Visit(this);
   std::cout << std::endl;
}

void PrinterVisitor::VisitElse(Else * elseNode) {
   std::cout << "Sinon " << std::endl;
   elseNode->GetBloc()->Visit(this);
}

void PrinterVisitor::VisitDeclaration(Declaration * decl) {
   decl->GetVariable()->GetType()->Visit(this);
   std::cout << " ";
   decl->GetVariable()->Visit(this);
   std::cout << " = ";
   decl->GetExpression()->Visit(this);
   std::cout << std::endl;
}

void PrinterVisitor::VisitRange(Range * range) {
   std::cout << " partant de ";
   range->GetStart()->Visit(this);
   if(range->IsIncreasing())
      std::cout << " et croissant jusque ";
   else
      std::cout << " down to ";
   if(range->IncludedEndIsDefined()){
      range->GetIncludedEnd()->Visit(this);
      std::cout << " inclu ";
   }
   else {
      range->GetExcludedEnd()->Visit(this);
      std::cout << " exclu ";
   }
}

void PrinterVisitor::VisitFor(For * forNode) {
   std::cout << "Pour ";
   forNode->GetVariable()->Visit(this);
   forNode->GetRange()->Visit(this);
   std::cout << std::endl;
   forNode->GetBloc()->Visit(this);
}

void PrinterVisitor::VisitFunction(Function * function) {
   //todo
}

void PrinterVisitor::VisitSignature(Signature * signature) {
   //todo
}

void PrinterVisitor::VisitFunctionDeclaration(FunctionDeclaration * functionDecl) {
   //todo
}

void PrinterVisitor::VisitIncludeLib(IncludeLib* includeLib) {
   //todo
}

void PrinterVisitor::VisitPrintableFromString(PrintableFromString * printStr) {
   std::cout << "\""  << printStr->GetString() << "\"";
}

void PrinterVisitor::VisitPrintableFromExpression(PrintableFromExpression * printExpr) {
   printExpr->GetExpression()->Visit(this);
}

void PrinterVisitor::VisitPrint(Print * print) {
   std::cout << "Affiche ";
   for(int iPrintable = 0; iPrintable < print->GetNbPrintables(); iPrintable++) {
      print->GetPrintable(iPrintable)->Visit(this);
      std::cout << " ";
   }	 
   if(print->WithEndline())
      std::cout << " et passer a la ligne";
   std::cout << std::endl;
}

void PrinterVisitor::VisitType(Type * type) {
   std::cout << type->GetName();
}

void PrinterVisitor::VisitVariable(Variable* variable)  {
   std::cout << variable->GetName();
}

void PrinterVisitor::VisitWhile(While* whileNode) {
   std::cout << "Tant que ";
   whileNode->GetCondition()->Visit(this);
   std::cout << std::endl;
   whileNode->GetBloc()->Visit(this);
}
   
void PrinterVisitor::VisitMain(Main* mainNode) {
   //todo
}


