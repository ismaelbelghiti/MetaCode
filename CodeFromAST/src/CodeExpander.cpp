#include "CodeFromAST/CodeExpander.h"
#include "CodeFromAST/EmptyVisitor.h"

///////////////
// Expanders //
///////////////

class VariableExpander : public EmptyVisitor {
public:
   VariableExpander(CodeExpander* codeExpander) {
      m_codeExpander = codeExpander;
   }
  
   virtual void VisitVariable(Variable* var) {
      m_result = new Variable(var->GetName(), var->GetType());
   }

   Variable* GetResult() {
      return m_result;
   };

private:
   CodeExpander* m_codeExpander;
   Variable* m_result;
};


class ExpressionExpander : public EmptyVisitor {
public:
   ExpressionExpander(CodeExpander* codeExpander) {
      m_codeExpander = codeExpander;
   }

   virtual void VisitExprFromVariable(ExprFromVariable* exprFromVariable) {
      Variable* var = 
	 m_codeExpander->ExpandVariable(exprFromVariable->GetVariable());
      m_result = new ExprFromVariable(var);
   }

   virtual void VisitExprFromInt(ExprFromInt* exprFromInt) {
      m_result =  new ExprFromInt(exprFromInt->GetValue() );
   }

   virtual void VisitExprFromBool(ExprFromBool* exprFromBool) {
      m_result =  new ExprFromBool(exprFromBool->GetValue() );
   }

   virtual void VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) {
      Expression* expr =
	 m_codeExpander->ExpandExpression(parenthesizedExpr->GetExpression());
      m_result = new ParenthesizedExpr(expr);
   }

   virtual void VisitMinus(Minus* minus) {
      Expression* expr =
	 m_codeExpander->ExpandExpression(minus->GetExpression());
      m_result = new Minus(expr);
   }

   virtual void VisitNegation(Negation* negation) {
      Expression* expr =
	 m_codeExpander->ExpandExpression(negation->GetExpression());
      m_result = new Negation(expr);
   }

   virtual void VisitAddition(Addition* add) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(add->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(add->GetRightExpr());
      m_result = new Addition(left,right);
   }

   virtual void VisitMultiplication(Multiplication * multiplication) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(multiplication->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(multiplication->GetRightExpr());
      m_result = new Multiplication(left,right);
   }

   virtual void VisitSubstraction(Substraction * substraction) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(substraction->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(substraction->GetRightExpr());
      m_result = new Substraction(left,right);
   }

   virtual void VisitEuclidianDivision(EuclidianDivision * euclDiv) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(euclDiv->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(euclDiv->GetRightExpr());
      m_result = new EuclidianDivision(left,right);
   }

   virtual void VisitModulus(Modulus * modulus) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(modulus->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(modulus->GetRightExpr());
      m_result = new Modulus(left,right);
   }

   virtual void VisitAnd(And * andNode) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(andNode->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(andNode->GetRightExpr());
      m_result = new And(left,right);
   }

   virtual void VisitOr(Or * orNode) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(orNode->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(orNode->GetRightExpr());
      m_result = new Or(left,right);
   }

   // Warning : treat them all !

   Expression* GetResult() {
      return m_result;
   };

private:
   CodeExpander* m_codeExpander;
   Expression* m_result;
};

class BlocExpander : public EmptyVisitor {
public:
   BlocExpander(CodeExpander* codeExpander) {
      m_codeExpander = codeExpander;
   }
  
   virtual void VisitBloc(Bloc* bloc) {
      int nbCodeNodes = bloc->GetNbCodeNodes();
      CodeNode** codeNode = new CodeNode*[nbCodeNodes];
      for(int iCodeNode = 0; iCodeNode < nbCodeNodes; iCodeNode++)
	 codeNode[iCodeNode] = bloc->GetCodeNode(iCodeNode);
      m_result = new Bloc(codeNode, nbCodeNodes);
   }

   Bloc* GetResult() {
      return m_result;
   };

private:
   CodeExpander* m_codeExpander;
   Bloc* m_result;
};


class RangeExpander : public EmptyVisitor {
public:
   RangeExpander(CodeExpander* codeExpander) {
      m_codeExpander = codeExpander;
   }
  
   virtual void VisitRange(Range* range) {
      m_result = new Range(
	 range->IsIncreasing(),
	 m_codeExpander->ExpandExpression(range->GetStart()),
	 m_codeExpander->ExpandExpression(range->GetExcludedEnd()),
	 m_codeExpander->ExpandExpression(range->GetIncludedEnd())
      );
   }

   Range* GetResult() {
      return m_result;
   };

private:
   CodeExpander* m_codeExpander;
   Range* m_result;
};

class PrintableExpander : public EmptyVisitor {
public:
   PrintableExpander(CodeExpander* codeExpander) {
      m_codeExpander = codeExpander;
   }
 
   virtual void VisitPrintableFromString(PrintableFromString* printableFromString) {
      m_result = new PrintableFromString(printableFromString->GetString());
   }

   virtual void VisitPrintableFromExpression(PrintableFromExpression* printableFromExpr) {
      m_result = new PrintableFromExpression(
	 m_codeExpander->ExpandExpression(printableFromExpr->GetExpression()) 
      );
   }

   Printable* GetResult() {
      return m_result;
   };

private:
   CodeExpander* m_codeExpander;
   Printable* m_result;
};


class CodeNodeExpander : public AbstractVisitor {
public:
   CodeNodeExpander(CodeExpander* codeExpander) {
      m_codeExpander = codeExpander;
   }

//recall
   virtual void VisitVariable(Variable* var) {
      m_result = m_codeExpander->ExpandVariable(var);
   }

   virtual void VisitExprFromVariable(ExprFromVariable* exprFromVariable) {
      m_result = m_codeExpander->ExpandExpression(exprFromVariable);
   }

   virtual void VisitExprFromInt(ExprFromInt* exprFromInt) {
      m_result = m_codeExpander->ExpandExpression(exprFromInt);
   }

   virtual void VisitExprFromBool(ExprFromBool* exprFromBool) {
      m_result = m_codeExpander->ExpandExpression(exprFromBool);
   }

   virtual void VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) {
      m_result = m_codeExpander->ExpandExpression(parenthesizedExpr);
   }

   virtual void VisitMinus(Minus* minus) {
      m_result = m_codeExpander->ExpandExpression(minus);
   }

   virtual void VisitNegation(Negation* negation) {
      m_result = m_codeExpander->ExpandExpression(negation);
   }

   virtual void VisitAddition(Addition* add) {
      m_result = m_codeExpander->ExpandExpression(add);
   }

   virtual void VisitMultiplication(Multiplication * multiplication) {
      m_result = m_codeExpander->ExpandExpression(multiplication);
   }

   virtual void VisitSubstraction(Substraction * substraction) {
      m_result = m_codeExpander->ExpandExpression(substraction);
   }

   virtual void VisitEuclidianDivision(EuclidianDivision * euclDiv) {
      m_result = m_codeExpander->ExpandExpression(euclDiv);
   }

   virtual void VisitModulus(Modulus * modulus) {
      m_result = m_codeExpander->ExpandExpression(modulus);
   }

   virtual void VisitAnd(And * andNode) {
      m_result = m_codeExpander->ExpandExpression(andNode);
   }

   virtual void VisitOr(Or * orNode) {
      m_result = m_codeExpander->ExpandExpression(orNode);
   }

   virtual void VisitBloc(Bloc* bloc) {
      m_result = m_codeExpander->ExpandBloc(bloc);
   }

   virtual void VisitRange(Range * range) {
      m_result = m_codeExpander->ExpandRange(range);
   }

//own
   virtual void VisitIf(If * ifNode) {
      m_result = new If(
	 m_codeExpander->ExpandExpression(ifNode->GetCondition()),
	 m_codeExpander->ExpandBloc(ifNode->GetBloc())
      );
   }

   virtual void VisitElseIf(ElseIf * elseIfNode) {
      m_result = new ElseIf(
	 m_codeExpander->ExpandExpression(elseIfNode->GetCondition()),
	 m_codeExpander->ExpandBloc(elseIfNode->GetBloc())
      ); 
   }

   virtual void VisitElse(Else * elseNode) {
      m_result = new Else(
	 m_codeExpander->ExpandBloc(elseNode->GetBloc())
      );
   }

   virtual void VisitDeclaration(Declaration * decl) {
      m_result = new Declaration(
	 m_codeExpander->ExpandVariable(decl->GetVariable()),
	 m_codeExpander->ExpandExpression(decl->GetExpression())
      );
   }

   virtual void VisitFor(For * forNode) {
      m_result = new For(
	 m_codeExpander->ExpandVariable(forNode->GetVariable()),
	 m_codeExpander->ExpandRange(forNode->GetRange()),
	 m_codeExpander->ExpandBloc(forNode->GetBloc())
      );
   }

   virtual void VisitFunction(Function * function) {
      // todo
   }

   virtual void VisitSignature(Signature * signature) {
      // todo
   }

   virtual void VisitFunctionDeclaration(FunctionDeclaration * functionDecl) {
      // todo
   }

   virtual void VisitIncludeLib(IncludeLib* includeLib) {
      m_result = new IncludeLib(includeLib->GetName());
   }

   virtual void VisitPrintableFromString(PrintableFromString * printStr) {
      m_result = m_codeExpander->ExpandPrintable(printStr);
   }

   virtual void VisitPrintableFromExpression(PrintableFromExpression * printExpr) {
      m_result = m_codeExpander->ExpandPrintable(printExpr);
   }

   virtual void VisitPrint(Print * print) {

   }

   virtual void VisitWhile(While* whileNode) {

   }
   
   virtual void VisitMain(Main* mainNode) {

   }

   virtual void VisitType(Type * type) {
      //nothing to do, we do not expand types
   }

   CodeNode* GetResult() {
      return m_result;
   };

private:
   CodeExpander* m_codeExpander;
   CodeNode* m_result;
};




//////////////////////////////
// Methods of CodeExpanders //
//////////////////////////////


Variable* CodeExpander::ExpandVariable(Variable* var) {
   VariableExpander* varExpander = new VariableExpander(this);
   var->Visit(varExpander);
   Variable* result = varExpander->GetResult();
   delete varExpander;
   return result;
}

Expression* CodeExpander::ExpandExpression(Expression* expr) {
   ExpressionExpander* exprExpander = new ExpressionExpander(this);
   expr->Visit(exprExpander);
   Expression* result = exprExpander->GetResult();
   delete exprExpander;
   return result;
}

Bloc* CodeExpander::ExpandBloc(Bloc* bloc) {
   BlocExpander* blocExpander = new BlocExpander(this);
   bloc->Visit(blocExpander);
   Bloc* result = blocExpander->GetResult();
   delete blocExpander;
   return result;
}

Range* CodeExpander::ExpandRange(Range* range) {
   RangeExpander* rangeExpander = new RangeExpander(this);
   range->Visit(rangeExpander);
   Range* result = rangeExpander->GetResult();
   delete rangeExpander;
   return result;
}

Printable* CodeExpander::ExpandPrintable(Printable* printable) {
   PrintableExpander* printableExpander = new PrintableExpander(this);
   printable->Visit(printableExpander);
   Printable* result = printableExpander->GetResult();
   delete printableExpander;
   return result;
}

CodeNode* CodeExpander::ExpandCodeNode(CodeNode* codeNode) {
   CodeNodeExpander* codeNodeExpander = new CodeNodeExpander(this);
   codeNode->Visit(codeNodeExpander);
   CodeNode * result = codeNodeExpander->GetResult();
   delete codeNodeExpander;
   return result;
}


