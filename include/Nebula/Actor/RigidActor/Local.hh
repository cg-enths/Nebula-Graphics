#ifndef __NEBULA_CONTENT_ACTOR_PHYSICS_RIGID_ACTOR_LOCAL_HPP__
#define __NEBULA_CONTENT_ACTOR_PHYSICS_RIGID_ACTOR_LOCAL_HPP__

#include <Nebula/Actor/Actor/Local.hh>
#include <Nebula/Actor/RigidActor/Base.hh>

namespace Neb {
	namespace Actor {
		namespace RigidActor {
			class Local:
				virtual public Neb::Actor::RigidActor::Base,
				virtual public Neb::Actor::Actor::Local
			{
				public:
					virtual void				step(double const & time, double const & dt);

					template<class D, typename... Args> inline void		dispatch(Args... a) {
						Neb::Actor::Actor::Local::dispatch<D>(a...);
						Neb::Actor::RigidActor::Base::dispatch<D>(a...);
						D::visit(this, a...);
					}

					virtual Neb::Actor::Base_s		get_projective();
			};
		}
	}
}

#endif







