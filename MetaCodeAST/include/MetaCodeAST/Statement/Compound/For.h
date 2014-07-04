#ifndef FOR_H
#define FOR_H

#include "MetaCodeAST/InterfaceType.h"

class Range : public IRange {
public:
   static const bool INCREASING = true;
   static const bool DECREASING = false;

   // You have to specify an excluded end since Python can only deal with excluded end. 
   // When an includedEnd is specified, it is prefered to the excluded one in languages 
   // like C++/Java/...
   Range(bool isIncreasing, IExpression* start, IExpression* excludedEnd, IExpression* includedEnd = 0);

   virtual bool IsIncreasing();

   virtual IExpression* GetStart();

   virtual IExpression* GetExcludedEnd();

   virtual bool IncludedEndIsDefined();

   virtual IExpression* GetIncludedEnd();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   bool m_isIncreasing;
   IExpression *m_start, *m_excludedEnd, *m_includedEnd;
};

class For : public IStatement {
public:
   For(IVariable* variable, IRange* range, IBloc* bloc);
      
   virtual IVariable* GetVariable();

   virtual IRange* GetRange();

   virtual IBloc* GetBloc();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

   virtual IStatement* TransformStatement(AbstractStatementTransformer* transformer);

private:
   IVariable* m_variable;
   IRange* m_range;
   IBloc* m_bloc;
};

#endif

