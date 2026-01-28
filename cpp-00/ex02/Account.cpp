#include "Account.hpp"
#include <iostream>

Account::Account() {}

Account::Account(int initial_deposit)
{
	//

}

Account::~Account() 
{
	//
}

void	Account::_displayTimestamp()
{
	//
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_nbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_nbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	//
}

void	Account::makeDeposit(int deposit)
{
	//
}

bool	Account::makeWithdrawal(int withdrawal)
{
	//
}

int	Account::checkAmount() const
{
	//
}

void	Account::displayStatus() const
{
	//
}
