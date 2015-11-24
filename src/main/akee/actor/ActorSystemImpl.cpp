
#include "akee/actor/ActorSystem.h"
#include "akee/actor/ActorSystemImpl.h"

namespace akee {

ActorSystem * ActorSystemImpl::createSystemImpl(const std::string & name, const Config & config) {
	ActorSystem * system = new ActorSystemImpl(name, config);
	return system;
}

ActorSystem * ActorSystemImpl::createAndStartSystemImpl(const std::string & name, const Config & config) {
	ActorSystem * system = new ActorSystemImpl(name, config);
	if (system) {
		system->start();
	}
	return system;
}

}  /* namespace akee */
