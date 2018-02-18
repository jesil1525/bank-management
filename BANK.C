#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


void admin();
void user();
void admin_login();
void user_login();
void add();
void list();
void edit();
void del();
void depwith();
void bal();
void transfer();

struct account
{
  long int accno;
  char name[30];
  int age;
  char sex;
  char dob[12];
  char aadhar[15];
  char address[50];
  char contact[20];
  float bal;
};

void main()
{
       int o;
       clrscr();
       printf("\nWELCOME TO AAA BANK\n");
       printf("\n1.Login as Administrator\n2.Login as User\n3.Exit\nYour choice");
       scanf("%d",&o);
       switch(o)
       {
	   case 1: admin_login();
		   break;
	   case 2: user_login();
		   break;
	   case 3: exit(0);
		   break;
	   default: printf("\nInvalid Option");
		    printf("\n1.Retry\n2.Exit\nYour choice:");
		    scanf("%d",&o);
		    switch(o)
		    {
		       case 1: main();
			       break;
		       case 2: exit(0);
			       break;
		       default: printf("\nInvalid Option");
		    }
       }
       getch();
}

void admin_login()
{
	int i=0,o;
	char ch,ap[10],eap[10];
	strcpy(ap,"a123");
	clrscr();
	printf("\nWelcome Administrator");
	printf("\nEnter Password:");
	do
	{
	     ch=getch();
	     if(ch!=13)
	     {
		 eap[i]=ch;
		 printf("*");
		 i++;
	     }
	     else
		 eap[i]=NULL;
	}while(ch!=13);
	if(strcmp(ap,eap)==0)
	{
	      admin();
	}
	else
	{
	      clrscr();
	      printf("\nInvalid Password!!");
	      printf("\n\n1.Retry.\n2.Go to home page.\n3.Exit.\nYour Option");
	      scanf("%d",&o);
	      switch(o)
	      {
		    case 1: admin_login();
			    break;
		    case 2: main();
			    break;
		    case 3: exit(0);
			    break;
		    default: exit(0);
	      }
	}
}
void admin()
{
      int o;
      clrscr();
      printf("\nWELCOME ADMIN");
      printf("\n1.Create Account\n2.Edit Account\n3.Delete Account\n4.List All Accounts\n5.Logout\n6.Exit\nYour choice:");
      scanf("%d",&o);
      switch(o)
      {
      case 1: add();
	      break;
      case 2: edit();
	      break;
      case 3: del();
	      break;
      case 4: list();
	      break;
      case 5: main();
	      break;
      case 6: exit(0);
	      break;
      default:main();
      }


      getch();
}
void add()
{
    struct account a;
    FILE *f1;
    int o;
    long int no;
    clrscr();
    f1=fopen("reco.dat","a+");
    printf("\nEnter Account.no:");
    scanf("%d",&no);
    while(fscanf(f1,"%d %s %d %c %s %s %s %s %f",&a.accno,a.name,&a.age,&a.sex,a.dob,a.aadhar,a.address,a.contact,&a.bal)!=EOF)
    {
	 if(a.accno==no)
	 {
	    printf("\nAccount number already taken!Try another!");
	    add();
	 }
    }
    a.accno=no;
    printf("\nADD RECORD\n");
    printf("\nEnter Name:");
    scanf("%s",a.name);
    printf("\nEnter Age:");
    scanf("%d",&a.age);
    printf("\nEnter Sex(M/F):");
    scanf("%s",a.sex);
    printf("\nEnter Date of Birth(dd/mm/yyyy):");
    scanf("%s",a.dob);
    printf("\nEnter Aadhar Card No.:");
    scanf("%s",a.aadhar);
    printf("\nEnter Address:");
    scanf("%s",a.address);
    printf("\nEnter Contact No.:");
    scanf("%s",a.contact);
    printf("\nMinimum Balance should be Rs.500");
    printf("\nEnter 500 if deposited:");
    scanf("%f",&a.bal);

    fprintf(f1,"%d %s %d %c %s %s %s %s %f\n",a.accno,a.name,a.age,a.sex,a.dob,a.aadhar,a.address,a.contact,a.bal);

    fclose(f1);
    printf("\nRecord Added Successfully");
    printf("\n1.Add Account\n2.Go to Home\n3.Go to main\n4.Logout\nYour option:");
    scanf("%d",&o);
    switch(o)
    {
	  case 1: add();
		  break;
	  case 2: admin();
		  break;
	  case 3: main();
		  break;
	  default:{
		  printf("\nInvalid");
		  admin();
		  }
    }
    getch();
}
void list()
{
    struct account a;
    FILE *view;
    int i=0,o;
    clrscr();
    view=fopen("reco.dat","r");
    printf("\nUSER LIST");
    while(fscanf(view,"%d %s %d %c %s %s %s %s %f",&a.accno,a.name,&a.age,&a.sex,a.dob,a.aadhar,a.address,a.contact,&a.bal)!=EOF)
    {
       printf("\n%d\n%s\n%d\n%c\n%s\n%s\n%s\n%s\n%f",a.accno,a.name,a.age,a.sex,a.dob,a.aadhar,a.address,a.contact,a.bal);
       i++;
    }
    fclose(view);
    if(i==0)
	printf("\nNO RECORDS FOUND");
    printf("\n1.Go to menu\n2.Logout");
    scanf("%d",&o);
    switch(o)
    {
       case 1: admin();
	       break;
       case 2: main();
	       break;
       default: admin();
    }
     getch();

}
void edit()
{
     struct account a;
     int found=0,o;
     long int no;
     FILE *old,*newrec;
     clrscr();
     old=fopen("reco.dat","r");
     newrec=fopen("new.dat","w");
     printf("\nEnter the Account no. to edit details:");
     scanf("%d",&no);
     while(fscanf(old,"%d %s %d %c %s %s %s %s %f",&a.accno,a.name,&a.age,&a.sex,a.aadhar,a.address,a.contact,&a.bal)!=EOF)
     {
     if(a.accno==no)
     {
	 found=1;
	 printf("\nEnter Name:");
	 scanf("%s",a.name);
	 printf("\nEnter Age:");
	 scanf("%d",&a.age);
	 printf("\nEnter Sex:");
	 scanf("%c",&a.sex);
	 printf("\nEnter date of the birth:");
	 scanf("%s",a.dob);
	 printf("\nEnter Aadhar number:");
	 scanf("%s",a.aadhar);
	 printf("\nEnter Contact No.:");
	 scanf("%s",a.contact);

	 fprintf(newrec,"%d %s %d %c %s %s %s %s %f",a.accno,a.name,a.age,a.sex,a.dob,a.aadhar,a.address,a.contact,a.bal);
     }
     }
     fclose(old);
     fclose(newrec);
     remove("reco.dat");
     rename("new.dat","reco.dat");
     if(found!=0)
     printf("\nChanges Saved Successfully!");
     else
     printf("\nAccount no. does not exist");
     printf("\n1.Edit Account\n2.Go to menu\n3.Logout\nYour choice:");
     scanf("%d",&o);
     switch(o)
     {
	 case 1: edit();
		 break;
	 case 2: admin();
		 break;
	 case 3: main();
		 break;
	 default:main();
     }
     getch();
}
void del()
{
    struct account a;
    int found=0,o;
    long int no;
    FILE *old,*newrec;
    clrscr();
    old=fopen("reco.dat","r");
    newrec=fopen("new.dat","w");
    printf("\nEnter the Account no.to Delete the record:");
    scanf("%d",&no);
    while(fscanf(old,"%d %s %d %c %s %s %s %s %f",&a.accno,a.name,&a.age,&a.sex,a.aadhar,a.address,a.contact,&a.bal)!=EOF)
    {
       if(a.accno!=no)
       {
	   fprintf(newrec,"%d %s %d %c %s %s %s %s %f",a.accno,a.name,a.age,a.sex,a.aadhar,a.address,a.contact,a.bal);
       }
       else
       {
	 printf("\nRecord deleted successfully!!");
	 found++;
       }
    }
    fclose(old);
    fclose(newrec);
    remove("reco.dat");
    rename("new.dat","reco.dat");
    if(found!=0)
    {
       printf("\nAccount deleted successfully!!");
    }
    else
    {
       printf("\nRecord not found!");
       printf("\n1.Try again\n2.Go to menu\n3.Logout\nYour choice:");
       scanf("%d",&o);
       switch(o)
       {
	   case 1: del();
		   break;
	   case 2: admin();
		   break;
	   case 3: main();
		   break;
	   default:admin();
       }
    }
}
void user()
{
  int o;
  clrscr();
  printf("\nWelcome to AAA Bank\n");
  printf("\n1.Deposit/Withdraw\n2.Transfer\n3.Balance Enquiry\nYour Choice:");
  switch(o)
  {
       case 1: depwith();
	       break;
       case 2: transfer();
	       break;
       case 3: bal();
	       break;
       default: main();
  }
   getch();
}
void user_login()
{
   struct account a;
   int found=0,o;
   long int no;
   char b[10];
   FILE *f1;
   f1=fopen("reco.dat","r");
   clrscr();
   printf("\nEnter Acc.no.:");
   scanf("%d",&no);
   printf("Enter Password(D.O.B)(mm/dd/yyyy):");
   scanf("%s",b);
   while(fscanf(f1,"%d %s %d %c %s %s %s %s %f",&a.accno,a.name,&a.age,&a.sex,a.dob,a.aadhar,a.address,a.contact,&a.bal)!=EOF)
   {
     if((a.accno==no)&&(a.dob==b))
     {
	found=1;
     }
   }
   fclose(f1);
     if(found==1)
     {
	 user();
     }
     else
     {
	printf("\nInvalid!!");
	printf("\n1.Retry\n2.Go to home\nYour Choice:");
	scanf("%d",&o);
	switch(o)
	{
	   case 1: user_login();
		   break;
	   case 2: main();
		   break;
	   default: main();
	}
     }
     getch();
}
void depwith()
{
    struct account a;
    long int no,o;
    int found=0;
    float m;
    FILE *old,*newrec;
    clrscr();
    old=fopen("reco.dat","r");
    newrec=fopen("new.dat","w");
    printf("\nEnter Acc.no.:");
    scanf("%d",&no);
    printf("\nDeposit/wiithdraw Amount:");
    scanf("%d",&m);
    while(fscanf(old,"%d %s %d %c %s %s %s %s %f",&a.accno,a.name,&a.age,&a.sex,a.dob,a.aadhar,a.address,a.contact,&a.bal)!=EOF)
    {
      if(a.accno==no)
      {
	  found=1;
	  printf("\n1.Deposit\n2.Withdraw\nYour Choice:");
	  scanf("%d",&o);
	  switch(o)
	  {
	     case 1: a.bal+=m;
		     break;
	     case 2: a.bal-=m;
		     break;
	     default: printf("\nInvalid");
		      depwith();
	  }
	  fprintf(newrec,"%d %s %d %c %s %s %s %s %f",a.accno,a.name,a.age,a.sex,a.dob,a.aadhar,a.address,a.contact,a.bal);
      }
    }
    fclose(old);
    fclose(newrec);
    remove("reco.dat");
    rename("new.dat","reco.dat");
    if(found!=0)
    {
       printf("\nAmount Deposited successfully!!\n");
       printf("\n1.Go to menu\n2.Logout\nYour Choice:");
       scanf("%d",&o);
       switch(o)
       {
	  case 1:user();
		 break;
	  case 2:main();
		 break;
	  default:user();
       }
    }
    else
    {
       printf("\nInvalid Acc.no.\n");
       printf("\n1.Retry\n2.Go to menu\n3.logout\nYour choice:");
       scanf("%d",&o);
       switch(o)
       {
	  case 1: depwith();
		  break;
	  case 2: user();
		  break;
	  case 3: main();
		  break;
	  default: user();
       }
    }
    getch();
}
void bal()
{
   struct account a;
   int found=0,c;
   long int no;
   FILE *f1;
   clrscr();
   f1=fopen("reco.dat","r");
   printf("\nEnter Acc.no.:");
   scanf("%d",&no);
   while(fscanf(f1,"%d %s %d %c %s %s %s %s %f",&a.accno,a.name,&a.age,&a.sex,a.dob,a.aadhar,a.address,a.contact,&a.bal)!=EOF)
   {
     if(a.accno==no)
     {
	found=1;
	printf("\nBalance:%f",a.bal);
     }
   }
   fclose(f1);
   if(found!=0)
   {
       printf("\nInvalid Account Number");
       printf("\n1.Retry\n2.Go to menu\n3.Logout\nYou Choice:");
       scanf("%d",&c);
       switch(c)
       {
	  case 1: bal();
		  break;
	  case 2: user();
		  break;
	  case 3:main();
		 break;
	  default:user();
       }
   }
   else
   {
       printf("\n1.Go Back\n2.Logout\nYour Choice:");
       scanf("%d",&c);
       switch(c)
       {
	  case 1:user();
		 break;
	  case 2:main();
		 break;
	  default:user();
       }
   }
   getch();
}
void transfer()
{
    struct account a;
    long int no,n;
    int found=0,o;
    float m;
    FILE *old,*newrec;
    clrscr();
    old=fopen("reco.dat","r");
    newrec=fopen("new.dat","w");
    printf("\nEnter your Acc.no.:");
    scanf("%d",&no);
    printf("\nEnter Acc.no. to transfer:");
    scanf("%d",&n);
    printf("\nEnter Amount to be transferred:");
    scanf("%d",&m);
    while(fscanf(old,"%d %s %d %c %s %s %s %s %f",&a.accno,a.name,&a.age,&a.sex,a.dob,a.aadhar,a.address,a.contact,&a.bal)!=EOF)
    {
       if(a.accno==no)
       {
	    found++;
       }
       if(a.accno==n)
       {
	    found++;
       }
       if(found==2)
       {
	    while(fscanf(old,"%d %s %d %c %s %s %s %s %f",&a.accno,a.name,&a.age,&a.sex,a.dob,a.aadhar,a.address,a.contact,&a.bal)!=EOF)
	    {
		if(a.accno==no)
		{
		    a.bal-=m;
		    fprintf(newrec,"%d %s %d %c %s %s %s %s %f",a.accno,a.name,a.age,a.sex,a.dob,a.aadhar,a.address,a.contact,a.bal);
		}
		if(a.accno==n)
		{
		    a.bal+=m;
		    fprintf(newrec,"%d %s %d %c %s %s %s %s %f",a.accno,a.name,a.age,a.sex,a.dob,a.aadhar,a.address,a.contact,a.bal);
		}
	    }
       }
    }
    fclose(old);
    fclose(newrec);
    remove("reco.dat");
    rename("new.dat","reco.dat");

    if(found==0)
    {
	printf("\nInvalid Account number!\n");
	printf("\n1.Retry\n2.Go to menu\n3.Logout");
	scanf("%d",&o);
	switch(o)
	{
	    case 1: transfer();
		    break;
	    case 2: user();
		    break;
	    case 3: main();
		    break;
	    default: user();
	}
    }
    else
    {
	 printf("\nAmount Transfered Successfully!!\n");
	 printf("\n1.Go to menu\n2.Logout");
	 scanf("%d",&o);
	 switch(o)
	 {
	    case 1: user();
		    break;
	    case 2: main();
		    break;
	    default: user();
	 }
    }
    getch();
}
























































































