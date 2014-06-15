#include "MetaCodeAST/Print.h"

std::string Printable::GetString() {
   return std::string();
}

Expression* Printable::GetExpression() { 
   return 0; 
}


PrintableFromString::PrintableFromString(std::string text) { 
   m_text = text; 
}

bool PrintableFromString::isExpression() { 
   return false; 
}

std::string PrintableFromString::GetString() {
   return m_text; 
}

void PrintableFromString::PrintDebug(int level) {
   printIndent(level);
   std::cout << "\""  << GetString() << "\"";
}


PrintableFromExpression::PrintableFromExpression(Expression *expr) {
   m_expr = expr;
}

bool PrintableFromExpression::isExpression() { 
   return true; 
}

Expression* PrintableFromExpression::GetExpression() {
   return m_expr;
}

void PrintableFromExpression::PrintDebug(int level) {
   GetExpression()->PrintDebug(level);
}


Print::Print(Printable** printable, int nbPrintables, bool withEndline ) {
   m_printable = printable;
   m_nbPrintables = nbPrintables;
   m_withEndline = withEndline;
}

int Print::GetNbPrintables() { 
   return m_nbPrintables;
}

Printable* Print::GetPrintable(int iPrintable) {
   return m_printable[iPrintable];
}

bool Print::WithEndline() {
   return m_withEndline;
}

void Print::PrintDebug(int level) {
   printIndent(level);
   std::cout << "Print : ";
   for(int iPrintable = 0; iPrintable < GetNbPrintables(); iPrintable++) {
      GetPrintable(iPrintable)->PrintDebug();
      std::cout << " ";
   }	 
   if(WithEndline())
      std::cout << "endline";
}
