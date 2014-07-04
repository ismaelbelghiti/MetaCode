#ifndef META_CODE_AST_H
#define META_CODE_AST_H

#include "MetaCodeAST/Utilities/indentation_space.h"
#include "MetaCodeAST/InterfaceType.h"

#include "MetaCodeAST/Utilities/Bloc.h"

#include "MetaCodeAST/Type/Type.h"
#include "MetaCodeAST/Variable/Variable.h"
#include "MetaCodeAST/Expression/Expression.h"
#include "MetaCodeAST/Statement/Compound/While.h"
#include "MetaCodeAST/Statement/Compound/For.h"
#include "MetaCodeAST/Statement/Compound/Conditional.h"
#include "MetaCodeAST/Statement/Compound/Main.h"
#include "MetaCodeAST/Statement/Compound/Function.h"
#include "MetaCodeAST/Statement/Instruction/Declaration.h"
#include "MetaCodeAST/Statement/Instruction/Print.h"
#include "MetaCodeAST/Statement/Instruction/IncludeLib.h"

#include "MetaCodeAST/AbstractVisitor.h"
#include "MetaCodeAST/AbstractTransformer.h"

#endif
