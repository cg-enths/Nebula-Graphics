
//#include <math/free.hpp>


#include <gru/config.hpp>
#include <gru/shape/desc.hpp>
#include <gru/shape/shape.hpp>
#include <gru/Graphics/light/desc.hpp>
#include <gru/Graphics/light/light.hpp>


glutpp::shape::desc::desc() {
	GLUTPP_DEBUG_0_FUNCTION;
}
/*
void	glutpp::shape::desc::load(tinyxml2::XMLElement* element) {

	GLUTPP_DEBUG_0_FUNCTION;

	get_raw()->load(element);
	
	// lights
	tinyxml2::XMLElement* element_light = element->FirstChildElement("light");
	light::desc_s ld;
	
	while(element_light)
	{
		ld.reset(new glutpp::light::desc);
		
		ld->get_raw()->load(element_light);
		
		get_lights()->vec_.push_back(std::make_tuple(ld));

		element_light = element_light->NextSiblingElement("light");
	}
}*/
glutpp::shape::desc &	glutpp::shape::desc::operator<<(boost::shared_ptr<glutpp::shape::shape> shape) {
	return *this;	
}









