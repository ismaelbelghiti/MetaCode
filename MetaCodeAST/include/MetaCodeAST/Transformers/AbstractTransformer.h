#ifndef ABSTRACT_TRANSFORMER_H
#define ABSTRACT_TRANSFORMER_H

#include "MetaCodeAST/Constructions.h"

class AbstractTypeTransformer {
public:
   virtual IType* TransformType(Type* type) = 0;
};

class AbstractVariableTransformer {
public:
   virtual IVariable* TransformVariable(Variable* var) = 0;
};

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


class AbstractTransformer :
   public AbstractTypeTransformer,
   public AbstractVariableTransformer,
   public AbstractExpressionTransformer,
   public AbstractStatementTransformer
{
};

#endif
