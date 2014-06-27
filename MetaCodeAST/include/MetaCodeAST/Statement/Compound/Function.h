#ifndef FUNCTION_H
#define FUNCTION_H

#include "MetaCodeAST/InterfaceType.h"

class FunctionDeclaration : public IStatement {
public:
   FunctionDeclaration(IVariable* var, IVariable** arg, int nbArgs,  IBloc* bloc);

   virtual IVariable* GetVariable();

   virtual int GetNbArgs();

   virtual IVariable* GetArg(int iArg);

   virtual IBloc* GetBloc();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   IVariable *m_var;
   IVariable** m_arg;
   int m_nbArgs;
   IBloc *m_bloc;
};

#endif
