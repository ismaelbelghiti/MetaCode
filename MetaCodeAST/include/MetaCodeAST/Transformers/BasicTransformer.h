#ifndef BASIC_TRANSFORMER_H
#define BASIC_TRANSFORMER_H

#include "MetaCodeAST/Transformers/AbstractTransformer.h"

class BasicTransformer : AbstractTransformer {
public:
   virtual IType* TransformType(Type* type);

   virtual IVariable* TransformVariable(Variable* var);

   virtual IExpression* TransformExprFromInt(ExprFromInt* expr);

   virtual IExpression* TransformExprFromBool(ExprFromBool* expr);

   virtual IExpression* TransformExprFromVariable(ExprFromVariable* expr);

   virtual IExpression* TransformParenthesizedExpr(ParenthesizedExpr* expr);

   virtual IExpression* TransformMinus(Minus* minus);

   virtual IExpression* TransformNegation(Negation* negation);

   virtual IExpression* TransformAddition(Addition* expr);

   virtual IExpression* TransformMultiplication(Multiplication* expr);

   virtual IExpression* TransformSubstraction(Substraction* expr);

   virtual IExpression* TransformEuclidianDivision(EuclidianDivision* expr);

   virtual IExpression* TransformModulus(Modulus* expr);

   virtual IExpression* TransformAnd(And* expr);

   virtual IExpression* TransformOr(Or* expr);

   virtual IStatement* TransformIf(If * ifNode);

   virtual IStatement* TransformElseIf(ElseIf * elseIfNode);

   virtual IStatement* TransformElse(Else * elseNode);

   virtual IStatement* TransformDeclaration(Declaration * decl);   

   virtual IStatement* TransformFor(For * forNode);

   virtual IStatement* TransformFunctionDeclaration(FunctionDeclaration * functionDecl);

   virtual IStatement* TransformIncludeLib(IncludeLib* includeLib);

   virtual IStatement* TransformWhile(While* whileNode);
   
   virtual IStatement* TransformMain(Main* mainNode);

   virtual IStatement* TransformPrint(Print * print);

private:
   virtual IBloc* TransformBloc(IBloc* bloc);
};



#endif
