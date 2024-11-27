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




int main() {

    //Declare variables and constants and initialize
    Product small = {50, "Small", 15.99, 0};
    Product medium = {100, "Medium", 24.99, 0};
    Product big = {250, "Big", 49.99, 0};
    Product extra = {500, "Extra", 89.99, 0};
    Product products[] = {small, medium, big, extra};

    int user_choice;
    int purchased_qty[4] = {0, 0, 0, 0};


    do {

        //Invite, read and save inputs
        user_choice = read_MainMenu();


        if (user_choice == 1) {
            
            //Display outputs
            write_Stock_Inventory(products, 4);

        } 

        
        else if (user_choice == 2) {

            cout << endl;

            for (int i = 0; i < 4; i++) {

                //Display outputs
                information(products[i]);
            
            }
        } 

        
        else if (user_choice == 3) {
            
            //Calculate
            calculate_User_Purchase(products, 4, purchased_qty);

        } 

        
        else if (user_choice == 4) {

            //Declare variables and constants and initialize
            int stock_choice = 0;

            do {
                
                //Invite, read and save inputs
                stock_choice = read_StockMenu();


                if (stock_choice == 1) {
                    
                    //Declare variables and constants and initialize
                    int code;
                    bool code_verif = false;

                    
                    //Invite, read and save inputs
                    do {

                        cout << "Enter the CODE of the product (50, 100, 250, or 500) to display its details: " << endl;
                        cin >> code;

                        
                        if ( (code != 50 && code != 100 && code != 250 && code !=500) || cin.fail()) {

                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "The product code entered is not valid." << endl << endl;
                            code_verif = false;

                        }

                        else {
                            
                            cout << endl;
                            code_verif = true;

                        }

                    } while (code_verif == false);

                    if (code == 50) {
                        
                        //Display outputs
                        one_Information(products[0]);
                    
                    }

                    else if (code == 100) {
                        
                        //Display outputs
                        one_Information(products[1]);
                    
                    }

                    else if (code == 250) {
                        
                        //Display outputs
                        one_Information(products[2]);
                    
                    }

                    else if (code == 500) {
                        
                        //Display outputs
                        one_Information(products[3]);
                    
                    }

                } 
                
                else if (stock_choice == 2) {

                    //Calculate
                    replenish_Stock_Inventory(products, 4);

                }

            } while (stock_choice != 3);

            
            

        }
        
    } while (user_choice != 5);


    //Display outputs
    cout << endl << "Thank you for using CALCULATOR PLUS! See you next time!" << endl << endl;

    return 0;
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



void show_Receipt(const Product products[], int size, const int purchased_qty[]) {
 
    //Declare variables and constants and initialize
    float total_before_tax = 0;
    float total_tps = 0;
    float total_tvq = 0;
    float grand_total = 0;
    int total_products = 0;
 
    //Display outputs
    cout << fixed << setprecision(2);
    cout << endl << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "Code\tDimension\tQty\tUnit Price\tSubtotal\tTPS\tTVQ\tTotal" << endl;
 
    //Calculate
    for (int i = 0; i < size; i++) {
        if (purchased_qty[i] > 0) {
            float subtotal = purchased_qty[i] * products[i].unit_price;
            float tps = subtotal * TPS;
            float tvq = subtotal * TVQ;
            float total = subtotal + tps + tvq;
 
            total_before_tax += subtotal;
            total_tps += tps;
            total_tvq += tvq;
            grand_total += total;
            total_products += purchased_qty[i];
 
            //Display outputs
            cout << products[i].code << "\t" << products[i].dimension << "\t\t" << purchased_qty[i]
                 << "\t" << products[i].unit_price << "\t\t" << subtotal
                 << "\t\t" << tps << "\t" << tvq << "\t" << total << endl;
        }
    }
 
    //Display outputs
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << endl << "NOMBRE DE PRODUITS ACHETES \t:\t" << total_products << "\titems" << endl;
    cout << "PRIX HORS TAXES\t\t\t:\t" << total_before_tax << "\t$CA" << endl;
    cout << "\tTPS\t\t\t:\t" << total_tps << "\t$CA" << endl;
    cout << "\tTVQ\t\t\t:\t" << total_tvq << "\t$CA" << endl;
    cout << "PRIX AVEC TAXE\t\t\t:\t" << grand_total << "\t$CA" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
 
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

            //Display outputs
            one_Information(products[i]);


            do {

                //Invite, read and save inputs
                cout << "How many new items to ADD to the stock?:" << endl;
                cin >> quantity;

                if (cin.fail() || quantity < 0) {

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Please, write a POSITIVE number." << endl << endl;

                }

            } while (cin.fail() || quantity < 0);
            

            //Calculate
            calculate_Add_ToStock(products[i], quantity);

            return;
        }
    }
    

}




void calculate_User_Purchase(Product products[], int size, int purchased_qty[]) {

    //Declare variables and constants and initialize
    int code;
    int quantity;
    float total_before_tax = 0;
    float total_tps = 0;
    float total_tvq = 0;
    float grand_total = 0;
    int total_products = 0;
    bool code_verif = false;
    bool all_good = false;


    for (int i = 0; i < size; i++) {
        purchased_qty[i] = 0;
    }

    do {


        //Invite, read and save inputs
        do {

            cout << endl << "Enter the CODE of the product you bought (50, 100, 250, or 500) or 0 to show the receipt: " << endl;
            cin >> code;

            if ((code != 50 && code != 100 && code != 250 && code != 500 && code != 0) || cin.fail()) {
                
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                //Display outputs
                cout << "The product code entered is not valid." << endl << endl;
                code_verif = false;

            } 
            
            else {

                code_verif = true;

            }

        } while (code_verif == false);

        
        if (code == 0) {
            
            //Display outputs
            show_Receipt(products, size, purchased_qty);
            all_good == true;
            return;

        }

        else {

            do {
                
                if (code == 50) {

                    //Invite, read and save inputs
                    do {

                        cout << endl << "Enter the QUANTITY you bought or 0 if this product is out of stock or to go back:" << endl;
                        cin >> quantity;

                        if (cin.fail() || quantity < 0) {

                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Please, write a POSITIVE number." << endl << endl;

                        }

                    } while (cin.fail() || quantity < 0);

                    if (quantity == 0) {

                        cout << "This product is out of stock." << endl << endl;
                        all_good = false;
                        
                    }


                    if (products[0].code == code) {

                        do {
                            if (quantity > products[0].current_stock) {

                                //Display outputs
                                cout << "ERROR! You have only " << products[0].current_stock << " in stock. You cannot buy " << quantity << " unit of this product now." << endl << endl;
                                all_good = false;
                                break;

                            }

                            else if (quantity == 0) {

                                all_good = false;
                                break;

                            }

                            else {

                                //Calculate
                                products[0].current_stock -= quantity;
                                purchased_qty[0] += quantity;

                                //Display outputs
                                cout << quantity << " product of dimension " << products[0].dimension << " (" << products[0].code << " ml) have been added to your cart." << endl;
                                all_good = false;
                                break;
                                return;

                            }
                        } while (true);
                    }
                    break;
                }
                
                else if (code == 100) {

                    //Invite, read and save inputs
                    do {

                        cout << endl << "Enter the QUANTITY you bought or 0 if this product is out of stock or to go back:" << endl;
                        cin >> quantity;

                        if (cin.fail() || quantity < 0) {

                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Please, write a POSITIVE number." << endl << endl;

                        }

                    } while (cin.fail() || quantity < 0);

                    if (quantity == 0) {

                        cout << "This product is out of stock." << endl << endl;
                        all_good = false;
                        
                    }


                    if (products[1].code == code) {

                        do {
                            if (quantity > products[1].current_stock) {

                                //Display outputs
                                cout << "ERROR! You have only " << products[1].current_stock << " in stock. You cannot buy " << quantity << " unit of this product now." << endl << endl;
                                all_good = false;
                                break;

                            }

                            else if (quantity == 0) {

                                all_good = false;
                                break;

                            }

                            else {

                                //Calculate
                                products[1].current_stock -= quantity;
                                purchased_qty[1] += quantity;

                                //Display outputs
                                cout << quantity << " product of dimension " << products[1].dimension << " (" << products[1].code << " ml) have been added to your cart." << endl;
                                all_good = false;
                                break;
                                return;

                            }
                        } while (true);
                    }
                    break;
                }
                
                else if (code == 250) {

                    //Invite, read and save inputs
                    do {

                        cout << endl << "Enter the QUANTITY you bought or 0 if this product is out of stock or to go back:" << endl;
                        cin >> quantity;

                        if (cin.fail() || quantity < 0) {

                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Please, write a POSITIVE number." << endl << endl;

                        }

                    } while (cin.fail() || quantity < 0);

                    if (quantity == 0) {

                        cout << "This product is out of stock." << endl << endl;
                        all_good = false;
                        
                    }


                    if (products[2].code == code) {

                        do {
                            if (quantity > products[2].current_stock) {

                                //Display outputs
                                cout << "ERROR! You have only " << products[2].current_stock << " in stock. You cannot buy " << quantity << " unit of this product now." << endl << endl;
                                all_good = false;
                                break;

                            }

                            else if (quantity == 0) {

                                all_good = false;
                                break;

                            }

                            else {

                                //Calculate
                                products[2].current_stock -= quantity;
                                purchased_qty[2] += quantity;

                                //Display outputs
                                cout << quantity << " product of dimension " << products[2].dimension << " (" << products[2].code << " ml) have been added to your cart." << endl;
                                all_good = false;
                                break;
                                return;

                            }
                        } while (true);
                    }
                    break;
                }
                
                else if (code == 500) {

                    //Invite, read and save inputs
                    do {

                        cout << endl << "Enter the QUANTITY you bought or 0 if this product is out of stock or to go back:" << endl;
                        cin >> quantity;

                        if (cin.fail() || quantity < 0) {

                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Please, write a POSITIVE number." << endl << endl;

                        }

                    } while (cin.fail() || quantity < 0);

                    if (quantity == 0) {

                        cout << "This product is out of stock." << endl << endl;
                        all_good = false;
                        
                    }


                    else if (products[3].code == code) {

                        do {
                            if (quantity > products[3].current_stock) {

                                //Display outputs
                                cout << "ERROR! You have only " << products[3].current_stock << " in stock. You cannot buy " << quantity << " unit of this product now." << endl << endl;
                                all_good = false;
                                break;

                            }

                            else if (quantity == 0) {

                                all_good = false;
                                break;

                            }

                            else {

                                //Calculate
                                products[3].current_stock -= quantity;
                                purchased_qty[3] += quantity;

                                //Display outputs
                                cout << quantity << " product of dimension " << products[3].dimension << " (" << products[3].code << " ml) have been added to your cart." << endl;
                                all_good = false;
                                break;
                                return;

                            }
                        } while (true);
                    }
                    break;
                }
            } while (all_good == false);
        }

    } while (all_good == false);
    

}


 


void write_Stock_Inventory(const Product products[], int size) {

    //Declare variables and constants and initialize
    int code;
    bool code_verif = false;

    //Invite, read and save inputs
    do {

        cout << "Enter the CODE of the product (50, 100, 250, or 500) to display its details: " << endl;
        cin >> code;

        
        if ( (code != 50 && code != 100 && code != 250 && code !=500) || cin.fail()) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            //Display outputs
            cout << "The product code entered is not valid." << endl << endl;
            code_verif = false;

        }

        for (int i = 0; i < size; i++) {

            if (products[i].code == code) {

                cout << endl;
                code_verif = true;
                //Display outputs
                information(products[i]);
                return;

            }
        }

    } while (code_verif == false);

}
