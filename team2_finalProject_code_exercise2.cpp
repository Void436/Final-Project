/*

READ user's choice from main menu 
COMPLY with user's choice 
FOR 1: DISPLAY a single product info
FOR 2: DISPLAY all product info
FOR 3: CALCULATE the user's purchase with taxes and total 
       DISPLAY the receit 
FOR 4:  CALCULATE and DISPLAY stock  quantity and be able to add  to stock
FOR 5: EXIT

*/     

#include <limits>
#include <iostream>
using namespace std;



struct Product {
    int code;
    string dimension;
    float unit_price;
    int current_stock = 0;
};


//Declare variables and constants and initialize

const float tps = 0.05;
const float tvq = 0.9975;

template <typename T>
//declaring functions
void information(const T& p);
int read_mainMenu ();
int read_stockMenu();
void stock_inventory (int code);
void calculate_User_Purchase ();
void calculate_Add_ToStock ( int code, int quantity );


//Main Program
int main()
{

    //Declare variables and constants and initialize
    Product small, medium, big, extra;
    int user_choice;

    //filling the product info
        //small
        small.code = 50;
        small.dimension = "Small";
        small.unit_price = 15.99;
        //medium
        medium.code = 100;
        medium.dimension = "Medium";
        medium.unit_price = 24.99;
        //small
        big.code = 250;
        big.dimension = "Big";
        big.unit_price = 49.99;
        //medium
        extra.code = 500;
        extra.dimension = "Extra";
        extra.unit_price = 89.99;

    while (user_choice != 5){
        cout 
        << "***************************************************************" <<endl
        << "*************  Welcome to CALCULATOR PLUS !  ******************" <<endl
        << "Choose :" <<endl
        << "1 for INFORMATION ABOUT 1 PRODUCT" <<endl
        << "2 for INFORMATION ABOUT ALL THE PRODUCTS" <<endl
        << "3 for PURCHASE CALCULATOR" <<endl
        << "4 for STOCK INVENTORY AND REPLENISHMENTS" <<endl
        << "5 for EXIT" <<endl
        << "***************************************************************" <<endl
        << "Write your choice below: (1 to 5)" <<endl ;
        cin >>user_choice;
        while (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (user_choice == 1) {
            while (user_choice != 50 & user_choice != 100 & user_choice != 250 & user_choice != 500){
            //invite input and make sure it is a number
            cout << "invite input" ;
            cin >>user_choice;
            while (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            //actual choice
            if (user_choice == 50){
                information(small);
            }
            else if (user_choice == 100){
                information(medium);
            }
            else if (user_choice == 250){
                information(big);
            }
            else if (user_choice == 500){
                information(extra);
            }
            else {
                cout << "you fool";
            }
        }
        }

        else if (user_choice == 2) {
            information(small);
            information(medium);
            information(big);
            information(extra);
            //names_of_the_other_functions (other variables);
        }
        else {
            cout << "ERROR! You wrote a wrong number. Try again!" <<endl;
        }
    }
}


















//robert
template <typename T>
void information(const T& p)
{
    cout
    << "----------------------------------------------------------------" <<endl
    << "CODE            : " << p.code <<endl
    << "DIMENSION       : " << p.dimension <<" ml" <<endl
    << "UNIT PRICE      : " << p.unit_price <<" $CA" <<endl
    << "TPS             : " << p.tps <<" $CA" <<"    (5%)" <<endl
    << "TVQ             : " << p.tvq <<" $CA" <<"   (9.975%)" <<endl
    << "TOTAL           : " << p.total <<" $CA" <<endl
    << "CURRENT STOCK   : " << p.current_stock <<" items" <<endl
    << "----------------------------------------------------------------" <<endl;
}

int read_mainMenu () {

}




















//fin


int read_stockMenu(){

}
 
void stock_inventory (int code) {

}




















//skander



void calculate_User_Purchase (){

}
 
void calculate_Add_ToStock ( int code, int quantity ){

}


