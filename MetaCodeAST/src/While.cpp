#include "MetaCodeAST.h"

While::While(IExpression *condExpr, IBloc* bloc) {
   m_condExpr = condExpr;
   m_bloc = bloc;
}

IExpression* While::GetCondition() { return m_condExpr; }

IBloc* While::GetBloc() { return m_bloc; }

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

IStatement* While::TransformStatement(AbstractStatementTransformer* transformer) {
   return transformer->TransformWhile(this);
}
