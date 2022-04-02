#include<stdio.h>
#include<stdlib.h>
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
    scanf("%[^\n]%*c",(s+i)->contact);
    return ps;
}
void displaySellerDetails(struct Seller *s)
{
    printf("Sno.\tCompany Name\tSeller Name\tAddress\tMobile Number\n");
    for(int i=0;i<seller_count;i++)
        printf("%d\t%s\t%s\t%s\t%s\n",i+1,(s+i)->company,(s+i)->name,(s+i)->address,(s+i)->contact);
    return;
}
struct Product * acceptProductDetails(struct Product *p)
{
    char a[30];
    int i = product_count-1;
    printf("Enter the Product Name: ");
    fgets(a,30,stdin);
    scanf("%[^\n]%*c",(p+i)->productName);
    //fgets((p+i)->productName,25,stdin);
    printf("Enter the Manufacturer: ");
    scanf("%[^\n]%*c",(p+i)->manufacturer);
    printf("Enter the Description: ");
    scanf("%[^\n]%*c",(p+i)->description);
    return p;

}
void displayProductDetails(struct Product *p)
{
    printf("Product Name\tManufacturer\tDescription\n");
    for(int i=0;i<product_count;i++)
    {
        printf("%s\t\t",(p+i)->productName);
        printf("%s\t\t",(p+i)->manufacturer);
        printf("%s\t\t",(p+i)->description);
        printf("\n");

    }
    return;
}
void displaySelPro(struct ProductSeller *ps)
{
    printf("Name\tProduct Name\tQuantity\tPrice\n");
    for(int i=0;i<seller_count;i++)
            for(int j=0;j<(ps+i)->count;j++)
                printf("%s\t%s\t%d\t%d\n",(ps+i)->sname,ps[i].pd[j].pname,ps[i].pd[j].quantity,ps[i].pd[j].price);
    return;/* (ps+i)->sname,(ps+i)->(pd+j)->pname,(ps+i)->(ps+j)->quantity,(ps+i)->(ps+j)->price*/
}
void main()
{
    int i,j,x,choice=5;

    struct Product *product;
    struct Seller *seller;
    struct ProductSeller *psell;
    struct Cart * cart;

    product=(struct Product *) malloc (0 * sizeof(struct Product));
    seller=(struct Seller *) malloc (0 * sizeof(struct Seller));
    psell = (struct ProductSeller *) malloc (0 * sizeof(struct ProductSeller));
    cart = (struct Cart *) malloc (0*sizeof(struct Cart));
    while(choice)
    {
        char temp[50];
        printf("\n1. Accept Product Degtails  \n2. Display Product Details  \n3. Enter Seller Details \n4. Display Seller Details \n5. Accept Product Quantity and price \n6. Display products thet the seller has \n7. Add items to the cart \n8. Display the Cart \n0. Exit \nEnter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: return;
                    break;

            case 1: product_count++;
                    product=realloc(product,product_count*sizeof(struct Product));
                    acceptProductDetails(product);
                    break;

            case 2: displayProductDetails(product);
                    break;

            case 3: seller_count++;
                    psell=realloc(psell,seller_count*sizeof(struct ProductSeller));
                    seller=realloc(seller,seller_count*sizeof(struct Seller));
                    acceptSellerDetails(seller,psell);
                    (psell +seller_count-1)-> pd = (struct ProductDetails *) malloc ( 0 * sizeof(struct ProductDetails));
                    break;

            case 4: displaySellerDetails(seller);
                    break;

            case 5: printf("Enter the seller name to enter the product: ");
                    fgets(temp,30,stdin);
                    scanf("%[^\n]%*c",temp);
                    for(i=0;i<seller_count;i++)
                        if (strcmp((psell+i)->sname,temp) ==0)
                            break;
                    if(i<seller_count)
                    {
                        char abc[30];
                        int j = (psell+i)->count;
                        (psell+i)->count ++;
                        (psell+i)->pd = realloc( (psell+i)->pd , (psell+i)->count*sizeof(struct ProductDetails));

                        printf("Enter Product Name: ");
                           fgets(abc,30,stdin);
                        scanf("%[^\n]%*c",abc);
                        for(x=0;x<product_count;x++)
                            if(strcmp(abc,product[x].productName)==0)
                                break;
                        if(x<product_count)
                        {
                            strcpy(psell[i].pd[j].pname,abc);
                            printf("Enter the Quantity: ");
                            scanf("%d",&psell[i].pd[j].quantity);
                            printf("Enter the Price: ");
                            scanf("%d",&psell[i].pd[j].price);
                        }
                        else
                            printf("Enter correct Product Name" );
                    }
                    else
                        printf("Enter Correct Customer Name");
                    break;

            case 6: for(int i=0;i<seller_count;i++)
                        for(int j=0;j<psell[i].count;j++)
                            printf("%s\t%s\t%d\t%d\n",psell[i].sname,psell[i].pd[j].pname,psell[i].pd[j].quantity,psell[i].pd[j].price);

                    //displaySelPro(psell);
                    break;

            case 7: printf("Enter the product name to add to the cart: ");
                    fgets(temp,30,stdin);
                    scanf("%[^\n]%*c",temp);
                    for(i=0;i<product_count;i++)
                        if(strcmp(temp,product[x].productName)==0)
                                break;
                    x=cartCount++;
                    cart = realloc(cart,cartCount*sizeof(struct Cart));
                   // cart[x].count=0;
                    strcpy(cart[x].product,temp);
                    printf("Enter the Quantity : ");
                    int quantity;
                    scanf("%d",&quantity);
                  //  = cart[x].quantity;

                    while(quantity>0)
                    {
                        int i1,j1,pp;
                        for(i=0;i<seller_count;i++)
                        {
                            for(j=0;j<psell[i].count;j++)
                                if(strcmp(psell[i].pd[j].pname,cart[x].product)==0)
                                    if((psell[i].pd[j].quantity)>0)
                                    {
                                        i1=i;
                                        j1=j;
                                        pp= psell[i].pd[j].quantity;
                                        break;
                                    }

                            if(j<psell[i].count)
                            {
                                i++;
                                break;
                            }
                        }
                        for(i=0;i<seller_count;i++)
                            for(j=0;j<psell[i].count;j++)
                                if((strcmp(psell[i].pd[j].pname,cart[x].product)==0)&&((psell[i].pd[j].quantity)>0))
                                    if(psell[i1].pd[j1].price>psell[i].pd[j].price)
                                        {
                                            i1=i;
                                            j1=j;
                                            pp= psell[i].pd[j].quantity;
                                        }

                        if(quantity>pp)
                        {
                            cart[x].quantity = psell[i1].pd[j1].quantity;
                            quantity=quantity-psell[i1].pd[j1].quantity;
                            psell[i1].pd[j1].quantity=0;

                        }
                        else if(pp>quantity)
                        {
                            cart[x].quantity = quantity;
                            psell[i1].pd[j1].quantity = psell[i1].pd[j1].quantity - quantity;
                            quantity = 0;

                        }
                        else if((pp-quantity)==0)
                        {
                            cart[x].quantity = quantity;
                            psell[i1].pd[j1].quantity=0;
                            quantity = 0;
                        }

                        cart[x].price = psell[i1].pd[j1].price * cart[x].quantity;
                        strcpy(cart[x].seller_name,psell[i1].sname);
                        if(quantity>0)
                        {
                            x=cartCount++;
                            cart = realloc(cart,cartCount*sizeof(struct Cart));
                             strcpy(cart[x].product,temp);
                        }

                    }
                    int total_amount=0;

                    break;
            case 8: for(i=0;i<cartCount;i++)
                    {
                        printf("Product: %s\n",cart[i].product);


                            printf("\tSeller : %s\n",cart[i].seller_name);
                            printf("\tQuantity : %d\n",cart[i].quantity);
                            printf("\tPrice : %d\n",cart[i].price);


                    }
                    for(i=0;i<cartCount;i++)
                        total_amount = total_amount + cart[i].price;
                    printf("\nTotal Amount : %d",total_amount);
                    break;


            default: printf("Enter a valid Input;");

        }

    }
}
