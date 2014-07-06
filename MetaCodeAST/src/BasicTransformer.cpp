#include "MetaCodeAST.h"

IType* BasicTransformer::TransformType(Type* type) {
   return new Type(type->GetName());
}

IVariable* BasicTransformer::TransformVariable(Variable* var) {
   return new Variable(
      var->GetName(),
      var->GetType()->TransformType(this)
   );
}

IExpression* BasicTransformer::TransformExprFromInt(ExprFromInt* expr) {
   return new ExprFromInt(expr->GetValue());
}

IExpression* BasicTransformer::TransformExprFromBool(ExprFromBool* expr) {
   return new ExprFromBool(expr->GetValue());
}

IExpression* BasicTransformer::TransformExprFromVariable(ExprFromVariable* expr) {
   return new ExprFromVariable(expr->GetVariable()->TransformVariable(this));
}

IExpression* BasicTransformer::TransformParenthesizedExpr(ParenthesizedExpr* expr) {
   return new ParenthesizedExpr(expr->GetExpression()->TransformExpression(this));
}

IExpression* BasicTransformer::TransformMinus(Minus* minus) {
   return new Minus(minus->GetExpression()->TransformExpression(this));
}

IExpression* BasicTransformer::TransformNegation(Negation* negation) {
   return new Negation(negation->GetExpression()->TransformExpression(this));
}

IExpression* BasicTransformer::TransformAddition(Addition* expr) {
   return new Addition(
      expr->GetLeftExpr()->TransformExpression(this),
      expr->GetRightExpr()->TransformExpression(this)
   );
}

IExpression* BasicTransformer::TransformMultiplication(Multiplication* expr) {
   return new Multiplication(
      expr->GetLeftExpr()->TransformExpression(this),
      expr->GetRightExpr()->TransformExpression(this)
   );
}

IExpression* BasicTransformer::TransformSubstraction(Substraction* expr) {
   return new Substraction(
      expr->GetLeftExpr()->TransformExpression(this),
      expr->GetRightExpr()->TransformExpression(this)
   );
}

IExpression* BasicTransformer::TransformEuclidianDivision(EuclidianDivision* expr) {
   return new EuclidianDivision(
      expr->GetLeftExpr()->TransformExpression(this),
      expr->GetRightExpr()->TransformExpression(this)
   );
}

IExpression* BasicTransformer::TransformModulus(Modulus* expr) {
   return new Modulus(
      expr->GetLeftExpr()->TransformExpression(this),
      expr->GetRightExpr()->TransformExpression(this)
   );
}

IExpression* BasicTransformer::TransformAnd(And* expr) {
   return new And(
      expr->GetLeftExpr()->TransformExpression(this),
      expr->GetRightExpr()->TransformExpression(this)
   );
}

IExpression* BasicTransformer::TransformOr(Or* expr) {
   return new Or(
      expr->GetLeftExpr()->TransformExpression(this),
      expr->GetRightExpr()->TransformExpression(this)
   );
}

IStatement* BasicTransformer::TransformIf(If * ifNode) {
   return new If(
      ifNode->GetCondition()->TransformExpression(this),
      TransformBloc(ifNode->GetBloc())
   );
}

IStatement* BasicTransformer::TransformElseIf(ElseIf * elseIfNode) {
   return new ElseIf(
      elseIfNode->GetCondition()->TransformExpression(this),
      TransformBloc(elseIfNode->GetBloc())
   );
}

IStatement* BasicTransformer::TransformElse(Else * elseNode) {
   return new Else(TransformBloc(elseNode->GetBloc()));
}

IStatement* BasicTransformer::TransformDeclaration(Declaration * decl) {
   return new Declaration(
      decl->GetVariable()->TransformVariable(this),
      decl->GetExpression()->TransformExpression(this)
   );
}   

IStatement* BasicTransformer::TransformFor(For * forNode) {
   IExpression* includedEnd = 0;
   if(forNode->GetRange()->IncludedEndIsDefined())
      includedEnd = forNode->GetRange()->GetIncludedEnd()->TransformExpression(this);
	 
   return new For(
      forNode->GetVariable()->TransformVariable(this),
      new Range(
	 forNode->GetRange()->IsIncreasing(),
	 forNode->GetRange()->GetStart()->TransformExpression(this),
	 forNode->GetRange()->GetExcludedEnd()->TransformExpression(this),
	 includedEnd
      ),
      TransformBloc(forNode->GetBloc())
   );
}

IStatement* BasicTransformer::TransformFunctionDeclaration(FunctionDeclaration * functionDecl) {
   int nbArgs = functionDecl->GetNbArgs();
   IVariable** arg = new IVariable*[nbArgs];
   for(int iArg = 0; iArg < nbArgs; iArg++)
      arg[iArg] = functionDecl->GetArg(iArg)->TransformVariable(this);

   return new FunctionDeclaration(
      functionDecl->GetVariable()->TransformVariable(this),
      arg,
      nbArgs,
      TransformBloc(functionDecl->GetBloc())
   );
}

IStatement* BasicTransformer::TransformIncludeLib(IncludeLib* includeLib) {
   return new IncludeLib(includeLib->GetName());
}

IStatement* BasicTransformer::TransformWhile(While* whileNode) {
   return new While(
      whileNode->GetCondition()->TransformExpression(this),
      TransformBloc(whileNode->GetBloc())
   );
}
   
IStatement* BasicTransformer::TransformMain(Main* mainNode) {
   return new Main(TransformBloc(mainNode->GetBloc()));
}

IStatement* BasicTransformer::TransformPrint(Print * print) {
   int nbPrintables = print->GetNbPrintables();
   IPrintable** printable = new IPrintable*[nbPrintables];
   for(int iPrintable = 0; iPrintable < nbPrintables; iPrintable++) {
      if(print->GetPrintable(iPrintable)->IsExpression())
	 printable[iPrintable] = new PrintableFromExpression(
	    print->GetPrintable(iPrintable)->GetExpression()->TransformExpression(this));
      else
	 printable[iPrintable] = new PrintableFromString(
	    print->GetPrintable(iPrintable)->GetString());
   }
}


//private

IBloc* BasicTransformer::TransformBloc(IBloc* bloc) {
   IStatement** statement = new IStatement*[bloc->GetNbStatements()];
   for(int iStatement = 0; iStatement < bloc->GetNbStatements(); iStatement++)
      statement[iStatement] = bloc->GetStatement(iStatement)->TransformStatement(this);
   return new Bloc(statement,bloc->GetNbStatements());
}
