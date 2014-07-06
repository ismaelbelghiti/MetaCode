#include "CodeFromAST/CLikePrinterVisitor.h"

CLikePrinterVisitor::CLikePrinterVisitor(CLikePrinterVisitor::Language lang, IStatement* root) {
   m_info = new InfosGatherVisitor(root);
}

void CLikePrinterVisitor::VisitExprFromInt(ExprFromInt* exprFromInt) {
   std::cout << exprFromInt->GetValue();
}

void CLikePrinterVisitor::VisitExprFromBool(ExprFromBool* exprFromBool) {
   if(exprFromBool->GetValue())
      std::cout << "Vrai";
   else
      std::cout << "Faux";
}

void CLikePrinterVisitor::VisitExprFromVariable(ExprFromVariable* exprFromVariable) {
   std::cout << exprFromVariable->GetVariable()->GetName();
}

void CLikePrinterVisitor::VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) {
   std::cout << "(";
   parenthesizedExpr->GetExpression()->Visit(this);
   std::cout << ")";
}

void CLikePrinterVisitor::VisitMinus(Minus* minus) {
   std::cout << "-";
   minus->GetExpression()->Visit(this);
}

void CLikePrinterVisitor::VisitNegation(Negation* negation) {
   std::cout << "!";
   negation->GetExpression()->Visit(this);
}

void CLikePrinterVisitor::VisitAddition(Addition * addition) {
   VisitBinaryOperation(addition, " + ");
}

void CLikePrinterVisitor::VisitMultiplication(Multiplication * multiplication) {
   VisitBinaryOperation(multiplication, " * ");
}

void CLikePrinterVisitor::VisitSubstraction(Substraction * substraction) {
   VisitBinaryOperation(substraction, " - ");
}

void CLikePrinterVisitor::VisitEuclidianDivision(EuclidianDivision * euclDiv) {
   VisitBinaryOperation(euclDiv, " / ");
}

void CLikePrinterVisitor::VisitModulus(Modulus * modulus) {
   VisitBinaryOperation(modulus, " modulo ");
}

void CLikePrinterVisitor::VisitAnd(And * andNode) {
   VisitBinaryOperation(andNode, " et ");
}

void CLikePrinterVisitor::VisitOr(Or * orNode) {
   VisitBinaryOperation(orNode, " ou ");
}

void CLikePrinterVisitor::VisitIf(If * ifNode) {
   printIndent(GetIndentLevel(ifNode));
   std::cout << "Si ";
   ifNode->GetCondition()->Visit(this);
   std::cout << std::endl;
   VisitBloc(ifNode->GetBloc());
}

void CLikePrinterVisitor::VisitElseIf(ElseIf * elseIfNode)  {
   printIndent(GetIndentLevel(elseIfNode));
   std::cout << "Sinon si ";
   elseIfNode->GetCondition()->Visit(this);
   std::cout << std::endl;
   VisitBloc(elseIfNode->GetBloc());
}

void CLikePrinterVisitor::VisitElse(Else * elseNode) {
   printIndent(GetIndentLevel(elseNode));
   std::cout << "Sinon " << std::endl;
   VisitBloc(elseNode->GetBloc());
}

void CLikePrinterVisitor::VisitDeclaration(Declaration * decl) {
   printIndent(GetIndentLevel(decl));
   decl->GetVariable()->GetType()->Visit(this);
   std::cout << " ";
   decl->GetVariable()->Visit(this);
   std::cout << " = ";
   decl->GetExpression()->Visit(this);
   std::cout << std::endl;
}

void CLikePrinterVisitor::VisitFor(For * forNode) {
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

void CLikePrinterVisitor::VisitFunctionDeclaration(FunctionDeclaration * functionDecl) {
   //todo
}

void CLikePrinterVisitor::VisitIncludeLib(IncludeLib* includeLib) {
   printIndent(GetIndentLevel(includeLib));
   std::cout << includeLib->GetName() << std::endl;   
}

void CLikePrinterVisitor::VisitPrint(Print * print) {
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

void CLikePrinterVisitor::VisitType(Type * type) {
   std::cout << type->GetName();
}

void CLikePrinterVisitor::VisitVariable(Variable* variable)  {
   std::cout << variable->GetName();
}

void CLikePrinterVisitor::VisitWhile(While* whileNode) {
   printIndent(GetIndentLevel(whileNode));
   std::cout << "Tant que ";
   whileNode->GetCondition()->Visit(this);
   std::cout << std::endl;
   VisitBloc(whileNode->GetBloc());
}
   
void CLikePrinterVisitor::VisitMain(Main* mainNode) {
   printIndent(GetIndentLevel(mainNode));
   std::cout << "Main " << std::endl;
   VisitBloc(mainNode->GetBloc());
}

int CLikePrinterVisitor::GetIndentLevel(IStatement* statement) {
   return m_info->GetIndentLevel(statement);
}

//private:

void CLikePrinterVisitor::VisitBloc(IBloc* bloc) {
   for(int iStatement = 0; iStatement < bloc->GetNbStatements(); iStatement++) {
      bloc->GetStatement(iStatement)->Visit(this);
   }
}

void CLikePrinterVisitor::VisitBinaryOperation(BinaryOperation* binOp, 
						    std::string opString) {
   binOp->GetLeftExpr()->Visit(this);
   std::cout << opString;
   binOp->GetRightExpr()->Visit(this);
}

