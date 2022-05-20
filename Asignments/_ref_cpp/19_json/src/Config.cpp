#include "Config.h"

bool Config::setFilePath(std::string path)
{
	filePath = path;
	return true;
}

int Config::readConfig()
{
	std::ifstream ifs(configFilePath);

	Json::Reader jr;

	jr.parse(ifs, configRoot);

	return 0;
}

std::string Config::getLogfilePath()
{
	return configRoot["logfile"].toString();
}
