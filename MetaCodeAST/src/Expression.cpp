#include "MetaCodeAST/Expression/Expression.h"
#include "MetaCodeAST/AbstractVisitor.h"
#include "MetaCodeAST/Expression/AbstractExpressionTransformer.h"
#include "MetaCodeAST/Utilities/indentation_space.h"

ExprFromInt::ExprFromInt(int value) {
   m_value = value;
}

int ExprFromInt::GetValue() {
   return m_value;
}

IType* ExprFromInt::GetType() {
   return cInt;
}

void ExprFromInt::PrintDebug(int level) {
   printIndent(level);
   std::cout << GetValue();
}

void ExprFromInt::Visit(AbstractVisitor* visitor) {
   visitor->VisitExprFromInt(this);
}

IExpression* ExprFromInt::TransformExpression(AbstractExpressionTransformer* transformer) {
   return transformer->TransformExprFromInt(this);
}

ExprFromBool::ExprFromBool(bool value) {
   m_value = value;
}

bool ExprFromBool::GetValue() {
   return m_value;
}

IType* ExprFromBool::GetType() {
   return cBool;
}

void ExprFromBool::PrintDebug(int level) {
   printIndent(level);
   if(m_value)
      std::cout << "True";
   else
      std::cout << "False";
}

void ExprFromBool::Visit(AbstractVisitor* visitor) {
   visitor->VisitExprFromBool(this);
}

IExpression* ExprFromBool::TransformExpression(AbstractExpressionTransformer* transformer) {
   return transformer->TransformExprFromBool(this);
}


ExprFromVariable::ExprFromVariable(IVariable* variable) {
   m_variable = variable;
}

IVariable* ExprFromVariable::GetVariable() {
   return m_variable;
}

IType* ExprFromVariable::GetType() {
   return GetVariable()->GetType();
}

void ExprFromVariable::PrintDebug(int level) {
   printIndent(level);
   GetVariable()->PrintDebug();
}

void ExprFromVariable::Visit(AbstractVisitor* visitor) {
   visitor->VisitExprFromVariable(this);
}

IExpression* ExprFromVariable::TransformExpression(AbstractExpressionTransformer* transformer) {
   return transformer->TransformExprFromVariable(this);
}

/////////////////////
// Unary Operation //
/////////////////////


UnaryOperation::UnaryOperation(IExpression* expr) {
   m_expr = expr;
}

IExpression* UnaryOperation::GetExpression() {
   return m_expr;
}


ParenthesizedExpr::ParenthesizedExpr(IExpression* expr) : UnaryOperation(expr) { }

IType* ParenthesizedExpr::GetType() {
   return GetExpression()->GetType();
}

void ParenthesizedExpr::PrintDebug(int level) {
   printIndent(level);
   std::cout << "(";
   GetExpression()->PrintDebug();
   std::cout << ")";
}

void ParenthesizedExpr::Visit(AbstractVisitor* visitor) {
   visitor->VisitParenthesizedExpr(this);
}

IExpression* ParenthesizedExpr::TransformExpression(AbstractExpressionTransformer* transformer) {
      return transformer->TransformParenthesizedExpr(this);
}

Minus::Minus(IExpression* expr) : UnaryOperation(expr) {}

IType* Minus::GetType() {
   return GetExpression()->GetType();
}

void Minus::PrintDebug(int level) {
   printIndent(level);
   std::cout << "-";
   GetExpression()->PrintDebug();
}

void Minus::Visit(AbstractVisitor* visitor) {
   visitor->VisitMinus(this);
}
   
IExpression* Minus::TransformExpression(AbstractExpressionTransformer* transformer) {
   return transformer->TransformMinus(this);
}


Negation::Negation(IExpression* expr) : UnaryOperation(expr) {}

IType* Negation::GetType() {
   return cBool;
}

void Negation::PrintDebug(int level) {
   printIndent(level);
   std::cout << "!";
   GetExpression()->PrintDebug();
}

void Negation::Visit(AbstractVisitor* visitor) {
   visitor->VisitNegation(this);
}
  
IExpression* Negation::TransformExpression(AbstractExpressionTransformer* transformer) {
   return transformer->TransformNegation(this);
}

//////////////////////
// Binary Operation //
//////////////////////

BinaryOperation::BinaryOperation(IExpression* leftExpr, IExpression* rightExpr) {
   m_leftExpr = leftExpr;
   m_rightExpr = rightExpr;
}

IExpression* BinaryOperation::GetLeftExpr() {
   return m_leftExpr;
}

IExpression* BinaryOperation::GetRightExpr() {
   return m_rightExpr;
}

void BinaryOperation::PrintDebug(int level) {
   printIndent(level);
   GetLeftExpr()->PrintDebug();
   std::cout << " " << GetSymbol() << " ";
   GetRightExpr()->PrintDebug();
}
  
Addition::Addition(IExpression* leftExpr, IExpression* rightExpr) 
   : BinaryOperation(leftExpr,rightExpr) {}
   
IType* Addition::GetType() {
   return GetLeftExpr()->GetType();
}

std::string Addition::GetSymbol() {
   return "+";
}

void Addition::Visit(AbstractVisitor* visitor) {
   visitor->VisitAddition(this);
}


IExpression* Addition::TransformExpression(AbstractExpressionTransformer* transformer) {
   return transformer->TransformAddition(this);
}


Multiplication::Multiplication(IExpression* leftExpr, IExpression* rightExpr) 
   : BinaryOperation(leftExpr,rightExpr) {}

IType* Multiplication::GetType() {
   return GetLeftExpr()->GetType();
}

std::string Multiplication::GetSymbol() {
   return "*";
}

void Multiplication::Visit(AbstractVisitor* visitor) {
   visitor->VisitMultiplication(this);
}

IExpression* Multiplication::TransformExpression(AbstractExpressionTransformer* transformer) {
   return transformer->TransformMultiplication(this);
}

Substraction::Substraction(IExpression* leftExpr, IExpression* rightExpr) 
   : BinaryOperation(leftExpr,rightExpr) {}

IType* Substraction::GetType() {
   return GetLeftExpr()->GetType();
}

std::string Substraction::GetSymbol() {
   return "-";
}

void Substraction::Visit(AbstractVisitor* visitor) {
   visitor->VisitSubstraction(this);
}

IExpression* Substraction::TransformExpression(AbstractExpressionTransformer* transformer) {
   return transformer->TransformSubstraction(this);
}

EuclidianDivision::EuclidianDivision(IExpression* leftExpr, IExpression* rightExpr) 
   : BinaryOperation(leftExpr,rightExpr) {}

IType* EuclidianDivision::GetType() {
   return cInt;
}

std::string EuclidianDivision::GetSymbol() {
   return "/";
}

void EuclidianDivision::Visit(AbstractVisitor* visitor) {
   visitor->VisitEuclidianDivision(this);
}


IExpression* EuclidianDivision::TransformExpression(AbstractExpressionTransformer* transformer) {
   return transformer->TransformEuclidianDivision(this);
}

Modulus::Modulus(IExpression* leftExpr, IExpression* rightExpr) 
   : BinaryOperation(leftExpr,rightExpr) {}

IType* Modulus::GetType() {
   return cInt;
}

std::string Modulus::GetSymbol() {
   return "%";
}

void Modulus::Visit(AbstractVisitor* visitor) {
   visitor->VisitModulus(this);
}

IExpression* Modulus::TransformExpression(AbstractExpressionTransformer* transformer) {
   return transformer->TransformModulus(this);
}


And::And(IExpression* leftExpr, IExpression* rightExpr) 
   : BinaryOperation(leftExpr,rightExpr) {}

IType* And::GetType() { return cBool; }

std::string And::GetSymbol() { return "&&"; }

void And::Visit(AbstractVisitor* visitor) {
   visitor->VisitAnd(this);
}

IExpression* And::TransformExpression(AbstractExpressionTransformer* transformer) {
   return transformer->TransformAnd(this);
}

Or::Or(IExpression* leftExpr, IExpression* rightExpr) 
   : BinaryOperation(leftExpr,rightExpr) {}

IType* Or::GetType() { return cBool; }

std::string Or::GetSymbol() { return "||"; }

void Or::Visit(AbstractVisitor* visitor) {
   visitor->VisitOr(this);
}

IExpression* Or::TransformExpression(AbstractExpressionTransformer* transformer) {
   return transformer->TransformOr(this);
}
