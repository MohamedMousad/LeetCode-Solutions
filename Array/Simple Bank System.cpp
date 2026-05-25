class Bank {
    vector<long long> accounts;
public:
    Bank(vector<long long>& balance) {
        // accounts.resize(balance.size());
        accounts = balance;        
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account2 <  1 || account2 > accounts.size() || account1 <  1 || account1 > accounts.size() || accounts[account1 - 1] < money)  
            return false;
        accounts[account1 - 1] -= money , accounts[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account < 1 || account > accounts.size() || money + accounts[account - 1] < 0) return false;
        accounts[account - 1] +=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        return deposit(account , -money);
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */