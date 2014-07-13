#include "MetaCodeGen.h"
#include <iostream>

int main()
{
   Main* m = MAIN(
      WHILE(new ExprFromInt(3)) (
	 IF(new ExprFromInt(2)) (
	    new IncludeLib("t1")
	 ),
	 ELSE(
	    new IncludeLib("t2"),
	    DECR_FOR(new Variable("i",cInt), new ExprFromInt(10), new ExprFromInt(1)) (
	       new IncludeLib("t3")
	    )
         )
      )
   );

   m->PrintDebug();

   return 0;
}
