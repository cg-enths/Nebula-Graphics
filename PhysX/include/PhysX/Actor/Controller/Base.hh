#ifndef __NEBULA_CONTENT_ACTOR_PHYSICS_CONTROLLER_HPP__
#define __NEBULA_CONTENT_ACTOR_PHYSICS_CONTROLLER_HPP__

#include <PxPhysicsAPI.h>

#include <Nebula/Actor/Base.hh>

namespace Neb {
	namespace Actor {
		class Controller: public Neb::Actor::Base {
			public:
				Controller(Neb::Actor::Util::Parent_s);
				virtual void		init();
				virtual void		release();
				virtual void		step(Neb::Core::TimeStep const & ts);
				
				virtual void		add_force();

				physx::PxController*	px_controller_;

		};
	}
}



#endif
