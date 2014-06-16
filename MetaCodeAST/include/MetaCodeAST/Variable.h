#ifndef VARIABLE_H
#define VARIABLE_H

#include "CodeNode.h"
#include <string>

class Type : public CodeNode {
public:
   Type(std::string typeName);

   virtual std::string GetName();

   virtual bool isEqual(Type* otherType);

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   std::string m_typeName;
};

extern Type *cInt;
extern Type *cBool;
extern Type *cVoid;


class Variable : public CodeNode {
public:
   Variable(std::string name, Type* type = cInt);

   virtual std::string GetName();

   virtual Type* GetType();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   std::string m_name;
   Type* m_type;
};

#endif
