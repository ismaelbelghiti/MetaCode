#ifndef FUNCTION_H
#define FUNCTION_H

#include "Variable.h"
#include "Bloc.h"

class Function : public CodeNode {
public:
   Function(Type* type, std::string name) {
      m_type = type;
      m_name = name; 
   }

  virtual Type* GetType() { return m_type; }

  virtual std::string GetName() { return m_name; }

  virtual void PrintDebug(int level = 0) {
     printIndent(level);
     std::cout << GetName();
  }

private:
  Type* m_type;
  std::string m_name;
};

class Signature : public CodeNode {
public:
   Signature(Variable** arg, int nbArgs) {
      m_arg = arg;
      m_nbArgs = nbArgs;
   }

   virtual int GetNbArgs() { return m_nbArgs; }

   virtual Variable* GetArg(int iArg) { return m_arg[iArg]; }
   
   virtual void PrintDebug(int level = 0)
   {
      printIndent(level);
      for(int iArg = 0; iArg < GetNbArgs(); iArg++) {
	 GetArg(iArg)->GetType()->PrintDebug();
	 std::cout << " ";
	 GetArg(iArg)->PrintDebug();
	 if(iArg < GetNbArgs()-1)
	    std::cout << ",";
      }
   }

private:
   Variable** m_arg;
   int m_nbArgs;
};

class FunctionDeclaration : public CodeNode {
public:
   FunctionDeclaration(Function* func, Signature* signature,  Bloc* bloc) {
      m_func = func;
      m_signature = signature;
      m_bloc = bloc;
   }

   virtual Function* GetFunction() { return m_func; }

   virtual Signature* GetSignature() { return m_signature; }

   virtual Bloc* GetBloc() { return m_bloc; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << "Function ";
      GetFunction()->PrintDebug();
      std::cout << " (";
      GetSignature()->PrintDebug();
      std::cout << ")";
   }

private:
   Function *m_func;
   Signature *m_signature;
   Bloc *m_bloc;
};

//class FunctionCall

#endif
