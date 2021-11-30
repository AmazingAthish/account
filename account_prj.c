/*WAP to perform the following operations based on user choice,
1. Create Account
2. Search Account
3. Display
4. Modify [1. Contact Number, 2. Address, 3. PIN]
5. Delete
6. Transactions [1. Withdraw, 2. Deposit]
7. Exit
*/
#include<stdio.h>
#include "account.h"
int main()
{
    int choice;
    do
    {
        printf("\n1. Create account\n2. Search Account\n3. Display");
        printf("\n4. Modify\n5. Delete\n6. Transactions\n7. Exit");
        printf("\nEnter choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                create_account();
                break;
            case 2:
                search_account();
                break;
            case 3:
                display_all();
                break;
            case 4:
                modify_account();
                break;
            case 5:
                delete_account();
                break;
            case 6:
                transactions();
                break;
            case 7:
                break;
            default:
                printf("\n--------- Invalid choice --------------");
        }
    }while(choice!=7);
}
