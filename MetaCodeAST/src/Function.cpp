#include "MetaCodeAST/Function.h"
#include "MetaCodeAST/AbstractVisitor.h"

Function::Function(Type* type, std::string name) {
   m_type = type;
   m_name = name; 
}

Type* Function::GetType() { 
   return m_type; 
}

std::string Function::GetName() { 
   return m_name; 
}

void Function::PrintDebug(int level) {
   printIndent(level);
   std::cout << GetName();
}

void Function::Visit(AbstractVisitor* visitor) {
   visitor->VisitFunction(this);
}

Signature::Signature(Variable** arg, int nbArgs) {
   m_arg = arg;
   m_nbArgs = nbArgs;
}

int Signature::GetNbArgs() { 
   return m_nbArgs; 
}

Variable* Signature::GetArg(int iArg) { 
   return m_arg[iArg]; 
}
   
void Signature::PrintDebug(int level) {
   printIndent(level);
   for(int iArg = 0; iArg < GetNbArgs(); iArg++) {
      GetArg(iArg)->GetType()->PrintDebug();
      std::cout << " ";
      GetArg(iArg)->PrintDebug();
      if(iArg < GetNbArgs()-1)
	 std::cout << ",";
   }
}

void Signature::Visit(AbstractVisitor* visitor) {
   visitor->VisitSignature(this);
}


FunctionDeclaration::FunctionDeclaration(Function* func, Signature* signature,  Bloc* bloc) {
   m_func = func;
   m_signature = signature;
   m_bloc = bloc;
}

Function* FunctionDeclaration::GetFunction() { 
   return m_func; 
}

Signature* FunctionDeclaration::GetSignature() { 
   return m_signature; 
}

Bloc* FunctionDeclaration::GetBloc() { 
   return m_bloc; 
}

void FunctionDeclaration::PrintDebug(int level) {
   printIndent(level);
   std::cout << "Function ";
   GetFunction()->PrintDebug();
   std::cout << " (";
   GetSignature()->PrintDebug();
   std::cout << ")";
}

void FunctionDeclaration::Visit(AbstractVisitor* visitor) {
   visitor->VisitFunctionDeclaration(this);
}


