#include<iostream>
#include<string>
using namespace std;

class Customer{
    public:
      int acc_no;
        string name;
        int balance;
        int pin;
        int de_amt;
        int w_amt;
        string type;
        string address;
        long int ph_no;
        int c=1;
        void cho_acc(){
        cout<<"Enter your account number-";
        cin>>acc_no;
        cout<<"Enter pin-";
        cin>>pin;
   
    switch(acc_no){

        case 9400001:
        if(pin==7894){
        name="Tanishk Kushwaha";
        balance=10000;
        acc_no=9400001;
        pin=7894;
        } else {
        cout<<"Invalid pin"<<endl;
        }
        break;

        case 9400002:
        if(pin==2607){
        name="Yash Tamrakar";
        balance=20000;
        acc_no=9400002;
        pin=2607;
        } else {
        cout<<"Invalid pin"<<endl;
        }
        break;
        
        case 9400003:
        if(pin==8819){
        name="Shivam Shukla";
        balance=5000;
        acc_no=9400003;
        pin=8819;
        } else {
        cout<<"Invalid pin"<<endl;
        }
        break;
       
        case 9400004:
        if(pin==4563){
        name="Tanmay Ghoshi";
        balance=10000;
        acc_no=9400004;
        pin=4563;
       } else {
        cout<<"Invalid pin"<<endl;
        }
        break;

        case 9400005:
        if(pin==4567){
        name="Shubhanshu Dubey";
        balance=10000;
        acc_no=9400005;
        pin=4567;
        } else {
        cout<<"Invalid pin"<<endl;
        }
        break;

        case 9400006:
        if(pin==4569){
        name="Yash Dubey";
        balance=10000;
        acc_no=9400006;
        pin=4569;
        break;
        } else {
        cout<<"Invalid pin"<<endl;
        }

        case 9400007:
        if(pin==4562){
        name="Shubham OKte";
        balance=10000;
        acc_no=9400007;
        pin=4562;
        } else {
        cout<<"Invalid pin"<<endl;
        }
        break;
        
        default:
        cout<<"Account does not exist"<<endl;
        c=0;
    }
  }
};

class Bank: public Customer
{
    public:
    int t=0;
    string f_name;
    string m_name;
    string l_name;
    void open_acc(){
        t=1;
        cout<<"Enter your details for opening the account\n";
        cout<<"First Name-";
        cin>>f_name;
        cout<<"Last name- ";
        cin>>l_name;
        name=f_name + m_name + l_name;
        cout<<"Phone Number-";
        cin>>ph_no;
        cout<<"Address-";
        cin>>address;
        cout<<"Accout type-";
        cin>>type;
        cout<<"Ammount-";
        cin>>balance;
        cout<<"Pin-";
        cin>>pin;
        cout<<"Account Created"<<endl;
        acc_no=9800008;
        acc_no++;
        cout<<"Your account number-"<<acc_no<<endl;
    }
    void check_balance(){
        Customer::cho_acc();
        if(t==1){
            name=name;
            acc_no=acc_no;
            balance=balance;
        }
     if(c==1 || t==1){
        if(acc_no==acc_no && pin==pin){
        cout<<endl<<"Name-"<<name<<endl;
        cout<<"Acc. Number-"<<acc_no<<endl;
        cout<<"Balance-"<<balance<<endl<<endl;
        } else {
            cout<<"Wrong pin or account does not exist"<<endl;
        }
     }
     else{
        return;
     }
    }
    void deposit(){
        if(t==0){
          cho_acc();
        } 
        cout<<"Enter the amount to deposit :";
        cin>>de_amt;
        balance += de_amt;
        cout<<"Total balance: "<<balance<<endl;
    }
    void withdraw(){
        if(t==0){
        cho_acc();
        }
        cout<<"Enter the amount to withdraw: ";
        cin>>w_amt;
        balance -= w_amt;
        cout<<"Total balance: "<<balance<<endl;
    }
};

class Card : public Bank{
    public:
    string card;
    int serv;
    void cards(){
    cho_acc();
    cout<<"Type of card"<<endl;
    cin>>card;
    cout<<"Address";
    cin>>address;
    cout<<"Your card will deliver to your postal address"<<endl;
    }
    void service(){
    cout<<"1.Block  2.Activate Ecom services  3.Activate ATM service  4.Deactivate ATM service\n";
    cout<<"Enter your choice: ";
    cin>>serv;
    switch (serv)
    {
    case 1:
    cout<<"Cards blocked"<<endl;
        break;
    case 2:
    cout<<" Your request for Ecom service is processed successfully"<<endl;
    break;
    case 3:
    cout<<" Your request for switching on atm service is processed successfully"<<endl;
    break;
    case 4:
    cout<<" Your request for switching on atm service is processed successfully"<<endl;
    break;
    default:
    cout<<"Invalid choice"<<endl;;
        break;
    }
    }

};
class Loan :public Bank{
    public:
    long long int lo_amt;
    double int_rate=8;
    float inters;
    int cre_scor;
    string ty_lo;
    int dur;
    void loan(){
    cout<<"Type of loan-";
    cin>>ty_lo;
    cout<<"Amount for loan-";
    cin>>lo_amt;
    cout<<"Duration for loan-";
    cin>>dur;
    cout<<"Enter credit score-";
    cin>>cre_scor;
    inters=lo_amt*dur*int_rate/100;
    if(cre_scor>=750 && lo_amt<=1000000 && dur<=10){
        cout<<"Loan approved at interest rate of 8%\n";
        cout<<"Your interest="<<inters<<endl;
    } else {
        cout<<"Loan Application is rejected"<<endl;
    }
  } 
};

int main(){
    Bank b;
    Loan l;
    Card k;
    int c=1;

    //cout<<"Enter your choice";
    while(c>0 && c<8){
    cout<<endl<<"1.Opening account  "<<"2.Check Balance  "<<"3.Deposit money  "<<"4.Withdraw money  "<<"5.Applying for loan  6.Applying for card  7.Card service"<<endl;
    cout<<endl<<"Enter your choice- ";
     cin>>c;
    switch(c){
        case 1:
        b.open_acc();
        break;
        case 2:
        b.check_balance();
        break;
        case 3:
        b.deposit();
        break;
        case 4:
        b.withdraw();
        break;
        case 5:
        l.loan();
        break;
        case 6:
        k.cards();
        break;
        case 7:
        k.service();
        break;
        default:
        cout<<"Invalid choice"<<endl;
    }
    cout<<"-----------------------------------------------------------------------------------------------------------------------------"<<endl;
  }
  return 0;
}