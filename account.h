struct Account
{
    int acno,bal,pin;
    char name[20],cont[10],add[30];
};
void create_account()
{
    FILE *fp1;
    struct Account A;
    fp1=fopen("account.txt","a");
    printf("\nEnter acno, name, address, contact, pin:\n");
    scanf("%d%s%s%s%d",&A.acno,A.name,A.add,A.cont,&A.pin);
    A.bal=500;
    fwrite((char *)&A,sizeof(struct Account),1,fp1);
    fclose(fp1);
    printf("\n************ ACCOUNT CREATED SUCCESSFULLY ***************");
}
void display(struct Account A)
{
    printf("\n%d\t%s\t%s\t%s\t%d",A.acno,A.name,A.add,A.cont,A.bal);
}
void display_all()
{
    FILE *fp1;
    struct Account A;
    fp1= fopen("account.txt","r");
    printf("\n************ Account Details are ****************");
    while(!feof(fp1))
    {
        fread((char *)&A,sizeof(struct Account),1,fp1);
        if(feof(fp1))
            break;
        display(A);
    }
    fclose(fp1);
}
void search_account()
{
    FILE *fp1;
    struct Account A;
    int ac,pi,flag=0;
    fp1= fopen("account.txt","r");
    printf("\nEnter account number and pin to search:");
    scanf("%d%d",&ac,&pi);
    while(!feof(fp1))
    {
        fread((char *)&A,sizeof(struct Account),1,fp1);
        if(feof(fp1))
            break;
        if(A.acno==ac && A.pin == pi)
        {
            display(A);
            flag=1;
            break;
        }
    }
    fclose(fp1);
    if(flag==0)
        printf("\n********** ACCOUNT NOT FOUND ***************");
}
void modify_account()
{
    FILE *fp1,*fp2;
    struct Account A;
    int ac,pi,flag=0,choice,p;
    fp1= fopen("account.txt","r");
    fp2= fopen("temp.txt","w");
    printf("\nEnter account number and pin to modify:");
    scanf("%d%d",&ac,&pi);
    while(!feof(fp1))
    {
        fread((char *)&A,sizeof(struct Account),1,fp1);
        if(feof(fp1))
            break;
        if(A.acno==ac && A.pin == pi)
        {
            display(A);
            flag=1;
            printf("\n1. Contact Number\n2. Address\n3. PIN\nEnter choice:");
            scanf("%d",&choice);
            if(choice == 1)
            {
                printf("\nEnter new Contact number :");
                scanf("%s",A.cont);
            }
            else if(choice == 2)
            {
                printf("\nEnter new Address:");
                scanf("%s",A.add);
            }
            else if(choice == 3)
            {
                printf("\nEnter old PIN :");
                scanf("%d",&p);
                if(p == A.pin)
                {
                    printf("\nEnter new PIN :");
                    scanf("%d",&A.pin);
                }
                else
                    printf("\n********** INVALID PIN ***********");
            }
            else
                printf("\n************ INVALID CHOICE ***********");
            fwrite((char *)&A,sizeof(struct Account),1,fp2);
        }
        else
            fwrite((char *)&A,sizeof(struct Account),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    if(flag==0)
        printf("\n********** ACCOUNT NOT FOUND ***************");
    else
    {
        remove("account.txt");
        rename("temp.txt","account.txt");
        printf("\n***** RECORD MODIFIED SUCCESSFULLY ************");
    }
}
void delete_account()
{
    FILE *fp1,*fp2;
    struct Account A;
    int ac,pi,flag=0,choice,p;
    fp1= fopen("account.txt","r");
    fp2= fopen("temp.txt","w");
    printf("\nEnter account number and pin to delete:");
    scanf("%d%d",&ac,&pi);
    while(!feof(fp1))
    {
        fread((char *)&A,sizeof(struct Account),1,fp1);
        if(feof(fp1))
            break;
        if(A.acno==ac && A.pin == pi)
        {
            display(A);
            flag=1;
        }
        else
            fwrite((char *)&A,sizeof(struct Account),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    if(flag==0)
        printf("\n********** ACCOUNT NOT FOUND ***************");
    else
    {
        remove("account.txt");
        rename("temp.txt","account.txt");
        printf("\n***** RECORD DELETED SUCCESSFULLY ************");
    }
}
void transactions()
{
    FILE *fp1,*fp2;
    struct Account A;
    int ac,pi,flag=0,choice,amt;
    fp1= fopen("account.txt","r");
    fp2= fopen("temp.txt","w");
    printf("\nEnter account number and pin for Transaction:");
    scanf("%d%d",&ac,&pi);
    while(!feof(fp1))
    {
        fread((char *)&A,sizeof(struct Account),1,fp1);
        if(feof(fp1))
            break;
        if(A.acno==ac && A.pin == pi)
        {
            display(A);
            flag=1;
            printf("\n1. Withdraw\n2. Deposit\nEnter choice:");
            scanf("%d",&choice);
            if(choice == 1)
            {
                if(A.bal>500)
                {
                    printf("\nEnter amount to withdraw :");
                    scanf("%d",&amt);
                    if((A.bal-amt)>=500)
                    {
                        A.bal-=amt;
                        printf("\n***** WITHDRAWAL SUCCESSFULLY *********");
                    }
                    else
                        printf("\n******* INSUFFICIENT BALANCE ***********");
                }
            }
            else if(choice == 2)
            {
                printf("\nEnter amount to deposit:");
                scanf("%d",&amt);
                A.bal+=amt;
                printf("\nDeposit Successful");
            }
            else
                printf("\n************ INVALID CHOICE ***********");
            fwrite((char *)&A,sizeof(struct Account),1,fp2);
        }
        else
            fwrite((char *)&A,sizeof(struct Account),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    if(flag==0)
        printf("\n********** ACCOUNT NOT FOUND ***************");
    else
    {
        remove("account.txt");
        rename("temp.txt","account.txt");
    }
}
