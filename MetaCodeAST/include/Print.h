#ifndef PRINT_H
#define PRINT_H

#include "Expression.h"

class Printable : public CodeNode {
public:
   virtual bool isExpression() = 0;

   virtual std::string GetString() { return std::string(); }

   virtual Expression* GetExpression() { return 0; }
};

class PrintableFromString : public Printable {
public:
   PrintableFromString(std::string text) { m_text = text; }

   virtual bool isExpression() { return false; }

   virtual std::string GetString() { return m_text; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << "\""  << GetString() << "\"";
   }

private:
   std::string m_text;
};

class PrintableFromExpression : public Printable {
public:
   PrintableFromExpression(Expression *expr) { m_expr = expr; }

   virtual bool isExpression() { return true; }

   virtual Expression* GetExpression() { return m_expr; }

   virtual void PrintDebug(int level = 0) {
      GetExpression()->PrintDebug(level);
   }

private:
   Expression* m_expr;
};

class Print : public CodeNode {
public:
   static const bool ENDLINE = true;
   static const bool NO_ENDLINE = false;

   Print(Printable** printable, int nbPrintables, bool withEndline = true) {
      m_printable = printable;
      m_nbPrintables = nbPrintables;
      m_withEndline = withEndline;
   }

   virtual int GetNbPrintables() { return m_nbPrintables; }

   virtual Printable* GetPrintable(int iPrintable) { return m_printable[iPrintable]; }

   virtual bool WithEndline() { return m_withEndline; }

   virtual void PrintDebug(int level = 0) {
      printIndent(level);
      std::cout << "Print : ";
      for(int iPrintable = 0; iPrintable < GetNbPrintables(); iPrintable++) {
	 GetPrintable(iPrintable)->PrintDebug();
	 std::cout << " ";
      }	 
      if(WithEndline())
	 std::cout << "endline";
   }

private:
   int m_nbPrintables;
   Printable** m_printable;
   bool m_withEndline;
};


#endif
