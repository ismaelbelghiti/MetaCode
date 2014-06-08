#ifndef MAIN_H
#define MAIN_H

#include "CodeNode.h"

class Main : public CodeNode {
public:
   Main(Bloc* bloc) {}

   virtual Bloc* GetBloc() { return m_bloc; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << "Main " << std::endl;
      GetBloc()->PrintDebug(level);
   }

private:
   Bloc* m_bloc;
};

#endif
