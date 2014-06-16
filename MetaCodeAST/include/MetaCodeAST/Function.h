#ifndef FUNCTION_H
#define FUNCTION_H

#include "Variable.h"
#include "Bloc.h"

class Function : public CodeNode {
public:
   Function(Type* type, std::string name);

   virtual Type* GetType();

   virtual std::string GetName();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
  Type* m_type;
  std::string m_name;
};

class Signature : public CodeNode {
public:
   Signature(Variable** arg, int nbArgs);

   virtual int GetNbArgs();

   virtual Variable* GetArg(int iArg);
   
   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   Variable** m_arg;
   int m_nbArgs;
};

class FunctionDeclaration : public CodeNode {
public:
   FunctionDeclaration(Function* func, Signature* signature,  Bloc* bloc);

   virtual Function* GetFunction();

   virtual Signature* GetSignature();

   virtual Bloc* GetBloc();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   Function *m_func;
   Signature *m_signature;
   Bloc *m_bloc;
};

//class FunctionCall

#endif
