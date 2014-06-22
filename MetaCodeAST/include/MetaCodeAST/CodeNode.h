#ifndef CODE_NODE_H
#define CODE_NODE_H

#include "indentation_space.h"

class AbstractTypeVisitor;
class AbstractVariableVisitor;
class AbstractExpressionVisitor;
class AbstractBlocVisitor;
class AbstractRangeVisitor;
class AbstractPrintableVisitor;
class AbstractStatementVisitor;
class AbstractFunctionVisitor;
class AbstractSignatureVisitor;
class AbstractVisitor;

class CodeNode {
public:
   virtual void PrintDebug(int level = 0) = 0;

   virtual void Visit(AbstractVisitor* visitor) = 0;
};

#endif
