#ifndef __GLUTPP_CAMERA_VIEW_SHADOW_DIRECTIONAL_H__
#define __GLUTPP_CAMERA_VIEW_SHADOW_DIRECTIONAL_H__

#include <neb/gfx/Camera/View/Base.hh>
#include <neb/gfx/core/light/util/Types.hh>

namespace neb {namespace gfx {namespace Camera {namespace view {

	/** @brief @Base */
	class shadow_directional: virtual public base {
		public:
			typedef std::weak_ptr<neb::gfx::core::light::directional>	light_weak;
			/** @brief Constructor */
			shadow_directional(std::shared_ptr< ::neb::gfx::environ::base > parent);
			/** @brief Get view matrix. */
			virtual glm::mat4			view();
			/** @brief Step
			 *
			 * @todo explain when in timeline this occurs and in which thread and why
			 */
			virtual void				step(gal::etc::timestep const & ts);

			light_weak				light_;
	};
}}}}

#endif

