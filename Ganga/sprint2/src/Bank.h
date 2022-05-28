#ifndef __Bank_h
#define __Bank_h
#include <string>
class Bank
{

	public:
	std::string dbFilePath;


	public:

	Bank() : dbFilePath("account.txt") {};

	bool createAccount();
	bool display_sp(int);
	bool modify_Account(int);
	bool delete_Account(int);
	bool display_all();
	bool deposit_withdraw(int, int);

};

#endif
