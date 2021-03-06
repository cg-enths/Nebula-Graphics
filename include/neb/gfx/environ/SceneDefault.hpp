#ifndef NEBULA_GFX_ENVIRON_SCENE_DEF_HPP
#define NEBULA_GFX_ENVIRON_SCENE_DEF_HPP

#include <neb/fnd/core/actor/util/decl.hpp>
#include <neb/fnd/environ/SceneDefault.hpp>

#include <neb/gfx/util/decl.hpp>
#include <neb/gfx/camera/util/decl.hpp>
#include <neb/gfx/glsl/util/decl.hpp>
#include <neb/gfx/environ/three.hpp>
#include <neb/gfx/environ/single.hpp>

namespace neb { namespace gfx { namespace environ {

	/** @brief base
	 *
	 * Abstract class that contains functions and data needed to render a specific kind of drawable.
	 */
	class SceneDefault:
		//virtual public neb::fnd::environ::SceneDefault,
		virtual public neb::gfx::environ::single<neb::gfx::camera::view::Base>,
		virtual public neb::gfx::environ::three
	{
		public:
			typedef std::shared_ptr<neb::gfx::glsl::program::Base>		program_shared;
			typedef std::shared_ptr<neb::gfx::camera::view::Base>		view_shared;
			typedef std::shared_ptr<neb::gfx::camera::proj::Base>		proj_shared;
		public:
			virtual void		init(parent_t * const & p);
			//virtual void		step(gal::etc::timestep const & ts);
			virtual void		render(neb::fnd::context::Base * const & context);
			typedef std::weak_ptr<neb::fnd::camera::view::Ridealong>	view_ridealong_weak;
			view_ridealong_weak		create_view_ridealong(
					std::weak_ptr<neb::fnd::core::actor::base> actor);
	};
}}}

#endif
