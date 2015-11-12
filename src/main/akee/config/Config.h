
#ifndef _AKEE_CONFIG_CONFIG_H_
#define _AKEE_CONFIG_CONFIG_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"

#include <string>

namespace akee {

class Config {
private:
	std::string name_;

public:
	Config() {
		name_ = "default";
	}

	Config(const std::string & name) {
		name_ = name;
	}

	~Config() {
	}

public:
	std::string getName() const {
		return name_;
	}

	void setName(const std::string & name) {
		name_ = name;
	}
};

}  /* namespace akee */

#endif  /* _AKEE_CONFIG_CONFIG_H_ */
