#include<jsoncpp/json/json.h>

//TODO: Make this class as a singleton class.
class Config
{
	private:
	std::string filePath;
	Json::Value configRoot;
	
	private:
	bool readConfig();

	public:
	Config(std::string configFilePath);
	Config();
	bool setFilePath(std::string path);

	std::string getLogfilePath();

}
