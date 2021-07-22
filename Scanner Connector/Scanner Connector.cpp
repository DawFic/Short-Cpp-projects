#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include "LJV7_IF.h"
#include <fstream>
#include <stdlib.h> 
#include <time.h>
#include <conio.h>
#pragma warning(disable:4996)
#define ROBOT 8
#define SKANER 14
#define PORT 5020
#define ETHPORT 24691


using namespace std;

int main() {
	char znak = 0;
	
	
	BYTE	abyIpAddress[4];	// The IP address of the controller to connect to. 
	WORD	wPortNo;// The port number of the controller to connect to.
	LJV7IF_ETHERNET_CONFIG pEthernetConfig;
	pEthernetConfig.abyIpAddress[0] = 192; 
	pEthernetConfig.abyIpAddress[1] = 168;
	pEthernetConfig.abyIpAddress[2] = 2;
	pEthernetConfig.abyIpAddress[3] = 5;
	pEthernetConfig.wPortNo = ETHPORT;
	LJV7IF_EthernetOpen(0, &pEthernetConfig);
	//LJV7IF_UsbOpen(0);
	byte jointID = 0; // nr programu skanera
	char fanucBufor[ROBOT]; // bufor wejsciowy od robota do skanera
	char skanerBufor[SKANER]; //bufor wyjsciowy od skanera do robota
	WSADATA WSAData;

	SOCKET server, client;
	
	SOCKADDR_IN serverAddr, clientAddr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);

	// socket create and verification 
	
	server = socket(AF_INET, SOCK_STREAM, 0);
	if (server == -1) 
	{
		printf("socket creation failed...\n");
		exit(0);
	}
	else
	{
		printf("Socket successfully created..\n");
	}
	memset(&serverAddr,0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification 
	if ((bind(server, (SOCKADDR*)&serverAddr, sizeof(serverAddr))) != 0) 
	{
		printf("socket bind failed...\n");
	}
	else
	{
		printf("Socket successfully binded..\n");
	}
	// Now server is ready to listen and verification 
	if ((listen(server, 5)) != 0) 
	{
		printf("Listen failed...\n");
	}
	else 
	{
		printf("Server listening..\n");
	}

	int clientAddrSize = sizeof(clientAddr);

	client = accept(server, (SOCKADDR*)&clientAddr, &clientAddrSize);
	if (client < 0) 
	{
		printf("server acccept failed...\n");
	}
	else
	{
		printf("server acccept the client...\n");
	}
	//nieskończona pętla komunikacji
	while (1) {
		memset(fanucBufor, 0, sizeof(fanucBufor)); //zerowanie bufora wejsciowego
		memset(skanerBufor, 0, sizeof(skanerBufor)); //zerowanie bufora wyjsciowego
		recv(client, fanucBufor, sizeof(fanucBufor), 0);

		//Request Status
		if (fanucBufor[0] == 0x1 && fanucBufor[1] == 0x1 && fanucBufor[2] == 0x6) {
			byte licznikBledow = 0;
			WORD tabBledow[1];
			LJV7IF_GetError(0, 3, &licznikBledow, tabBledow);
			//Wysłanie odpowiedzi bez błędu do robota
			if (licznikBledow == 0) {
				skanerBufor[0] = 0x82;
				skanerBufor[1] = 0x0;
				skanerBufor[2] = 0x18;
				skanerBufor[3] = 0x1;
			}
			else {
				//Wyjście z pętli
				break;
			}

		}
		//Set Joint ID
		else if (fanucBufor[0] == 0x2 && fanucBufor[1] == 0x1 && fanucBufor[2] == 0x10) {
			LJV7IF_ChangeActiveProgram(0, fanucBufor[3]);
			jointID = fanucBufor[3];
			skanerBufor[0] = 0x82;
		}
		//Request joint data
		else if (fanucBufor[0] == 0x1 && fanucBufor[1] == 0x6 && fanucBufor[2] == 0x8 && fanucBufor[3] == 0x9 && fanucBufor[4] == 0xA && fanucBufor[5] == 0xB && fanucBufor[6] == 0xC && fanucBufor[7] == 0xD) {
			LJV7IF_MEASURE_DATA aMeasureData[LJV7IF_OUT_COUNT];
			LJV7IF_GetMeasurementValue(0, aMeasureData);
			if (aMeasureData[0].byDataInfo == 0x1 || aMeasureData[0].byDataInfo == 0x2 || aMeasureData[1].byDataInfo == 0x1 || aMeasureData[1].byDataInfo == 0x2)
				skanerBufor[1] = 0xC;
			else
				skanerBufor[1] = 0x0;

			skanerBufor[0] = 0x82;
			skanerBufor[2] = 0x0;//X
			skanerBufor[3] = 0x0;//X
			skanerBufor[5] = (short)(aMeasureData[1].fValue * 100);//młodszy bajt Y(OUT2) wczytany do tabeli	
			skanerBufor[4] = ((short)(aMeasureData[1].fValue * 100)) >> 8;//starszy bajt Y(OUT2) wczytany do tabeli
			skanerBufor[7] = (short)(aMeasureData[0].fValue * 100);//młodszy bajt Z(OUT1) wczytany do tabeli
			skanerBufor[6] = ((short)(aMeasureData[0].fValue * 100)) >> 8;//starszy bajt Z(OUT1) wczytany do tabeli
			skanerBufor[8] = 0x0;//Gap
			skanerBufor[9] = 0x0;//Gap
			skanerBufor[10] = 0x0;//Mismatch
			skanerBufor[11] = 0x0;//Mismatch
			skanerBufor[12] = 0x0;//Area
			skanerBufor[13] = 0x0;//Area
		}
		//Request Joint ID
		else if (fanucBufor[0] == 0x1 && fanucBufor[1] == 0x1 && fanucBufor[2] == 0x10) {
			skanerBufor[0] = 0x82;
			skanerBufor[1] = 0x0;
			skanerBufor[2] = 0x0;
			skanerBufor[3] = jointID;
		}
		//End Track oraz Sensor OFF
		else if (fanucBufor[0] == 0x2 && fanucBufor[1] == 0x1 && fanucBufor[2] == 0x6 && fanucBufor[3] == 0x0) {
			LJV7IF_TARGET_SETTING targetSetting;
			targetSetting.byType = jointID + 16;		// Setting type
			targetSetting.byCategory = 0x0;		// Category
			targetSetting.byItem = 0x1;			// Setting item
			targetSetting.byTarget1 = 0x0;		// Setting Target 1
			targetSetting.byTarget2 = 0x0;		// Setting Target 2
			targetSetting.byTarget3 = 0x0;		// Setting Target 3
			targetSetting.byTarget4 = 0x0;		// Setting Target 4
			DWORD dwError;
			int buf = 1;
			LJV7IF_SetSetting(0, 2, targetSetting, &buf , 1, &dwError);
			skanerBufor[0] = 0x82;
		}
		//Start Track
		else if (fanucBufor[0] == 0x2 && fanucBufor[1] == 0x1 && fanucBufor[2] == 0x6 && fanucBufor[3] == 0x1) {
			LJV7IF_TARGET_SETTING targetSetting;
			targetSetting.byType = jointID + 16;			// Setting type
			targetSetting.byCategory = 0x0;		// Category
			targetSetting.byItem = 0x1;			// Setting item
			targetSetting.byTarget1 = 0x0;		// Setting Target 1
			targetSetting.byTarget2 = 0x0;		// Setting Target 2
			targetSetting.byTarget3 = 0x0;		// Setting Target 3
			targetSetting.byTarget4 = 0x0;		// Setting Target 4
			DWORD dwError;
			int buf = 0;
			LJV7IF_SetSetting(0, 2, targetSetting, &buf, 1, &dwError);
			skanerBufor[0] = 0x82;
		}
		//Sensor ON
		else if (fanucBufor[0] == 0x2 && fanucBufor[1] == 0x1 && fanucBufor[2] == 0x13 && fanucBufor[3] == 0x1) {
			LJV7IF_TARGET_SETTING targetSetting;
				targetSetting.byType=jointID+16;			// Setting type
				targetSetting.byCategory=0x0;		// Category
				targetSetting.byItem=0x1;			// Setting item
				targetSetting.byTarget1=0x0;		// Setting Target 1
				targetSetting.byTarget2=0x0;		// Setting Target 2
				targetSetting.byTarget3=0x0;		// Setting Target 3
				targetSetting.byTarget4=0x0;		// Setting Target 4
				DWORD dwError;
				int buf = 1;
			LJV7IF_SetSetting(0, 2, targetSetting, &buf, 1, &dwError);
			skanerBufor[0] = 0x82;
		}
		send(client, skanerBufor, sizeof(skanerBufor), 0);
	}
	cout << "Program Closing" << endl;
	closesocket(server);
	return 0;
}
