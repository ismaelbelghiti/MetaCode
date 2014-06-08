#ifndef VARIABLE_H
#define VARIABLE_H

#include "CodeNode.h"
#include <string>

class Type : public CodeNode {
public:
   Type(std::string typeName) { m_typeName = typeName; }

   virtual std::string GetName() { return m_typeName; }

   virtual bool isEqual(Type* otherType) { return GetName() == otherType->GetName(); }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << GetName();
   }

private:
   std::string m_typeName;
} *cInt = new Type("int"), *cBool = new Type("bool"), *cVoid = new Type("void");

class Variable : public CodeNode {
public:
   Variable(std::string name, Type* type = cInt) { 
      m_name = name;
      m_type = type;
   }

   virtual std::string GetName() { return m_name; }

   virtual Type* GetType() { return m_type; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << GetName();
   }

private:
   std::string m_name;
   Type* m_type;
};

#endif
