#ifndef __NEBULA_CONTENT_ACTOR_PHYSICS_ACTOR_REMOTE_HPP__
#define __NEBULA_CONTENT_ACTOR_PHYSICS_ACTOR_REMOTE_HPP__

#include <Nebula/Actor/Remote.hh>
#include <Nebula/Actor/Actor/Base.hh>

namespace neb { namespace core { namespace actor {
namespace neb {
	namespace Actor {
		namespace Actor {
			class Remote:
				virtual public neb::Actor::Actor::Base,
				virtual public neb::Actor::Remote
			{
				public:
					virtual void		step(neb::core::TimeStep const & ts);
			};
		}
	}
}

#endif


