#include "MetaCodeGen.h"
#include <iostream>

int main()
{
   Main* m = MAIN(
      new IncludeLib("t1"),
      ELSE(
	 new IncludeLib("t2")
      )
   );

   m->PrintDebug();

   return 0;
}
