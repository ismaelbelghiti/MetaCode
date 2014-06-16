#include "MetaCodeAST/While.h"
#include "MetaCodeAST/AbstractVisitor.h"

While::While(Expression *condExpr, Bloc* bloc) {
   m_condExpr = condExpr;
   m_bloc = bloc;
}

Expression* While::GetCondition() { return m_condExpr; }

Bloc* While::GetBloc() { return m_bloc; }

void While::PrintDebug(int level) {
   printIndent(level);
   std::cout << "While ";
   GetCondition()->PrintDebug();
   std::cout << std::endl;
   GetBloc()->PrintDebug(level);
}

void While::Visit(AbstractVisitor* visitor) {
   visitor->VisitWhile(this);
}

