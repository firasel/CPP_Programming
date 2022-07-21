#include<bits/stdc++.h>
using namespace std;

class Shop
{
public:
    string product_name[10];
    int product_price[10];
    int product_quantity[10];
private:
    int total_income;
public:
    void setter(int total_income)
    {
        this -> total_income += total_income;
    }
    int getter()
    {
        return this -> total_income;
    }
    Shop()
    {
        this -> total_income = 0;
    }
    // Take product input
    void takeInput(int n)
    {
        for(int i=0; i<n; i++)
        {
            cout<<"Product "<<i+1<<" Name: ";
            cin>>product_name[i];
            cout<<"Product "<<i+1<<" Price: ";
            cin>>product_price[i];
            cout<<"Product "<<i+1<<" Quantity: ";
            cin>>product_quantity[i];
        }
    }
    // Print all product details
    void printProducts(int n)
    {
        cout<<endl<<endl<<"        BUY PRODUCTS        "<<endl;
        cout<<"        ____________        "<<endl<<endl;
        cout<<"Product Index:    ";
        for(int i=1; i<=n; i++) cout<<i<<"        ";
        cout<<endl;
        cout<<"Product Name:     ";
        for(int i=0; i<n; i++) cout<<product_name[i]<<"   ";
        cout<<endl;
        cout<<"Product Price:    ";
        for(int i=0; i<n; i++) cout<<product_price[i]<<"   ";
        cout<<endl;
        cout<<"Product Quantity: ";
        for(int i=0; i<n; i++) cout<<product_quantity[i]<<"   ";
        cout<<endl<<endl;
    }
    // Buy product method
    void buyProduct(int n)
    {
        int select,qty;
        cout<<"Which product do you want? From 1 to "<<n<<": ";
        cin>>select;
        select -= 1;
        cout<<"What is the quantity that you want of "<<product_name[select]<<": ";
        cin>>qty;
        cout<<endl;
        if(qty <= product_quantity[select])
        {
            product_quantity[select] -= qty;
            cout<<product_name[select]<<" bought "<<qty<<" pc successfully"<<endl;
            this->setter(product_price[select] * qty);
            cout<<"Your total income : "<<this->getter()<<endl;
        }
        else cout<<"This quantity is not available"<<endl;
    }
};

int main()
{
    int n;
    cout<<"Number of products: ";
    cin>>n;

    Shop products;
    products.takeInput(n);

    while(true)
    {
        products.printProducts(n);
        products.buyProduct(n);
    }
    return 0;
}
