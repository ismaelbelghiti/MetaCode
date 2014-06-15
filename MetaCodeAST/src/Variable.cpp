#include "MetaCodeAST/Variable.h"

Type::Type(std::string typeName) { 
   m_typeName = typeName; 
}

std::string Type::GetName() { 
   return m_typeName; 
}

bool Type::isEqual(Type* otherType) { 
   return GetName() == otherType->GetName(); 
}

void Type::PrintDebug(int level) {
   printIndent(level);
   std::cout << GetName();
}


Type * cInt = new Type("int");
Type * cBool = new Type("bool");
Type * cVoid = new Type("void");


Variable::Variable(std::string name, Type* type) { 
   m_name = name;
   m_type = type;
}

std::string Variable::GetName() { return m_name; }

Type* Variable::GetType() { return m_type; }

void Variable::PrintDebug(int level) {
   printIndent(level);
   std::cout << GetName();
}

