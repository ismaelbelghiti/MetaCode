#ifndef INDENTATION_SPACE_H
#define INDENTATION_SPACE_H

#include <iostream>

const int TAB_SIZE = 3;

void printIndent(int level)
{
   for(int iLevel = 0; iLevel < level; iLevel++)
      for(int iSpace = 0; iSpace < TAB_SIZE; iSpace++)
	 std::cout << " ";
}

#endif
