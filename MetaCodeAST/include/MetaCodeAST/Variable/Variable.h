#ifndef VARIABLE_H
#define VARIABLE_H

#include "MetaCodeAST/InterfaceType.h"

class Variable : public IVariable {
public:
   Variable(std::string name, IType* type);

   virtual std::string GetName();

   virtual IType* GetType();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

   virtual IVariable* TransformVariable(AbstractVariableTransformer* transformer);

private:
   std::string m_name;
   IType* m_type;
};

#endif
