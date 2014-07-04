#ifndef META_CODE_AST_H
#define META_CODE_AST_H

#include "MetaCodeAST/Utilities/indentation_space.h"
#include "MetaCodeAST/InterfaceType.h"

#include "MetaCodeAST/Utilities/Bloc.h"

#include "MetaCodeAST/Constructions/Type/Type.h"
#include "MetaCodeAST/Constructions/Variable/Variable.h"
#include "MetaCodeAST/Constructions/Expression/Expression.h"
#include "MetaCodeAST/Constructions/Statement/Compound/While.h"
#include "MetaCodeAST/Constructions/Statement/Compound/For.h"
#include "MetaCodeAST/Constructions/Statement/Compound/Conditional.h"
#include "MetaCodeAST/Constructions/Statement/Compound/Main.h"
#include "MetaCodeAST/Constructions/Statement/Compound/Function.h"
#include "MetaCodeAST/Constructions/Statement/Instruction/Declaration.h"
#include "MetaCodeAST/Constructions/Statement/Instruction/Print.h"
#include "MetaCodeAST/Constructions/Statement/Instruction/IncludeLib.h"

#include "MetaCodeAST/Visitors/AbstractVisitor.h"
#include "MetaCodeAST/Transformers/AbstractTransformer.h"

#endif
