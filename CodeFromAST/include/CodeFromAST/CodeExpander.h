#ifndef CODE_EXPANDER_H
#define CODE_EXPANDER_H

#include <vector>
#include "MetaCodeAST.h"

/**
 * Class used for the really first preprocess of the AST. It aims
 * to ensure that no two distinct nodes share the same pointer
 * (except for Type nodes)
 */
class CodeExpander : public AbstractVisitor {
public:
   virtual Variable* ExpandVariable(Variable* var);

   virtual Expression* ExpandExpression(Expression* expr);

   virtual Bloc* ExpandBloc(Bloc* bloc);

   virtual Range* ExpandRange(Range* range);

   virtual Printable* ExpandPrintable(Printable* printable);

   virtual CodeNode* ExpandCodeNode(CodeNode* codeNode);
};

#endif
