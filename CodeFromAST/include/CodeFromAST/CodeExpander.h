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

   virtual ExprFromBool* ExpandExprFromBool(ExprFromBool* exprFromBool);

   virtual ExprFromInt* ExpandExprFromInt(ExprFromInt* exprFromInt);

   virtual Expression* ExpandExpression(Expression* expr);
};

#endif
