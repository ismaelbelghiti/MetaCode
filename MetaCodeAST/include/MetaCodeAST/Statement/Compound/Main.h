#ifndef MAIN_H
#define MAIN_H

#include "MetaCodeAST/InterfaceType.h"

class Main : public IStatement {
public:
   Main(IBloc* bloc);

   virtual IBloc* GetBloc();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

   virtual IStatement* TransformStatement(AbstractStatementTransformer* transformer);

private:
   IBloc* m_bloc;
};

#endif
