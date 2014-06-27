#ifndef INTERFACE_TYPE_H
#define INTERFACE_TYPE_H

#include <string>

class AbstractVisitor;

class AbstractTypeTransformer;
class AbstractVariableTransformer;
class AbstractExpressionTransformer;
class AbstractStatementTransformer;
class AbstractBlocTransformer;
class AbstractRangeTransformer;
class AbstractPrintableTransformer;
class AbstractSignatureTransformer;


class IType {
public:
   virtual std::string GetName();

   virtual void PrintDebug(int level = 0) = 0;

   virtual void Visit(AbstractVisitor* visitor) = 0;
   
   //virtual IType* TransformType(AbstractTypeTransformer* transformer) = 0;
};

class IVariable {
public:
   virtual IType* GetType();

   virtual std::string GetName() = 0;

   virtual void PrintDebug(int level = 0) = 0;

   virtual void Visit(AbstractVisitor* visitor) = 0;

   //virtual IVariable* TransformVariable(AbstractVariableTransformer* transformer) = 0;
};

class IExpression {
public:
   virtual IType* GetType();
   
   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor) = 0;  

   //virtual IExpression* TransformExpression(AbstractExpressionTransformer* transformer) = 0;
};

class IStatement {
public:
   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor) = 0;

   //virtual IStatement* TransformStatement(AbstractStatementTransformer* transformer) = 0;
};

class IBloc {
public:
   virtual int GetNbStatements() = 0;

   virtual IStatement* GetStatement(int iStatement) = 0;

   virtual void PrintDebug(int level = 0) = 0;

   virtual void Visit(AbstractVisitor* visitor) = 0;

   //virtual IBloc* TransforBloc(AbstractBlocTransformer* transformer) = 0;
};

class IRange {
public:
   virtual bool IsIncreasing() = 0;

   virtual IExpression* GetStart() = 0;

   virtual IExpression* GetExcludedEnd() = 0;

   virtual bool IncludedEndIsDefined() = 0;

   virtual IExpression* GetIncludedEnd() = 0;

   virtual void PrintDebug(int level = 0) = 0;

   virtual void Visit(AbstractVisitor* visitor) = 0;

   //virtual IRange* TransformRange(AbstractRangeTransformer* transformer) = 0;
};

class IPrintable {
public:
   virtual bool isExpression() = 0;

   virtual std::string GetString() = 0;

   virtual IExpression* GetExpression() = 0;

   virtual void PrintDebug(int level = 0) = 0;

   virtual void Visit(AbstractVisitor* visitor) = 0;

   //virtual IPrintable* TransformPrintable(AbstractPrintableTransformer* transformer) = 0;
};

class ISignature {
public:
   virtual int GetNbArgs() = 0;

   virtual IVariable* GetArg(int iArg) = 0;
   
   virtual void PrintDebug(int level = 0);

   virtual void Visit(AbstractVisitor* visitor) = 0;

   //virtual ISignature* TransformSignature(AbstractSignatureTransformer* transformer) = 0;
};



#endif 
