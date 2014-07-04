#ifndef ABSTRACT_EXPRESSION_TRANSFORMER_H
#define ABSTRACT_EXPRESSION_TRANSFORMER_H

#include "MetaCodeAST.h"

class AbstractExpressionTransformer {
public:
   virtual IExpression* TransformExprFromInt(ExprFromInt* expr) = 0;

   virtual IExpression* TransformExprFromBool(ExprFromBool* expr) = 0;

   virtual IExpression* TransformExprFromVariable(ExprFromVariable* expr) = 0;

   virtual IExpression* TransformParenthesizedExpr(ParenthesizedExpr* expr) = 0;

   virtual IExpression* TransformMinus(Minus* minus) = 0;

   virtual IExpression* TransformNegation(Negation* negation) = 0;

   virtual IExpression* TransformAddition(Addition* expr) = 0;

   virtual IExpression* TransformMultiplication(Multiplication* expr) = 0;

   virtual IExpression* TransformSubstraction(Substraction* expr) = 0;

   virtual IExpression* TransformEuclidianDivision(EuclidianDivision* expr) = 0;

   virtual IExpression* TransformModulus(Modulus* expr) = 0;

   virtual IExpression* TransformAnd(And* expr) = 0;

   virtual IExpression* TransformOr(Or* expr) = 0;
};

#endif
