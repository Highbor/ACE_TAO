// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:151

#ifndef _TAO_IDL_TYPECODEFACTORYC_H_
#define _TAO_IDL_TYPECODEFACTORYC_H_

#include /**/ "ace/pre.h"

#include "typecodefactory_export.h"

#ifndef TAO_TYPECODEFACTORY_SAFE_INCLUDE
#error "You should not include TypeCodeFactoryC.h directly, use TypeCodeFactory_Loader.h"
#endif /* !TAO_TYPECODEFACTORY_SAFE_INCLUDE */

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"

#include "tao/IFR_Client/IFR_ExtendedC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_TypeCodeFactory_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_TypeCodeFactory_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be/be_visitor_root/root_ch.cpp:63

namespace TAO
{
  class Collocation_Proxy_Broker;
}

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:48

namespace CORBA
{

  // TAO_IDL - Generated from
  // be/be_interface.cpp:601

#if !defined (_CORBA_TYPECODEFACTORY__VAR_OUT_CH_)
#define _CORBA_TYPECODEFACTORY__VAR_OUT_CH_

  class TypeCodeFactory;
  typedef TypeCodeFactory *TypeCodeFactory_ptr;

  typedef
    TAO_Objref_Var_T<
        TypeCodeFactory
      >
    TypeCodeFactory_var;

  typedef
    TAO_Objref_Out_T<
        TypeCodeFactory
      >
    TypeCodeFactory_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:53

#if !defined (_CORBA_TYPECODEFACTORY_CH_)
#define _CORBA_TYPECODEFACTORY_CH_

  class TAO_TypeCodeFactory_Export TypeCodeFactory
    : public virtual CORBA::Object
  {
  public:
    typedef TypeCodeFactory_ptr _ptr_type;
    typedef TypeCodeFactory_var _var_type;

    // The static operations.
    static TypeCodeFactory_ptr _duplicate (TypeCodeFactory_ptr obj);

    static TypeCodeFactory_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static TypeCodeFactory_ptr _nil (void)
      {
        return (TypeCodeFactory_ptr)0;
      }

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_struct_tc (
        const char * id,
        const char * name,
        const CORBA::StructMemberSeq & members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_union_tc (
        const char * id,
        const char * name,
        CORBA::TypeCode_ptr discriminator_type,
        const CORBA::UnionMemberSeq & members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_enum_tc (
        const char * id,
        const char * name,
        const CORBA::EnumMemberSeq & members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_alias_tc (
        const char * id,
        const char * name,
        CORBA::TypeCode_ptr original_type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_exception_tc (
        const char * id,
        const char * name,
        const CORBA::StructMemberSeq & members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_interface_tc (
        const char * id,
        const char * name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_string_tc (
        CORBA::ULong bound
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_wstring_tc (
        CORBA::ULong bound
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_fixed_tc (
        CORBA::UShort digits,
        CORBA::UShort scale
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_sequence_tc (
        CORBA::ULong bound,
        CORBA::TypeCode_ptr element_type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_array_tc (
        CORBA::ULong length,
        CORBA::TypeCode_ptr element_type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_value_tc (
        const char * id,
        const char * name,
        CORBA::ValueModifier type_modifier,
        CORBA::TypeCode_ptr concrete_base,
        const CORBA::ValueMemberSeq & members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_value_box_tc (
        const char * id,
        const char * name,
        CORBA::TypeCode_ptr boxed_type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_native_tc (
        const char * id,
        const char * name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_recursive_tc (
        const char * id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_abstract_interface_tc (
        const char * id,
        const char * name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_local_interface_tc (
        const char * id,
        const char * name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_component_tc (
        const char * id,
        const char * name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_home_tc (
        const char * id,
        const char * name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::TypeCode_ptr create_event_tc (
        const char * id,
        const char * name,
        CORBA::ValueModifier type_modifier,
        CORBA::TypeCode_ptr concrete_base,
        const CORBA::ValueMemberSeq & members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:185

    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    TypeCodeFactory (void);
    virtual ~TypeCodeFactory (void);

  private:
    TypeCodeFactory (const TypeCodeFactory &);
    void operator= (const TypeCodeFactory &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_TypeCodeFactory;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:66

} // module CORBA

// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:48

// Traits specializations.
namespace TAO
{
};

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_TypeCodeFactory_Export void operator<<= (CORBA::Any &, CORBA::TypeCodeFactory_ptr); // copying
TAO_TypeCodeFactory_Export void operator<<= (CORBA::Any &, CORBA::TypeCodeFactory_ptr *); // non-copying
TAO_TypeCodeFactory_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::TypeCodeFactory_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// be/be_codegen.cpp:969

#if defined (__ACE_INLINE__)
#include "TypeCodeFactoryC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */
