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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:301


#include "Default_ORTC.h"
#include "tao/Any_Impl_T.h"
#include "tao/Typecode.h"
#include "tao/Valuetype/ValueFactory.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "Default_ORTC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_arg_traits.cpp:59

// Arg traits specializations.
namespace TAO
{
};

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_TAO_Default_ORT_ObjectReferenceTemplate[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  48,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x54414f5f), 
  ACE_NTOHL (0x44656661), 
  ACE_NTOHL (0x756c745f), 
  ACE_NTOHL (0x4f52542f), 
  ACE_NTOHL (0x4f626a65), 
  ACE_NTOHL (0x63745265), 
  ACE_NTOHL (0x66657265), 
  ACE_NTOHL (0x6e636554), 
  ACE_NTOHL (0x656d706c), 
  ACE_NTOHL (0x6174653a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:TAO_Default_ORT/ObjectReferenceTemplate:1.0
    24,
  ACE_NTOHL (0x4f626a65), 
  ACE_NTOHL (0x63745265), 
  ACE_NTOHL (0x66657265), 
  ACE_NTOHL (0x6e636554), 
  ACE_NTOHL (0x656d706c), 
  ACE_NTOHL (0x61746500),  // name = ObjectReferenceTemplate
    0, // value modifier
  CORBA::tk_null, // no stateful base valuetype

0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_TAO_Default_ORT_ObjectReferenceTemplate (
    CORBA::tk_value,
    sizeof (_oc_TAO_Default_ORT_ObjectReferenceTemplate),
    (char *) &_oc_TAO_Default_ORT_ObjectReferenceTemplate,
    0,
    sizeof (TAO_Default_ORT::ObjectReferenceTemplate)
  );

namespace TAO_Default_ORT
{
  ::CORBA::TypeCode_ptr _tc_ObjectReferenceTemplate =
    &_tc_TAO_tc_TAO_Default_ORT_ObjectReferenceTemplate;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_cs.cpp:94

void
TAO::Value_Traits<TAO_Default_ORT::ObjectReferenceTemplate>::tao_add_ref (
    TAO_Default_ORT::ObjectReferenceTemplate * p
  )
{
  CORBA::add_ref (p);
}

void
TAO::Value_Traits<TAO_Default_ORT::ObjectReferenceTemplate>::tao_remove_ref (
    TAO_Default_ORT::ObjectReferenceTemplate * p
  )
{
  CORBA::remove_ref (p);
}

TAO_Default_ORT::ObjectReferenceTemplate *
TAO_Default_ORT::ObjectReferenceTemplate::_downcast (CORBA::ValueBase *v)
{
  if (v == 0)
    {
      return 0;
    }
  
  return (ObjectReferenceTemplate *) v->_tao_obv_narrow ((ptrdiff_t) &_downcast);
}

const char *
TAO_Default_ORT::ObjectReferenceTemplate::_tao_obv_repository_id (void) const
{
  return this->_tao_obv_static_repository_id ();
}

void *
#if defined (_MSC_VER)
TAO_Default_ORT::ObjectReferenceTemplate::TAO_Default_ORT_ObjectReferenceTemplate_tao_obv_narrow (ptrdiff_t type_id)
#else
TAO_Default_ORT::ObjectReferenceTemplate::_tao_obv_narrow (ptrdiff_t type_id)
#endif /* _MSC_VER */
{
  if (type_id == (ptrdiff_t) &_downcast)
    {
      return this;
    }
  
  void *rval = 0;
  
  if (rval == 0)
    {
#if defined (_MSC_VER)
      rval = this->PortableInterceptor_ObjectReferenceTemplate_tao_obv_narrow (type_id);
#else
      rval = this->PortableInterceptor::ObjectReferenceTemplate::_tao_obv_narrow (type_id);
#endif /* _MSC_VER */
    }
  
  return rval;
}

#if defined (_MSC_VER)
void *
TAO_Default_ORT::ObjectReferenceTemplate::_tao_obv_narrow (ptrdiff_t type_id)
{
  return this->TAO_Default_ORT_ObjectReferenceTemplate_tao_obv_narrow (type_id);
}
#endif /* _MSC_VER */

void
TAO_Default_ORT::ObjectReferenceTemplate::_tao_any_destructor (void *_tao_void_pointer)
{
  ObjectReferenceTemplate *_tao_tmp_pointer =
    ACE_static_cast (
        ObjectReferenceTemplate *,
        _tao_void_pointer
      );
  CORBA::remove_ref (_tao_tmp_pointer);
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceTemplate::_tao_marshal_v (TAO_OutputCDR & strm)
{
  return this->_tao_marshal__TAO_Default_ORT_ObjectReferenceTemplate (strm);
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal_v (TAO_InputCDR & strm)
{
  return this->_tao_unmarshal__TAO_Default_ORT_ObjectReferenceTemplate (strm);
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal (
    TAO_InputCDR &strm,
    ObjectReferenceTemplate *&new_object
  )
{
  CORBA::ValueBase *base = 0;
  CORBA::ValueFactory_var factory;
  CORBA::Boolean retval =
    CORBA::ValueBase::_tao_unmarshal_pre (
        strm,
        factory.out (),
        base,
        ObjectReferenceTemplate::_tao_obv_static_repository_id ()
      );
  
  if (retval == 0)
    {
      return 0;
    }
  
  if (factory.in () != 0)
    {
      base = factory->create_for_unmarshal ();
      
      if (base == 0)
        {
          return 0;  // %! except.?
        }
      
      retval = base->_tao_unmarshal_v (strm);
      
      if (retval == 0)
        {
          return 0;
        }
    }
  
  // Now base must be null or point to the unmarshaled object.
  // Align the pointer to the right subobject.
  new_object = ObjectReferenceTemplate::_downcast (base);
  return retval;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_obv_cs.cpp:58

OBV_TAO_Default_ORT::ObjectReferenceTemplate::ObjectReferenceTemplate (void)
{}

OBV_TAO_Default_ORT::ObjectReferenceTemplate::~ObjectReferenceTemplate (void)
{}

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_marshal__TAO_Default_ORT_ObjectReferenceTemplate (TAO_OutputCDR &strm)
{
  return _tao_marshal_state (strm);
}

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal__TAO_Default_ORT_ObjectReferenceTemplate (TAO_InputCDR &strm)
{
  return _tao_unmarshal_state (strm);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/any_op_cs.cpp:57

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    TAO_Default_ORT::ObjectReferenceTemplate *_tao_elem
  )
{
  CORBA::add_ref (_tao_elem);
  _tao_any <<= &_tao_elem;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    TAO_Default_ORT::ObjectReferenceTemplate **_tao_elem
  )
{
  TAO::Any_Impl_T<TAO_Default_ORT::ObjectReferenceTemplate>::insert (
      _tao_any,
      TAO_Default_ORT::ObjectReferenceTemplate::_tao_any_destructor,
      TAO_Default_ORT::_tc_ObjectReferenceTemplate,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    TAO_Default_ORT::ObjectReferenceTemplate *&_tao_elem
  )
{
  return
    TAO::Any_Impl_T<TAO_Default_ORT::ObjectReferenceTemplate>::extract (
        _tao_any,
        TAO_Default_ORT::ObjectReferenceTemplate::_tao_any_destructor,
        TAO_Default_ORT::_tc_ObjectReferenceTemplate,
        _tao_elem
      );
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO_Default_ORT::ObjectReferenceTemplate>::to_value (
    CORBA::ValueBase *&_tao_elem
  ) const
{
  CORBA::add_ref (this->value_);
  _tao_elem = this->value_;
  return 1;
}



// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:263

void
CORBA::add_ref (TAO_Default_ORT::ObjectReferenceTemplate * vt)
{
  if (vt != 0)
    {
      vt->_add_ref ();
    }
}

void
CORBA::remove_ref (TAO_Default_ORT::ObjectReferenceTemplate * vt)
{
  if (vt != 0)
    {
      vt->_remove_ref ();
    }
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/cdr_op_cs.cpp:73

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const TAO_Default_ORT::ObjectReferenceTemplate *_tao_valuetype
  )
{
  return
    CORBA::ValueBase::_tao_marshal (
        strm,
        ACE_const_cast (
            TAO_Default_ORT::ObjectReferenceTemplate *,
            _tao_valuetype
          ),
        (ptrdiff_t) &TAO_Default_ORT::ObjectReferenceTemplate::_downcast
      );
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    TAO_Default_ORT::ObjectReferenceTemplate *&_tao_valuetype
  )
{
  return TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal (strm, _tao_valuetype);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/marshal_cs.cpp:44

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_marshal_state (TAO_OutputCDR &)
{
  if (
    1
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal_state (TAO_InputCDR &)
{
  if (
    1
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/root.cpp:1703

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Basic_Impl_T<
        CORBA::SetOverrideType
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::PolicyError
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::InvalidPolicies
      >;

  template class
    TAO::Any_Basic_Impl_T<
        CORBA::TCKind
      >;

  template class
    TAO::Any_Basic_Impl_T<
        CORBA::exception_type
      >;

  template class
    TAO::Any_Basic_Impl_T<
        CORBA::ParameterMode
      >;  
  
  template class
    TAO_Value_Out_T<
        TAO_Default_ORT::ObjectReferenceTemplate,
        TAO::Value_Traits<TAO_Default_ORT::ObjectReferenceTemplate>
      >;

  template class
    TAO::Any_Impl_T<
        TAO_Default_ORT::ObjectReferenceTemplate
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Basic_Impl_T< \
        CORBA::SetOverrideType \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::PolicyError \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::InvalidPolicies \
      >

# pragma instantiate \
    TAO::Any_Basic_Impl_T< \
        CORBA::TCKind \
      >

# pragma instantiate \
    TAO::Any_Basic_Impl_T< \
        CORBA::exception_type \
      >

# pragma instantiate \
    TAO::Any_Basic_Impl_T< \
        CORBA::ParameterMode \
      ># pragma instantiate \
    TAO_Value_Var_T< \
        TAO_Default_ORT::ObjectReferenceTemplate, \
        TAO::Value_Traits<TAO_Default_ORT::ObjectReferenceTemplate> \
      >
  
# pragma instantiate \
    TAO_Value_Out_T< \
        TAO_Default_ORT::ObjectReferenceTemplate, \
        TAO::Value_Traits<TAO_Default_ORT::ObjectReferenceTemplate> \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        TAO_Default_ORT::ObjectReferenceTemplate \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

