#ifndef BLOC_H
#define BLOC_H

#include "CodeNode.h"

class Bloc : public CodeNode {
public:
   Bloc(CodeNode** codeNode, int nbCodeNodes);

   virtual int GetNbCodeNodes();

   virtual CodeNode* GetCodeNode(int iCodeNode);

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   CodeNode** m_codeNode;
   int m_nbCodeNodes;
};

#endif
