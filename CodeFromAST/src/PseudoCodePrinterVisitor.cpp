#include "CodeFromAST/PseudoCodePrinterVisitor.h"

void PseudoCodePrinterVisitor::VisitExprFromInt(ExprFromInt* exprFromInt) {
   std::cout << exprFromInt->GetValue();
}

void PseudoCodePrinterVisitor::VisitExprFromBool(ExprFromBool* exprFromBool) {
   if(exprFromBool->GetValue())
      std::cout << "Vrai";
   else
      std::cout << "Faux";
}

void PseudoCodePrinterVisitor::VisitExprFromVariable(ExprFromVariable* exprFromVariable) {
   std::cout << exprFromVariable->GetVariable()->GetName();
}

void PseudoCodePrinterVisitor::VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) {
   std::cout << "(";
   parenthesizedExpr->GetExpression()->Visit(this);
   std::cout << ")";
}

void PseudoCodePrinterVisitor::VisitMinus(Minus* minus) {
   std::cout << "-";
   minus->GetExpression()->Visit(this);
}

void PseudoCodePrinterVisitor::VisitNegation(Negation* negation) {
   std::cout << "!";
   negation->GetExpression()->Visit(this);
}

void PseudoCodePrinterVisitor::VisitBinaryOperation(BinaryOperation* binaryOp) {
   binaryOp->GetLeftExpr()->Visit(this);
   std::cout << " " << binaryOp->GetSymbol() << " ";
   binaryOp->GetRightExpr()->Visit(this);
}

void PseudoCodePrinterVisitor::VisitBloc(Bloc* bloc) {
   for(int iCodeNode = 0; iCodeNode < bloc->GetNbCodeNodes(); iCodeNode++) {
      bloc->GetCodeNode(iCodeNode)->Visit(this);
      std::cout << std::endl;
   }
}

void PseudoCodePrinterVisitor::VisitIf(If * ifNode) {
   std::cout << "Si ";
   ifNode->GetCondition()->Visit(this);
   std::cout << std::endl;
}

void PseudoCodePrinterVisitor::VisitElseIf(ElseIf * elseIfNode)  {
   std::cout << "Sinon si ";
   elseIfNode->GetCondition()->Visit(this);
   std::cout << std::endl;
}

void PseudoCodePrinterVisitor::VisitElse(Else * elseNode) {
   std::cout << "Sinon " << std::endl;
   elseNode->GetBloc()->Visit(this);
}

void PseudoCodePrinterVisitor::VisitDeclaration(Declaration * decl) {
   decl->GetVariable()->GetType()->Visit(this);
   std::cout << " ";
   decl->GetVariable()->Visit(this);
   std::cout << " = ";
   decl->GetExpression()->Visit(this);
   std::cout << std::endl;
}

void PseudoCodePrinterVisitor::VisitRange(Range * range) {
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

void PseudoCodePrinterVisitor::VisitFor(For * forNode) {
   std::cout << "Pour ";
   forNode->GetVariable()->Visit(this);
   forNode->GetRange()->Visit(this);
   std::cout << std::endl;
   forNode->GetBloc()->Visit(this);
}

void PseudoCodePrinterVisitor::VisitFunction(Function * function) {
   //todo
}

void PseudoCodePrinterVisitor::VisitSignature(Signature * signature) {
   //todo
}

void PseudoCodePrinterVisitor::VisitFunctionDeclaration(FunctionDeclaration * functionDecl) {
   //todo
}

void PseudoCodePrinterVisitor::VisitIncludeLib(IncludeLib* includeLib) {
   //todo
}

void PseudoCodePrinterVisitor::VisitPrintableFromString(PrintableFromString * printStr) {
   std::cout << "\""  << printStr->GetString() << "\"";
}

void PseudoCodePrinterVisitor::VisitPrintableFromExpression(PrintableFromExpression * printExpr) {
   printExpr->GetExpression()->Visit(this);
}

void PseudoCodePrinterVisitor::VisitPrint(Print * print) {
   std::cout << "Affiche ";
   for(int iPrintable = 0; iPrintable < print->GetNbPrintables(); iPrintable++) {
      print->GetPrintable(iPrintable)->Visit(this);
      std::cout << " ";
   }	 
   if(print->WithEndline())
      std::cout << " et passer a la ligne";
   std::cout << std::endl;
}

void PseudoCodePrinterVisitor::VisitType(Type * type) {
   std::cout << type->GetName();
}

void PseudoCodePrinterVisitor::VisitVariable(Variable* variable)  {
   std::cout << variable->GetName();
}

void PseudoCodePrinterVisitor::VisitWhile(While* whileNode) {
   std::cout << "Tant que ";
   whileNode->GetCondition()->Visit(this);
   std::cout << std::endl;
   whileNode->GetBloc()->Visit(this);
}
   
void PseudoCodePrinterVisitor::VisitMain(Main* mainNode) {
   //todo
}


