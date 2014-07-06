#ifndef INFOS_GATHER_VISITOR_H
#define INFOS_GATHER_VISITOR_H

#include <vector>
#include <map>
#include "MetaCodeAST.h"

class InfosGatherVisitor : public EmptyVisitor {
public:
   InfosGatherVisitor(IStatement* root);

   virtual void VisitIf(If * ifNode);

   virtual void VisitElseIf(ElseIf * elseIfNode);

   virtual void VisitElse(Else * elseNode);

   virtual void VisitDeclaration(Declaration * decl);

   virtual void VisitFor(For * forNode);

   virtual void VisitFunctionDecaration(FunctionDeclaration * functionDecl);

   virtual void VisitIncludeLib(IncludeLib* includeLib);

   virtual void VisitPrintableFromString(PrintableFromString * printStr);

   virtual void VisitPrintableFromExpression(PrintableFromExpression * printExpr);

   virtual void VisitPrint(Print * print);

   virtual void VisitWhile(While* whileNode);
   
   virtual void VisitMain(Main* mainNode);

   virtual int GetIndentLevel(IStatement* statement);

private:
   virtual void VisitBloc(IBloc* bloc, int currentLevel);

   virtual int GetCurrentLevel();

   virtual void Call(IStatement* statement, int indentLevel);

   std::vector<IStatement*> m_activeParent;
   std::vector<int> m_callIndentLevel;
   std::map<IStatement*,int> m_indentLevel;
};

#endif
