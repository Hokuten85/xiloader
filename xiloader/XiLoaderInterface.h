#pragma once
#include "Redirector.h"

class XiLoaderInterface : private XiPivot::Core::Redirector
{
public:
	XiLoaderInterface();
	~XiLoaderInterface();

	bool Initialize();

private:
	struct Settings
	{
		Settings();

		std::string rootPath;
	};

	Settings               m_settings;
};

