#include<stdio.h>

#define OFF		2
#define ON		1

struct vehicle
{
	char traffic_light;
	int engine_tempreture;
	int room_tempreture;
	int engine_state;
	int speed;
	int AC;
	int TemperatureController;
};
struct vehicle car={'R',0,0,OFF,OFF,0,OFF};        //at R speed=0
void engineoff(void);
void traficlight(void);
void roomtempreture(void);
void enginetempreture(void);
void display(void);


int main()
{
	int option=2;

	while(car.engine_state==OFF)
	{
	printf( "Write 1 for Turn on the vehicle engine \n");
	printf("WRite 2 for Turn off the vehicle engine \n");
	printf( "Write 3 for Quit the system \n");
	printf( "write the option that you want : \n");
	fflush(stdout);

	scanf( "%d",&car.engine_state);

	if(car.engine_state ==3)
	{
		printf("quit\n");
		fflush(stdout);
		break;
	}
	else if(car.engine_state ==OFF)
	{
		printf("engine off\n");
		fflush(stdout);
	}
	else if(car.engine_state ==ON)
	{
		printf("engine on\n");
		while(car.engine_state==ON)
		{
		printf("write 2 for turn off engine\n");
		printf("write 3 for traffic light\n");
		printf("write 4 for room tempreture\n");
		printf("write 5 for engine tempreture\n");
		printf( "write the option that you want : \n");
		fflush(stdout);

		scanf( "%d",&option);

		if(option==2)
		{
			engineoff();
		}
		else if(option==3)
		{
			traficlight();
		}
		else if(option==4)
		{
			roomtempreture();
		}
		else if(option==5)
		{
			enginetempreture();
		}
		display();

	}
	}
	}

}


void engineoff(void)
{
	car.engine_state=OFF;
}


void traficlight(void)
{
	printf("enter traffic light\n");
	printf("enter G for orange and speed=100 \n");
	printf("enter O for orange and speed=30 \n");
	printf("enter R for orange and speed=0 \n");
	fflush(stdout);

	scanf(" %c",&car.traffic_light);

	if(car.traffic_light=='G')
	{
		car.speed=100;
	}
	else if(car.traffic_light=='O')
	{
		car.speed=30;
		car.AC=ON;
		car.TemperatureController=ON;
		car.room_tempreture =car.room_tempreture* (5/4) + 1;
		car.engine_tempreture =car.engine_tempreture* (5/4) + 1;
	}
	else if(car.traffic_light=='R')
	{
		car.speed=0;
	}
}

void roomtempreture(void)
{
	printf("enter room tempreture\n");
	fflush(stdout);
	scanf("%d",&car.room_tempreture);
	if(car.room_tempreture<10 ||car.room_tempreture>30)
	{
		car.room_tempreture=20;
		car.AC=ON;
	}
	else
	{
		car.AC=OFF;
	}
}


void enginetempreture(void)
{
	printf("enter engine tempreture\n");
	fflush(stdout);
	scanf("%d",&car.engine_tempreture);
	if(car.engine_tempreture<100 || car.engine_tempreture>150)
	{
		car.engine_tempreture=125;
		car.TemperatureController=ON;
	}
	else
	{
		car.TemperatureController=OFF;
	}
}

void display(void)
{
	if(car.engine_state==ON)
	{
		printf("Engine state is ON\n");
	}
	else
	{
		printf("Engine state is OFF\n");
	}

	if(car.AC==ON)
	{
		printf("AC is ON\n");
	}
	else
	{
		printf("AC is OFF\n");
	}

	printf("Vehicle Speed=%d\n",car.speed);
	printf("Room Temperature=%d\n",car.room_tempreture);

	if(car.TemperatureController==ON)
	{
		printf("Engine Temperature Controller State is ON\n");
	}
	else
	{
		printf("Engine Temperature Controller State is OFF\n");
	}

	printf("Engine Temperature=%d\n",car.engine_tempreture);
}




