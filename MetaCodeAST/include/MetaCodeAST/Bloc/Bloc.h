#ifndef BLOC_H
#define BLOC_H

#include "MetaCodeAST/InterfaceType.h"

class Bloc : public IBloc {
public:
   Bloc(IStatement** statement, int nbSatements);

   virtual int GetNbStatements();

   virtual IStatement* GetStatement(int iStatement);

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   IStatement** m_statement;
   int m_nbStatements;
};

#endif
