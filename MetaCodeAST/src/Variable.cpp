#include "MetaCodeAST/Variable/Variable.h"
#include "MetaCodeAST/AbstractVisitor.h"
#include "MetaCodeAST/Utilities/indentation_space.h"

Type::Type(std::string typeName) { 
   m_typeName = typeName; 
}

std::string Type::GetName() { 
   return m_typeName; 
}

bool Type::isEqual(IType* otherType) { 
   return GetName() == otherType->GetName(); 
}

void Type::PrintDebug(int level) {
   printIndent(level);
   std::cout << GetName();
}

void Type::Visit(AbstractVisitor* visitor) {
   visitor->VisitType(this);
}



IType * cInt = new Type("int");
IType * cBool = new Type("bool");
IType * cVoid = new Type("void");


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



