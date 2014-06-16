#ifndef PRINT_H
#define PRINT_H

#include "Expression.h"

class Printable : public CodeNode {
public:
   virtual bool isExpression() = 0;

   virtual std::string GetString();

   virtual Expression* GetExpression();
};

class PrintableFromString : public Printable {
public:
   PrintableFromString(std::string text);

   virtual bool isExpression();

   virtual std::string GetString();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   std::string m_text;
};

class PrintableFromExpression : public Printable {
public:
   PrintableFromExpression(Expression *expr);

   virtual bool isExpression();

   virtual Expression* GetExpression();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   Expression* m_expr;
};

class Print : public CodeNode {
public:
   static const bool ENDLINE = true;
   static const bool NO_ENDLINE = false;

   Print(Printable** printable, int nbPrintables, bool withEndline = true);   

   virtual int GetNbPrintables();

   virtual Printable* GetPrintable(int iPrintable);

   virtual bool WithEndline();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

private:
   int m_nbPrintables;
   Printable** m_printable;
   bool m_withEndline;
};


#endif
