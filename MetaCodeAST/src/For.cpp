#include "MetaCodeAST/For.h"

Range::Range(bool isIncreasing, Expression* start, Expression* excludedEnd, Expression* includedEnd) {
   m_isIncreasing = isIncreasing;
   m_start = start;
   m_excludedEnd = excludedEnd;
   m_includedEnd = includedEnd;
}

bool Range::IsIncreasing() { return m_isIncreasing; }

Expression* Range::GetStart() { return m_start;}

Expression* Range::GetExcludedEnd() { return m_excludedEnd; }

bool Range::IncludedEndIsDefined() { return m_includedEnd != 0; }

Expression* Range::GetIncludedEnd() { return m_includedEnd; }

void Range::PrintDebug(int level) {
   printIndent(level);
   std::cout << " from ";
   GetStart()->PrintDebug();
   if(IsIncreasing())
      std::cout << " up to ";
   else
      std::cout << " down to ";
   if(IncludedEndIsDefined()){
      GetIncludedEnd()->PrintDebug();
      std::cout << " included ";
   }
   else {
      GetExcludedEnd()->PrintDebug();
      std::cout << " excluded ";
   }
	 
}



For::For(Variable* variable, Range* range, Bloc* bloc) {
   m_variable = variable;
   m_range = range;
   m_bloc = bloc;
}
      
Variable* For::GetVariable() {
   return m_variable;
}

Range* For::GetRange() {
   return m_range; 
}

Bloc* For::GetBloc() { 
   return m_bloc; 
}

void For::PrintDebug(int level) {
   printIndent(level);
   std::cout << "For ";
   GetVariable()->PrintDebug();
   GetRange()->PrintDebug();
   std::cout << std::endl;
   GetBloc()->PrintDebug(level);
}

