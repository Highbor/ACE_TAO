// $Id$

#include "ace/Get_Opt.h"
#include "ace/Array_Base.h"
#include "ace/Task.h"
#include "tao/ORB_Core.h"
#include "tao/RTCORBA/Thread_Pool.h"
#include "testS.h"
#include "tao/RTPortableServer/RTPortableServer.h"
#include "../check_supported_priorities.cpp"

ACE_RCSID(Collocations, Collocations, "$Id$")

RTCORBA::Priority default_thread_priority;

class test_i;

struct Test_Object_And_Servant
{
  test_var object_;
  test_i *servant_;
};

typedef ACE_Array_Base<Test_Object_And_Servant> Tests;

void
setup_test_parameters (Test_Object_And_Servant *test,
                       RTCORBA::Current_ptr current,
                       CORBA::ORB_ptr orb
                       ACE_ENV_ARG_DECL);
class test_i :
  public POA_test
{
public:
  test_i (CORBA::ORB_ptr orb,
          PortableServer::POA_ptr poa,
          Tests &tests
          ACE_ENV_ARG_DECL);

  void start (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  void method (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  PortableServer::POA_ptr _default_POA (ACE_ENV_SINGLE_ARG_DECL);

  int client_propagated (void);

  void client_propagated (int);

  int server_declared (void);

  void server_declared (int);

  RTCORBA::Priority server_priority (void);

  void server_priority (RTCORBA::Priority);

  int in_lane (void);

  void in_lane (int);

  int serviced_by_rt_tp (void);

  void serviced_by_rt_tp (int);

  void thread_info (const char *method_name);

  void invocation_pool_and_lane (CORBA::ULong pool,
                                 CORBA::ULong lane);

  void invocation_pool (CORBA::ULong pool);

  void invocation_lane (CORBA::ULong lane);

  RTCORBA::Priority invocation_priority (void);

  void invocation_priority (RTCORBA::Priority);

private:

  CORBA::ORB_var orb_;
  PortableServer::POA_var poa_;
  Tests &tests_;

  int client_propagated_;
  int server_declared_;
  RTCORBA::Priority server_priority_;
  int in_lane_;
  int serviced_by_rt_tp_;

  CORBA::ULong pool_;
  CORBA::ULong lane_;
  RTCORBA::Priority invocation_priority_;

  RTCORBA::Current_var current_;
};

test_i::test_i (CORBA::ORB_ptr orb,
                PortableServer::POA_ptr poa,
                Tests &tests
                ACE_ENV_ARG_DECL)
  : orb_ (CORBA::ORB::_duplicate (orb)),
    poa_ (PortableServer::POA::_duplicate (poa)),
    tests_ (tests),
    client_propagated_ (0),
    server_declared_ (0),
    server_priority_ (0),
    serviced_by_rt_tp_ (1),
    invocation_priority_ (0)
{
  CORBA::Object_var object =
    this->orb_->resolve_initial_references ("RTCurrent"
                                            ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->current_ =
    RTCORBA::Current::_narrow (object.in ()
                               ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

int
test_i::client_propagated (void)
{
  return this->client_propagated_;
}

void
test_i::client_propagated (int client_propagated)
{
  this->client_propagated_ = client_propagated;
}

int
test_i::server_declared (void)
{
  return this->server_declared_;
}

void
test_i::server_declared (int server_declared)
{
  this->server_declared_ = server_declared;
}

RTCORBA::Priority
test_i::server_priority (void)
{
  return this->server_priority_;
}

void
test_i::server_priority (RTCORBA::Priority server_priority)
{
  this->server_priority_ = server_priority;
}

int
test_i::in_lane (void)
{
  return this->in_lane_;
}

void
test_i::in_lane (int in_lane)
{
  this->in_lane_ = in_lane;
}

int
test_i::serviced_by_rt_tp (void)
{
  return this->serviced_by_rt_tp_;
}

void
test_i::serviced_by_rt_tp (int serviced_by_rt_tp)
{
  this->serviced_by_rt_tp_ = serviced_by_rt_tp;
}

void
test_i::invocation_pool_and_lane (CORBA::ULong pool,
                                  CORBA::ULong lane)
{
  this->pool_ = pool;
  this->lane_ = lane;
}

void
test_i::invocation_pool (CORBA::ULong pool)
{
  this->pool_ = pool;
}

void
test_i::invocation_lane (CORBA::ULong lane)
{
  this->lane_ = lane;
}

RTCORBA::Priority
test_i::invocation_priority (void)
{
  return this->invocation_priority_;
}

void
test_i::invocation_priority (RTCORBA::Priority invocation_priority)
{
  this->invocation_priority_ = invocation_priority;
}

void
test_i::start (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG,
              "\n"));

  this->thread_info ("test_i::start");

  ACE_DEBUG ((LM_DEBUG,
              "\n"));

  Tests::ITERATOR iterator (this->tests_);
  while (!iterator.done ())
    {
      Test_Object_And_Servant *test = 0;
      iterator.next (test);

      setup_test_parameters (test,
                             this->current_.in (),
                             this->orb_.in ()
                             ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      test->object_->method (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      CORBA::String_var ior =
        this->orb_->object_to_string (test->object_.in ()
                                      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      CORBA::Object_var object =
        this->orb_->string_to_object (ior.in ()
                                      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      test_var test_from_string =
        test::_narrow (object.in ()
                       ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      test_from_string->method (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      iterator.advance ();
    }
}

void
test_i::thread_info (const char *method_name)
{
  // Get the ORB_Core's TSS resources.
  TAO_ORB_Core_TSS_Resources *tss =
    this->orb_->orb_core ()->get_tss_resources ();

  /// Get the lane attribute in TSS.
    TAO_Thread_Lane *lane =
      (TAO_Thread_Lane *) tss->lane_;

    if (lane)
      {
        ACE_DEBUG ((LM_DEBUG,
                    "(%t) %s (pool = %d; lane = %d); priority = %d (should be %d)\n",
                    method_name,
                    lane->pool ().id (),
                    lane->id (),
                    this->current_->the_priority (),
                    this->invocation_priority ()));

        ACE_ASSERT (this->pool_ == lane->pool ().id ());
        ACE_ASSERT (this->lane_ == lane->id ());
        ACE_ASSERT (this->current_->the_priority () ==
                    this->invocation_priority ());
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG,
                    "(%t) %s (default thread pool); priority = %d (should be %d)\n",
                    method_name,
                    this->current_->the_priority (),
                    this->invocation_priority ()));

        ACE_ASSERT (this->pool_ == 0);
        ACE_ASSERT (this->lane_ == 0);
        ACE_ASSERT (this->current_->the_priority () ==
                    this->invocation_priority ());
      }
}

void
test_i::method (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->thread_info ("test_i::method");
}

PortableServer::POA_ptr
test_i::_default_POA (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
{
  return PortableServer::POA::_duplicate (this->poa_.in ());
}

void
setup_test_parameters (Test_Object_And_Servant *test,
                       RTCORBA::Current_ptr current,
                       CORBA::ORB_ptr orb
                       ACE_ENV_ARG_DECL)
{
  CORBA::Short current_thread_priority =
    current->the_priority (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  if (!test->servant_->serviced_by_rt_tp () ||
      test->servant_->client_propagated ())
    {
      test->servant_->invocation_priority (current_thread_priority);
    }
  else if (test->servant_->server_declared ())
    {
      test->servant_->invocation_priority (test->servant_->server_priority ());
    }
  else
    {
      test->servant_->invocation_priority (default_thread_priority);
    }

  if (test->servant_->client_propagated () &&
      test->servant_->in_lane ())
    {
      if (current_thread_priority == default_thread_priority)
        test->servant_->invocation_lane (0);
      else
        test->servant_->invocation_lane (1);
    }

  if (!test->servant_->serviced_by_rt_tp ())
    {
      // Get the ORB_Core's TSS resources.
      TAO_ORB_Core_TSS_Resources *tss =
        orb->orb_core ()->get_tss_resources ();

      /// Get the lane attribute in TSS.
        TAO_Thread_Lane *lane =
          (TAO_Thread_Lane *) tss->lane_;

        if (lane)
          {
            test->servant_->invocation_pool_and_lane (lane->pool ().id (),
                                                      lane->id ());
          }
        else
          {
            test->servant_->invocation_pool_and_lane (0, 0);
          }
    }
}

class Server
{
public:
  Server (CORBA::ORB_ptr orb
          ACE_ENV_ARG_DECL);

  void create_servant_in_root_poa (ACE_ENV_SINGLE_ARG_DECL);
  void create_poa_and_servant_with_tp_policy (const char *poa_name,
                                              int set_priority_model,
                                              RTCORBA::PriorityModel priority_model
                                              ACE_ENV_ARG_DECL);
  void create_poa_and_servant_with_tp_with_lanes_policy (const char *poa_name,
                                                         RTCORBA::PriorityModel priority_model
                                                         ACE_ENV_ARG_DECL);
  void test (ACE_ENV_SINGLE_ARG_DECL);
  void start_testing (ACE_ENV_SINGLE_ARG_DECL);
  void shutdown (ACE_ENV_SINGLE_ARG_DECL);

  CORBA::ORB_var orb_;
  RTCORBA::RTORB_var rt_orb_;
  PortableServer::POA_var root_poa_;
  PortableServer::POAManager_var poa_manager_;
  RTCORBA::Current_var current_;

  Tests tests_;

  CORBA::ULong stacksize_;
  CORBA::ULong static_threads_;
  CORBA::ULong dynamic_threads_;
  CORBA::Boolean allow_request_buffering_;
  CORBA::Boolean allow_borrowing_;
  CORBA::ULong max_buffered_requests_;
  CORBA::ULong max_request_buffer_size_;
};

Server::Server (CORBA::ORB_ptr orb
                ACE_ENV_ARG_DECL)
  : orb_ (CORBA::ORB::_duplicate (orb)),
    stacksize_ (0),
    static_threads_ (1),
    dynamic_threads_ (0),
    allow_request_buffering_ (0),
    allow_borrowing_ (0),
    max_buffered_requests_ (0),
    max_request_buffer_size_ (0)
{
  CORBA::Object_var object =
    this->orb_->resolve_initial_references ("RTORB"
                                            ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->rt_orb_ =
    RTCORBA::RTORB::_narrow (object.in ()
                             ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  object =
    this->orb_->resolve_initial_references ("RTCurrent"
                                            ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->current_ =
    RTCORBA::Current::_narrow (object.in ()
                               ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  default_thread_priority =
    this->current_->the_priority (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  object =
    this->orb_->resolve_initial_references ("RootPOA"
                                            ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->root_poa_ =
    PortableServer::POA::_narrow (object.in ()
                                  ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->poa_manager_ =
    this->root_poa_->the_POAManager (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  this->poa_manager_->activate (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
}

void
Server::create_servant_in_root_poa (ACE_ENV_SINGLE_ARG_DECL)
{
  test_i *servant = 0;
  ACE_NEW_THROW_EX (servant,
                    test_i (this->orb_.in (),
                            this->root_poa_.in (),
                            this->tests_
                            ACE_ENV_ARG_PARAMETER),
                    CORBA::NO_MEMORY ());
  ACE_CHECK;

  servant->invocation_pool_and_lane (0, 0);
  servant->in_lane (0);
  servant->serviced_by_rt_tp (0);

  PortableServer::ServantBase_var safe_servant (servant);

  this->tests_.size (this->tests_.size () + 1);
  this->tests_[this->tests_.size () - 1].servant_ =
    servant;
  this->tests_[this->tests_.size () - 1].object_ =
    servant->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
}

void
Server::create_poa_and_servant_with_tp_policy (const char *poa_name,
                                               int set_priority_model,
                                               RTCORBA::PriorityModel priority_model
                                               ACE_ENV_ARG_DECL)
{
  RTCORBA::ThreadpoolId threadpool_id =
    this->rt_orb_->create_threadpool (this->stacksize_,
                                      this->static_threads_,
                                      this->dynamic_threads_,
                                      default_thread_priority,
                                      this->allow_request_buffering_,
                                      this->max_buffered_requests_,
                                      this->max_request_buffer_size_
                                      ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::Policy_var threadpool_policy =
    this->rt_orb_->create_threadpool_policy (threadpool_id
                                             ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::Policy_var priority_model_policy =
    this->rt_orb_->create_priority_model_policy (priority_model,
                                                 default_thread_priority
                                                 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::PolicyList policies;

  policies.length (policies.length () + 1);
  policies[policies.length () - 1] =
    threadpool_policy;

  if (set_priority_model)
    {
      policies.length (policies.length () + 1);
      policies[policies.length () - 1] =
        priority_model_policy;
    }

  PortableServer::POA_var poa =
    this->root_poa_->create_POA (poa_name,
                                 this->poa_manager_.in (),
                                 policies
                                 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  RTPortableServer::POA_var rt_poa =
    RTPortableServer::POA::_narrow (poa.in ()
                                    ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  test_i *servant1 = 0;
  ACE_NEW_THROW_EX (servant1,
                    test_i (this->orb_.in (),
                            poa.in (),
                            this->tests_
                            ACE_ENV_ARG_PARAMETER),
                    CORBA::NO_MEMORY ());
  ACE_CHECK;

  servant1->in_lane (0);

  PortableServer::ObjectId_var id1;

  if (set_priority_model)
    {
      if (priority_model == RTCORBA::CLIENT_PROPAGATED)
        {
          servant1->invocation_pool_and_lane (1, 0);
          servant1->client_propagated (1);

          id1 =
            rt_poa->activate_object (servant1
                                     ACE_ENV_ARG_PARAMETER);
          ACE_CHECK;
        }
      else
        {
          test_i *servant2 = 0;

          ACE_NEW_THROW_EX (servant2,
                            test_i (this->orb_.in (),
                                    poa.in (),
                                    this->tests_
                                    ACE_ENV_ARG_PARAMETER),
                            CORBA::NO_MEMORY ());
          ACE_CHECK;

          servant2->in_lane (0);

          PortableServer::ServantBase_var safe_servant2 (servant2);

          PortableServer::ObjectId_var id2;

          servant1->invocation_pool_and_lane (2, 0);
          servant2->invocation_pool_and_lane (2, 0);
          servant1->server_declared (1);
          servant2->server_declared (1);
          servant1->server_priority (default_thread_priority + 1);
          servant2->server_priority (default_thread_priority);

          id1 =
            rt_poa->activate_object_with_priority (servant1,
                                                   default_thread_priority + 1
                                                   ACE_ENV_ARG_PARAMETER);
          ACE_CHECK;

          id2 =
            rt_poa->activate_object_with_priority (servant2,
                                                   default_thread_priority
                                                   ACE_ENV_ARG_PARAMETER);
          ACE_CHECK;

          CORBA::Object_var object2 =
            poa->id_to_reference (id2.in ()
                                  ACE_ENV_ARG_PARAMETER);
          ACE_CHECK;

          this->tests_.size (this->tests_.size () + 1);
          this->tests_[this->tests_.size () - 1].object_ =
            test::_narrow (object2.in ()
                           ACE_ENV_ARG_PARAMETER);
          this->tests_[this->tests_.size () - 1].servant_ =
            servant2;
          ACE_CHECK;
        }
    }
  else
    {
      servant1->invocation_pool_and_lane (3, 0);

      id1 =
        rt_poa->activate_object (servant1
                                 ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }

  PortableServer::ServantBase_var safe_servant (servant1);

  CORBA::Object_var object1 =
    poa->id_to_reference (id1.in ()
                          ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->tests_.size (this->tests_.size () + 1);
  this->tests_[this->tests_.size () - 1].object_ =
    test::_narrow (object1.in ()
                   ACE_ENV_ARG_PARAMETER);
  this->tests_[this->tests_.size () - 1].servant_ =
    servant1;
  ACE_CHECK;
}

void
Server::create_poa_and_servant_with_tp_with_lanes_policy (const char *poa_name,
                                                          RTCORBA::PriorityModel priority_model
                                                          ACE_ENV_ARG_DECL)
{
  RTCORBA::ThreadpoolLanes lanes (2);
  lanes.length (2);

  lanes[0].lane_priority = default_thread_priority;
  lanes[0].static_threads = this->static_threads_;
  lanes[0].dynamic_threads = this->dynamic_threads_;

  lanes[1].lane_priority = default_thread_priority + 1;
  lanes[1].static_threads = this->static_threads_;
  lanes[1].dynamic_threads = this->dynamic_threads_;

  RTCORBA::ThreadpoolId threadpool_id =
    this->rt_orb_->create_threadpool_with_lanes (this->stacksize_,
                                                 lanes,
                                                 this->allow_borrowing_,
                                                 this->allow_request_buffering_,
                                                 this->max_buffered_requests_,
                                                 this->max_request_buffer_size_
                                                 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::Policy_var threadpool_policy =
    this->rt_orb_->create_threadpool_policy (threadpool_id
                                             ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::Policy_var priority_model_policy =
    this->rt_orb_->create_priority_model_policy (priority_model,
                                                 default_thread_priority
                                                 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::PolicyList policies;

  policies.length (policies.length () + 1);
  policies[policies.length () - 1] =
    threadpool_policy;

  policies.length (policies.length () + 1);
  policies[policies.length () - 1] =
    priority_model_policy;

  PortableServer::POA_var poa =
    this->root_poa_->create_POA (poa_name,
                                 this->poa_manager_.in (),
                                 policies
                                 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  RTPortableServer::POA_var rt_poa =
    RTPortableServer::POA::_narrow (poa.in ()
                                    ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  test_i *servant1 = 0;
  ACE_NEW_THROW_EX (servant1,
                    test_i (this->orb_.in (),
                            poa.in (),
                            this->tests_
                            ACE_ENV_ARG_PARAMETER),
                    CORBA::NO_MEMORY ());
  ACE_CHECK;

  servant1->in_lane (1);

  PortableServer::ServantBase_var safe_servant1 (servant1);

  PortableServer::ObjectId_var id1;

  if (priority_model == RTCORBA::CLIENT_PROPAGATED)
    {
      servant1->invocation_pool (4);
      servant1->client_propagated (1);

      id1 =
        rt_poa->activate_object (servant1
                                 ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      test_i *servant2 = 0;

      ACE_NEW_THROW_EX (servant2,
                        test_i (this->orb_.in (),
                                poa.in (),
                                this->tests_
                                ACE_ENV_ARG_PARAMETER),
                        CORBA::NO_MEMORY ());
      ACE_CHECK;

      servant2->in_lane (1);

      PortableServer::ServantBase_var safe_servant2 (servant2);

      PortableServer::ObjectId_var id2;

      servant1->invocation_pool_and_lane (5, 1);
      servant2->invocation_pool_and_lane (5, 0);
      servant1->server_declared (1);
      servant2->server_declared (1);
      servant1->server_priority (default_thread_priority + 1);
      servant2->server_priority (default_thread_priority);

      id1 =
        rt_poa->activate_object_with_priority (servant1,
                                               default_thread_priority + 1
                                               ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      id2 =
        rt_poa->activate_object_with_priority (servant2,
                                               default_thread_priority
                                               ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      CORBA::Object_var object2 =
        poa->id_to_reference (id2.in ()
                              ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->tests_.size (this->tests_.size () + 1);
      this->tests_[this->tests_.size () - 1].object_ =
        test::_narrow (object2.in ()
                       ACE_ENV_ARG_PARAMETER);
      this->tests_[this->tests_.size () - 1].servant_ =
        servant2;
      ACE_CHECK;
    }

  CORBA::Object_var object1 =
    poa->id_to_reference (id1.in ()
                          ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->tests_.size (this->tests_.size () + 1);
  this->tests_[this->tests_.size () - 1].object_ =
    test::_narrow (object1.in ()
                   ACE_ENV_ARG_PARAMETER);
  this->tests_[this->tests_.size () - 1].servant_ =
    servant1;
  ACE_CHECK;
}

void
Server::start_testing (ACE_ENV_SINGLE_ARG_DECL)
{
  Tests::ITERATOR iterator (this->tests_);
  while (!iterator.done ())
    {
      Test_Object_And_Servant *test = 0;
      iterator.next (test);

      setup_test_parameters (test,
                             this->current_.in (),
                             this->orb_.in ()
                             ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      test->object_->start (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      iterator.advance ();
    }
}

void
Server::test (ACE_ENV_SINGLE_ARG_DECL)
{
  this->start_testing (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  ACE_DEBUG ((LM_DEBUG,
              "\n\n*** Changing priority to be higher ***\n\n"));

  this->current_->the_priority (default_thread_priority + 1
                                ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->start_testing (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
}

void
Server::shutdown (ACE_ENV_SINGLE_ARG_DECL)
{
  this->orb_->shutdown (1 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->orb_->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
}

class Task : public ACE_Task_Base
{
public:

  Task (ACE_Thread_Manager &thread_manager,
        CORBA::ORB_ptr orb);

  int svc (void);

  CORBA::ORB_var orb_;

};

Task::Task (ACE_Thread_Manager &thread_manager,
            CORBA::ORB_ptr orb)
  : ACE_Task_Base (&thread_manager),
    orb_ (CORBA::ORB::_duplicate (orb))
{
}

int
Task::svc (void)
{
  ACE_TRY_NEW_ENV
    {
      Server server (this->orb_.in ()
                     ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      server.create_servant_in_root_poa (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      server.create_poa_and_servant_with_tp_policy ("tp_client_propagated_poa",
                                                    1,
                                                    RTCORBA::CLIENT_PROPAGATED
                                                    ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      server.create_poa_and_servant_with_tp_policy ("tp_server_declared_poa",
                                                    1,
                                                    RTCORBA::SERVER_DECLARED
                                                    ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      server.create_poa_and_servant_with_tp_policy ("tp_no_priority_model_poa",
                                                    0,
                                                    RTCORBA::CLIENT_PROPAGATED
                                                    ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      server.create_poa_and_servant_with_tp_with_lanes_policy ("tp_with_lanes_client_propagated_poa",
                                                               RTCORBA::CLIENT_PROPAGATED
                                                               ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      server.create_poa_and_servant_with_tp_with_lanes_policy ("tp_with_lanes_server_declared_poa",
                                                               RTCORBA::SERVER_DECLARED
                                                               ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      server.test (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      server.shutdown (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Exception caught:");
      return -1;
    }
  ACE_ENDTRY;

  return 0;
}

int
main (int argc, char *argv[])
{
  ACE_TRY_NEW_ENV
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc,
                         argv,
                         ""
                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Make sure we can support multiple priorities that are
      // required for this test.
      if (!check_supported_priorities (orb.in ()))
        return 2;

      // Thread Manager for managing task.
      ACE_Thread_Manager thread_manager;

      // Create task.
      Task task (thread_manager,
                 orb.in ());

      // Task activation flags.
      long flags =
        THR_NEW_LWP |
        THR_JOINABLE |
        orb->orb_core ()->orb_params ()->thread_creation_flags ();

      // Activate task.
      int result =
        task.activate (flags);
      if (result == -1)
        {
          if (errno == EPERM)
            {
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "Cannot create thread with scheduling policy %s\n"
                                 "because the user does not have the appropriate privileges, terminating program....\n"
                                 "Check svc.conf options and/or run as root\n",
                                 sched_policy_name (orb->orb_core ()->orb_params ()->ace_sched_policy ())),
                                2);
            }
          else
            // Unexpected error.
            ACE_ASSERT (0);
        }

      // Wait for task to exit.
      result =
        thread_manager.wait ();
      ACE_ASSERT (result != -1);
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Exception caught:");
      return -1;
    }
  ACE_ENDTRY;

  return 0;
}


#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Array_Base<Test_Object_And_Servant>;
template class ACE_Array_Iterator<Test_Object_And_Servant>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Array_Base<Test_Object_And_Servant>
#pragma instantiate ACE_Array_Iterator<Test_Object_And_Servant>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
