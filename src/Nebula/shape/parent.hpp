#ifndef __GLUTPP_PARENT_H__
#define __GLUTPP_PARENT_H__

#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

//#include <galaxy/flag.hpp>
/*
#include <math/vec4.hpp>
#include <math/vec3.hpp>
#include <math/vec2.hpp>
#include <math/transform.hpp>
#include <math/geo/polyhedron.hpp>
*/
#include <Nebula/config.hpp> // Nebula/config.hpp.in
#include <Nebula/Actor/Types.hpp>
#include <Nebula/Util/Shared.hpp>
#include <Nebula/shape/desc.hpp>
#include <Nebula/Graphics/material.hpp>
#include <Nebula/Graphics/mesh.hpp>

#include <Nebula/Core/Pose.hpp>

namespace Neb {
	namespace Shape {
		/** @brief @Parent
		 * abstract class for parent of a shape
		 */
		class parent: virtual public Neb::Core::Pose, virtual public Neb::Shared {
			public:
				parent();
				virtual ~parent() {}

				//virtual physx::PxMat44					getPoseGlobal() = 0;
				//virtual physx::PxMat44					getPose() = 0;
				
				
				Neb::Actor::Base_s			isActor();
				Neb::Shape::shape_s			isShape();
				
				/** @brief Shapes */
				Neb::Map<Neb::Shape::shape>			shapes_;

		};
	}
}

#endif





