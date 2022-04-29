	   #include <stdio.h>
	   #include <string.h>
       #include <sys/stat.h>
       #include <sys/types.h>


       #include <fcntl.h>           /* Definition of AT_* constants */
       #include <sys/stat.h>


int main(int argc, char *argv[])
{
	char base[10] = "./teleDB/";
	char path[100] = "";
	int pathLength = 0;
	mode_t defaultMode = 0777;
	mkdir(base, defaultMode);

	char *contactName = argv[1];


//insert contact:
	strcpy(path, base);
	pathLength = strlen(path);

	for(int i=0; i< strlen(contactName); i++)
	{
		path[pathLength] = contactName[i];
		path[pathLength+1] = '/';
		path[pathLength+2] = '\0';
		pathLength += 2;
		mkdir(path, defaultMode);
	}

	strcat(path, "info.txt");
	fopen(path, "w+");
	//fill the file info.txt
	//scanf()
	//fputs();
	//fclose();

//////////search:
	name = scanf();
	nameToPath(name);

	if(NULL == fopen(path, "r") )
	{
		"Contact does not exist"
	}
	else
	{
		("%s found.\n", name)
		while(fgets())
		{
			print line;
		}
		fclose();
	}
	













	{
		strcpy(path, base);	//initialize
		pathLength = strlen(path);
		for(int i=0; i< strlen(name); i++)
		{
			path[pathLength] = name[i];
			path[pathLength+1] = '/';
			path[pathLength+2] = '\0';
			pathLength +=2;
		}

		strcat(path, "info.txt"
	}





	
	

}
