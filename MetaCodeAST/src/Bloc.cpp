#include "MetaCodeAST/Bloc.h"
#include "MetaCodeAST/AbstractVisitor.h"

Bloc::Bloc(CodeNode** codeNode, int nbCodeNodes) {
   m_codeNode = codeNode; 
   m_nbCodeNodes = nbCodeNodes;
}

int Bloc::GetNbCodeNodes() {
   return m_nbCodeNodes; 
}

CodeNode* Bloc::GetCodeNode(int iCodeNode) {
   return m_codeNode[iCodeNode];  
}

void Bloc::PrintDebug(int level) {
   printIndent(level);
   std::cout << "{" << std::endl;
   for(int iCodeNode = 0; iCodeNode < GetNbCodeNodes(); iCodeNode++) {
      GetCodeNode(iCodeNode)->PrintDebug(level+1);
      std::cout << std::endl;
   }
   std::cout << "}" << std::endl;
}

void Bloc::Visit(AbstractVisitor* visitor) {
   visitor->VisitBloc(this);
}
