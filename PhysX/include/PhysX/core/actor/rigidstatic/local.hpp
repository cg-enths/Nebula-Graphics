#ifndef PHYSX_CONTENT_ACTOR_RIGIDBODY_LOCAL_HPP
#define PHYSX_CONTENT_ACTOR_RIGIDBODY_LOCAL_HPP

#include <PxPhysicsAPI.h>

#include <Nebula/Actor/RigidBody/Local.hh>

#include <PhysX/core/actor/rigidactor/local.hpp>
#include <PhysX/core/actor/rigidbody/base.hpp>
#include <PhysX/core/actor/util/decl.hpp>

namespace phx { namespace core { namespace actor { namespace rigidstatic {



	class local:
		virtual public neb::core::actor::rigidstatic::local,
		virtual public phx::core::actor::rigidactor::local,
		virtual public phx::core::actor::rigidstatic::base
	{
		public:
			local(sp::shared_ptr<neb::core::actor::util::parent>);

			virtual void					init();
			virtual void					release();
			virtual void					step(neb::core::TimeStep const & ts);


			virtual void					create_physics() = 0;
			virtual void					init_physics() = 0;

			virtual void					add_force(real) = 0;
			virtual void					set_pose(physx::PxTransform);

			virtual int					fire();

			virtual sp::shared_ptr<phx::core::actor::rigiddynamic::base>		get_projectile() = 0;


			physx::PxActor*					px_actor_;

			//std::shared_ptr<neb::core::actor>		object_;
	};


}}}}

#endif

