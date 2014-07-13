#include "MetaCodeAST.h"

Main::Main(IBloc* bloc) { m_bloc = bloc; }

IBloc* Main::GetBloc() { return m_bloc; }

void Main::PrintDebug(int level) {
   printIndent(level);
   std::cout << "Main " << std::endl;
   GetBloc()->PrintDebug(level);
}
   
void Main::Visit(AbstractVisitor* visitor) {
   visitor->VisitMain(this);
}

IStatement* Main::TransformStatement(AbstractStatementTransformer* transformer) {
   return transformer->TransformMain(this);
}
