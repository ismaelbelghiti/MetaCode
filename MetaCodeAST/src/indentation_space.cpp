#include "MetaCodeAST.h"

void printIndent(int level)
{
   for(int iLevel = 0; iLevel < level; iLevel++)
      for(int iSpace = 0; iSpace < TAB_SIZE; iSpace++)
	 std::cout << " ";
}
