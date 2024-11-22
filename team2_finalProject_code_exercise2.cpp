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
int main (){

    //Declare variables and constants and initialize
    Product small, medium, big, extra;
    

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


    //Invite, read and save inputs
    


    //Calculate



    //Display outputs




    return 0;

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


