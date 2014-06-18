
#include <Galaxy-Log/log.hpp>

#include <Nebula/App/Base.hh>
#include <Nebula/Scene/Local.hh>
#include <Nebula/Actor/RigidBody/Base.hh>
#include <Nebula/timer/Actor/Release.hpp>



#include <PhysX/util/convert.hpp>
#include <PhysX/core/scene/local.hpp>
#include <PhysX/core/actor/rigiddynamic/local.hpp>

phx::core::scene::local::local(sp::shared_ptr<neb::core::scene::util::parent> parent):
	neb::core::scene::base(parent),
	neb::core::scene::local(parent),
	phx::core::scene::base(parent)
{
	BOOST_LOG_CHANNEL_SEV(lg, "phx core scene", debug) << __PRETTY_FUNCTION__;
}
void			phx::core::scene::local::init() {
	neb::core::scene::local::init();
	phx::core::scene::base::init();
}
void			phx::core::scene::local::release() {
	neb::core::scene::local::release();
	phx::core::scene::base::release();
}
void			phx::core::scene::local::step(neb::core::TimeStep const & ts) {
	neb::core::scene::local::step(ts);
	phx::core::scene::base::step(ts);

	auto app = neb::app::base::global();

	// timer
	//timer_set_.step(time);

	//physx::PxU32 nbPxactor = px_scene_->getNbActors(physx::PxActorTypeSelectionFlag::eRIGID_DYNAMIC);

	// PxScene
	assert(px_scene_ != NULL);

	px_scene_->simulate(ts.dt);
	px_scene_->fetchResults(true);

	// retrieve array of actors that moved
	physx::PxU32 nb_active_transforms;
	const physx::PxActiveTransform* active_transforms = px_scene_->getActiveTransforms(nb_active_transforms);

	//printf( "count PxRigidActor:%i count active transform:%i\n", nbPxactor, nb_active_transforms );

	//physx::PxTransform pose;
	physx::PxTransform pose;

	// update each render object with the new transform
	for(physx::PxU32 i = 0; i < nb_active_transforms; ++i) {
		//physx::PxActor* px_actor = active_transforms[i].actor;

		//printf( "actor type = %i\n", px_actor->getType() );

		physx::PxActor* pxactor = active_transforms[i].actor;
		assert(pxactor);
		physx::PxRigidBody* pxrigidbody = pxactor->isRigidBody();


		void* ud = active_transforms[i].userData;
		assert(ud);

		neb::core::actor::base* pactor = static_cast<neb::core::actor::base*>(ud);
		auto actor = pactor->isActorBase();


		if(actor) {
			pose = active_transforms[i].actor2World;
			actor->setPose(neb::core::pose(
						phx::util::convert(pose.q),
						vec4(phx::util::convert(pose.p),1)
						));

			if(pxrigidbody != NULL) {
				auto rigidbody = isActorRigidBody();
				//dynamic_cast<neb::core::actor::rigidbody::RigidBody*>(actor);

				assert(rigidbody != NULL);

				physx::PxVec3 v(pxrigidbody->getLinearVelocity());

				rigidbody->velocity_ = phx::util::convert(v);

				//v.print();
			}

			actor->flag_.set(neb::core::actor::util::Flag::E::SHOULD_UPDATE);
		}
	}

	// vehicle
	//physx::PxVec3 g(0,-0.25,0);
	//vehicle_manager_.vehicle_suspension_raycasts(px_scene_);
	//vehicle_manager_.update((float)dt, g);

	send_actor_update();

}
void		phx::core::scene::local::fire(sp::shared_ptr<phx::core::actor::base> actor) {

	auto proj = actor->get_projectile();

	//auto me = std::dynamic_pointer_cast<neb::core::actor::actor>(shared_from_this());

	//auto a = create_actor_local(desc);

	/** @todo replace neb::timer::actor::type with inheritance */

	std::shared_ptr<neb::Timer::actor::base> t(
			new neb::Timer::actor::Release(proj, last_ + 5.0)
			);


}





