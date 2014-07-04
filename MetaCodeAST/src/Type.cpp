#include "MetaCodeAST.h"

Type::Type(std::string typeName) {
   m_typeName = typeName;
}

std::string Type::GetName() {
   return m_typeName;
}

bool Type::isEqual(IType* otherType) {
   return otherType->GetName() == GetName();
}

void Type::PrintDebug(int level) {
   printIndent(level);
   std::cout << GetName();
}

void Type::Visit(AbstractVisitor* visitor) {
   visitor->VisitType(this);
}

IType* Type::TransformType(AbstractTypeTransformer* transformer) {
   transformer->TransformType(this);
}

Type* cInt = new Type("int");
Type* cBool = new Type("bool");
Type* cVoid = new Type("void");



