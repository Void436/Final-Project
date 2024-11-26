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

#include <iostream>
using namespace std;


//Declare variables and constants and initialize

struct Product {
    int code;
    string dimension;
    float unit_price;
    int current_stock = 0;
};

const float TPS = 0.05;
const float TVQ = 0.09975;



//declaring functions
void information(const Product& product);
int read_mainMenu();
int read_stockMenu();
void stock_inventory(Product& product);
void calculate_User_Purchase(Product products[], int size);
void calculate_Add_ToStock(Product& product, int quantity);




//main Program
int main()
{

    //Declare variables and constants and initialize
    Product small, medium, big, extra;
    int user_choice;
    int user_choice_sequel;

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
            while (user_choice_sequel != 50 & user_choice_sequel != 100 & user_choice_sequel != 250 & user_choice_sequel != 500){
            //invite input and make sure it is a number
            cout << "Enter the CODE of the product (50, 100, 250 or 500) to display it's details:" <<endl;
            cin >>user_choice_sequel;
            while (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            //actual choice
            if (user_choice_sequel == 50){
                information(small);
            }
            else if (user_choice_sequel == 100){
                information(medium);
            }
            else if (user_choice_sequel == 250){
                information(big);
            }
            else if (user_choice_sequel == 500){
                information(extra);
            }
            else {
                cout << "The product code entered is not valid." <<endl;
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

        else if (user_choice == 3) {

        }

        else if (user_choice == 4) {

        }

        else if (user_choice == 5) {
            cout << "Thank you for shopping at Sirop d'Érable Montréal.See you soon!";
        }

        else {
            cout << "ERROR! You wrote a wrong number. Try again!" <<endl;
        }
    }
}


















//robert
 
void information(const Product& product) {
    cout << fixed << setprecision(2);
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "CODE\t\t:  " << product.code << endl;
 
    if (product.code == 250) {
           
        cout << "DIMENSION\t:  " << product.dimension << "\t\tml" << endl;
   
    }
 
    else {
 
        cout << "DIMENSION\t:  " << product.dimension << "\tml" << endl;
 
    }
 
    cout << "UNIT PRICE\t:  " << product.unit_price << "\t$CA" << endl;
    cout << "TPS\t\t:  " << product.unit_price * TPS << "\t\t$CA\t(5%)" << endl;
    cout << "TVQ\t\t:  " << product.unit_price * TVQ << "\t\t$CA\t(9.975%)" << endl;
    cout << "TOTAL\t\t:  " << (product.unit_price * TPS)  + (product.unit_price * TVQ) + product.unit_price << "\t$CA" << endl;
    cout << "CURRENT STOCK\t:  " << product.current_stock << "\t\titems" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
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


