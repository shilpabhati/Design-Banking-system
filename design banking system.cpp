#include <bits/stdc++.h>


using namespace std;
int special_pin= 8888;


class account{
    private:
    int pin;
    int account_no;
    double balance;
    public:
        account() {
            pin=0000;
            account_no=0000;
            balance=0000;
     }

     double get_balance(){
         return balance;
     }
     void set_balance(double b){
         balance=b;
     }
     int get_account_no(){
         return account_no;
     };
     void set_account_no(int a){
         account_no=a;
     };
     bool verify_pin(int p){
         if(p==pin)return true;
         else return false;
     };
     void set_pin(int p){
         pin=p;
     };


};


account *  accounts = new account[100];
bool * is_avail= new bool[100];



void open_balance(double d,int p){
    int avail_pos=-1;
    for(int i=0;i<100;i++)if(is_avail[i]==true){avail_pos=i;break;} //First Unfilled Position got alloted
    if(avail_pos!=-1){
        account ac;
        ac.set_balance(d);
        ac.set_pin(p);
        ac.set_account_no(avail_pos+1001);
        accounts[avail_pos]=ac;
        is_avail[avail_pos]=false;
        int an=ac.get_account_no();
        cout<<"your account no is "<<an<<endl;
        return;
    }
    else {cout<<"Currently All Positions Filled"<<endl;
    return;}
}
void balance_inquiry(int an,int p){

    if(an<=1100&&an>=1001&&is_avail[an-1001]==false){
        account * ac;
        ac= &accounts[an-1001];
        bool is=ac->verify_pin(p);
        if(is){
            double b=ac->get_balance();
            cout<<"balance of account no "<<an<<":"<<b<<endl;
            return;
        }
        else {cout<<" wrong pin"<<endl;
        return;}

    }
    else cout<<"Account Does Not Exist"<<endl;
}
void deposit(int an,int p,double d){
    if(an<=1100&&an>=1001&&is_avail[an-1001]==false){
        account *ac;
        ac=&accounts[an-1001];
        bool is=ac->verify_pin(p);
        if(is){
            double cb=ac->get_balance();
            double nb=cb+d;
            ac->set_balance(nb);
            cout<<"New balance of account no "<<an<<":"<<nb<<endl;
            return;
        }
        else {cout<<" wrong pin"<<endl;
        return;}

    }
    else cout<<"Account Does Not Exist"<<endl;
    return;
}
void withdrawl(int an,int p,double d){
    if(an<=1100&&an>=1001&&is_avail[an-1001]==false){
        account *ac;
        ac=&accounts[an-1001];
        bool is=ac->verify_pin(p);
        if(is){
            double cb=ac->get_balance();
            if(cb>=d){
            double nb=cb-d;
            ac->set_balance(nb);
            cout<<"New balance of account no "<<an<<":"<<nb<<endl;;
            return;
            }
            else {
              cout  <<"insufficient balance"<<endl;
              return;
            }
        }
        else {cout<<" wrong pin"<<endl;
        return;
        }

    }
    else cout<<"Account Does Not Exist"<<endl;
    return;
}
void close_balance(int an,int p){
    if(an<=1100&&an>=1001&&is_avail[an-1001]==false){
        account * ac;
        ac=&accounts[an-1001];
        bool is=ac->verify_pin(p);
        if(is){
            is_avail[an-1001]=true;
            ac= new account();
            cout<<"Account closed"<<endl;
            return;
        }
        else {cout<<" wrong pin"<<endl;
        return;}

    }
    else cout<<"Account Does not exist"<<endl;
}
void interest(double in,int p){

        if(p==special_pin){
            for(int i=0;i<100;i++){
                    if(is_avail[i]==false){
                           account * ac=&accounts[i];
                          double cb=ac->get_balance();
                        double nb=cb+((cb*in*1)/100); //computing interest @i for 1 year
                         ac->set_balance(nb);
                    }

            }
            cout<<"Interest Applied"<<endl;
            return;
        }
        else {cout<<" wrong pin"<<endl;
        return;}

}
void print_all(int p){

        if(p==special_pin){
            for(int i=0;i<100;i++){
                     if(is_avail[i]==false){
                account * ac=&accounts[i];
                int an=ac->get_account_no();
                double ab=ac->get_balance();
                cout<<"account no : "<<an<<" balance "<<ab<<endl;
                     }

            }

            return;
        }
        else {cout<<" wrong pin"<<endl;
        return;}

}
void close_all(int p){

        if(p==special_pin){
                 delete[] accounts;
                 delete[] is_avail;
                cout<<"all account deleted"<<endl;
            return;
        }
        else {cout<<" wrong pin"<<endl;
        return;}

}


int main()
{
    for(int i=0;i<100;i++)is_avail[i]=true;

    while(1){
    cout<<"Enter Transaction Type"<<endl;
    char ty;
    cin>>ty;
    if(ty=='O'){
        double am;
        int p;
        cout<<"Enter ammount ?"<<endl;
        cin>>am;
        cout<<"Enter pin ?"<<endl;
        cin>>p;
        open_balance(am,p);
    }
    else if(ty=='B'){
        int an, p;
        cout<<"Enter account no ?"<<endl;
        cin>>an;
        cout<<"Enter pin ?"<<endl;
        cin>>p;
        balance_inquiry(an,p);
    }
    else if(ty=='D'){
        double d;
        int an, p;
        cout<<"Enter account no ?"<<endl;
        cin>>an;
        cout<<"Enter deposit ?"<<endl;
        cin>>d;
        cout<<"Enter pin ?"<<endl;
        cin>>p;
        deposit(an,p,d);
    }
    else if(ty=='W'){
        double d;
        int an, p;
        cout<<"Enter account no ?"<<endl;
        cin>>an;
        cout<<"Enter withdrawl ammount ?"<<endl;
        cin>>d;
        cout<<"Enter pin ?"<<endl;
        cin>>p;
        withdrawl(an,p,d);
    }
    else if(ty=='C'){

        int an, p;
        cout<<"Enter account no ?"<<endl;
        cin>>an;
        cout<<"Enter pin ?"<<endl;
        cin>>p;
        close_balance(an,p);
    }
    else if(ty=='I'){
        int p;
        double i;
        cout<<"Enter special pin ?"<<endl;
        cin>>p;
        cout<<"Enter interest ?"<<endl;
        cin>>i;
        interest(i,p);
    }
    else if(ty=='P'){

        int p;
        cout<<"Enter special pin ?"<<endl;
        cin>>p;
        print_all(p);
    }
    else if(ty=='E'){
        int p;
        cout<<"Enter special pin ?"<<endl;
        cin>>p;
        close_all(p);
        break;

    }
    }
    return 0;
}
