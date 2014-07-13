#ifndef META_CODE_GEN_COUNT_ARGS_H
#define META_CODE_GEN_COUNT_ARGS_H

#include "MetaCodeAST.h"

int foo();

int count_args() { return 0; }

template<typename T, typename ...Args>
int count_args(T head, Args... args ) { return 1 + count_args(args...); }

template<typename Q, typename T>
void fill_array_from_args(Q** array, T* head) { array[0] = head; }

template<typename Q, typename T, typename ...Args>
void fill_array_from_args(Q** array, T* head, Args... args) {
   array[0] = head;
   fill_array_from_args(array+1, args...);
}

template<typename ...Args>
Bloc* create_bloc(Args... args) {
   int nb = count_args(args...);
   IStatement** statement = new IStatement*[nb];
   fill_array_from_args(statement, args...);
   return new Bloc(statement, nb);
}

template<typename ...Args>
Print* create_print(bool withEndline, Args... args) {
   int nb = count_args(args...);
   IPrintable** printable = new IPrintable*[nb];
   fill_array_from_args(printable, args...);
   return new Print(printable, nb, withEndline);
}

#endif
