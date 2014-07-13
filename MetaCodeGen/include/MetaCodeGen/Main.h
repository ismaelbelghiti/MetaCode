#ifndef META_CODE_GEN_MAIN_H
#define META_CODE_GEN_MAIN_H

#include "MetaCodeAST.h"
#include "MetaCodeGen/Utilities.h"

template<typename ...Args>
Main* MAIN(Args... args) {
   return new Main(create_bloc(args...));
}

#endif












