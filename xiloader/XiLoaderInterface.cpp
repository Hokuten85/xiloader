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
	return instance().setupHooks();
}

XiLoaderInterface::Settings::Settings()
{
	char workPath[MAX_PATH];

	GetCurrentDirectoryA(MAX_PATH, static_cast<LPSTR>(workPath));

	/* default to "plugin location"/DATs */
	rootPath = std::string(workPath) + "/DATs";
}
