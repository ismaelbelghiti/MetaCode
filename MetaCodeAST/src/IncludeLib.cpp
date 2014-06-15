#include "MetaCodeAST/IncludeLib.h"

IncludeLib::IncludeLib(std::string name) { 
   m_name = name; 
}

std::string IncludeLib::GetName() { 
   return m_name; 
}
