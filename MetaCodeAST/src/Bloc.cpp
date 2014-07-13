#include "MetaCodeAST.h"

Bloc::Bloc(IStatement** statement, int nbStatements) {
   m_statement = statement; 
   m_nbStatements = nbStatements;
}

int Bloc::GetNbStatements() {
   return m_nbStatements; 
}

IStatement* Bloc::GetStatement(int iStatement) {
   return m_statement[iStatement];  
}

void Bloc::PrintDebug(int level) {
   printIndent(level);
   std::cout << "{" << std::endl;
   for(int iStatement = 0; iStatement < GetNbStatements(); iStatement++) {
      GetStatement(iStatement)->PrintDebug(level+1);
      std::cout << std::endl;
   }
   printIndent(level);
   std::cout << "}" << std::endl;
}


