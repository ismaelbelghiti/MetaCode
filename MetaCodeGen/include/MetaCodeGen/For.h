#ifndef META_CODE_GEN_FOR_H
#define META_CODE_GEN_FOR_H

#include "MetaCodeAST.h"
#include "MetaCodeGen/Utilities.h"

class ForConstructor {
public:
   ForConstructor(IVariable* var, bool isIncreasing, IExpression* start,
		  IExpression* excludedEnd, IExpression* includedEnd) {
      m_var = var;
      m_isIncreasing = isIncreasing;
      m_start = start;
      m_excludedEnd = excludedEnd;
      m_includedEnd = includedEnd;
   }
   
   template<typename ...Args>
   For* operator() (Args... args) {
      return new For(m_var, new Range(m_isIncreasing,m_start,m_excludedEnd,m_includedEnd), create_bloc(args...));
   }

private:
   bool m_isIncreasing;
   IVariable* m_var;
   IExpression* m_start;
   IExpression* m_excludedEnd;
   IExpression* m_includedEnd;
};

ForConstructor INCR_FOR(IVariable* variable, IExpression* start, IExpression* excludedEnd)  {
   return ForConstructor(variable, true, start, excludedEnd, 0);
}

ForConstructor DECR_FOR(IVariable* variable, IExpression* start, IExpression* excludedEnd)  {
   return ForConstructor(variable, false, start, excludedEnd, 0);
}

#endif
