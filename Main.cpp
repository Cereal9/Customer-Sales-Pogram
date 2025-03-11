/*
CSCE 306  Karl,Ethan,Cesar and Richard


This program is a way for a company to keep track of their customers.
It can store customer data into vectors from a file called 
customers.txt. Once Stored workers can look up customers for 
their information either by their first name or Id number.

This program can also check order status by looking up customers
orders with an OrderID. It can find when the order was placed by reading
the orders.txt file.

Another feature of this program is that it can add customers into a
queue for rainbow tribles. This allows the company to keep track
of who is able to get the rainbow tribles when they first arrive
people can be removed once they have recieved their order.

Finally This program can handle customer sales. It can look
up a customer check to make sure they exist before creating an order
once all information about quantity and price is all entered into the system
it will save the data in a transactions.txt file and an orders.txt file
to keep track of the information for the rest of the program


*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <iomanip>
#include "Orders.h"
#include "Customer.h"
#include "transactions.h"
#include "Salesperson.h"
#include "Sales.h"
#include "SuperSales.h"
#include "Supervisor.h"
#include "Manager.h"
#include <sstream>






using namespace std;

//This function and vector will read from a file called customers.txt
//It will Take customers information and split it where ever
//there is a semi colon once all store into the vector then closes the file
vector<Customer> readCustomerData() {
    vector<Customer> customers;
    ifstream file("customers.txt");

    if (!file) {
        cerr << "Error: Unable to open customer.txt" << endl;
        return customers;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        

        
        string  id, firstName, lastName, address, city, state, zipCode;

        
        if (getline(ss, id, ';') && getline(ss, firstName, ';') && getline(ss, lastName, ';') &&
            getline(ss, address, ';') && getline(ss, city, ';') &&
            getline(ss, state, ';') && getline(ss, zipCode, ';')) {
            Customer customer(id, firstName, lastName, address, city, state, zipCode);
            customers.push_back(customer);
        }
    }

    file.close();

    return customers;
}

//This function will write to the customer file and save the new 
//customers added from case 2
void writeCustomerData(const vector<Customer>& customers) 
{
    ofstream file("customers.txt");

    if (!file) 
    {
        cerr << "Error: Unable to open customer.txt for writing" << endl;
        return;
    }

    for (const Customer& customer : customers) 
    {
        file << customer.getId() << ";" << customer.getFirstName() << ";" << customer.getLastName() << ";"
            << customer.getAddress() << ";" << customer.getCity() << ";" << customer.getState() << ";"
            << customer.getZipCode() << endl;
    }

    file.close();
}





// This vector stores information needed for Transaction
// It will read from the file transactions.txt and input it 
//into the vector Transactions
vector<Transactions> readTransactionData()
{
    vector<Transactions> transactions;
    ifstream file("transactions.txt");

    if (!file)
    {
        cerr << "Error: Unable to open transactions.txt " << endl;
        return transactions;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string temp;

        string CustID;
        string salesPersonID;
        string OrderID;
        

        getline(ss, CustID, ';');

        getline(ss, salesPersonID, ';');

        getline(ss, OrderID, ';');



        Transactions transaction(CustID, salesPersonID, OrderID);

        transactions.push_back(transaction);

    }


    file.close();
    return transactions;

}













//This Vector is for Orders it will  read the data from 
//the file orders.txt and then it will input it all into
//a vector called Orders
vector<Orders> readOrderData() {
    vector<Orders> orders;
    ifstream file("orders.txt");

    if (!file) {
        cerr << "Error: Unable to open orders.txt" << endl;
        return orders;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        

        string orderID;
        string date;
        int quantity;
        double amountPaid;

        // Use getline with stringstream to split the line based on semicolon
        
        
        getline(ss, orderID, ';');

        getline(ss, date, ';');

        getline(ss, temp, ';');
        quantity = stoi(temp);

        getline(ss, temp, ';');
        amountPaid = stod(temp);

        Orders order(orderID, date, quantity, amountPaid);
        orders.push_back(order);
    }

    file.close();
    return orders;
}





//This function will look up a customers order by taking in the OrderID
//Order ID will be found in the order vector and it will display order information
void lookupCustomerOrder(const vector<Transactions>& transactions, const vector<Orders>& orders, string customerID) {
    bool found = false;

    for (const Transactions& transaction : transactions) {
        if (transaction.getCustID() == customerID) {
            string orderID = transaction.getOrderID();

            // Search for the order in the orders vector
            for (const Orders& order : orders) {
                if (order.getOrderID() == orderID) {
                    cout << "Customer Information:" << endl;
                    cout << "Customer ID: " << customerID << endl;
                    cout << "Order Information:" << endl;
                    cout << "Order ID: " << orderID << endl;
                    cout << "Date: " << order.getDate() << endl;
                    cout << "Quantity: " << order.getQuantity() << endl;
                    cout << "Amount Paid: $" << order.getAmountPaid() << endl;
                    found = true;
                    break;
                }
            }
        }
    }

    if (!found) {
        cout << "No orders found for customer with ID: " << customerID << endl;
    }
}

















//This Function will handle customer sales if the employee wants to enter a sale
//It will take a customers Id number and then check if the customer exists
//then it will ask for a quantity and esstablish a price with the quantity
//Once everything has been completed it will display a confirmation and
//save it to the orders file
void handleCustomerSale(vector<Orders>& orders, const vector<Customer>& customers, vector<Transactions>& transactions) {


    string customerID;
    double newAmountPaid;
    string newOrderID;
    string newDate;
    int newQuantity;
    string salesPersonID;


    cout << "Enter Sales Person ID: ";
    cin >> salesPersonID;

    cout << "Enter Customer ID: ";
    cin >> customerID;

    // Check if the customer exists
    bool customerExists = false;
    string customerName;
    for (const Customer& customer : customers) {
        if (customer.getId() == customerID) {
            customerName = customer.getFirstName() + " " + customer.getLastName();
            customerExists = true;
            break;
        }
    }

    if (!customerExists) {
        cout << "Customer not found with ID: " << customerID << endl;
        return;
    }

    cout << "Enter Quantity (up to 5): ";
    cin >> newQuantity;
    //quantity selection
    if (newQuantity < 1 || newQuantity > 5) {
        cout << "Invalid quantity. Quantity should be between 1 and 5." << endl;
        return;
    }


    //checks quantities 
    switch (newQuantity) {
    case 1:
        newAmountPaid = 9.50;
        break;
    case 2:
        newAmountPaid = 16.15;
        break;
    case 3:
        newAmountPaid = 25.88;
        break;
    case 4:
        newAmountPaid = 28.15;
        break;
    case 5:
        newAmountPaid = 30.00;
        break;
    default:
        break;
    }

    // Display the confirmation

    cout << "Customer: " << customerName << endl;

    cout << "Quantity Purchased: " << newQuantity << endl;

    cout << "Price: $" << newAmountPaid << endl;

    cout << "Enter New Order ID:" << endl;

    cin >> newOrderID;

    cout << "Enter Sale Date (using dashes):" << endl;

    cin >> newDate;



    // Create order and transaction objects for the sale
    Orders newOrder(newOrderID, newDate, newQuantity, newAmountPaid);

    orders.push_back(newOrder);

    Transactions newTransaction(customerID, salesPersonID, newOrderID);

    transactions.push_back(newTransaction);

    //writes new order to order text file
    ofstream file("orders.txt", ios::app);
    if (file) {
        file << newOrderID << ";" << newDate << ";" << newQuantity << ";" << newAmountPaid << endl;
        file.close();
        cout << "Order added successfully!" << endl;
    }
    else {
        cerr << "Error: Unable to open orders.txt for writing" << endl;
    }



    //writes customer id and order id to transactions text file
    ofstream file2("transactions.txt", ios::app);

    if (file2)
    {
        file2 << customerID << ";" << salesPersonID << ";" << newOrderID << endl;
    }

    else
    {
        cerr << "Error: unable to open transactions.txt for writing" << endl;
    }



}






void loadWaitingList(queue<string>& waitingList) {
    ifstream file("rainbowList.txt");
    string customerID;

    if (!file) {
        cerr << "Error: Unable to open rainbowList.txt" << endl;
        return;
    }

    while (file >> customerID) {
        waitingList.push(customerID);
    }

    file.close();
}




void saveWaitingList(const queue<string>& waitingList) {
    ofstream file("rainbowList.txt");

    if (!file) {
        cerr << "Error: Unable to open rainbowList.txt for writing" << endl;
        return;
    }

    queue<string> waitingListCopy = waitingList;

    while (!waitingListCopy.empty()) {
        file << waitingListCopy.front() << endl;
        waitingListCopy.pop();
    }

    file.close();
}





//This function uses data from transactions vector and uses a search ID
//from the customer look up (case 1) 
//tests if the searchID matches customer ID and then pulls up order IDs
//If the Id of the customer is not found in the transaction vector it returns !found
void LookupCustomerOrders(const vector<Transactions>& transactions, string searchID)
{
    string ordersearch;
    bool found = false;
    for (const Transactions& transaction : transactions)
        if (transaction.getCustID() == searchID)
        {
            ordersearch == transaction.getOrderID();
            
            found = true;
            break;
        }

    if (!found)
    {
        cout << "Customer Has No Orders" << endl;
    }




}







//reads the salesStaff.txt file and creates a vector of pointers to salesPerson objects using it's derived classes
//returns the vector of pointers for each salesPerson
vector<SalesPerson*> readSalesStaff() {
    //creating a vector of base class (sales person) pointers
    vector<SalesPerson*> salesStaff;
    ifstream file("salesStaff.txt");

    if (!file) {
        cerr << "Error: Unable to open salesStaff.txt" << endl;
        return salesStaff;
    }


    string line;
    //assuming number of sales people stays at 13
    while (getline(file, line)) {
        stringstream ss(line);
        

        string title, name, salesPersonID, bossID;

        //using stringstream to set read columns in the file to variables
        getline(ss, title, ';');
        getline(ss, name, ';');
        getline(ss, salesPersonID, ';');
        getline(ss, bossID, ';');
        
        
        //create derived object and pointers to them based on title and put into the vector

        

        if (title == "Sales") {
            salesStaff.push_back(new Sales(title, name, salesPersonID, bossID));
        }
        else if (title == "SuperSales") {
            salesStaff.push_back(new SuperSales(title, name, salesPersonID, bossID));
        }
        else if (title == "Supervisor") {
            salesStaff.push_back(new Supervisor(title, name, salesPersonID, bossID));
        }
        else if (title == "Manager") {
            salesStaff.push_back(new Manager(title, name, salesPersonID, bossID));
        }
    }

    file.close();

   

    
    return salesStaff;
}

vector<SalesPerson*> setSalesForCommission(vector<SalesPerson*>& salesStaff, const vector<Orders>& orders, const vector<Transactions>& transactions) {
    for (int i = 0; i < salesStaff.size(); i++) {
        string salesPersonID = salesStaff[i]->getSalesPersonID();
        string title = salesStaff[i]->getTitle();
        double personalSales = 0;

        // Iterate through transactions to find relevant orders for the current salesperson
        for (int j = 0; j < transactions.size(); j++) {
            if (salesPersonID == transactions[j].getSalesPersonID()) {
                string orderID = transactions[j].getOrderID();

                // Iterate through orders to accumulate personal sales
                for (int k = 0; k < orders.size(); k++) {
                    if (orderID == orders[k].getOrderID()) {
                        personalSales += orders[k].getAmountPaid();
                    }
                }
            }
        }

        // Set the personal sales of the salesperson using their title class' set personal sales method
        if (title == "Sales") {
            Sales* s = dynamic_cast<Sales*>(salesStaff[i]);
            if (s) {
                s->setPersonalSales(personalSales);
            }
        }
        else if (title == "SuperSales") {
            SuperSales* ss = dynamic_cast<SuperSales*>(salesStaff[i]);
            if (ss) {
                ss->setPersonalSales(personalSales);
            }
        }
        else if (title == "Supervisor") {
            Supervisor* sv = dynamic_cast<Supervisor*>(salesStaff[i]);
            if (sv) {
                sv->setPersonalSales(personalSales);
                sv->setEmployeeSales(personalSales);  // Assuming Supervisor's initial employee sales is personal sales
            }
        }
        else if (title == "Manager") {
            Manager* m = dynamic_cast<Manager*>(salesStaff[i]);
            if (m) {
                m->setPersonalSales(personalSales);
                m->setEmployeeSales(personalSales);
            }
        }
    }

    // Calculate totalEmployeeSales for each Supervisor
    for (int i = 0; i < salesStaff.size(); i++) {
        string title = salesStaff[i]->getTitle();
        if (title == "Supervisor") {
            Supervisor* sv = dynamic_cast<Supervisor*>(salesStaff[i]);
            if (sv) {
                double totalEmployeeSales = 0;

                for (int j = 0; j < salesStaff.size(); j++) {
                    if (sv->getSalesPersonID() == salesStaff[j]->getBossID() &&
                        (salesStaff[j]->getTitle() == "Sales" || salesStaff[j]->getTitle() == "SuperSales")) {
                        
                        totalEmployeeSales += salesStaff[j]->getPersonalSales();
                    }
                }

                sv->setEmployeeSales(totalEmployeeSales);
                
            }
        }
    }

    // Set Manager's employee sales
    double totalEmployeeSales = 0;
    for (int i = 0; i < salesStaff.size(); i++) {
        string title = salesStaff[i]->getTitle();
        if (title == "Supervisor" || title == "Sales" || title == "SuperSales") {
            Supervisor* sv = dynamic_cast<Supervisor*>(salesStaff[i]);
            if (sv) {
                totalEmployeeSales += sv->getEmployeeSales() + sv->getPersonalSales();
            }
        }
    }

    bool foundManager = false;
    int managerIndex = 0;

    while (!foundManager && managerIndex < salesStaff.size()) {
        string title = salesStaff[managerIndex]->getTitle();
        if (title == "Manager") {
            Manager* m = dynamic_cast<Manager*>(salesStaff[managerIndex]);
            if (m) {
                m->setEmployeeSales(totalEmployeeSales);
                foundManager = true;
            }
        }
        managerIndex++;
    }

    return salesStaff;
}

void printSalesReport(const vector<SalesPerson*>& salesStaff) {
    // Print header with dashes
    cout << left << setw(20) << "Name" << setw(15) << "Title" << setw(15) << "SalesPersonID" << setw(15) << "BossID" << setw(15) 
        << "Personal Sales" << setw(20) << "Employee Sales" << setw(15) << "Commission" << endl;

    cout << setfill('-') << setw(120) << "" << setfill(' ') << "\n" << endl;

    for (const auto& person : salesStaff) {
        if (!person) {
            cout << "Null pointer detected\n";
            continue;
        }

        cout << left << setw(20) << person->getName() << setw(15) << person->getTitle() << setw(15) << person->getSalesPersonID() << setw(15) 
            << person->getBossID() << setw(15) << fixed << setprecision(2) << person->getPersonalSales();

        if (auto* supervisor = dynamic_cast<Supervisor*>(person)) {
            cout << setw(20) << fixed << setprecision(2) << supervisor->getEmployeeSales();
        }
        else if (auto* manager = dynamic_cast<Manager*>(person)) {
            cout << setw(20) << fixed << setprecision(2) << manager->getEmployeeSales();
        }
        else {
            cout << setw(20) << "N/A";
        }

        cout << setw(15) << fixed << setprecision(2) << person->getCommission() << endl;
    }
}










int main() 
{
    //initization of everything required 


    vector<Transactions> transactions = readTransactionData();

    vector<Customer> customers = readCustomerData();

    vector<Orders> orders = readOrderData();

    vector<SalesPerson*> salesStaff = readSalesStaff();


    salesStaff = setSalesForCommission(salesStaff, orders, transactions);

    queue<string> waitingList;

    loadWaitingList(waitingList);

    saveWaitingList(waitingList);

    int rainbowSelection;

    string tempID;

    string customerID;

    int idInUse;

    string customerIDtoLookup;

    string searchId;

    string searchFirstName;

    int choice;

    string newId;

    string newFirstName, newLastName, newAddress, newCity, newState, newZipCode;

    bool found = false;


    Customer newCustomer; // Declare newCustomer outside the switch and initialize with default values





    do {
        //Main Menu setup
        cout << "---------------------------------------------- " << endl;
        cout << "                    Menu                      |" << endl;
        cout << "----------------------------------------------|" << endl;
        cout << "1. Display customer information by ID         |" << endl;
        cout << "2. Display Customer Information by First Name |" << endl;
        cout << "3. Add a new customer                         |" << endl;
        cout << "4. Look Up An Order By Customer ID            |" << endl;
        cout << "5. Rainbow Tribles                            |" << endl;
        cout << "6. Customer Sale                              |" << endl;
        cout << "7. Print Sales Report                         |" << endl;
        cout << "8. Exit                                       |" << endl;
        cout << "---------------------------------------------- " << endl;

        //selection for main menu
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {



            //case 1 finds customer by Id number from the Customer vector
        case 1:
            
            found = false;
            cout << "Enter customer ID: ";
            int ordersearch;
            cin >> searchId;
            for (const Customer& customer : customers)
            {
                if (customer.getId() == searchId)
                {
                    cout << "Customer Information:" << endl;
                    cout << "ID: " << customer.getId() << endl;
                    cout << "First Name: " << customer.getFirstName() << endl;
                    cout << "Last Name: " << customer.getLastName() << endl;
                    cout << "Address: " << customer.getAddress() << endl;
                    cout << "City: " << customer.getCity() << endl;
                    cout << "State: " << customer.getState() << endl;
                    cout << "Zip Code: " << customer.getZipCode() << "\n" << endl;
                    
                    LookupCustomerOrders(transactions, searchId); //function that looks up order ids 

                    
                    


                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Customer not found with ID: " << searchId << endl;

            }
            break;





        case 2:
            //Searching for Customer by First name to get Information
            //Will display multiple customers if needed
            found = false;
            cout << "Enter customer first name: ";
            cin >> searchFirstName;
            cout << "Customers with the first name " << searchFirstName << ":" << endl;
            for (const Customer& customer : customers) {
                if (customer.getFirstName() == searchFirstName) {
                    cout << "\nCustomer Information:" << endl;
                    cout << "ID: " << customer.getId() << endl;
                    cout << "First Name: " << customer.getFirstName() << endl;
                    cout << "Last Name: " << customer.getLastName() << endl;
                    cout << "Address: " << customer.getAddress() << endl;
                    cout << "City: " << customer.getCity() << endl;
                    cout << "State: " << customer.getState() << endl;
                    cout << "Zip Code: " << customer.getZipCode() << "\n" << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "No customers found with the first name: " << searchFirstName << endl;
            }
            break;






        case 3:
        {


            //Creates New customer and writes to file
            cout << "Enter customer ID: ";
            cin >> newId;

            // Check if the newId is already in use
            bool idInUse = false;
            for (const Customer& customer : customers) {
                if (customer.getId() == newId) {
                    idInUse = true;
                    cout << "Customer ID " << newId << " is already in use. Please choose a different ID." << endl;
                    break; // Exit the loop early since the ID is in use
                }
            }

            if (!idInUse)
            {
                cout << "Enter First Name: ";
                cin >> newFirstName;
                cout << "Enter Last Name: ";
                cin >> newLastName;
                cout << "Enter Address: ";
                cin.ignore();
                getline(cin, newAddress);
                cout << "Enter City: ";
                getline(cin, newCity);
                cout << "Enter State: ";
                getline(cin, newState);
                cout << "Enter Zip Code: ";
                cin >> newZipCode;

                cout << "Customer added successfully!" << endl;
            }




            // Set the values of newCustomer
            newCustomer = Customer(newId, newFirstName, newLastName, newAddress, newCity, newState, newZipCode);
            customers.push_back(newCustomer);

            // Write the updated customer data to the file
            writeCustomerData(customers);

            
            break;
        }






        case 4:
            
            cout << "Enter Customer ID: ";
            cin >> customerIDtoLookup;
            lookupCustomerOrder(transactions,orders, customerIDtoLookup);
            break;






        case 5:
        
            cout << "Enter 1 to add a person to the waiting list \nEnter 2 to sale a rainbow tribble to the next person in line";
            cin >> rainbowSelection;
            if (rainbowSelection == 1)
            {
            
                if (rainbowSelection == 1)//adding to the list
                cout << "Enter Customer ID to add: ";
                cin >> customerID;
                waitingList.push(customerID);
                saveWaitingList(waitingList); //update the rainbowList file
                cout << "Customer with ID " << customerID << " added to the waiting list." << endl;
                break;
            }
            else
            {
                if (!waitingList.empty())
                {
                    customerID = waitingList.front();
                    waitingList.pop();
                    saveWaitingList(waitingList); //update the rainbowList file
                    cout << "Customer with ID " << customerID << " removed from the waiting list." << endl;
                }

                for (const Customer& customer : customers)
                {
                    tempID = stoi(customerID);

                    if (customer.getId() == tempID)
                    {
                        cout << "\nRainbow Tribble Sale Information:" << endl;
                        cout << "First Name: " << customer.getFirstName() << endl;
                        cout << "Last Name: " << customer.getLastName() << endl;
                        cout << "Quantity: 1 rainbow tribble" << endl;
                        cout << "Price: $9.50";
                    }
                }
                break;


            }
            break;
   
        

        case 6:
        {
            handleCustomerSale(orders, customers, transactions);


            break;
        }


        case 7:
        {
            printSalesReport(salesStaff);
        
            break;
        }






        case 8:
        {
            cout << "Saving and Exiting program..." << endl;
            break;
        }






        default:
        {
            cout << "Invalid choice. Please try again." << endl;
        }


        }


     } while (choice != 8);

    return 0;
}


