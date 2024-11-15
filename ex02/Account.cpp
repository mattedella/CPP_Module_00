/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:49:30 by mdella-r          #+#    #+#             */
/*   Updated: 2024/10/29 15:06:16 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <functional>
#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0, Account::_totalAmount = 0, Account::_totalNbDeposits = 0, Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";created" << std::endl;
	_totalAmount += _amount;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";closed" << std::endl;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
	<< ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits()
	<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";deposit:" << deposit
	<< ";amount:" << _amount + deposit
	<< ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
}

int	Account::checkAmount(void) const {
	return this->_amount;
}

bool Account::makeWithdrawal( int withdrawals) {
	if (withdrawals > _amount) {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";withdrawal:refused" << std::endl;
		return false;
	}
	_displayTimestamp();
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";withdrawal:" << withdrawals
	<< ";amount:" << _amount - withdrawals
	<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withdrawals;
	_totalAmount -= withdrawals;
	return true;
}

void	Account::_displayTimestamp(void) {
	char	buf[80];

	time_t	now = time(NULL);

	tm* localTime = localtime(&now);
	strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", localTime);

	std::cout << buf;
}

int	Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

