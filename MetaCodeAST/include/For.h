#ifndef FOR_H
#define FOR_H

#include "Expression.h"
#include "Bloc.h"

class Range : public CodeNode {
public:
   static const bool INCREASING = true;
   static const bool DECREASING = false;

   // You have to specify an excluded end since Python can only deal with excluded end. 
   // When an includedEnd is specified, it is prefered to the excluded one in languages 
   // like C++/Java/...
   Range(bool isIncreasing, Expression* start, Expression* excludedEnd, Expression* includedEnd = 0) {
      m_isIncreasing = isIncreasing;
      m_start = start;
      m_excludedEnd = excludedEnd;
      m_includedEnd = includedEnd;
   }

   virtual bool IsIncreasing() { return m_isIncreasing; }

   virtual Expression* GetStart() { return m_start;}

   virtual Expression* GetExcludedEnd() { return m_excludedEnd; }

   virtual bool IncludedEndIsDefined() { return m_includedEnd != 0; }

   virtual Expression* GetIncludedEnd() { return m_includedEnd; }

   virtual void PrintDebug(int level = 0) {
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

private:
   bool m_isIncreasing;
   Expression *m_start, *m_excludedEnd, *m_includedEnd;
};

class For : public CodeNode {
public:
   For(Variable* variable, Range* range, Bloc* bloc) {
      m_variable = variable;
      m_range = range;
      m_bloc = bloc;
   }
      
   virtual Variable* GetVariable() { return m_variable; }

   virtual Range* GetRange() { return m_range; }

   virtual Bloc* GetBloc() { return m_bloc; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << "For ";
      GetVariable()->PrintDebug();
      GetRange()->PrintDebug();
      std::cout << std::endl;
      GetBloc()->PrintDebug(level);
   }

private:
   Variable* m_variable;
   Range* m_range;
   Bloc* m_bloc;
};

#endif

