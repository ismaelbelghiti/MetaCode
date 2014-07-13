#ifndef META_CODE_GEN_ELSE_H
#define META_CODE_GEN_ELSE_H

#include "MetaCodeAST.h"
#include "MetaCodeGen/Utilities.h"

template<typename ...Args>
Else* ELSE(Args... args) {
   return new Else(create_bloc(args...));
}

#endif




