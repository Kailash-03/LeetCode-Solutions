class Bank {
private:
    vector<long long> acc;
    
public:
    Bank(vector<long long>& balance) {
        acc.push_back(0);
        int n=balance.size();
        acc.insert(acc.end(), balance.begin(), balance.end());

    }
    
    bool transfer(int b1, int b2, long long money) {
        if( b1<=0 || b1>=acc.size() || b2<=0 || b2>=acc.size()) return false;
        if(money>acc[b1]) return false;
        acc[b1]-=money;
        acc[b2]+=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account<=0 || account>=acc.size()) return false;
        acc[account]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account<=0 || account>=acc.size()) return false;
        if( acc[account]<money) return false;
        acc[account]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */