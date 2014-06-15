#ifndef MAIN_H
#define MAIN_H

#include "CodeNode.h"
#include "Bloc.h"

class Main : public CodeNode {
public:
   Main(Bloc* bloc);

   virtual Bloc* GetBloc();

   virtual void PrintDebug(int level = 0);

private:
   Bloc* m_bloc;
};

#endif
