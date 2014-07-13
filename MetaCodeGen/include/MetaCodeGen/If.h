#ifndef META_CODE_GEN_IF_H
#define META_CODE_GEN_IF_H

#include "MetaCodeAST.h"
#include "MetaCodeGen/Utilities.h"

class IfConstructor {
public:
   IfConstructor(IExpression* cond) {
      m_cond = cond;
   }
   
   template<typename ...Args>
   If* operator() (Args... args) {
      return new If(m_cond,create_bloc(args...));
   }

private:
   IExpression* m_cond;
};

IfConstructor IF(IExpression* cond)  {
   return IfConstructor(cond);
}

#endif




