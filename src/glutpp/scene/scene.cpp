#include <stdio.h>


#include <glutpp/window/window.h>
#include <glutpp/renderable.h>
#include <glutpp/scene/desc.h>
#include <glutpp/scene/scene.h>
#include <glutpp/actor/actor.h>
#include <glutpp/light/light.h>

#include <glutpp/glsl/program.h>

glutpp::scene::scene::scene(glutpp::scene::desc_shared desc):
	desc_(desc)
{
	GLUTPP_DEBUG_0_FUNCTION;

	assert(desc);
}
glutpp::scene::scene::~scene() {
	GLUTPP_DEBUG_0_FUNCTION;
}
void glutpp::scene::scene::i(int ni) {
	GLUTPP_DEBUG_0_FUNCTION;
	
	//desc_->raw_.i_ = ni;
	desc_->i_ = ni;
}
int glutpp::scene::scene::i() {
	return desc_->i_;
}
unsigned int glutpp::scene::scene::f() {
	return desc_->raw_.flag_;
}
void glutpp::scene::scene::f(unsigned int flag) {
	desc_->raw_.flag_ = flag;
}
void	glutpp::scene::scene::init(std::shared_ptr<renderable> renderable) {

	assert(renderable);

	//renderable_ = renderable;
}
void	glutpp::scene::scene::render(
		double time,
		std::shared_ptr<glutpp::camera> camera,
		std::shared_ptr<glutpp::window::window> window) {

	GLUTPP_DEBUG_1_FUNCTION;

	assert(camera);

	auto p = glutpp::__master.use_program(glutpp::program_name::e::LIGHT);


	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	camera->load();

	int i = 0;
	for(auto it = actors_.map_.begin(); it != actors_.map_.end(); ++it)
	{
		it->second->load_lights(i);
	}

	p->get_uniform(glutpp::uniform_name::LIGHT_COUNT)->load(i);

	//printf("%i\n",i);

	draw(window);
}
int	glutpp::scene::scene::draw(std::shared_ptr<glutpp::window::window> window) {

	GLUTPP_DEBUG_1_FUNCTION;

	for(auto it = actors_.map_.begin(); it != actors_.map_.end(); ++it)
	{
		it->second->draw(window);
	}
}
void	glutpp::scene::scene::resize(int w, int h) {
}





