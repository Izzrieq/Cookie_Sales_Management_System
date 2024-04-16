// library declaration
#include <iostream>
#include <string>
// for table width (setw)
#include <iomanip>
using namespace std;

// set max array
const int MAX = 50;

// to create line as table border
char line = '=';

// array declaration
int transactionNo[MAX];
int quantitySold[MAX];
double pricePerUnit[MAX];
string cookieType[MAX];
string customerName[MAX];

// set count back to 0
int countTransaction = 0;

//[1]recordsales function start
void recordSales()
{
    if (countTransaction < MAX)
    {
        cout << "Enter the transaction detail: " << endl;
        // User start enter detail about customer
        cout << "Transaction No: ";
        cin >> transactionNo[countTransaction];
        // to check the transactionNo not less than 0
        if (transactionNo[countTransaction] < 0)
        {
            cout << "Transaction No must be greater than 0 \n";
            return recordSales();
        }
        cin.ignore();

        cout << "Cookie Type: ";
        cin >> cookieType[countTransaction];

        cout << "Quantity sold: ";
        cin >> quantitySold[countTransaction];
        if (quantitySold[countTransaction] < 0)
        {
            cout << "Quantity must be greater than 0 \n";
            return recordSales();
        }

        cout << "Price per unit: ";
        cin >> pricePerUnit[countTransaction];
        cin.ignore();
        if (pricePerUnit[countTransaction] < 0)
        {
            cout << "Price per unit must be greater than 0 \n";
            return recordSales();
        }

        cout << "Customer Name: ";
        getline(cin, customerName[countTransaction]);
        countTransaction++;
        // enter customer details end
    }
    else
    {
        cout << "Transaction maximum reached" << endl;
    }
}
//[1]recordsales function end

//[2]calculatetotalrevenue function start
double calculateTotalRevenue()
{
    double total = 0.0;
    for (int i = 0; i < countTransaction; i++)
    {
        /* i is for index
        total declaration is to sum for all quantitySold * pricePerUnit depends on which index*/
        total += quantitySold[i] * pricePerUnit[i];
    }
    return total;
}
//[2]totalrevenue function end

//[3]displaysalesrecords function start
void displaySalesRecords()
{
    if (countTransaction < 1)
    {
        cout << "There's is no Record Sales \n";
    }
    else
    {
        cout << "Sales Records:" << endl;
        for (int i = 0; i < 100; i++)
        {
            cout << line;
        }
        cout << "\n";
        // this is table heading, i use iomanip library to set with for heading
        cout << "Trans No" << setw(15) << "Cookie Type" << setw(15) << "Quantity" << setw(15) << "Price" << setw(15) << "Customer" << endl;
        for (int i = 0; i < 100; i++)
        {
            cout << line;
        }
        cout << "\n";
        for (int i = 0; i < countTransaction; i++)
        {
            // use for loop to display all data that contain inside of array
            cout << transactionNo[i] << setw(15) << cookieType[i] << setw(15) << quantitySold[i] << setw(20) << "RM" << pricePerUnit[i] << setw(10) << customerName[i] << endl;
        }
        for (int i = 0; i < 100; i++)
        {
            cout << line;
        }
    }
}
//[3]displaysalesrecords function end

//[4]displaysalesrecords function start
// pass parameter
void findSalesByCustomer(string customersearch)
{
    cout << "Sales Records for Customer " << customersearch << ":" << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << line;
    }
    cout << "\n";
    cout << "Trans No" << setw(15) << "Cookie Type" << setw(15) << "Quantity" << setw(15) << "Price" << setw(15) << "Customer"
         << endl;
    cout << "\n";
    for (int i = 0; i < 100; i++)
    {
        cout << line;
    }
    cout << "\n";
    // function start to search for customername
    bool foundcustomer = false;
    for (int i = 0; i < countTransaction; i++)
    {
        if (customerName[i] == customersearch)
        {
            foundcustomer = true;
            cout << transactionNo[i] << setw(15) << cookieType[i] << setw(15) << quantitySold[i] << setw(20) << "RM" << pricePerUnit[i] << setw(10) << customerName[i] << endl;
        }
    }
    if (!foundcustomer)
    {
        cout << " \n  No sales record for customer :" << customerName << "\n"
             << endl;
    }
}
//[4]displaysalesrecords function end

//[5] updatesalesrecords function start
void updateSalesRecord(int updatetrans)
{
    for (int i = 0; i < countTransaction; i++)
    {
        if (transactionNo[i] == updatetrans)
        {
            cout << "Enter new detail " << updatetrans << ": " << endl;

            // entering all new data for the customer detail
            cout << "Cookie type: ";
            cin >> cookieType[i];

            cout << "Quantity Sold: ";
            cin >> quantitySold[i];

            cout << "Price Per Unit: ";
            cin >> pricePerUnit[i];
            cin.ignore();

            cout << "Customer Name: ";
            getline(cin, customerName[i]);

            cout << "Sales record updated successfully.\n";
            return;
        }
    }
    cout << "The transaction not found in the system" << endl;
}
//[5] updatesalesrecords function end

int main()
{

    int choice;

    // using do while loop to achive system that will ask user to choose the option until user hit number '6'
    do
    {
        for (int i = 0; i < 40; i++)
        {
            cout << line;
        }
        cout << "\nCookie Sales Management System\n";
        cout << "[1] Record Sales\n";
        cout << "[2] Calculate Total Revenue\n";
        cout << "[3] Display Sales Records\n";
        cout << "[4] Find Sales by Customer\n";
        cout << "[5] Update Sales Record\n";
        cout << "[6] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:
            recordSales();
            break;
        case 2:
            cout << "Total Revenue: RM" << calculateTotalRevenue() << "\n";
            break;
        case 3:
            displaySalesRecords();
            break;
        case 4:
        {
            string customersearch;
            cout << "Enter customer name: ";
            cin.ignore();
            getline(cin, customersearch);
            // user need to enter exact same name as in the array beware for capital letter
            findSalesByCustomer(customersearch);
        }
        break;
        case 5:
        {
            int updatetrans;
            cout << "Enter transaction number to update: ";
            cin >> updatetrans;
            // using transactionNo = updatetrans to achive updatesalesrecord()
            updateSalesRecord(updatetrans);
        }
        break;
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    return 0;
}