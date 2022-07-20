#include<bits/stdc++.h>
using namespace std;

class Shop
{
public:
    string product_name;
    int product_price;
    int product_quantity;
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
};

void takeInput(int n, Shop products[])
{
    for(int i=0; i<n; i++)
    {
        cout<<"Product "<<i+1<<" Name: ";
        cin>>products[i].product_name;
        cout<<"Product "<<i+1<<" Price: ";
        cin>>products[i].product_price;
        cout<<"Product "<<i+1<<" Quantity: ";
        cin>>products[i].product_quantity;
    }
};

void printProducts(int n, Shop products[]){
    cout<<endl<<endl<<"        BUY PRODUCTS        "<<endl;
    cout<<"        ____________        "<<endl<<endl;
    cout<<"Product Index:    ";
    for(int i=1; i<=n; i++) cout<<i<<"        ";
    cout<<endl;
    cout<<"Product Name:     ";
    for(int i=0; i<n; i++) cout<<products[i].product_name<<"   ";
    cout<<endl;
    cout<<"Product Price:    ";
    for(int i=0; i<n; i++) cout<<products[i].product_price<<"   ";
    cout<<endl;
    cout<<"Product Quantity: ";
    for(int i=0; i<n; i++) cout<<products[i].product_quantity<<"   ";
    cout<<endl<<endl;
}

void buyProduct(int n, Shop products[]){
    int select,qty;
    cout<<"Which product do you want? From 1 to "<<n<<": ";
    cin>>select;
    select -= 1;
    cout<<"What is the quantity that you want of "<<products[select].product_name<<": ";
    cin>>qty;
    cout<<endl;
    if(qty <= products[select].product_quantity){
        products[select].product_quantity -= qty;
        cout<<products[select].product_name<<" bought "<<qty<<" pc successfully"<<endl;
        products[select].setter(products[select].product_price * qty);
        cout<<"Your total income : "<<products[select].getter()<<endl;
    }else cout<<"This quantity is not available"<<endl;
}

int main()
{
    int n;
    cout<<"Number of products: ";
    cin>>n;

    Shop products[n];
    takeInput(n, products);
    while(true){
        printProducts(n, products);
        buyProduct(n, products);
    }
    return 0;
}
