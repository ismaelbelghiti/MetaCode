#ifndef TYPE_H
#define TYPE_H

#include "MetaCodeAST/InterfaceType.h"

class Type : public IType {
public:
   Type(std::string typeName);

   virtual std::string GetName();

   virtual bool isEqual(IType* otherType);

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

   virtual IType* TransformType(AbstractTypeTransformer* transformer); 

private:
   std::string m_typeName;
};

extern Type* cInt;
extern Type* cBool;
extern Type* cVoid;

#endif
