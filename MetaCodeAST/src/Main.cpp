#include "MetaCodeAST/Main.h"
#include "MetaCodeAST/AbstractVisitor.h"

Main::Main(Bloc* bloc) {}

Bloc* Main::GetBloc() { return m_bloc; }

void Main::PrintDebug(int level) {
   printIndent(level);
   std::cout << "Main " << std::endl;
   GetBloc()->PrintDebug(level);
}
   
void Main::Visit(AbstractVisitor* visitor) {
   visitor->VisitMain(this);
}
