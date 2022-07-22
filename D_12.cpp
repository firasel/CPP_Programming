#include<bits/stdc++.h>
using namespace std;

class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
protected:
    double total_tax;
public:
    Restaurant()
    {
        this->total_tax=0;
    }

    void addTax(double tax)
    {
        this -> total_tax += tax;
    }

    // Food details input
    void foodItemsInput(int n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>food_item_codes[i];
            cin.ignore();
            getline(cin,food_item_names[i]);
            cin>>food_item_prices[i];
        }
    }
    // Food details print
    void foodItemsPrint(int n)
    {
        cout<<endl<<setw(42)<<right<<"MAKE BILL"<<endl;
        cout<<setw(48)<<right<<"_______________________"<<endl;
        cout<<setw(25)<<left<<"Item Code"
            <<setw(40)<<left<<"Item Name"
            <<"Item Price"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<setw(25)<<left<<food_item_codes[i]
                <<setw(40)<<left<<food_item_names[i]
                <<food_item_prices[i]<<endl;
        }
    }
    // Find and store single food details
    bool getFoodDetails(int n, int code, string *itemsName, int *itemsPrice)
    {
        for(int i=0; i<n; i++)
        {
            if(food_item_codes[i] == code)
            {
                *itemsName = food_item_names[i];
                *itemsPrice = food_item_prices[i];
                return true;
            }
        }
        return false;
    }
    // Item code & quantity input & store the food details
    void itemCodeInput(int items, int n, int itemsCode[], string itemsName[], int itemsPrice[], int itemsQuantity[])
    {
        for(int i=0; i<items; i++)
        {
            int code;
            while(true)
            {
                cout<<"Enter Item "<<i+1<<" Code : ";
                cin>>code;
                if(this->getFoodDetails(n, code, &itemsName[i], &itemsPrice[i])) break;
                else cout<<"Item code wrong, please enter valid item code."<<endl;
            }
            itemsCode[i] = code;
            cout<<"Enter Item "<<i+1<<" Quantity : ";
            cin>>itemsQuantity[i];
        }
    }
    // Print the bill summry
    void billSummryPrint(int items, int tableNo, int itemsCode[], string itemsName[], int itemsPrice[], int itemsQuantity[])
    {
        double tax=0, total=0;
        cout<<endl<<setw(62)<<right<<"BILL SUMMARY"<<endl;
        cout<<setw(68)<<right<<"________________________"<<endl;
        cout<<"Table No. : "<<tableNo<<endl;
        cout<<setw(25)<<left<<"Item Code"
            <<setw(30)<<left<<"Item Name"
            <<setw(20)<<left<<"Item Price"
            <<setw(20)<<left<<"Item Quantity"
            <<"Total Price"<<endl;
        for(int i=0; i<items; i++)
        {
            cout<<setw(25)<<left<<itemsCode[i]
                <<setw(30)<<left<<itemsName[i]
                <<setw(20)<<left<<itemsPrice[i]
                <<setw(20)<<left<<itemsQuantity[i]
                <<itemsQuantity[i]*itemsPrice[i]<<endl;
            total+=(itemsQuantity[i]*itemsPrice[i]);
        }
        tax = total * 0.05;
        total+=tax;
        cout<<setw(95)<<"TAX"<<tax<<endl;
        cout<<setfill('_')<<setw(106)<<'_'<<endl;
        cout<<setfill(' ')<<setw(95)<<left<<"NET TOTAL"
            <<total<<endl<<endl;
        this->addTax(tax);
    }
    // Generate bill
    void generateBill(int n)
    {
        int tableNo,items;
        cout<<endl<<"Enter Table No : ";
        cin>>tableNo;
        cout<<"Enter Number of Items : ";
        cin>>items;

        int itemsCode[items], itemsQuantity[items], itemsPrice[items];
        string itemsName[items];
        this->itemCodeInput(items, n, itemsCode, itemsName, itemsPrice, itemsQuantity);
        this->billSummryPrint(items, tableNo, itemsCode, itemsName, itemsPrice, itemsQuantity);
    }
};

int main()
{
    int n;
    Restaurant dtRestaurant;
    cin>>n;
    dtRestaurant.foodItemsInput(n);
    while(true)
    {
        dtRestaurant.foodItemsPrint(n);
        dtRestaurant.generateBill(n);
    }
    return 0;
}
