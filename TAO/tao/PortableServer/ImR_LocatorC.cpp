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


#include "ImR_LocatorC.h"
#include "tao/Stub.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Object_T.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"
#include "tao/Any_Basic_Impl_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Object_Argument_T.h"
#include "tao/UB_String_Arguments.h"
#include "tao/Typecode.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "ImR_LocatorC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_arg_traits.cpp:59

// Arg traits specializations.
namespace TAO
{
};

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for ImplementationRepository::Locator.

ImplementationRepository::Locator_ptr
TAO::Objref_Traits<ImplementationRepository::Locator>::tao_duplicate (
    ImplementationRepository::Locator_ptr p
  )
{
  return ImplementationRepository::Locator::_duplicate (p);
}

void
TAO::Objref_Traits<ImplementationRepository::Locator>::tao_release (
    ImplementationRepository::Locator_ptr p
  )
{
  CORBA::release (p);
}

ImplementationRepository::Locator_ptr
TAO::Objref_Traits<ImplementationRepository::Locator>::tao_nil (void)
{
  return ImplementationRepository::Locator::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<ImplementationRepository::Locator>::tao_marshal (
    ImplementationRepository::Locator_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*ImplementationRepository__TAO_Locator_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_cs.cpp:78

void ImplementationRepository::Locator::activate_server_in_location (
    const char * server,
    const char * location
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , ImplementationRepository::NotFound
    , ImplementationRepository::CannotActivate
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }
  
  if (this->the_TAO_Locator_Proxy_Broker_ == 0)
    {
      ImplementationRepository_Locator_setup_collocation (
          this->ACE_NESTED_CLASS (CORBA, Object)::_is_collocated ()
        );
    }
  
  TAO::Arg_Traits<void>::ret_val _tao_retval;
  TAO::Arg_Traits<CORBA::Char *>::in_arg_val _tao_server (server);
  TAO::Arg_Traits<ImplementationRepository::Address>::in_arg_val _tao_location (location);
  
  TAO::Argument *_tao_signature [] =
    {
      &_tao_retval,
      &_tao_server,
      &_tao_location
    };
  
  static TAO_Exception_Data
  _tao_ImplementationRepository_Locator_activate_server_in_location_exceptiondata [] = 
    {
      {
        "IDL:ImplementationRepository/NotFound:1.0",
        ImplementationRepository::NotFound::_alloc,
        ImplementationRepository::_tc_NotFound
      },
      
      {
        "IDL:ImplementationRepository/CannotActivate:1.0",
        ImplementationRepository::CannotActivate::_alloc,
        ImplementationRepository::_tc_CannotActivate
      }
    };
  
  TAO::Invocation_Adapter _tao_call (
      this,
      _tao_signature,
      3,
      "activate_server_in_location",
      27,
      this->the_TAO_Locator_Proxy_Broker_
    );
  
  _tao_call.invoke (
      _tao_ImplementationRepository_Locator_activate_server_in_location_exceptiondata,
      2
      ACE_ENV_ARG_PARAMETER
    );
  ACE_CHECK;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_cs.cpp:78

void ImplementationRepository::Locator::remove_server_in_location (
    const char * server,
    const char * location
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , ImplementationRepository::NotFound
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }
  
  if (this->the_TAO_Locator_Proxy_Broker_ == 0)
    {
      ImplementationRepository_Locator_setup_collocation (
          this->ACE_NESTED_CLASS (CORBA, Object)::_is_collocated ()
        );
    }
  
  TAO::Arg_Traits<void>::ret_val _tao_retval;
  TAO::Arg_Traits<CORBA::Char *>::in_arg_val _tao_server (server);
  TAO::Arg_Traits<ImplementationRepository::Address>::in_arg_val _tao_location (location);
  
  TAO::Argument *_tao_signature [] =
    {
      &_tao_retval,
      &_tao_server,
      &_tao_location
    };
  
  static TAO_Exception_Data
  _tao_ImplementationRepository_Locator_remove_server_in_location_exceptiondata [] = 
    {
      {
        "IDL:ImplementationRepository/NotFound:1.0",
        ImplementationRepository::NotFound::_alloc,
        ImplementationRepository::_tc_NotFound
      }
    };
  
  TAO::Invocation_Adapter _tao_call (
      this,
      _tao_signature,
      3,
      "remove_server_in_location",
      25,
      this->the_TAO_Locator_Proxy_Broker_
    );
  
  _tao_call.invoke (
      _tao_ImplementationRepository_Locator_remove_server_in_location_exceptiondata,
      1
      ACE_ENV_ARG_PARAMETER
    );
  ACE_CHECK;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_cs.cpp:78

void ImplementationRepository::Locator::shutdown_server_in_location (
    const char * server,
    const char * location
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , ImplementationRepository::NotFound
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }
  
  if (this->the_TAO_Locator_Proxy_Broker_ == 0)
    {
      ImplementationRepository_Locator_setup_collocation (
          this->ACE_NESTED_CLASS (CORBA, Object)::_is_collocated ()
        );
    }
  
  TAO::Arg_Traits<void>::ret_val _tao_retval;
  TAO::Arg_Traits<CORBA::Char *>::in_arg_val _tao_server (server);
  TAO::Arg_Traits<ImplementationRepository::Address>::in_arg_val _tao_location (location);
  
  TAO::Argument *_tao_signature [] =
    {
      &_tao_retval,
      &_tao_server,
      &_tao_location
    };
  
  static TAO_Exception_Data
  _tao_ImplementationRepository_Locator_shutdown_server_in_location_exceptiondata [] = 
    {
      {
        "IDL:ImplementationRepository/NotFound:1.0",
        ImplementationRepository::NotFound::_alloc,
        ImplementationRepository::_tc_NotFound
      }
    };
  
  TAO::Invocation_Adapter _tao_call (
      this,
      _tao_signature,
      3,
      "shutdown_server_in_location",
      27,
      this->the_TAO_Locator_Proxy_Broker_
    );
  
  _tao_call.invoke (
      _tao_ImplementationRepository_Locator_shutdown_server_in_location_exceptiondata,
      1
      ACE_ENV_ARG_PARAMETER
    );
  ACE_CHECK;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_cs.cpp:78

void ImplementationRepository::Locator::server_is_shutting_down_in_location (
    const char * server,
    const char * location
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , ImplementationRepository::NotFound
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }
  
  if (this->the_TAO_Locator_Proxy_Broker_ == 0)
    {
      ImplementationRepository_Locator_setup_collocation (
          this->ACE_NESTED_CLASS (CORBA, Object)::_is_collocated ()
        );
    }
  
  TAO::Arg_Traits<void>::ret_val _tao_retval;
  TAO::Arg_Traits<CORBA::Char *>::in_arg_val _tao_server (server);
  TAO::Arg_Traits<ImplementationRepository::Address>::in_arg_val _tao_location (location);
  
  TAO::Argument *_tao_signature [] =
    {
      &_tao_retval,
      &_tao_server,
      &_tao_location
    };
  
  static TAO_Exception_Data
  _tao_ImplementationRepository_Locator_server_is_shutting_down_in_location_exceptiondata [] = 
    {
      {
        "IDL:ImplementationRepository/NotFound:1.0",
        ImplementationRepository::NotFound::_alloc,
        ImplementationRepository::_tc_NotFound
      }
    };
  
  TAO::Invocation_Adapter _tao_call (
      this,
      _tao_signature,
      3,
      "server_is_shutting_down_in_location",
      35,
      this->the_TAO_Locator_Proxy_Broker_
    );
  
  _tao_call.invoke (
      _tao_ImplementationRepository_Locator_server_is_shutting_down_in_location_exceptiondata,
      1
      ACE_ENV_ARG_PARAMETER
    );
  ACE_CHECK;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_cs.cpp:78

CORBA::ULong ImplementationRepository::Locator::register_activator (
    const char * location,
    CORBA::Object_ptr object_ref
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , ImplementationRepository::AlreadyRegistered
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }
  
  if (this->the_TAO_Locator_Proxy_Broker_ == 0)
    {
      ImplementationRepository_Locator_setup_collocation (
          this->ACE_NESTED_CLASS (CORBA, Object)::_is_collocated ()
        );
    }
  
  TAO::Arg_Traits<CORBA::ULong>::ret_val _tao_retval;
  TAO::Arg_Traits<CORBA::Char *>::in_arg_val _tao_location (location);
  TAO::Arg_Traits<CORBA::Object>::in_arg_val _tao_object_ref (object_ref);
  
  TAO::Argument *_tao_signature [] =
    {
      &_tao_retval,
      &_tao_location,
      &_tao_object_ref
    };
  
  static TAO_Exception_Data
  _tao_ImplementationRepository_Locator_register_activator_exceptiondata [] = 
    {
      {
        "IDL:ImplementationRepository/AlreadyRegistered:1.0",
        ImplementationRepository::AlreadyRegistered::_alloc,
        ImplementationRepository::_tc_AlreadyRegistered
      }
    };
  
  TAO::Invocation_Adapter _tao_call (
      this,
      _tao_signature,
      3,
      "register_activator",
      18,
      this->the_TAO_Locator_Proxy_Broker_
    );
  
  _tao_call.invoke (
      _tao_ImplementationRepository_Locator_register_activator_exceptiondata,
      1
      ACE_ENV_ARG_PARAMETER
    );
  ACE_CHECK_RETURN (_tao_retval.excp ());
  
  return _tao_retval.retn ();
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_cs.cpp:78

CORBA::ULong ImplementationRepository::Locator::unregister_activator (
    const char * location,
    CORBA::Object_ptr object_ref
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , ImplementationRepository::NotFound
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }
  
  if (this->the_TAO_Locator_Proxy_Broker_ == 0)
    {
      ImplementationRepository_Locator_setup_collocation (
          this->ACE_NESTED_CLASS (CORBA, Object)::_is_collocated ()
        );
    }
  
  TAO::Arg_Traits<CORBA::ULong>::ret_val _tao_retval;
  TAO::Arg_Traits<CORBA::Char *>::in_arg_val _tao_location (location);
  TAO::Arg_Traits<CORBA::Object>::in_arg_val _tao_object_ref (object_ref);
  
  TAO::Argument *_tao_signature [] =
    {
      &_tao_retval,
      &_tao_location,
      &_tao_object_ref
    };
  
  static TAO_Exception_Data
  _tao_ImplementationRepository_Locator_unregister_activator_exceptiondata [] = 
    {
      {
        "IDL:ImplementationRepository/NotFound:1.0",
        ImplementationRepository::NotFound::_alloc,
        ImplementationRepository::_tc_NotFound
      }
    };
  
  TAO::Invocation_Adapter _tao_call (
      this,
      _tao_signature,
      3,
      "unregister_activator",
      20,
      this->the_TAO_Locator_Proxy_Broker_
    );
  
  _tao_call.invoke (
      _tao_ImplementationRepository_Locator_unregister_activator_exceptiondata,
      1
      ACE_ENV_ARG_PARAMETER
    );
  ACE_CHECK_RETURN (_tao_retval.excp ());
  
  return _tao_retval.retn ();
}

ImplementationRepository::Locator::Locator (int collocated)
 : the_TAO_Locator_Proxy_Broker_ (0)
{
  this->ImplementationRepository_Locator_setup_collocation (collocated);
}

void
ImplementationRepository::Locator::ImplementationRepository_Locator_setup_collocation (int collocated)
{
  if (collocated)
    {
      this->the_TAO_Locator_Proxy_Broker_ =
        ::ImplementationRepository__TAO_Locator_Proxy_Broker_Factory_function_pointer (this);
    }
  
  this->ImplementationRepository_Administration_setup_collocation (collocated);
}

ImplementationRepository::Locator::~Locator (void)
{}

void 
ImplementationRepository::Locator::_tao_any_destructor (void *_tao_void_pointer)
{
  Locator *_tao_tmp_pointer =
    ACE_static_cast (Locator *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

ImplementationRepository::Locator_ptr
ImplementationRepository::Locator::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL
  )
{
  return
    TAO::Narrow_Utils<Locator>::narrow (
        _tao_objref,
        "IDL:ImplementationRepository/Locator:1.0",
        ImplementationRepository__TAO_Locator_Proxy_Broker_Factory_function_pointer
        ACE_ENV_ARG_PARAMETER
      );
}

ImplementationRepository::Locator_ptr
ImplementationRepository::Locator::_duplicate (Locator_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
ImplementationRepository::Locator::_is_a (
    const char *value
    ACE_ENV_ARG_DECL
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:ImplementationRepository/Administration:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:ImplementationRepository/Locator:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return this->ACE_NESTED_CLASS (CORBA, Object)::_is_a (
          value
          ACE_ENV_ARG_PARAMETER
        );
    }
}

const char* ImplementationRepository::Locator::_interface_repository_id (void) const
{
  return "IDL:ImplementationRepository/Locator:1.0";
}

CORBA::Boolean
ImplementationRepository::Locator::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_ImplementationRepository_Locator[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  41,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x496d706c), 
  ACE_NTOHL (0x656d656e), 
  ACE_NTOHL (0x74617469), 
  ACE_NTOHL (0x6f6e5265), 
  ACE_NTOHL (0x706f7369), 
  ACE_NTOHL (0x746f7279), 
  ACE_NTOHL (0x2f4c6f63), 
  ACE_NTOHL (0x61746f72), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0x0),  // repository ID = IDL:ImplementationRepository/Locator:1.0
    8,
  ACE_NTOHL (0x4c6f6361), 
  ACE_NTOHL (0x746f7200),  // name = Locator
  };

static CORBA::TypeCode _tc_TAO_tc_ImplementationRepository_Locator (
    CORBA::tk_objref,
    sizeof (_oc_ImplementationRepository_Locator),
    (char *) &_oc_ImplementationRepository_Locator,
    0,
    sizeof (ImplementationRepository::Locator)
  );

namespace ImplementationRepository
{
  ::CORBA::TypeCode_ptr _tc_Locator =
    &_tc_TAO_tc_ImplementationRepository_Locator;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_cs.cpp:50

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::Locator_ptr _tao_elem
  )
{
  ImplementationRepository::Locator_ptr _tao_objptr =
    ImplementationRepository::Locator::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::Locator_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<ImplementationRepository::Locator>::insert (
      _tao_any,
      ImplementationRepository::Locator::_tao_any_destructor,
      ImplementationRepository::_tc_Locator,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    ImplementationRepository::Locator_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<ImplementationRepository::Locator>::extract (
        _tao_any,
        ImplementationRepository::Locator::_tao_any_destructor,
        ImplementationRepository::_tc_Locator,
        _tao_elem
      );
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<ImplementationRepository::Locator>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_cs.cpp:63

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const ImplementationRepository::Locator_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    ImplementationRepository::Locator_ptr &_tao_objref
  )
{
  CORBA::Object_var obj;
  
  if ((strm >> obj.inout ()) == 0)
    {
      return 0;
    }
  
  typedef ::ImplementationRepository::Locator RHS_SCOPED_NAME;
  
  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        ImplementationRepository__TAO_Locator_Proxy_Broker_Factory_function_pointer
      );
    
  return 1;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/root.cpp:1703

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        ImplementationRepository::AlreadyRegistered
      >;

  template class
    TAO::Any_Dual_Impl_T<
        ImplementationRepository::CannotActivate
      >;

  template class
    TAO::Any_Dual_Impl_T<
        ImplementationRepository::NotFound
      >;

  template class
    TAO::Any_Basic_Impl_T<
        ImplementationRepository::ActivationMode
      >;

  template class
    TAO_Objref_Var_T<
        ImplementationRepository::Locator,
        TAO::Objref_Traits<ImplementationRepository::Locator>
      >;
  
  template class
    TAO_Objref_Out_T<
        ImplementationRepository::Locator,
        TAO::Objref_Traits<ImplementationRepository::Locator>
      >;

  template class
    TAO::Any_Impl_T<
        ImplementationRepository::Locator
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        ImplementationRepository::AlreadyRegistered \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        ImplementationRepository::CannotActivate \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        ImplementationRepository::NotFound \
      >

# pragma instantiate \
    TAO::Any_Basic_Impl_T< \
        ImplementationRepository::ActivationMode \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        ImplementationRepository::Locator, \
        TAO::Objref_Traits<ImplementationRepository::Locator> \
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        ImplementationRepository::Locator, \
        TAO::Objref_Traits<ImplementationRepository::Locator> \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        ImplementationRepository::Locator \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

