#include<iostream>
#include<fstream>
#include "Config.h"

bool Config::setFilePath(std::string path)
{
	filePath = path;
	return true;
}

bool Config::readConfig()
{
	std::ifstream ifs(filePath);

	Json::Reader jr;

	jr.parse(ifs, configRoot);

	return true;
}

std::string Config::getLogfilePath()
{
	return configRoot["logfile"].asString();
}

Config::Config() : filePath("../config/config.json") {};

Config::Config(std::string path) : filePath(path) {};
