#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "Account.h"

typedef Account* ACCOUNT_PTR;

class AccountArray
{
    ACCOUNT_PTR* arr;
    int arrlen;
	AccountArray(const AccountArray&) {}
	AccountArray& operator=(const AccountArray&) {}
public:
    AccountArray(int len=100);
    ACCOUNT_PTR& operator[](int);
    ACCOUNT_PTR operator[](int) const;
    int GetArrLen() const;
    ~AccountArray();
};

#endif // !__ARRAY_H__