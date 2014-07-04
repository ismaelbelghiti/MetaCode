#ifndef LIB_H
#define LIB_H

#include "MetaCodeAST/InterfaceType.h"

class IncludeLib : public IStatement {
public:
   IncludeLib(std::string name);

   virtual std::string GetName(); 

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

   virtual IStatement* TransformStatement(AbstractStatementTransformer* transformer);

private:
   std::string m_name;
};

#endif
