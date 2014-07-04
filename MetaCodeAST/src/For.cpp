#include "MetaCodeAST/Statement/Compound/For.h"
#include "MetaCodeAST/AbstractVisitor.h"
#include "MetaCodeAST/Statement/AbstractStatementTransformer.h"
#include "MetaCodeAST/Utilities/indentation_space.h"

Range::Range(bool isIncreasing, IExpression* start, IExpression* excludedEnd, IExpression* includedEnd) {
   m_isIncreasing = isIncreasing;
   m_start = start;
   m_excludedEnd = excludedEnd;
   m_includedEnd = includedEnd;
}

bool Range::IsIncreasing() { return m_isIncreasing; }

IExpression* Range::GetStart() { return m_start;}

IExpression* Range::GetExcludedEnd() { return m_excludedEnd; }

bool Range::IncludedEndIsDefined() { return m_includedEnd != 0; }

IExpression* Range::GetIncludedEnd() { return m_includedEnd; }

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

void Range::Visit(AbstractVisitor* visitor) {
   visitor->VisitRange(this);
}



For::For(IVariable* variable, IRange* range, IBloc* bloc) {
   m_variable = variable;
   m_range = range;
   m_bloc = bloc;
}
      
IVariable* For::GetVariable() {
   return m_variable;
}

IRange* For::GetRange() {
   return m_range; 
}

IBloc* For::GetBloc() { 
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

void For::Visit(AbstractVisitor* visitor) {
   visitor->VisitFor(this);
}

IStatement* For::TransformStatement(AbstractStatementTransformer* transformer) {
   return transformer->TransformFor(this);
}
