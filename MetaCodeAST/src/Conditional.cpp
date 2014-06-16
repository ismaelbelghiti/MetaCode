#include "MetaCodeAST/Conditional.h"
#include "MetaCodeAST/AbstractVisitor.h"

If::If(Expression *condExpr, Bloc* bloc) {
   m_condExpr = condExpr;
   m_bloc = bloc;
}

Expression* If::GetCondition() {
   return m_condExpr; 
}

Bloc* If::GetBloc() {
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

ElseIf::ElseIf(Expression *condExpr, Bloc* bloc) {
   m_condExpr = condExpr;
   m_bloc = bloc;
}

Expression* ElseIf::GetCondition() {
   return m_condExpr;
}

Bloc* ElseIf::GetBloc() {
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


Else::Else(Bloc* bloc) {}

Bloc* Else::GetBloc() {
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
