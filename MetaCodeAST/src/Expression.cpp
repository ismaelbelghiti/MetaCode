#include "MetaCodeAST/Expression.h"
#include "MetaCodeAST/AbstractVisitor.h"

ExprFromInt::ExprFromInt(int value) {
   m_value = value;
}

int ExprFromInt::GetValue() {
   return m_value;
}

Type* ExprFromInt::GetType() {
   return cInt;
}

void ExprFromInt::PrintDebug(int level) {
   printIndent(level);
   std::cout << GetValue();
}

void ExprFromInt::Visit(AbstractVisitor* visitor) {
   visitor->VisitExprFromInt(this);
}


ExprFromBool::ExprFromBool(bool value) {
   m_value = value;
}

bool ExprFromBool::GetValue() {
   return m_value;
}

Type* ExprFromBool::GetType() {
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


ExprFromVariable::ExprFromVariable(Variable* variable) {
   m_variable = variable;
}

Variable* ExprFromVariable::GetVariable() {
   return m_variable;
}

Type* ExprFromVariable::GetType() {
   return GetVariable()->GetType();
}

void ExprFromVariable::PrintDebug(int level) {
   printIndent(level);
   GetVariable()->PrintDebug();
}

void ExprFromVariable::Visit(AbstractVisitor* visitor) {
   visitor->VisitExprFromVariable(this);
}

/////////////////////
// Unary Operation //
/////////////////////


UnaryOperation::UnaryOperation(Expression* expr) {
   m_expr = expr;
}

Expression* UnaryOperation::GetExpression() {
   return m_expr;
}


ParenthesizedExpr::ParenthesizedExpr(Expression* expr) : UnaryOperation(expr) { }

Type* ParenthesizedExpr::GetType() {
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


Minus::Minus(Expression* expr) : UnaryOperation(expr) {}

Type* Minus::GetType() {
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
   

Negation::Negation(Expression* expr) : UnaryOperation(expr) {}

Type* Negation::GetType() {
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
  

//////////////////////
// Binary Operation //
//////////////////////

BinaryOperation::BinaryOperation(Expression* leftExpr, Expression* rightExpr) {
   m_leftExpr = leftExpr;
   m_rightExpr = rightExpr;
}

Expression* BinaryOperation::GetLeftExpr() {
   return m_leftExpr;
}

Expression* BinaryOperation::GetRightExpr() {
   return m_rightExpr;
}

void BinaryOperation::PrintDebug(int level) {
   printIndent(level);
   GetLeftExpr()->PrintDebug();
   std::cout << " " << GetSymbol() << " ";
   GetRightExpr()->PrintDebug();
}

void BinaryOperation::Visit(AbstractVisitor* visitor) {
   visitor->VisitBinaryOperation(this);
}
  

Addition::Addition(Expression* leftExpr, Expression* rightExpr) 
   : BinaryOperation(leftExpr,rightExpr) {}
   
Type* Addition::GetType() {
   return GetLeftExpr()->GetType();
}

std::string Addition::GetSymbol() {
   return "+";
}


Multiplication::Multiplication(Expression* leftExpr, Expression* rightExpr) 
   : BinaryOperation(leftExpr,rightExpr) {}

Type* Multiplication::GetType() {
   return GetLeftExpr()->GetType();
}

std::string Multiplication::GetSymbol() {
   return "*";
}


Substraction::Substraction(Expression* leftExpr, Expression* rightExpr) 
   : BinaryOperation(leftExpr,rightExpr) {}

Type* Substraction::GetType() {
   return GetLeftExpr()->GetType();
}

std::string Substraction::GetSymbol() {
   return "-";
}


EuclidianDivision::EuclidianDivision(Expression* leftExpr, Expression* rightExpr) 
   : BinaryOperation(leftExpr,rightExpr) {}

Type* EuclidianDivision::GetType() {
   return cInt;
}

std::string EuclidianDivision::GetSymbol() {
   return "/";
}


Modulus::Modulus(Expression* leftExpr, Expression* rightExpr) 
   : BinaryOperation(leftExpr,rightExpr) {}

Type* Modulus::GetType() {
   return cInt;
}

std::string Modulus::GetSymbol() {
   return "%";
}


And::And(Expression* leftExpr, Expression* rightExpr) 
   : BinaryOperation(leftExpr,rightExpr) {}

Type* And::GetType() { return cBool; }

std::string And::GetSymbol() { return "&&"; }


Or::Or(Expression* leftExpr, Expression* rightExpr) 
   : BinaryOperation(leftExpr,rightExpr) {}

Type* Or::GetType() { return cBool; }

std::string Or::GetSymbol() { return "||"; }

