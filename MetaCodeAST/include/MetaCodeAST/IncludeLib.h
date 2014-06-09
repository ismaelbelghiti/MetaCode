#ifndef LIB_H
#define LIB_H

#include "CodeNode.h"

class IncludeLib : public CodeNode {
public:
   IncludeLib(std::string name) { m_name = name; }

   std::string GetName() { return m_name; }

private:
   std::string m_name;
};

#endif
