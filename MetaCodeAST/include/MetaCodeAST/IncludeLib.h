#ifndef LIB_H
#define LIB_H

#include "CodeNode.h"

class IncludeLib : public CodeNode {
public:
   IncludeLib(std::string name);

   virtual std::string GetName(); 

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   std::string m_name;
};

#endif
