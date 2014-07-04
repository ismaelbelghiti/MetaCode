#include "MetaCodeAST.h"


Variable::Variable(std::string name, IType* type) { 
   m_name = name;
   m_type = type;
}

std::string Variable::GetName() { return m_name; }

IType* Variable::GetType() { return m_type; }

void Variable::PrintDebug(int level) {
   printIndent(level);
   std::cout << GetName();
}

void Variable::Visit(AbstractVisitor* visitor) {
   visitor->VisitVariable(this);
}

IVariable* Variable::TransformVariable(AbstractVariableTransformer* transformer) {
   return transformer->TransformVariable(this);
}


