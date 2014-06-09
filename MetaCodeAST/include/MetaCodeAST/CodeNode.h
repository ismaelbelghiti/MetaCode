#ifndef CODE_NODE_H
#define CODE_NODE_H

#include "indentation_space.h"

class CodeNode {
public:
   virtual void PrintDebug(int level = 0) = 0;
};

#endif
