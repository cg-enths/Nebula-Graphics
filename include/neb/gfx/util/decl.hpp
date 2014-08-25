#ifndef NEBULA_GRAPHICS_TYPES_HH
#define NEBULA_GRAPHICS_TYPES_HH

#include <memory>

namespace neb {

	struct attrib_name {
		enum e {
			COOR,
			TEX,
			POSITION,
			NORMAL,
			TEXCOOR,
			TANGENT,
			BINORMAL,
			INSTANCE_MODEL0,
			INSTANCE_MODEL1,
			INSTANCE_MODEL2,
			INSTANCE_MODEL3,
			INSTANCE_SAMPLER,
			INSTANCE_DIFFUSE,
			INSTANCE_AMBIENT,
			INSTANCE_SPECULAR,
			INSTANCE_EMISSION,
			INSTANCE_SHININESS,
		};
	};
	struct program_name {
		enum e {
			TEXT,
			LIGHT,
			IMAGE,
			NORM,
			NORM_IMAGE,
			THREED
		};
	};

	/** @brief %Graphics */
	namespace gfx {
		namespace window {
			namespace util {
				class parent;
			}

			class base;
		}

		class texture;

		namespace mesh {
			template<typename BUFFER> class base;
			class tri1;
			class instanced;
		}

		/** @brief Graphical User Interface */
		namespace gui {
			/** @brief %Layout */
			namespace layout {
				class base;

				/** @brief %utilities */
				namespace util {
					class parent;
				}


			}

			/** @brief %Object */
			namespace object {
				/** @brief %utilities */
				namespace util {
					class parent;
				}

				class base;
				class terminal;
			}

		}

		/**@brief %Context */
		namespace context {
			/** @brief %utilities */
			namespace util {
				class parent;
			}
			class base;
			class window;
		}

		/**@brief %environ */
		namespace environ {
			class base;
			class two;
			class three;
		}

		/**@brief %environ */
		namespace drawable {
			class base;
			class two;
			class three;
		}

		/** @brief Camera */
		namespace Camera {
			namespace View {
				class base;
				class Free;
				class Ridealong;

			}
			namespace Projection {
				class base;
				class Perspective;

			}
		}
	}
}

#endif



