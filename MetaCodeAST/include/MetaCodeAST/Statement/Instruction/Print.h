#ifndef PRINT_H
#define PRINT_H

#include "MetaCodeAST/InterfaceType.h"

class Printable : public IPrintable {
public:
   virtual bool isExpression() = 0;

   virtual std::string GetString() = 0;

   virtual IExpression* GetExpression() = 0;

};

class PrintableFromString : public IPrintable {
public:
   PrintableFromString(std::string text);

   virtual bool isExpression();

   virtual std::string GetString();

   virtual IExpression* GetExpression();

   virtual void PrintDebug(int level = 0);

private:
   std::string m_text;
};

class PrintableFromExpression : public IPrintable {
public:
   PrintableFromExpression(IExpression *expr);

   virtual bool isExpression();

   virtual std::string GetString();

   virtual IExpression* GetExpression();

   virtual void PrintDebug(int level = 0);

private:
   IExpression* m_expr;
};

class Print : public IStatement {
public:
   static const bool ENDLINE = true;
   static const bool NO_ENDLINE = false;

   Print(IPrintable** printable, int nbPrintables, bool withEndline = true);   

   virtual int GetNbPrintables();

   virtual IPrintable* GetPrintable(int iPrintable);

   virtual bool WithEndline();

   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor);

   virtual IStatement* TransformStatement(AbstractStatementTransformer* transformer);

private:
   int m_nbPrintables;
   IPrintable** m_printable;
   bool m_withEndline;
};


#endif
