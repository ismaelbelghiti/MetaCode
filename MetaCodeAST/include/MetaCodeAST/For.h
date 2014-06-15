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
   Range(bool isIncreasing, Expression* start, Expression* excludedEnd, Expression* includedEnd = 0);

   virtual bool IsIncreasing();

   virtual Expression* GetStart();

   virtual Expression* GetExcludedEnd();

   virtual bool IncludedEndIsDefined();

   virtual Expression* GetIncludedEnd();

   virtual void PrintDebug(int level = 0);

private:
   bool m_isIncreasing;
   Expression *m_start, *m_excludedEnd, *m_includedEnd;
};

class For : public CodeNode {
public:
   For(Variable* variable, Range* range, Bloc* bloc);
      
   virtual Variable* GetVariable();

   virtual Range* GetRange();

   virtual Bloc* GetBloc();

   virtual void PrintDebug(int level = 0);

private:
   Variable* m_variable;
   Range* m_range;
   Bloc* m_bloc;
};

#endif

