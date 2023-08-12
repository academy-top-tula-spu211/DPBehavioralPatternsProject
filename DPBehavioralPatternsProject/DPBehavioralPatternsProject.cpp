#include <iostream>
#include "Chain.h"

int main()
{
    Receiver* receiver = new Receiver(true, true, true);
    
    PaymentHandler* handler = new BankPaymentHandler();
    handler->Successor() = new PayPalPaymentHandler();
    handler->Successor()->Successor() = new MoneyPaymentHandler();

    handler->Handle(receiver);
}
