#include<jsoncpp/json/json.h>

//TODO: Make this class as a singleton class.

class Employee 
{
	std::string name;
	std::string  empCode;
	int salary;
	std::string title;
	public: 
	Employee() : name(""), empCode(""), salary(0), title("") {}
};

class Config
{
	private:
	std::string filePath;
	Json::Value configRoot;
	Json::Value oneEmp;

	Employee emp;
	std::vector<Employee> records;
	
	private:

	public:
	bool readConfig();
	Config(std::string configFilePath);
	Config();
	bool setFilePath(std::string path);
	bool readRecords();
	bool readOneRecord();

	std::string getLogfilePath();

};
