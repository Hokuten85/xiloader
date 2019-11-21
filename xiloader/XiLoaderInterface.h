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
		std::vector<std::string> overlays;
	};

	Settings               m_settings;
};

