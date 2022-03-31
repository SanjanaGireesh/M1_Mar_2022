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