

#ifndef _AKEE_CONFIG_CONFIGURATIONFACTORY_H_
#define _AKEE_CONFIG_CONFIGURATIONFACTORY_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"
#include "akee/config/Config.h"

namespace akee {

class ConfigurationFactory {
private:
	//

public:
	ConfigurationFactory() {
	}

	~ConfigurationFactory() {
	}

private:
	static Config loadDefaultConfiguration() {
		return Config("default");
	}

public:
	static Config load() {
		return loadDefaultConfiguration();
	}
};

}  /* namespace akee */

#endif  /* _AKEE_CONFIG_CONFIGURATIONFACTORY_H_ */
