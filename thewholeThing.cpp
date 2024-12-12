#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

class account {        // The class
  public:          // Access specifier
    std::string name;  // Attribute
    bool checking;  // Attribute
    int age;
    double curAmount; // Attribute
    int password;
   
   account(std::string a,bool b, int c, double d, int e){
      name = a;
      checking = b;
      age = c;
      curAmount = d;
      password = e;
    }

void deposit(int y){
    curAmount += y;
    }
void withdraw(int y){
 if (y <= curAmount) {
            curAmount -= y;
        } else {
            std::cout << "Insufficient balance!" << std::endl;
        }
}
    
      friend std::ostream& operator<<(std::ostream& os, const account& acc) {
        os << "Account Details:" << std::endl;
        os << "Name: " << acc.name << std::endl;
        os << "Checking Account: " << (acc.checking ? "Yes" : "No") << std::endl;
        os << "Age: " << acc.age << std::endl;
        os << "Current Amount: $" << acc.curAmount << std::endl;
        os << "Password: DO NOT SHARE!" <<acc.password<<std::endl;
        return os;
    }
};
    
    ;
    
int main()
{
    int choice;
    std::string name;
    std::string nameSearch;
    std::string depWi;
    int amount;
    bool check;
    int age;
    int passW;
    int passEntry;
    double balance;
    
    std::map<std::string, account> acc_map;
    while(choice!=4){
    std::cout << "Bank Management System"<<std::endl;
    std::cout << "======================"<<std::endl;
    std::cout << "                      "<<std::endl;
    std::cout << "1. CREATE NEW ACCOUNT "<<std::endl;
    std::cout << "2. FIND ACCOUNT "<<std::endl;
    std::cout << "3. WITHDRAW OR DEPOSIT "<<std::endl;
    std::cout << "4. QUIT "<<std::endl;
    std::cin >> choice;
    
    if(choice==1){
        std::cout<<"Enter your name"<<std::endl;
        std::cin>>name;
        std::cout<<"Is this for a checking account? (1 for yes, 0 for no)"<<std::endl;
        std::cin>>check;
        std::cout<<"Enter your age"<<std::endl;
        std::cin>>age;
        if(age<18){
            std::cout<<"I'm sorry! You are too young to use our service! Try again next year!"<<std::endl;
        }else{
            std::cout<<"What is your current amount you wish to deposit?"<<std::endl;
            std::cin>>balance;
            std::cout<<"Generating password..."<<std::endl;
            passW = rand();
            account newAcc(name,check,age,balance,passW);
            std::cout<<newAcc;
            
            acc_map.insert(std::make_pair(name, newAcc));
        }
        }else if(choice==2){
            std::cout<<"Enter account name"<<std::endl;
            std::cin>>nameSearch;
            auto it = acc_map.find(nameSearch);//counts iterator
            if(acc_map.find(nameSearch)!=acc_map.end()){
                std::cout<<"Account Found!"<<std::endl;
                
                //std::cout<<acc_map[nameSearch];
                std::cout<< it->second;
            }else{
                std::cout<<"Not found! Sorry!"<<std::endl;
            }
            
        
        }else if(choice ==3){
            std::cout<<"Enter account name"<<std::endl;
            std::cin>>nameSearch;
            auto it = acc_map.find(nameSearch);//counts iterator
            if(acc_map.find(nameSearch)!=acc_map.end()){
                std::cout<<"Account Found!"<<std::endl;
                
                //std::cout<<acc_map[nameSearch];
                std::cout<< it->second;
                std::cout<<"What is account password?"<<std::endl;
                std::cin>>passEntry;
                while(passEntry != it->second.password){
                    std::cout<<"Not Valid"<<std::endl;
                    std::cout<<"What is account password?"<<std::endl;
                    std::cin>>passEntry;
                }
                
                std::cout<<"Deposit?(D) or Withdraw?(W)"<<std::endl;
                std::cin>>depWi;
                if (depWi=="D"){
                    std::cout<<"How much do you wish to deposit?"<<std::endl;
                    std::cin>>amount;
                    if(amount<=0){
                        std::cout<<"Invalid Amount!"<<std::endl;
    
                    }else{
                        it->second.deposit(amount);  // Modify balance by depositing
                        std::cout << "Deposit Successful!" << std::endl;
                        std::cout << it->second;
                    }
                }else if(depWi=="W"){
                    std::cout<<"How much do you wish to Withdraw?"<<std::endl;
                    std::cin>>amount;
                    if(amount > it->second.curAmount){
                        std::cout<<"Invalid Amount!"<<std::endl;
    
                    }else{
                        it->second.withdraw(amount);
                        std::cout << it->second;
                    }
                }
            }else{
                std::cout<<"Not found! Sorry!"<<std::endl;
            }
        }
    
    }
    
    return 0;
}
