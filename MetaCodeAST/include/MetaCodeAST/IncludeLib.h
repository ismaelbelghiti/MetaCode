#ifndef LIB_H
#define LIB_H

#include "CodeNode.h"

class IncludeLib : public CodeNode {
public:
   IncludeLib(std::string name);

   virtual std::string GetName(); 

private:
   std::string m_name;
};

#endif
