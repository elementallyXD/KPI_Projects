#include "BinTree.h"
#include <conio.h>

using namespace std;

int main(void)
{
	BinTree ticket;              // Creat been tree
	ticket.ReadInfo("List.csv"); // Picking information from csv
	
	cout << "\t\t\t\tLab4_V2_Bidyak\n" << endl;
	cout << "Print Tree (UP):" << endl;
	printf("______________________________________________________________________________________________\n");
	ticket.ShowTree(UP);         //print all tickets
	printf("______________________________________________________________________________________________\n\n");

	cout << "\nAdding ticket: \"\"Austria\",988,\"Ivanov\",25.12 \"" << endl;
	ticket.AddTicket("Austria",988,"Ivanov",25.12);
	cout << "Print Tree (UP):" << endl;
	printf("______________________________________________________________________________________________\n");
	ticket.ShowTree(UP);        //print all tickets
	printf("______________________________________________________________________________________________\n\n");

	cout << "\nPrint elements by Flight and Date:" << endl;
	cout << "All tickets with: 887 Flight; Date: 21.12;\n" << endl;
	printf("______________________________________________________________________________________________\n");
	ticket.Get_Ticket(887, 21.12);
	printf("______________________________________________________________________________________________\n\n");

	cout << "Delete ticket with \"666\" Flight:" << endl;
	cout << "Print Tree (UP) :" << endl;
	printf("______________________________________________________________________________________________\n");
	ticket.DelNode(666);      // delete node with 666 flight
	ticket.ShowTree(UP);      // print all tickets
	printf("______________________________________________________________________________________________\n\n");

	_getch();
	return 0;
}