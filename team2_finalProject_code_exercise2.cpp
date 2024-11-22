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


//declaring functions
void write_productInfo (int code);
int read_mainMenu ();
int read_stockMenu();
void stock_inventory (int code);
void calculate_User_Purchase ();
void calculate_Add_ToStock ( int code, int quantity );


//Main Program
int main (){

    //Declare variables and constants and initialize



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


