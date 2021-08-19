/*****************************PREPROCESSORS****************************/

//INDIAN RAILWAY TICKET RESERVATION



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char name[50];
	int train_num;
	int num_of_seats;
}pd;




/*******************************FUNCTIONS****************************/
void reservation(void);							//  Reservation function
void viewdetails(void);							//View details of all the TRAINS
void payment(void);
void cancel(void);							// Cancel ticket	
void printticket(char name[],int,int,float);				// Print ticket  
void specifictrain(int);						// Print data related to specific train
float charge(int,int);							//charge w.r.t number of seats and train



/******************************** MAIN() FUNCTION *************************************/

int main()

{
	system("clear"); 
	printf("\t\t=====================================================================\n");
	printf("\t\t|                                                                   |\n");
	printf("\t\t|                                                                   |\n");
	printf("\t\t|        -----------------------------------------------            |\n");
	printf("\t\t|                      	 WELCOME TO                               |\n");
	printf("\t\t|           INDIAN RAILWAY TICKET RESERVATION SYSTEM                |\n");
	printf("\t\t|        -----------------------------------------------            |\n");
	printf("\t\t|                                                                   |\n");
	printf("\t\t|                                                                   |\n");
	printf("\t\t=====================================================================\n\n\n");
		
	    
	printf(" \n Press any key to continue:");
	getchar();


	int menu_choice,choice_return;

	start:

	
	printf("\n=================================================\n");
	printf("    INDIAN RAILWAY TICKET RESERVATION SYSTEM   ");
	printf("\n=================================================");
	printf("\n 1 >> Reserve A Ticket");
	printf("\n------------------------------------");
	printf("\n 2 >> View All Available Trains");
	printf("\n------------------------------------");
	printf("\n 3 >> Ticket Payment");
	printf("\n------------------------------------");
	printf("\n 4 >> Cancel Reservation");
	printf("\n------------------------------------");
	printf("\n 5 >> Exit");
	printf("\n------------------------------------");
	printf("\n\n Enter the choice -->");
	scanf("%d",&menu_choice);

	switch(menu_choice)
	{
		case 1:
			reservation();	
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..\n");
			getchar();
			break;
		case 3:
			payment();
			break;
		case 4:
			cancel();
			break;
		case 5:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

/***************************************VIEWDETAILS()**************************************/

 

void viewdetails(void)
{
	
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");	
	printf("\nTr.No |\tName\t\t\t|\tDestinations\t\t\t| Charges\t\t|  Departure\t\t|\t Arrival |\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n1001  |\tRani Channamma Express \t|\tBangalore to Belgavi\t\t| Rs.800\t\t|  22.15 \t\t| 08.45  |");
	printf("\n1002  |\tRani Channamma Express \t|\tBelagavi to Bangalore \t\t| Rs.800\t\t|  18.30 \t\t| 06.45 |");
	printf("\n1003  |\tBasav Express \t\t|\tBangalore to Vijayapur\t\t| Rs.500\t\t|  18.00 \t\t| 07.00  |");
	printf("\n1004  |\tCity Express\t\t|\tHuballi to Chennai \t\t| Rs.1000\t\t|  08.00 \t\t| 23.00  |");
	printf("\n1005  |\tInter City Express\t|\tMumbai to Dehli\t\t\t| Rs.2500\t\t|  03.00 \t\t| 15.30  |");
	printf("\n1006  |\tGolden City Express\t|\tKolar to Belagavi\t\t| Rs.400\t\t|  22.15 \t\t| 09.00  |");
	printf("\n1007  |\tYPR EXP\t\t\t|\tYesvantpur to Pune\t\t| Rs.750\t\t|  18.30 \t\t| 05.00  |");
	printf("\n1008  |\tKarnataka Express\t|\tMysore to Belagavi\t\t| Rs.800\t\t|  23.00 \t\t| 07.45  |");
	printf("\n1009  |\tGoa Express\t\t|\tKochi to Goa\t\t\t| Rs.1200\t\t|  17.00 \t\t| 10.15  |");
	printf("\n1010  |\tHaripriya Express\t|\tTirupati to Kolhapur\t\t| Rs.950\t\t|  14.30 \t\t| 09.45  |\n");    
	printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
}

/*********************************RESERVATION()********************************************/

void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	
	printf("\nEnter Your Name:> ");
	scanf("%s",passdetails.name);                                     // name
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);                            // no. of seats
	printf("\n\n>>Press Enter To View Available Trains<< \n");
	getchar();

	viewdetails();                                                    // all the trains details
	printf("\n\nEnter train number:> ");

	start1:

	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1001 && passdetails.train_num<=1010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);		
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}
	
	printf("\n\nConfirm Ticket (y/n) --->");
	
	start:

	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
	
		printf("====================");
		printf("\nReservation Done\n");
		printf("====================\n");
		printf("\nPress any key to go back to Main menu\n");
	}
	else
	{
		if(confirm=='n')
		{
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	
}

/********************************CHARGE()********************************/

float charge(int train_num,int num_of_seats)
{
	if (train_num==1001)
	{
		return(800.0*num_of_seats);
	}
	if (train_num==1002)
	{
		return(800.0*num_of_seats);
	}
	if (train_num==1003)
	{
		return(500.0*num_of_seats);
	}
	if (train_num==1004)
	{
		return(1000.0*num_of_seats);
	}
	if (train_num==1005)
	{
		return(2500.0*num_of_seats);
	}
	if (train_num==1006)
	{
		return(400.0*num_of_seats);
	}
	if (train_num==1007)
	{
		return(750.0*num_of_seats);
	}
	if (train_num==1008)
	{
		return(800.0*num_of_seats);
	}
	if (train_num==1009)
	{
		return(1200.0*num_of_seats);
	}
	if (train_num==1010)
	{
		return(950.0*num_of_seats);
	}
}


/****************************PRINTTICKET()*****************************/

void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charges);
}

/*************************** SPECIFICTRAIN()*******************************/

void specifictrain(int train_num)
{
	
	if (train_num==1001)
	{
		printf("\nTrain:\t\t\tRani Channamma Express");
		printf("\nDestination:\t\tBangalore to Belagavi");
		printf("\nDeparture:\t\t22.15");
		printf("\nArrival:\t\t08.45");
	}
	if (train_num==1002)
	{
		printf("\nTrain:\t\t\tRani Channamma Express");
		printf("\nDestination:\t\tBelagavi to Bangalore");
		printf("\nDeparture:\t\t18.30");
		printf("\nArrival:\t\t06.45");
	}
	if (train_num==1003)
	{
		printf("\nTrain:\t\t\tBasav Express");
		printf("\nDestination:\t\tBangalore to Vijayapur");
		printf("\nDeparture:\t\t18.00");
		printf("\nArrival:\t\t07.00");
		
	}
	if (train_num==1004)
	{
		printf("\nTrain:\t\t\tCity Express");
		printf("\nDestination:\t\thubballi to chennai");
		printf("\nDeparture:\t\t08.00");
		printf("\nArrival:\t\t23.00");
	}
	if (train_num==1005)
	{
		printf("\nTrain:\t\t\tInter city Express");
		printf("\nDestination:\t\tMumbai to dehli");
		printf("\nDeparture:\t\t03.00");
		printf("\nArrival:\t\t15.30");
	}
	if (train_num==1006)
	{
		printf("\ntrain:\t\t\tGolden City Express");
		printf("\nDestination:\t\tKolar to Belagavi");
		printf("\nDeparture:\t\t22.15");
		printf("\nArrival:\t\t09.00");
	}
	if (train_num==1007)
	{
		printf("\ntrain:\t\t\tYPR Express");
		printf("\nDestination:\t\tYesvantpur to Pune");
		printf("\nDeparture:\t\t18.30 ");
		printf("\nArrival:\t\t05.00");
	}
	if (train_num==1008)
	{
		printf("\ntrain:\t\t\tKarnataka Express");
		printf("\n Destination:\t\tMysore to Belagavi");
		printf("\nDeparture:\t\t23.00");
		printf("\nArrival:\t\t07.45");
	}
	if (train_num==1009)
	{
		printf("\ntrain:\t\t\tGoa Express");
		printf("\nDestination:\t\tKochi to Goa");
		printf("\nDeparture:\t\t17.00 ");
		printf("\nArrival:\t\t10.15");
	}
	if (train_num==1010)
	{
		printf("\ntrain:\t\t\tHaripriya Express");
		printf("\nDestination:\t\tTirupati to Kolhapur");
		printf("\nDeparture:\t\t14.30 ");
		printf("\nArrival:\t\t09.45");
	}
}

void payment(void)
{
	char press;
	printf("\n\nPayment through **  CARD OR BHIM/UPI ** Press : A");
	printf("\n\nPayment through ** CASH ** Press : B \n");
	printf("\n\nPress ( A / B ) ---:> ");

	start2:

	scanf(" %c",&press);
	if(press == 'A')
	{
		printf("====================");
		printf("\nPAYMENT IS DONE \n");
		printf("====================\n");
		printf("\nPress any key to go back to Main menu\n");
	}
	else
	{
		if(press=='B')
		{

			printf("====================");
			printf("\nPAYMENT DONE \n");
			printf("====================\n");
			printf("\nPress any key to go back to Main menu\n");
		}	
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start2;
		}
	}
}




void cancel(void) 
{
	 
	int train_num;
	printf("---------------------------\n");
	printf("  Enter the train number: \n");
	printf("---------------------------\n");
	scanf("%i",&train_num);
	printf("\n\nBooking is Cancelled");
 	
}
















