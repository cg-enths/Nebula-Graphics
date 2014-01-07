//#include <assert.h>

#include <glutpp/scene/scene.h>
#include <glutpp/renderable.h>
#include <glutpp/gui/layout.h>

glutpp::renderable::renderable(glutpp::window::window_shared window):
	window_(window)
{
	printf("%s\n",__PRETTY_FUNCTION__);
}
glutpp::renderable&	glutpp::renderable::operator=(glutpp::renderable const & r){
	printf("%s\n",__PRETTY_FUNCTION__);
}
unsigned int glutpp::renderable::f() {
	return flag_;
}
void glutpp::renderable::f(unsigned int flag) {
	flag_ = flag;
}
void glutpp::renderable::init(glutpp::window::window_shared window) {
	printf("%s\n",__PRETTY_FUNCTION__);

	assert(window);
	
	window_ = window;
	
	// camera
	camera_.reset(new glutpp::camera);
	camera_->init(shared_from_this());
}
glutpp::window::window_shared glutpp::renderable::get_window() {
	auto window = window_.lock();
	
	assert(window);
	
	return window;
}
void	glutpp::renderable::resize(int w, int h) {
	camera_->w_ = w;
	camera_->h_ = h;
}
void glutpp::renderable::render(double time, glutpp::window::window_shared window) {

	GLUTPP_DEBUG_1_FUNCTION;

	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	if(scene_)
	{
		scene_->render(time, camera_, window);
	}
	
	if(layout_)
	{
		layout_->render_shader(time);
	}
}







