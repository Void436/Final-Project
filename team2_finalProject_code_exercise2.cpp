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
#include <limits> // to reject alphabets in input
#include <iomanip> // for only 2 numbers after the decimal
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


//Declaring functions
void information(const Product& product);
int read_MainMenu();
int read_StockMenu();
void calculate_User_Purchase(Product products[], int size, int purchased_qty[]);
void calculate_Add_ToStock(Product& product, int quantity);
void write_Stock_Inventory(const Product products[], int size);
void one_Information(const Product& product);
void replenish_Stock_Inventory(Product products[], int size);
void show_Receipt(const Product products[], int size, const int purchased_qty[]);




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









//FINLEY
int read_StockMenu() {
 
    //Declare variables and constants and initialize
    int choice;
 
    //Invite, read and save inputs
    do {
        cout << "******************************************************************************************************************" << endl;
        cout << "Choose :" << endl;
        cout << "\t1. for STOCK INVENTORY" << endl;
        cout << "\t2. for STOCK REPLENISHMENT" << endl;
        cout << "\t3. for MAIN MENU" << endl;
        cout << "******************************************************************************************************************" << endl;
        cout << "Write your choice below (1 to 3) " << endl;
        cin >> choice;
 
        if (choice < 1 || choice > 3 || cin.fail()) {
 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
 
            //Display outputs
            cout << "ERROR! You wrote a wrong number. Try again!" << endl << endl;
            choice = 0;
 
        }
 
    } while (choice < 1 || choice > 3);
 
 
    return choice;
 
}



void one_Information(const Product& product) {
 
    //Display outputs
    cout << fixed << setprecision(2);
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "CODE\t\t:  " << product.code << endl;
 
    if (product.code == 250) {
           
        cout << "DIMENSION\t:  " << product.dimension << "\t\tml" << endl;
   
    }
 
 
    else {
 
        cout << "DIMENSION\t:  " << product.dimension << "\tml" << endl;
 
    }
 
    cout << "CURRENT STOCK\t:  " << product.current_stock << "\t\titems" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
 
}



void calculate_Add_ToStock(Product& product, int quantity) {
 
    //Calculate
    product.current_stock += quantity;

    //Display outputs
    cout << "The stock was REPLENISHED successfully." << endl << endl;
 
}
















//ROBERT
void information(const Product& product) {
    
    //Display outputs
    cout << fixed << setprecision(2);
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "CODE\t\t:  " << product.code << endl;
 
    if (product.code == 250) {
           
        cout << "DIMENSION\t:  " << product.dimension << "\t\tml" << endl;
   
    }
 
    else {
 
        cout << "DIMENSION\t:  " << product.dimension << "\tml" << endl;
 
    }
 
    //Calculate and display outputs
    cout << "UNIT PRICE\t:  " << product.unit_price << "\t$CA" << endl;
    cout << "TPS\t\t:  " << product.unit_price * TPS << "\t\t$CA\t(5%)" << endl;
    cout << "TVQ\t\t:  " << product.unit_price * TVQ << "\t\t$CA\t(9.975%)" << endl;
    cout << "TOTAL\t\t:  " << (product.unit_price * TPS)  + (product.unit_price * TVQ) + product.unit_price << "\t$CA" << endl;
    cout << "CURRENT STOCK\t:  " << product.current_stock << "\t\titems" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl << endl;

}
 


int read_MainMenu() {

    //Declare variables and constants and initialize
    int choice;

    //Invite, read and save inputs
    do {

        cout << "******************************************************************************************************************" << endl;
        cout << "*****************************************  Welcome to CALCULATOR PLUS !  *****************************************" << endl;
        cout << "Choose :" << endl;
        cout << "\t1. for INFORMATION ABOUT 1 PRODUCT" << endl;
        cout << "\t2. for INFORMATION ABOUT ALL THE PRODUCTS" << endl;
        cout << "\t3. for PURCHASE CALCULATOR" << endl;
        cout << "\t4. for STOCK INVENTORY AND REPLENISHMENT" << endl;
        cout << "\t5. for EXIT" << endl;
        cout << "******************************************************************************************************************" << endl;
        
        cout << "Enter your choice (1-5): " << endl;
        cin >> choice;
 
        if (choice < 1 || choice > 5 || cin.fail()) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            //Display outputs
            cout << "ERROR! You wrote a wrong number. Try again!" << endl << endl;
            choice = 0;

        }

    } while (choice < 1 || choice > 5);

    return choice;

}



void show_Receipt(const Product products[], int size, const int purchased_qty[]){

}




















//SKANDER
void replenish_Stock_Inventory(Product products[], int size) {

    //Declare variables and constants and initialize
    int code;
    int quantity;
    bool code_verif = false;

    //Invite, read and save inputs
    do {

        cout << "Enter the CODE of the product (50, 100, 250, or 500) to REPLENISH your stock: " << endl;
        cin >> code;

        if ((code != 50 && code != 100 && code != 250 && code != 500) || cin.fail()) {
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "The product code entered is not valid." << endl << endl;
            code_verif = false;

        } 
        
        else {

            code_verif = true;

        }

    } while (code_verif == false);

    cout << endl;

    for (int i = 0; i < size; i++) {

        if (products[i].code == code) {

            one_Information(products[i]);


            do {

                cout << "How many new items to ADD to the stock?:" << endl;
                cin >> quantity;

                if (cin.fail() || quantity < 0) {

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Please, write a POSITIVE number." << endl << endl;

                }

            } while (cin.fail() || quantity < 0);
            
            calculate_Add_ToStock(products[i], quantity);

            return;
        }
    }
    

}



void calculate_User_Purchase (){

}
 

void write_Stock_Inventory(const Product products[], int size){

}


