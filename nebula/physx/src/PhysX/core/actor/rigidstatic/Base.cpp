#include <Galaxy-Log/log.hpp>

#include <neb/debug.hh>
//#include <neb/Physics.hh>
#include <neb/core/shape/base.hpp>

#include <PhysX/app/base.hpp>
#include <PhysX/util/convert.hpp>
#include <PhysX/core/actor/util/parent.hpp>
#include <PhysX/core/actor/rigidstatic/base.hpp>
#include <PhysX/core/scene/base.hpp>

phx::core::actor::rigidstatic::base::base(sp::shared_ptr<phx::core::actor::util::parent> parent):
	neb::core::actor::base(parent),
	phx::core::actor::base(parent),
	phx::core::actor::actor::base(parent),
	phx::core::actor::rigidactor::base(parent)
{
	if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "phx core actor", debug) << __PRETTY_FUNCTION__;
}
void			phx::core::actor::rigidstatic::base::create_physics() {
	if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "phx core actor", debug) << __PRETTY_FUNCTION__;
	
	if(px_actor_ != NULL) {
		if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "phx core actor", debug) << "been here!";
		return;
	}
	
	auto scene = sp::dynamic_pointer_cast<phx::core::scene::base>(getScene());//scene_.lock();
	assert(scene);
	
	auto p = getPose();

	physx::PxTransform pose(
			phx::util::convert(vec3(p.pos_)),
			phx::util::convert(p.rot_)
			);

	//pose.p.print();
	//pose.q.print();

	// PxActor
	physx::PxRigidStatic* px_rigid_static = phx::app::base::global()->px_physics_->createRigidStatic(pose);

	if(px_rigid_static == NULL)
	{
		printf("create actor failed!");
		exit(1);
	}

	px_actor_ = px_rigid_static;

	// userData
	px_rigid_static->userData = isActorBase().get();
	assert(this == shared_from_this().get());
	assert(this == isActorBase().get());

	// add PxActor to PxScene
	assert(scene->px_scene_ != NULL);

	scene->px_scene_->addActor(*px_rigid_static);
}
void			phx::core::actor::rigidstatic::base::init_physics() {

	printf("%s\n", __PRETTY_FUNCTION__);

	setupFiltering();
}

