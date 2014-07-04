#include "MetaCodeAST.h"
   
FunctionDeclaration::FunctionDeclaration(IVariable* var, IVariable** arg, int nbArgs,  IBloc* bloc) {
   m_var = var;
   m_arg = arg;
   m_nbArgs = nbArgs;
   m_bloc = bloc;
}

IVariable* FunctionDeclaration::GetVariable() { 
   return m_var; 
}

int FunctionDeclaration::GetNbArgs() { 
   return m_nbArgs; 
}

IVariable* FunctionDeclaration::GetArg(int iArg) { 
   return m_arg[iArg]; 
}

IBloc* FunctionDeclaration::GetBloc() { 
   return m_bloc; 
}

void FunctionDeclaration::PrintDebug(int level) {
   printIndent(level);
   std::cout << "Function ";
   GetVariable()->PrintDebug();
   std::cout << " (";
   for(int iArg = 0; iArg < GetNbArgs(); iArg++) {
      GetArg(iArg)->GetType()->PrintDebug();
      std::cout << " ";
      GetArg(iArg)->PrintDebug();
      if(iArg < GetNbArgs()-1)
	 std::cout << ",";
   }
   std::cout << ")";
}

void FunctionDeclaration::Visit(AbstractVisitor* visitor) {
   visitor->VisitFunctionDeclaration(this);
}

IStatement* FunctionDeclaration::TransformStatement(AbstractStatementTransformer* transformer) {
   return transformer->TransformFunctionDeclaration(this);
}

