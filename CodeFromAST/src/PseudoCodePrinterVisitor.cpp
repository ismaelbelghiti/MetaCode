#include "CodeFromAST/PseudoCodePrinterVisitor.h"

PseudoCodePrinterVisitor::PseudoCodePrinterVisitor(IStatement* root) {
   m_info = new InfosGatherVisitor(root);
}

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

void PseudoCodePrinterVisitor::VisitAddition(Addition * addition) {
   VisitBinaryOperation(addition, " + ");
}

void PseudoCodePrinterVisitor::VisitMultiplication(Multiplication * multiplication) {
   VisitBinaryOperation(multiplication, " * ");
}

void PseudoCodePrinterVisitor::VisitSubstraction(Substraction * substraction) {
   VisitBinaryOperation(substraction, " - ");
}

void PseudoCodePrinterVisitor::VisitEuclidianDivision(EuclidianDivision * euclDiv) {
   VisitBinaryOperation(euclDiv, " / ");
}

void PseudoCodePrinterVisitor::VisitModulus(Modulus * modulus) {
   VisitBinaryOperation(modulus, " modulo ");
}

void PseudoCodePrinterVisitor::VisitAnd(And * andNode) {
   VisitBinaryOperation(andNode, " et ");
}

void PseudoCodePrinterVisitor::VisitOr(Or * orNode) {
   VisitBinaryOperation(orNode, " ou ");
}

void PseudoCodePrinterVisitor::VisitIf(If * ifNode) {
   printIndent(GetIndentLevel(ifNode));
   std::cout << "Si ";
   ifNode->GetCondition()->Visit(this);
   std::cout << std::endl;
   VisitBloc(ifNode->GetBloc());
}

void PseudoCodePrinterVisitor::VisitElseIf(ElseIf * elseIfNode)  {
   printIndent(GetIndentLevel(elseIfNode));
   std::cout << "Sinon si ";
   elseIfNode->GetCondition()->Visit(this);
   std::cout << std::endl;
   VisitBloc(elseIfNode->GetBloc());
}

void PseudoCodePrinterVisitor::VisitElse(Else * elseNode) {
   printIndent(GetIndentLevel(elseNode));
   std::cout << "Sinon " << std::endl;
   VisitBloc(elseNode->GetBloc());
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

void PseudoCodePrinterVisitor::VisitFor(For * forNode) {
   printIndent(GetIndentLevel(forNode));
   std::cout << "Pour ";
   forNode->GetVariable()->Visit(this);
   std::cout << " partant de ";
   IRange* range = forNode->GetRange();
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
   std::cout << std::endl;
   VisitBloc(forNode->GetBloc());
}

void PseudoCodePrinterVisitor::VisitFunctionDeclaration(FunctionDeclaration * functionDecl) {
   //todo
}

void PseudoCodePrinterVisitor::VisitIncludeLib(IncludeLib* includeLib) {
   printIndent(GetIndentLevel(includeLib));
   std::cout << includeLib->GetName() << std::endl;   
}

void PseudoCodePrinterVisitor::VisitPrint(Print * print) {
   printIndent(GetIndentLevel(print));
   std::cout << "Affiche ";
   for(int iPrintable = 0; iPrintable < print->GetNbPrintables(); iPrintable++) {
      IPrintable* printable = print->GetPrintable(iPrintable);
      if(printable->IsExpression())
	 printable->GetExpression()->Visit(this);
      else
	 std::cout << "\""  << printable->GetString() << "\"";	 
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
   printIndent(GetIndentLevel(whileNode));
   std::cout << "Tant que ";
   whileNode->GetCondition()->Visit(this);
   std::cout << std::endl;
   VisitBloc(whileNode->GetBloc());
}
   
void PseudoCodePrinterVisitor::VisitMain(Main* mainNode) {
   printIndent(GetIndentLevel(mainNode));
   std::cout << "Main " << std::endl;
   VisitBloc(mainNode->GetBloc());
}

int PseudoCodePrinterVisitor::GetIndentLevel(IStatement* statement) {
   return m_info->GetIndentLevel(statement);
}

//private:

void PseudoCodePrinterVisitor::VisitBloc(IBloc* bloc) {
   for(int iStatement = 0; iStatement < bloc->GetNbStatements(); iStatement++) {
      bloc->GetStatement(iStatement)->Visit(this);
    }
}

void PseudoCodePrinterVisitor::VisitBinaryOperation(BinaryOperation* binOp, 
						    std::string opString) {
   binOp->GetLeftExpr()->Visit(this);
   std::cout << opString;
   binOp->GetRightExpr()->Visit(this);
}

