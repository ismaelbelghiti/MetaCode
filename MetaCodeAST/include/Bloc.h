#ifndef BLOC_H
#define BLOC_H

#include "CodeNode.h"

class Bloc : public CodeNode {
public:
   Bloc(CodeNode** codeNode, int nbCodeNodes) {
      m_codeNode = codeNode; 
      m_nbCodeNodes = nbCodeNodes;
   }

   virtual int GetNbCodeNodes() { return m_nbCodeNodes; }

   virtual CodeNode* GetCodeNode(int iCodeNode) { return m_codeNode[iCodeNode];  }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << "{" << std::endl;
      for(int iCodeNode = 0; iCodeNode < GetNbCodeNodes(); iCodeNode++) {
	 GetCodeNode(iCodeNode)->PrintDebug(level+1);
	 std::cout << std::endl;
      }
      std::cout << "}" << std::endl;
   }

private:
   CodeNode** m_codeNode;
   int m_nbCodeNodes;
};

#endif
