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


class CodeNodeExpander : public EmptyVisitor {
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

//own
   

   // Warning : treat them all !

   CodeNode* GetResult() {
      return m_result;
   };

private:
   CodeExpander* m_codeExpander;
   CodeNode* m_result;
};


/////////////
// Methods //
/////////////


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

CodeNode* CodeExpander::ExpandCodeNode(CodeNode* codeNode) {
   CodeNodeExpander* codeNodeExpander = new CodeNodeExpander(this);
   codeNode->Visit(codeNodeExpander);
   CodeNode * result = codeNodeExpander->GetResult();
   delete codeNodeExpander;
   return result;
}

