#include "MetaCodeAST/Statement/Instruction/Print.h"
#include "MetaCodeAST/AbstractVisitor.h"
#include "MetaCodeAST/Statement/AbstractStatementTransformer.h"
#include "MetaCodeAST/Printable/AbstractPrintableTransformer.h"
#include "MetaCodeAST/Utilities/indentation_space.h"


PrintableFromString::PrintableFromString(std::string text) { 
   m_text = text; 
}

bool PrintableFromString::isExpression() { 
   return false; 
}

std::string PrintableFromString::GetString() {
   return m_text; 
}

IExpression* PrintableFromString::GetExpression() {
   return 0;
}

void PrintableFromString::PrintDebug(int level) {
   printIndent(level);
   std::cout << "\""  << GetString() << "\"";
}


PrintableFromExpression::PrintableFromExpression(IExpression *expr) {
   m_expr = expr;
}

bool PrintableFromExpression::isExpression() { 
   return true; 
}

std::string PrintableFromExpression::GetString() {
   return std::string(); 
}


IExpression* PrintableFromExpression::GetExpression() {
   return m_expr;
}

void PrintableFromExpression::PrintDebug(int level) {
   GetExpression()->PrintDebug(level);
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

IStatement* Print::TransformStatement(AbstractStatementTransformer* transformer) {
   return transformer->TransformPrint(this);
}
