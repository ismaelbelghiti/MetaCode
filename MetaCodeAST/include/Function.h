#ifndef FUNCTION_H
#define FUNCTION_H

#include "Variable.h"
#include "Bloc.h"

class FunctionDeclaration : public CodeNode {
public:
   Function(Type* type, std::string name, Variable** arg, int nbArgs,  Bloc* bloc) {
      m_type = type;
      m_name = name;
      m_arg = arg;
      m_nbArgs = nbArgs;
      m_bloc = bloc;
   }

   virtual Type* GetType() { return m_type; }

   virtual std::string GetName() { return m_name; }

   virtual int GetNbArgs() { return m_nbArgs; }

   virtual Variable* GetArg(int iArg) { return m_arg[iArg]; }

   virtual Bloc* GetBloc() { return m_bloc; }

private:
   Type* m_type;
   std::string m_name;
   Variable** m_arg;
   int m_nbArgs;
   Bloc* m_bloc;
};



#endif
