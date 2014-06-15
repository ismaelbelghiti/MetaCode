#include "MetaCodeAST/Main.h"

Main::Main(Bloc* bloc) {}

Bloc* Main::GetBloc() { return m_bloc; }

void Main::PrintDebug(int level) {
   printIndent(level);
   std::cout << "Main " << std::endl;
   GetBloc()->PrintDebug(level);
}
