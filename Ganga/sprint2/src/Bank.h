#ifndef __Bank_h
#define __Bank_h
#include <string>
class Bank
{

	public:
	std::string dbFilePath;
	Account ac;

	public:

	Bank() : dbFilePath("Account.txt") {};

	bool write_Account();
	bool display_sp(int);
	bool modify_Account(int);
	bool delete_Account(int);
	bool display_all();
	bool deposit_withdraw(int, int);

}

#endif
