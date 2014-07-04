#include "MetaCodeAST/Statement/Instruction/Declaration.h"
#include "MetaCodeAST/AbstractVisitor.h"
#include "MetaCodeAST/Statement/AbstractStatementTransformer.h"
#include "MetaCodeAST/Utilities/indentation_space.h"

Declaration::Declaration(IVariable* variable, IExpression* expr) {     
   m_variable = variable;
   m_expr = expr;
}

IVariable* Declaration::GetVariable() {
   return m_variable;
}

IExpression* Declaration::GetExpression() {
   return m_expr;
}

void Declaration::PrintDebug(int level) {
   printIndent(level);
   GetVariable()->GetType()->PrintDebug();
   std::cout << " ";
   GetVariable()->PrintDebug();
   std::cout << " = ";
   GetExpression()->PrintDebug();
}

void Declaration::Visit(AbstractVisitor* visitor) {
   visitor->VisitDeclaration(this);
}

IStatement* Declaration::TransformStatement(AbstractStatementTransformer* transformer) {
   return transformer->TransformDeclaration(this);
}

