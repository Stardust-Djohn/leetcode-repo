class Bank {
public:
    Bank(vector<long long>& balance) {
        this->user=balance;
        this->num=balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 - 1 > num || account2 - 1 > num) return false;
        if(withdraw(account1,money)){
            return deposit(account2,money);
        }else{
            return false;
        }
    }
    
    bool deposit(int account, long long money) {
        if(account-1>num) return false;
        user[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account-1>num || user[account-1]<money) return false;
        user[account-1]-=money;
        return true;
    }
private:
    vector<long long> user;
    int num;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */