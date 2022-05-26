#include<jsoncpp/json/json.h>
#include<vector>

class Employee
{
public:
    std::string name;
	std::string empCode;
    int salary;
    std::string title;

    Employee() : name(""), empCode(""), salary(0), title("")  {}
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
   // Config(std::string configFilePath);
    Config();
    bool setFilePath(std::string path);
    bool readRecords();
    bool readOneRecord();
	int editRecord();//will update vector record
	int createRecord();
	int searchRecord();
	int deleteRecord();
	bool saverecordinjson();
	int printpayslip();
	int editpayroll();
  //  std::string getLogfilePath();

};

