#include<stdio.h>
#include<stdlib.h>
/**
 * @file Managing a Shopping Portal.c
 * @author Sanjana G (malugeee@gmail.com)
 * @brief Can order and buy things easily
 * @version 0.1
 * @date 2022-04-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// Alphanumeric LCD functions
#include<string.h>

static int product_count;
static int seller_count;
static int productSeller;
static int cartCount;

struct Product{
    char productName[30];
    char manufacturer[30];
    char description[30];
};

struct Seller{
    char company[30];
    char name[30];
    char address[30];
    char contact[30];
};

struct ProductDetails{
    char pname[30];
    int quantity;
    int price;
};

struct ProductSeller{
    char sname[30];
    int count;
    struct ProductDetails *pd;
};

struct CartSeller{
    char seller_name[30];
    int quantity;
    int price;
};

struct Cart{
    char product[30];
    int quantity;
    int price;
   // int count;
    char seller_name[30];
    //struct CartSeller *cs;

};


struct ProductSeller * acceptSellerDetails(struct Seller *s ,struct ProductSeller *ps)
{
    char a[30];
    int i=seller_count-1;
    printf("Enter company name: ");
    fgets(a,30,stdin);
    scanf("%[^\n]%*c",a);
    strcpy((s+i)->company,a);
    strcpy((ps+i)->sname,a);
    (ps+i)->count=0;
    printf("Enter seller name: ");
    scanf("%[^\n]%*c",(s+i)->name);
    printf("Enter seller address: ");
    scanf("%[^\n]%*c",(s+i)->address);
    printf("Enter seller mobile number: ");
    scanf("%[\n]%*c",(s+i)->contact);
    return ps;
}