// This may look like C, but it's really -*- C++ -*-
#ifndef AST_TEMPLATE_MODULE_INST_H
#define AST_TEMPLATE_MODULE_INST_H

#include "ast_field.h"
#include "fe_utils.h"

class AST_Template_Module;

class TAO_IDL_FE_Export AST_Template_Module_Inst
  : public virtual AST_Field
{
public:
  AST_Template_Module_Inst (UTL_ScopedName *n,
                            AST_Template_Module *ref,
                            FE_Utils::T_ARGLIST *template_args);

  virtual ~AST_Template_Module_Inst ();

  AST_Template_Module *ref () const;

  FE_Utils::T_ARGLIST const *
  template_args () const;

  // AST Dumping.
  virtual void dump (ACE_OSTREAM_TYPE &o);

  // Cleanup function.
  virtual void destroy ();

  // Visiting.
  virtual int ast_accept (ast_visitor *visitor);

  static AST_Decl::NodeType const NT;

private:
  FE_Utils::T_ARGLIST * template_args_;
};

#endif           // AST_TEMPLATE_MODULE_INST_H
