#include "CodeFromAST/PseudoCodePrinterVisitor.h"

PseudoCodePrinterVisitor::PseudoCodePrinterVisitor(CodeNode* root) {
   m_info = new InfosGatherVisitor(root);
}

void PseudoCodePrinterVisitor::VisitExprFromInt(ExprFromInt* exprFromInt) {
   printIndent(GetIndentLevel(exprFromInt));
   std::cout << exprFromInt->GetValue();
}

void PseudoCodePrinterVisitor::VisitExprFromBool(ExprFromBool* exprFromBool) {
   printIndent(GetIndentLevel(exprFromBool));
   if(exprFromBool->GetValue())
      std::cout << "Vrai";
   else
      std::cout << "Faux";
}

void PseudoCodePrinterVisitor::VisitExprFromVariable(ExprFromVariable* exprFromVariable) {
   printIndent(GetIndentLevel(exprFromVariable));
   std::cout << exprFromVariable->GetVariable()->GetName();
}

void PseudoCodePrinterVisitor::VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) {
   printIndent(GetIndentLevel(parenthesizedExpr));
   std::cout << "(";
   parenthesizedExpr->GetExpression()->Visit(this);
   std::cout << ")";
}

void PseudoCodePrinterVisitor::VisitMinus(Minus* minus) {
   printIndent(GetIndentLevel(minus));
   std::cout << "-";
   minus->GetExpression()->Visit(this);
}

void PseudoCodePrinterVisitor::VisitNegation(Negation* negation) {
   printIndent(GetIndentLevel(negation));
   std::cout << "!";
   negation->GetExpression()->Visit(this);
}

void PseudoCodePrinterVisitor::VisitAddition(Addition * addition) {
   printIndent(GetIndentLevel(addition));
   VisitBinaryOperation(addition, " + ");
}

void PseudoCodePrinterVisitor::VisitMultiplication(Multiplication * multiplication) {
   printIndent(GetIndentLevel(multiplication));
   VisitBinaryOperation(multiplication, " * ");
}

void PseudoCodePrinterVisitor::VisitSubstraction(Substraction * substraction) {
   printIndent(GetIndentLevel(substraction));
   VisitBinaryOperation(substraction, " - ");
}

void PseudoCodePrinterVisitor::VisitEuclidianDivision(EuclidianDivision * euclDiv) {
   printIndent(GetIndentLevel(euclDiv));
   VisitBinaryOperation(euclDiv, " / ");
}

void PseudoCodePrinterVisitor::VisitModulus(Modulus * modulus) {
   printIndent(GetIndentLevel(modulus));
   VisitBinaryOperation(modulus, " modulo ");
}

void PseudoCodePrinterVisitor::VisitAnd(And * andNode) {
   printIndent(GetIndentLevel(andNode));
   VisitBinaryOperation(andNode, " et ");
}

void PseudoCodePrinterVisitor::VisitOr(Or * orNode) {
   printIndent(GetIndentLevel(orNode));
   VisitBinaryOperation(orNode, " ou ");
}

void PseudoCodePrinterVisitor::VisitBloc(Bloc* bloc) {
   for(int iCodeNode = 0; iCodeNode < bloc->GetNbCodeNodes(); iCodeNode++) {
      bloc->GetCodeNode(iCodeNode)->Visit(this);
      std::cout << std::endl;
   }
}

void PseudoCodePrinterVisitor::VisitIf(If * ifNode) {
   printIndent(GetIndentLevel(ifNode));
   std::cout << "Si ";
   ifNode->GetCondition()->Visit(this);
   std::cout << std::endl;
   ifNode->GetBloc()->Visit(this);
}

void PseudoCodePrinterVisitor::VisitElseIf(ElseIf * elseIfNode)  {
   printIndent(GetIndentLevel(elseIfNode));
   std::cout << "Sinon si ";
   elseIfNode->GetCondition()->Visit(this);
   std::cout << std::endl;
   elseIfNode->GetBloc()->Visit(this);
}

void PseudoCodePrinterVisitor::VisitElse(Else * elseNode) {
   printIndent(GetIndentLevel(elseNode));
   std::cout << "Sinon " << std::endl;
   elseNode->GetBloc()->Visit(this);
}

void PseudoCodePrinterVisitor::VisitDeclaration(Declaration * decl) {
   printIndent(GetIndentLevel(decl));
   decl->GetVariable()->GetType()->Visit(this);
   std::cout << " ";
   decl->GetVariable()->Visit(this);
   std::cout << " = ";
   decl->GetExpression()->Visit(this);
   std::cout << std::endl;
}

void PseudoCodePrinterVisitor::VisitRange(Range * range) {
   printIndent(GetIndentLevel(range));
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
   printIndent(GetIndentLevel(forNode));
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
   printIndent(GetIndentLevel(print));
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
   printIndent(GetIndentLevel(variable));
   std::cout << variable->GetName();
}

void PseudoCodePrinterVisitor::VisitWhile(While* whileNode) {
   printIndent(GetIndentLevel(whileNode));
   std::cout << "Tant que ";
   whileNode->GetCondition()->Visit(this);
   std::cout << std::endl;
   whileNode->GetBloc()->Visit(this);
}
   
void PseudoCodePrinterVisitor::VisitMain(Main* mainNode) {
   //todo
}

int PseudoCodePrinterVisitor::GetIndentLevel(CodeNode* codeNode) {
   return m_info->GetIndentLevel(codeNode);
}

//private:
void PseudoCodePrinterVisitor::VisitBinaryOperation(BinaryOperation* binOp, std::string opString) {
   binOp->GetLeftExpr()->Visit(this);
   std::cout << opString;
   binOp->GetRightExpr()->Visit(this);
}

