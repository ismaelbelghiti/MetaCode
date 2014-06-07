#ifndef VARIABLE_H
#define VARIABLE_H

#include "CodeNode.h"
#include <string>

class Variable : public CodeNode {
public:
   Variable(std::string name) { m_name = name; }

   virtual std::string GetName() { return m_name; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << GetName();
   }

private:
   std::string m_name;
};

#endif
