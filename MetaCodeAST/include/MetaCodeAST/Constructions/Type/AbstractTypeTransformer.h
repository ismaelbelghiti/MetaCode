#ifndef ABSTRACT_TYPE_TRANSFORMER_H
#define ABSTRACT_TYPE_TRANSFORMER_H

#include "MetaCodeAST.h"

class AbstractTypeTransformer {
public:
   virtual IType* TransformType(Type* type) = 0;
};


#endif
