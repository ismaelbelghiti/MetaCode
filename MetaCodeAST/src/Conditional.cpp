#include "MetaCodeAST.h"

If::If(IExpression *condExpr, IBloc* bloc) {
   m_condExpr = condExpr;
   m_bloc = bloc;
}

IExpression* If::GetCondition() {
   return m_condExpr; 
}

IBloc* If::GetBloc() {
   return m_bloc;
}

void If::PrintDebug(int level) {
   printIndent(level);
   std::cout << "If ";
   GetCondition()->PrintDebug();
   std::cout << std::endl;
   GetBloc()->PrintDebug(level);
}

void If::Visit(AbstractVisitor* visitor) {
   visitor->VisitIf(this);
}

IStatement* If::TransformStatement(AbstractStatementTransformer* transformer) {
   return transformer->TransformIf(this);
}


ElseIf::ElseIf(IExpression *condExpr, IBloc* bloc) {
   m_condExpr = condExpr;
   m_bloc = bloc;
}

IExpression* ElseIf::GetCondition() {
   return m_condExpr;
}

IBloc* ElseIf::GetBloc() {
   return m_bloc;
}

void ElseIf::PrintDebug(int level) {
   printIndent(level);
   std::cout << "ElseIf ";
   GetCondition()->PrintDebug();
   std::cout << std::endl;
   GetBloc()->PrintDebug(level);
}

void ElseIf::Visit(AbstractVisitor* visitor) {
   visitor->VisitElseIf(this);
}

IStatement* ElseIf::TransformStatement(AbstractStatementTransformer* transformer) {
   return transformer->TransformElseIf(this);
}


Else::Else(IBloc* bloc) { m_bloc = bloc; }

IBloc* Else::GetBloc() {
   return m_bloc;
}

void Else::PrintDebug(int level) {
   printIndent(level);
   std::cout << "Else " << std::endl;
   GetBloc()->PrintDebug(level);
}

void Else::Visit(AbstractVisitor* visitor) {
   visitor->VisitElse(this);
}

IStatement* Else::TransformStatement(AbstractStatementTransformer* transformer) {
   return transformer->TransformElse(this);
}
