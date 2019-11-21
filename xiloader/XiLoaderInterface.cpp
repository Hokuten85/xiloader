#include "XiLoaderInterface.h"



XiLoaderInterface::XiLoaderInterface() : XiPivot::Core::Redirector()
{
	Redirector::s_instance = this;
}


XiLoaderInterface::~XiLoaderInterface()
{
}

bool XiLoaderInterface::Initialize()
{
	instance().setRootPath(m_settings.rootPath);
	for (const auto &path : m_settings.overlays)
	{
		instance().addOverlay(path);
	}

	return instance().setupHooks();
}

XiLoaderInterface::Settings::Settings()
{
	char workPath[MAX_PATH];

	//GetCurrentDirectoryA(MAX_PATH, static_cast<LPSTR>(workPath));

	GetModuleFileNameA(nullptr, static_cast<LPSTR>(workPath), MAX_PATH);
	std::string tmpPath = std::string(workPath);

	/* default to "plugin location"/DATs */
	rootPath = tmpPath.substr(0, tmpPath.find_last_of("/\\")) + "/DATs";
}
