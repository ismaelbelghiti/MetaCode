#include "MetaCodeAST.h"

IncludeLib::IncludeLib(std::string name) { 
   m_name = name; 
}

std::string IncludeLib::GetName() { 
   return m_name; 
}

void IncludeLib::PrintDebug(int level) {
   printIndent(level);
   std::cout << GetName();
}

void IncludeLib::Visit(AbstractVisitor* visitor) {
   visitor->VisitIncludeLib(this);
}

IStatement* IncludeLib::TransformStatement(AbstractStatementTransformer* transformer) {
   return transformer->TransformIncludeLib(this);
}
