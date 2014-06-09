#ifndef UTILS_H
#define UTILS_H

#include "../MetaCodeAST/MetaCodeAST.h"

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
   CodeNode** codeNode = new CodeNode*[nb];
   fill_array_from_args(codeNode, args...);
   return new Bloc(codeNode, nb);
}

template<typename ...Args>
Print* create_print(bool withEndline, Args... args) {
   int nb = count_args(args...);
   Printable** printable = new Printable*[nb];
   fill_array_from_args(printable, args...);
   return new Print(printable, nb, withEndline);
}

template<typename ...Args>
Signature* create_signature(Args... args) {
   int nb = count_args(args...);
   Variable** variable = new Variable*[nb];
   fill_array_from_args(variable, args...);
   return new Signature(variable, nb);
}


#endif
