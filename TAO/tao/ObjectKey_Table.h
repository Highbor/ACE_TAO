// -*- C++ -*-

//=============================================================================
/**
 *  @file ObjectKey_Table.h
 *
 *  $Id$
 *
 *  @author Balachandran Natarajan <bala@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef TAO_OBJECTKEY_TABLE_H
#define TAO_OBJECTKEY_TABLE_H

#include /**/ "ace/pre.h"
#include "ace/RB_Tree.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Null_Mutex.h"

#include "tao/Object_KeyC.h"

// Forward declarations
class TAO_ORB_Core;

namespace TAO
{

  // Forward declarations within the namespace..
  class Refcounted_ObjectKey;
  class ObjectKey;

  /**
   * @class ObjectKey_Table
   *
   * @brief: Compares the length and then the contents of ObjectKeys.
   *
   * Should have been a specialization of the functor
   * ACE_Less_Than<sequence<CORBA::Octet>>. But that will not work
   * so easily across bunch of stuff. Hence let us put up with this
   * for the time being.
   */
  class TAO_Export Less_Than_ObjectKey
  {
  public:
    int operator () (const TAO::ObjectKey &lhs,
                     const TAO::ObjectKey &rhs) const;
  };

  /**
   * @class ObjectKey_Table
   *
   * @brief Table that maintains the set of ObjectKey's seen by the
   * ORB.
   *
   * The ORB maintains one table for the whole ORB. ObjectKeys
   * generated by the ORB or the ones seen by the ORB from remote
   * ORB's are stored here. The ObjectKeys are stored through a
   * wrapper which encapsulates the refcount on them. This class
   * actually provides the synchronization mechanism for manipulating
   * the reference counts on the object keys provided by the wrapper
   * class.
   *
   * This class does not offer a find () call with a reason. The call
   * to bind () will return a pointer which is expected to be cached
   * by the client/caller and use the pointer in every invocation.
   *
   * @NOTE: This class uses the ACE_RB_Tree to maintain the table of
   * ObjectKeys. The RB_Tree has good insertion and lookup
   * properties. Its Iteration properties are not that good, but we
   * dont need to do much iteration unless we are closing down the
   * table.
   *
   * @NOTE: The reasons to use RB_Tree are its good dynamic
   * properties. We should try to strategize the class to use either a
   * Hash_Map or a RB_Tree based on some runtime option. For that we
   * need an adapter class in ACE, like an ACE_Lock_Adapter class. We
   * will do that if our instrumentation shows the need for it.
   *
   */
  class TAO_Export ObjectKey_Table
  {
  public:
    /// Default Constructor and destructor..
    ObjectKey_Table (void);

    ~ObjectKey_Table (void);

    /// Initialize method that sets up the underlying lock and other
    /// related stuff.
    int init (TAO_ORB_Core *orb);

    /// Iterates and unbinds the contents of the table.
    int destroy (void);

    /// Bind the ObjectKey in the table.
    /**
     * Bind an ObjectKey in the table and return a pointer to the
     * Refcounted_ObjectKey which the client can use. If the ObjectKey
     * is already available in the table, this operation just
     * increments the refcount on the ObjectKey. If the ObjectKey is
     * new it is bounded to the table. Returns a 0 on success and a -1
     * on failure.
     */
    int bind (const ObjectKey &key,
              Refcounted_ObjectKey *&key_new);

    /// Unbind an ObjectKey from the table.
    int unbind (TAO::Refcounted_ObjectKey *&key);

  protected:
    /// Implementation for bind ().
    int bind_i (const ObjectKey &key,
                Refcounted_ObjectKey *&key_new);

    /// Implementation for unbind ().
    int unbind_i (Refcounted_ObjectKey *&key);

  private:

    // Some useful typedefs.
    typedef ACE_RB_Tree<TAO::ObjectKey,
                        TAO::Refcounted_ObjectKey *,
                        TAO::Less_Than_ObjectKey,
                        ACE_Null_Mutex> TABLE;

    /// Lock for the table.
    ACE_Lock *lock_;

    /// Table that contains the data
    TABLE table_;
  };
}

#include /**/ "ace/post.h"

#endif /*TAO_OBJECT_KEY_TABLE_H*/
