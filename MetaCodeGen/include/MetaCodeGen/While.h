#ifndef META_CODE_GEN_WHILE_H
#define META_CODE_GEN_WHILE_H

#include "MetaCodeAST.h"
#include "MetaCodeGen/Utilities.h"

class WhileConstructor {
public:
   WhileConstructor(IExpression* cond) {
      m_cond = cond;
   }
   
   template<typename ...Args>
   While* operator() (Args... args) {
      return new While(m_cond,create_bloc(args...));
   }

private:
   IExpression* m_cond;
};

WhileConstructor WHILE(IExpression* cond)  {
   return WhileConstructor(cond);
}

#endif
