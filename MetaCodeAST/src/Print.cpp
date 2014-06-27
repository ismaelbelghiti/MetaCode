#include "MetaCodeAST/Statement/Instruction/Print.h"
#include "MetaCodeAST/AbstractVisitor.h"
#include "MetaCodeAST/Utilities/indentation_space.h"

std::string Printable::GetString() {
   return std::string();
}

IExpression* Printable::GetExpression() { 
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

void PrintableFromString::Visit(AbstractVisitor* visitor) {
   visitor->VisitPrintableFromString(this);
}


PrintableFromExpression::PrintableFromExpression(IExpression *expr) {
   m_expr = expr;
}

bool PrintableFromExpression::isExpression() { 
   return true; 
}

IExpression* PrintableFromExpression::GetExpression() {
   return m_expr;
}

void PrintableFromExpression::PrintDebug(int level) {
   GetExpression()->PrintDebug(level);
}

void PrintableFromExpression::Visit(AbstractVisitor* visitor) {
   visitor->VisitPrintableFromExpression(this);
}


Print::Print(IPrintable** printable, int nbPrintables, bool withEndline ) {
   m_printable = printable;
   m_nbPrintables = nbPrintables;
   m_withEndline = withEndline;
}

int Print::GetNbPrintables() { 
   return m_nbPrintables;
}

IPrintable* Print::GetPrintable(int iPrintable) {
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

void Print::Visit(AbstractVisitor* visitor) {
   visitor->VisitPrint(this);
}
