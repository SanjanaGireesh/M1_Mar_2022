#ifndef UNITY_FRAMEWORK_H
#define UNITY_FRAMEWORK_H
#define UNITY

#define UNITY_VERSION_MAJOR    2
#define UNITY_VERSION_MINOR    5
#define UNITY_VERSION_BUILD    1
#define UNITY_VERSION          ((UNITY_VERSION_MAJOR << 16) | (UNITY_VERSION_MINOR << 8) | UNITY_VERSION_BUILD)

#ifdef __cplusplus
}
#endif
#endif


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*---------#
ifdef __cplusplus
extern "C"
{
#endif
--------------*/
#include "unity_internals.h"

/*-------------------------------------------------------
 * Test Setup / Teardown
 *-------------------------------------------------------*/

static int product_count;
static int seller_count;
static int productSeller;
static int cartCount;


 /*---------------------------------read theinputs
 *     - by default, Unity prints to standard out with putchar.  define UNITY_OUTPUT_CHAR(a) with a different function if desired
 *     - define UNITY_DIFFERENTIATE_FINAL_FAIL to print FAILED (vs. FAIL) at test end summary - for automated search for failure
 * Optimization
 *     - by default, line numbers are stored in unsigned shorts.  Define UNITY_LINE_TYPE with a different type if your files are huge
 *     - by default, test and failure counters are unsigned shorts.  Define UNITY_COUNTER_TYPE with a different type if you want to save space or have more than 65535 Tests.
 * Test Cases
 *     - define UNITY_SUPPORT_TEST_CASES to include the TEST_CASE macro, though really it's mostly about the runner generator script
 * Parameterized Tests
 *     - you'll want to create a define of TEST_CASE(...) which basically evaluates to nothing
 * Tests with Arguments
 *     - you'll want to define UNITY_USE_COMMAND_LINE_ARGS if you have the test runner passing arguments to Unity
 *-------------------------------------------------------
 * Basic Fail and Ignore
 *-------------------------------------------------------*/


struct Product{
    char productName[30];
    char manufacturer[30];
    char description[50];
};

struct Seller{
    char company[30];
    char name[30];
    char address[30];
    char contact[10];
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

/*-------------------------------------------------------
 * Configuration Options
 *-------------------------------------------------------
 * All options described below should be passed as a compiler flag to all files using Unity. If you must add #defines, place them BEFORE the #include above.
 * Integers/longs/pointers
 *     - Unity attempts to automatically discover your integer sizes
 *       - define UNITY_EXCLUDE_STDINT_H to stop attempting to look in <stdint.h>
 *       - define UNITY_EXCLUDE_LIMITS_H to stop attempting to look in <limits.h>
 *     - If you cannot use the automatic methods above, you can force Unity by using these options:
 *       - define UNITY_SUPPORT_64
 *       - set UNITY_INT_WIDTH
 *       - set UNITY_LONG_WIDTH
 *       - set UNITY_POINTER_WIDTH-----------------------------------------------------*/


struct ProductSeller * acceptSellerDetails(struct Seller *s ,struct ProductSeller *ps)
{
    char a[30];
    int i=seller_count-1;
    printf("Enter company name: ");
    fgets(a,5,stdin);
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
    char a[10];
    int i = product_count-1;
    printf("Enter the Product Name: ");
    fgets(a,5,stdin);
    scanf("%[^\n]%*c",(p+i)->productName);
    //fgets((p+i)->productName,25,stdin);
    printf("Enter the Manufacturer: ");
    scanf("%[^\n]%*c",(p+i)->manufacturer);
    printf("Enter the Description: ");
    scanf("%[^\n]%*c",(p+i)->description);
    return p;

}


#ifdef __cplusplus
}
#endif
#endif
