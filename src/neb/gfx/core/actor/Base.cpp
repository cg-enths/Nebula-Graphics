#include <gal/log/log.hpp>

#include <neb/core/debug.hh>

#include <neb/core/util/decl.hpp>
#include <neb/core/util/config.hpp>
#include <neb/core/util/log.hpp>
#include <neb/core/scene/base.hpp>

#include <neb/timer/Actor/Base.hpp>

#include <neb/gfx/window/util/signals.hpp>
#include <neb/gfx/core/actor/base.hpp>
#include <neb/gfx/core/shape/base.hpp>
#include <neb/gfx/window/Base.hh>
#include <neb/gfx/util/decl.hpp>
#include <neb/gfx/util/log.hpp>


neb::gfx::core::actor::base::base(shared_ptr<neb::core::actor::util::parent> parent):
	neb::core::actor::base(parent)
{
	if(DEBUG_NEB) LOG(lg, neb::core::actor::sl, debug) << __PRETTY_FUNCTION__;
}
neb::gfx::core::actor::base::~base() {
	if(DEBUG_NEB) LOG(lg, neb::core::actor::sl, debug) << __PRETTY_FUNCTION__;
}
void				neb::gfx::core::actor::base::init() {
	if(DEBUG_NEB) LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

}
void				neb::gfx::core::actor::base::release() {
	if(DEBUG_NEB) LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;
	
}
void				neb::gfx::core::actor::base::load_lights(neb::core::light::util::count & light_count, neb::core::pose const & pose) {
	if(DEBUG_NEB) LOG(lg, neb::core::actor::sl, debug) << __PRETTY_FUNCTION__;

	auto parent(parent_.lock());
	assert(parent);

	auto npose = pose * pose_;
	
	typedef neb::core::actor::util::parent A;
	typedef neb::core::shape::util::parent S;

	auto lambda_actor = [&] (A::map_type::iterator<0> it) {
		
		auto actor = sp::dynamic_pointer_cast<neb::gfx::core::actor::base>(it->ptr_);

		if(!actor) {
			::std::cout << "ptr   = " << it->ptr_ << " type= " << typeid(*it->ptr_).name() << ::std::endl;
			::std::cout << "actor = " << actor << ::std::endl;
			abort();
		}
		
		actor->load_lights(light_count, npose);
	};
	
	auto lambda_shape = [&]  (S::map_type::iterator<0> it) {
		auto shape = sp::dynamic_pointer_cast<neb::gfx::core::shape::base>(it->ptr_);
		assert(shape);
		
		shape->load_lights(light_count, npose);
		
	};
	
	/*parent->*/A::map_.for_each<0>(lambda_actor);
	
	/*parent->*/S::map_.for_each<0>(lambda_shape);
}
void				neb::gfx::core::actor::base::draw(
		sp::shared_ptr<neb::gfx::context::base> context,
		sp::shared_ptr<neb::glsl::program> p,
		neb::core::pose const & pose)
{
	if(DEBUG_NEB) LOG(lg, neb::core::actor::sl, debug) << __PRETTY_FUNCTION__;

	auto npose = pose * pose_;

	typedef neb::core::actor::util::parent A;
	typedef neb::core::shape::util::parent S;

	A::map_.for_each<0>([&] (A::map_type::iterator<0> it) {
			auto actor = sp::dynamic_pointer_cast<neb::gfx::core::actor::base>(it->ptr_);
			assert(actor);
			actor->draw(context, p, npose);
			});

	S::map_.for_each<0>([&] (S::map_type::iterator<0> it) {
			auto shape = sp::dynamic_pointer_cast<neb::gfx::core::shape::base>(it->ptr_);
			assert(shape);
			shape->draw(context, p, npose);
			});


}

void		neb::gfx::core::actor::base::step(gal::std::timestep const & ts) {
	if(DEBUG_NEB) LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

}



