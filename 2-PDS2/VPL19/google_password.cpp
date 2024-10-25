#include "google_password.h"

#include <iostream>

using namespace std;

void GooglePassword::insert(const string& url, const string& login, const string& password)
{
    if (!this->passwords_.count(url))
    {
        if (validPassword(password))
        {
            this->passwords_[url] = Usuario{ login, password };
        }
    }
}

void GooglePassword::remove(const string& url)
{
    this->passwords_.erase(url);
}

void GooglePassword::update(const string& url, const string& login, const string& old_password, const string& new_password)
{
    if (validPassword(new_password) && this->passwords_.count(url) && this->passwords_[url].password == old_password)
    {
        this->passwords_[url] = Usuario{ login, new_password };
    }
}

void GooglePassword::printPasswords()
{
    cout << this->passwords_.size() << endl;
    for(auto passwd:this->passwords_)
    {
        cout << passwd.first << ": " << passwd.second.login << " and " << passwd.second.password << endl;
    }
}

bool GooglePassword::validPassword(const string& password) const
{
    if (password.size() < 6 || password.size() > 50)
    {
        return false;
    }
    if (password.find("123456") != string::npos)
    {
        return false;
    }
    if (password.find(" ") != string::npos)
    {
        return false;
    }

    return true;
}