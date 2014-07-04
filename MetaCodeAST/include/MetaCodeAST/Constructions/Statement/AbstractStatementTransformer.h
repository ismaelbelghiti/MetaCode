#ifndef ABSTRACT_STATEMENT_TRANSFORMER_H
#define ABSTRACT_STATEMENT_TRANSFORMER_H

#include "MetaCodeAST.h"

class AbstractStatementTransformer {
public:
   virtual IStatement* TransformIf(If * ifNode) = 0;

   virtual IStatement* TransformElseIf(ElseIf * elseIfNode) = 0;

   virtual IStatement* TransformElse(Else * elseNode) = 0;

   virtual IStatement* TransformDeclaration(Declaration * decl) = 0;   

   virtual IStatement* TransformFor(For * forNode) = 0;

   virtual IStatement* TransformFunctionDeclaration(FunctionDeclaration * functionDecl) = 0;

   virtual IStatement* TransformIncludeLib(IncludeLib* includeLib) = 0;

   virtual IStatement* TransformWhile(While* whileNode) = 0;
   
   virtual IStatement* TransformMain(Main* mainNode) = 0;

   virtual IStatement* TransformPrint(Print * print) = 0;
};


#endif
