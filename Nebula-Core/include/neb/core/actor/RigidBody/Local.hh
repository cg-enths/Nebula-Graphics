#ifndef NEBULA_CONTENT_ACTOR_RIGID_BODY_LOCAL_HH
#define NEBULA_CONTENT_ACTOR_RIGID_BODY_LOCAL_HH

#include <neb/core/actor/Util/Types.hh>

#include <neb/core/actor/RigidActor/Local.hh>
#include <neb/core/actor/RigidBody/Base.hh>

namespace neb { namespace core { namespace actor { namespace rigidbody {



			class local:
				virtual public neb::core::actor::rigidactor::local,
				virtual public neb::core::actor::rigidbody::base
			{
				public:
					local(sp::shared_ptr<neb::core::actor::util::parent> parent);

					virtual void		step(gal::std::timestep const & ts);
	
			};



}}}}

#endif

