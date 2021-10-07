#include<bits/stdc++.h>

using namespace std;

/// PIYUSH KUMAR ///


class atm{
    private:
        long int account_no;
        string name;
        int pin;
        double balance;
        string mobile_no;
    
    public:
        void setData(long int account_no_a , string name_a , int pin_a, double balance_a, string mobile_no_a){
            account_no=account_no_a;
            name=name_a;
            pin=pin_a;
            balance=balance_a;
            mobile_no=mobile_no_a;
        }
    
    long int getaccountno(){
        return account_no;
    }
    string getname(){
        return name;
    }
    int getpin(){
        return pin;
    }
    double getbalance(){
        return balance;
    }
    string getmobile(){
        return mobile_no;
    }
    
    //change mobile no.
    void setmob(string mob_prev, string mob_new){
        if(mob_prev==mobile_no){
            cout<<"successfully updated mobile no";
            getch();
        }
        else{
            cout<< " INCORRECT!! OLD MOBILE NO.";
            getch();
        }
    }
    //cash withdrawal
    void cashwidr(int amount_a){
        if(amount_a>0 && amount_a<balance){
            balance=balance - amount_a;
            cout<<"COLLECT CASH"<<endl;
            cout<<"AVAIBLE BALANCE: "<<balance;
            getch();
        }
        else{
            cout<<"INSUFFICIENT BALANCE";
            getch();
        }
    }
};


int main(){
    int choice = 0, enterPIN;		//enterPIN and enterAccountNo. ---> user authentication
	long int enterAccountNo;

	system("cls");
	atm user1;
	user1.setData(1234567, "POOJA", 1111, 45000.90, "9999999999");


	do
	{
		system("cls");

		cout << endl << "****Welcome to ATM*****" << endl;
		cout << endl << "Enter Your Account No ";	  
		cin >> enterAccountNo;
		cout << endl << "Enter PIN ";				  
		cin >> enterPIN;



		// check whether enter values matches with user details
		if ((enterAccountNo == user1.getaccountno()) && (enterPIN == user1.getpin()))
		{
			do
			{
				int amount = 0;
				string oldMobileNo, newMobileNo;

				system("cls");
				// user Interface
				cout << endl << "**** Welcome to ATM *****" << endl;
				cout << endl << "Select Options ";
				cout << endl << "1. Check Balance";
				cout << endl << "2. Cash withdraw";
				cout << endl << "3. Show User Details";
				cout << endl << "4. Update Mobile no.";
				cout << endl << "5. Exit" << endl;
				cin >> choice;						

				switch (choice)					
				{
				case 1:								
					cout << endl << "Your Bank balance is :" << user1.getbalance(); 
																					
					getch();
					break;


				case 2:									// if user presses 2
					cout << endl << "Enter the amount :";		
					cin >> amount;
					user1.cashwidr(amount);			// calling cashWithdraw function 
													    // passing the withdraw amount 
					break;


				case 3:										// if user presses 3
					cout << endl << "*** User Details are :- ";
					cout << endl << "-> Account no" << user1.getaccountno();
					cout << endl << "-> Name      " << user1.getname();
					cout << endl << "-> Balance   " << user1.getbalance();
					cout << endl << "-> Mobile No." << user1.getmobile();
													// getting and printing user details
					getch();
					break;


				case 4:								   //  if user presses 4
					cout << endl << "Enter Old Mobile No. ";
					cin >> oldMobileNo;							// take old mobile no

					cout << endl << "Enter New Mobile No. ";
					cin >> newMobileNo;							// take new mobile no

					user1.setmob(oldMobileNo, newMobileNo);	// now set new mobile no
					break;

													// if user presses 5
				case 5:
					exit(0);						// exit application

				default:							// handle invalid user inputs
					cout << endl << "Enter Valid Data !!!";
				} 

			} while (1);				// MENU	   // condition will always TRUE and loop is										capable of running infinite times
		}

		else
		{
			cout << endl << "User Details are Invalid !!! ";
			getch();
		}
	} while (1);						//LOGIN		// condition will always TRUE and loop is										capable of running infinite times

	return 0;
}
