#pragma once
#include <iostream>

using namespace std;

class Receiver
{
	bool bankTransfer;
	bool moneyTransfer;
	bool payPalTransfer;
public:
	Receiver(bool b, bool m, bool p)
		: bankTransfer{ b },
		moneyTransfer{ m },
		payPalTransfer{ p } {}

	bool& BankTransfer() { return bankTransfer; }
	bool& MoneyTransfer() { return moneyTransfer; }
	bool& PayPalTransfer() { return payPalTransfer; }
};

class PaymentHandler
{
	PaymentHandler* successor;
public:
	PaymentHandler*& Successor(){ return successor; }
	virtual void Handle(Receiver* reciever) = 0;
};

class BankPaymentHandler : public PaymentHandler
{
public:
	void Handle(Receiver* reciever) override
	{
		if (reciever->BankTransfer())
			cout << "bank transfer is ok!\n";
		else if (Successor() != nullptr)
		{
			cout << "bank transfer is crush!\n";
			Successor()->Handle(reciever);
		}
	}
};

class MoneyPaymentHandler : public PaymentHandler
{
public:
	void Handle(Receiver* reciever) override
	{
		if (reciever->MoneyTransfer())
			cout << "money transfer is ok!\n";
		else if (Successor() != nullptr)
		{
			cout << "money transfer is crush!\n";
			Successor()->Handle(reciever);
		}
	}
};

class PayPalPaymentHandler : public PaymentHandler
{
public:
	void Handle(Receiver* reciever) override
	{
		if (reciever->PayPalTransfer())
			cout << "paypal transfer is ok!\n";
		else if (Successor() != nullptr)
		{
			cout << "paypal transfer is crush!\n";
			Successor()->Handle(reciever);
		}
	}
};