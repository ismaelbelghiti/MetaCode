#ifndef ABSTRACT_VARIABLE_TRANSFORMER_H
#define ABSTRACT_VARIABLE_TRANSFORMER_H

#include "MetaCodeAST.h"

class AbstractVariableTransformer {
public:
   virtual IVariable* TransformVariable(Variable* var) = 0;
};


#endif
