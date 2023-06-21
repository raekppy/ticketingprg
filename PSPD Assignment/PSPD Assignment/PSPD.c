#include <stdio.h>

int num = 0;
int done = 0;

struct customer {
	char name[20];
	int code;
	int ic;
	float reward;
}C[100];

reg(){
	struct customer;
	printf("Enter Name: ");
	fflush(stdin);
	gets(C[num].name);
	printf("Your Name is %s\n\n", C[num].name);
	printf("Enter IC Number: ");
	scanf("%d", &C[num].ic);
	printf("Your IC Number is %d\n\n", C[num].ic);
	C[num].code = 100001 + num;
	C[num].reward = 0;
	printf("Your 6 digits code is %d\n", C[num].code);
	system("pause");
	num++;
	system ("cls");
}

tic(){
	int input;
	printf("1. To continue purchase ticket as member \n2. To continue purchase ticket as guest \n");
	scanf("%d", &input);
	switch (input){
	case 1:
		member();
		break;
	case 2:
		guest();
		break;
	default:
		printf("Please Try Again\n");
		system("pause");
		system("cls");
	}
}

member(){
	int code_input, Dstation, Astation, time, Atick, Ctick;
	int code_found = 0;
	int count = 0;
	int y = 1;
	int j = 1;
	float price, Cprice, reward, Diffstation, rem, pts;
	float Rdiscount = 0;
	float amount;
	struct customer;
	printf("Please Enter 6 digits code: \n");
	scanf("%d", &code_input);
	for (int a = 0; a < 100; a++) {
		if (code_input == C[a].code) {
			code_found = 1;
			break;
		}
		else
		{
			count++;
		}
	}
	if (code_found == 1) {
		printf("Please Enter Your Departure Station Number (Example: 1): ");
		scanf("%d", &Dstation);
		if (j != 0) {
			printf("Please Enter Your Arrival Station Number (Example: 1): ");
			scanf("%d", &Astation);
			if (Astation <= Dstation) {
			Diffstation = -(Astation - Dstation);
			price = Diffstation;
			printf("Please Select Your Travel Time\n 1. [7PM - 11PM] OR [6AM - 7:15AM]\n 2. [Others] \n");
			scanf("%d", &time);
			switch (time){
			case 1:
				price = price * 0.75;
				break;
			case 2:
				price = price * 1;
				break;
			default:
				printf("Bad Input");
			}
			printf("Please Enter Number Of Adult Ticket: \n");
			scanf("%d", &Atick);
			if (Atick >= 5) {
				price = (price * Atick) * 0.9;
			}
			else {
				price = price * Atick;
			}
			printf("Please Enter Number Of Children Ticket: \n");
			scanf("%d", &Ctick);
			Cprice = (Diffstation / 2) * Ctick;
			price = price + Cprice;
			while (C[count].reward >= 500) {
				C[count].reward = C[count].reward - 500;
				Rdiscount = Rdiscount + 5;
			}
			price = price - Rdiscount;
			reward = (int)price;
			printf("Total Price: RM%.2f\n", price);

			while (y != 0) {
				printf("Please Enter Payment Amount: \n");
				scanf("%f", &amount);
				if (amount < price){
					printf("Invalid Input\n");
				}
				else {
					rem = amount - price;
					printf("Remainder: RM%.2f\n", rem);
					C[count].reward = C[count].reward + reward;
					printf("Points Cumulated: %.2f\n", C[count].reward);
					break;
				}
		}
	}
		else {
		Diffstation = Astation - Dstation;
		price = Diffstation;
		printf("Please Select Your Travel Time\n 1. [7PM - 11PM] OR [6AM - 7:15AM]\n 2. [Others] \n");
		scanf("%d", &time);
		switch (time){
		case 1:
			price = price * 0.75;
			break;
		case 2:
			price = price * 1;
			break;
		default:
			printf("Bad Input");
		}
		printf("Please Enter Number Of Adult Ticket: \n");
		scanf("%d", &Atick);
		if (Atick >= 5) {
			price = (price * Atick) * 0.9;
		}
		else {
			price = price * Atick;
		}
		printf("Please Enter Number Of Children Ticket: \n");
		scanf("%d", &Ctick);
		Cprice = (Diffstation / 2) * Ctick;
		price = price + Cprice;
			while (C[count].reward >= 500) {
				C[count].reward = C[count].reward - 500;
				Rdiscount = Rdiscount + 5;
			}
			price = price - Rdiscount;
			reward = (int)price;
			printf("Total Price: RM%.2f\n", price);
		
			while (y != 0) {
				printf("Please Enter Payment Amount: \n");
				scanf("%f", &amount);
				if (amount < price){
					printf("Invalid Input\n");
				}
				else {
					rem = amount - price;
					printf("Remainder: RM%.2f\n", rem);
					C[count].reward = C[count].reward + reward;
					printf("Points Cumulated: %.2f\n", C[count].reward);
					break;
				break;
			}
		}
		
				}
			}
		}
	else {
		printf("Code Not Found\n\n");
	}
	system("pause");
	system("cls");
	}


guest(){
	int code_input, Dstation, Astation, time, Atick, Ctick;
	int code_found = 0;
	int count = 0;
	int y = 1;
	int j = 1;
	float price, Cprice, reward, Diffstation, rem, pts;
	float Rdiscount = 0;
	float amount;
	struct customer;
	printf("Please Enter Your Departure Station Number (Example: 1): ");
	scanf("%d", &Dstation);
	if (j != 0) {
	printf("Please Enter Your Arrival Station Number (Example: 1): ");
	scanf("%d", &Astation);
	if (Astation <= Dstation) {
		Diffstation = -(Astation - Dstation);
		price = Diffstation;
		printf("Please Select Your Travel Time\n 1. [7PM - 11PM] OR [6AM - 7:15AM]\n 2. [Others] \n");
		scanf("%d", &time);
		switch (time){
		case 1:
			price = price * 0.75;
			break;
		case 2:
			price = price * 1;
			break;
		default:
			printf("Bad Input");
		}
		printf("Please Enter Number Of Adult Ticket: \n");
		scanf("%d", &Atick);
		if (Atick >= 5) {
			price = (price * Atick) * 0.9;
		}
		else {
			price = price * Atick;
		}
		printf("Please Enter Number Of Children Ticket: \n");
		scanf("%d", &Ctick);
		Cprice = (Diffstation / 2) * Ctick;
		price = price + Cprice;
		while (C[count].reward >= 500) {
			C[count].reward = C[count].reward - 500;
			Rdiscount = Rdiscount + 5;
		}
		price = price - Rdiscount;
		reward = (int)price;
		printf("Total Price: RM%.2f\n", price);

		while (y != 0) {
			printf("Please Enter Payment Amount: \n");
			scanf("%f", &amount);
			if (amount < price){
				printf("Invalid Input\n");
			}
			else {
				rem = amount - price;
				printf("Remainder: RM%.2f\n", rem);
				break;
			}
		}
	}
	else {
	Diffstation = Astation - Dstation;
	price = Diffstation;
	printf("Please Select Your Travel Time\n 1. [7PM - 11PM] OR [6AM - 7:15AM]\n 2. [Others] \n");
	scanf("%d", &time);
	switch (time){
	case 1:
		price = price * 0.75;
		break;
	case 2:
		price = price * 1;
		break;
	default:
		printf("Please Try Again\n");
	}
	printf("Please Enter Number Of Adult Ticket: \n");
	scanf("%d", &Atick); 
	if (Atick >= 5) {
		price = (price * Atick) * 0.9;
	}
	else {
		price = price * Atick;
	}
	printf("Please Enter Number Of Children Ticket: \n");
	scanf("%d", &Ctick);
	Cprice = (Diffstation / 2) * Ctick;
	price = price + Cprice;
	printf("Total Price: RM%.2f\n", price);
	while (y != 0){
		printf("Please Enter Payment Amount: \n");
		scanf("%f", &amount);
		if (amount < price){
			printf("Invalid Input\n");
		}
		else {
		rem = amount - price;
		printf("Remainder: RM%.2f\n", rem);
		break;
			}
		}
	}
}
	system("pause");
	system("cls");
}

rew(){
	struct customer;
	int six_code, c_reward;
	printf("Please Enter Your 6 digits code: \n");
	scanf("%d", &six_code);
	for (int b = 0; b < 100; b++) {
		if (six_code == C[b].code) {
			printf("Your Name: %s\n",C[b].name);
			printf("Your IC Number: %d\n", C[b].ic);
			printf("Your Reward Point: %.2f\n", C[b].reward);
			break;
		}
		else
		{
			printf("Code Not Found");
		}
	}
	system("pause");
	system("cls");
}

void main() {
	while (done != 1){
		int option;
		printf("\n\t\t==Welcome To KiwiExpress Ticketing System==\n\n");
		printf("1. Registration \n2. Check Reward \n3. Purchase Ticket\n");
		scanf("%d", &option);
		switch (option){
		case 1:
			reg();
			break;
		case 2:
			rew();
			break;
		case 3:
			tic();
			break;
		default:
			printf("Please Try Again\n");
			system("pause");
			system("cls");
	}
}
	system("pause");
}