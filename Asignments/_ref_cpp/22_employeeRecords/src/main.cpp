#include<iostream>
#include<fstream>
#include<getopt.h>
#include<string>

#include "Config.h"

Config config;

int parseCommandLine(int argc, char* argv[])
{
	int opt = 0;

	static struct option long_options[] = {
		{"config", required_argument,       0,  'c' },
		{"help", no_argument,       0,  'h' },
		{ NULL, 0,     NULL, 0 }
	};
	while((opt = getopt_long(argc, argv, "hc:",long_options,NULL)) != -1)
	{
		switch (opt) {
			case 'c':
				//copy config file here.
				//configFilePath = optarg;
				config.setFilePath(optarg);
				break;
			case 'h':
				printf("Usage: %s [OPTION]... [FILE]... \n Print \n", argv[0]);
				exit(0);
				break;				
			default:
				printf("Try '%s --h' for more information.", argv[0]);
		}
	}

	return 0;
}


int main(int argc, char *argv[])
{


	parseCommandLine(argc, argv);

	config.setFilePath("config/employeeRecords.json");
	config.readConfig();
	config.readRecords();

	//std::cout << "Logfile path is : " << config.getLogfilePath() << std::endl;

	return 0;
}
