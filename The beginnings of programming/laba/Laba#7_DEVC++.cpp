/*#include <iostream>
#include <stdio.h>   //для стандартных ввода вывода
#include <windows.h> // для HANDLE, курсора, цвета,
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <unistd.h>  
using namespace std;

HANDLE hConsole;    //HANDLE hStdout
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);  // получение дескриптора устройства стандартного вывода

void GotoXY(int X, int Y)
{
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);  //функция премещения курсора по Х и У
}

void frame (int x1, int y1, int x2, int y2) //maluje ramku
{    int i;
 GotoXY(x1,y1);
 cout << '\311';;// верхній лівий куточок
 for (i=(x1+1); i<=(x2-1); i++) cout <<'\315';// подвійна горизонталь
 cout << '\273';// правий верхній куточок
 for (i=(y1+1); i<=(y2-1); i++)
  {
  GotoXY(x1,i);
  cout << '\272';// подвійна вертикальна
  GotoXY(x2,i);
  cout << '\272';
  }
  GotoXY(x1, y2);
  cout << '\310';
  for (i=(x1+1); i<=(x2-1);i++)
  cout << '\315';// подвійна горизонталь
  cout << '\274';// правий нижній куточок
 return ;
 } //frame

void zastavka ()
{
 system ("cls");
 frame (10,5,70,18);
 GotoXY(34,8);  cout << "Laboratory work"<<endl;
 GotoXY(32, 10); cout << "number 7 variant 2"<< endl;
 GotoXY(30, 12); cout << "created by Bidyak Mikhailo" << endl;
 GotoXY(37, 17); cout << "Kyiv 2016"<< endl;
 getch();
 system ("cls");
 return ;
 } // zastavka

const int n=4;// {кількість режимів}
typedef   char punkt[17] ;
          punkt q_name [n]={"1. Show 2D  ", "2. Show 3D ", "3. Exit "};
 short   i, j;


void d2 ()// {2D}
{	initgraph();
	system("cls");
	settextstyle(1, 0, 4);
	setcolor(7);
	setfillstyle(1, 7);

	for(int i=0; i<15; i++){
	arc(700+i, 220, 60, -90, 80);
	arc(700+i, 380, -160, 90, 70);}
	
	sleep(5);
	closegraph();
return;}

void d3 () //  {3D}
{	initgraph();
	system("cls");
	setcolor(8);
	setfillstyle(1, 8);
	
	for (int j =0; j<15; j++)
	for(int i=0; i<15; i++){
	arc(700+i+j, 220-j, 60, -90, 80);
	arc(700+j+i, 380-j, -160, 90, 70);	}
	
	setcolor(7);

	for(int i=0; i<15; i++){
	arc(700+i, 220, 60, -90, 80);
	arc(700+i, 380, -160, 90, 70);}
	
	sleep(5);
	closegraph(); 
return ;}


int main ()
{
	zastavka();
	while (true) {
	system("cls");
	GotoXY (24,4); //{початок заголовку}
	cout << "Main menu";
	for (j=0; j<4; j++)
	{ GotoXY (25, 7+j+1); cout <<q_name[j];  }
	GotoXY (20,15); cout << "Input number of regim and press Enter : ";
	cin >> i;
	switch (i)
	{case 1: d2(); break;
 	case 2: d3(); break;
 	case 3: return 0; 
 	default: {
			GotoXY(20,17);
			cout << " ERROR. Repeat";
    		Sleep(1000);
}
}// switch
}// {while}
return 0;}// {main}*/

/*#include <dos.h>
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
int main ()
{
int const N=500;
int r,dx,dy, p,Gx,Gy, gd,gm, x,y, x1,y1 ,i;
float k;
int 	Xd[N],Yd[N],  // ьрёёшт? ъююЁфшэрЄ юс·хъЄют
		vX[N],vY[N],   // ьрёёшт? ёъюЁюёЄхщ юс·хъЄют
				 m[N] ; // ЎтхЄ юс·хъЄют
				initgraph(&gd,&gm,"");
				Gx=getmaxx();
				Gy=getmaxy();
		srand (time(NULL));
//небо в алмазах - генератор точек с гашением в их окрестности набора точек}
outtext ("diamond sky");
getch();
cleardevice();
do {
	i=rand()%7+9;
	x=rand()%(Gx);
	y=rand()%(Gy);
	putpixel(x,y,i);
	for (i=0; i<=rand()%900;i++){ putpixel(x-15+rand()%(31),y-15+rand()%(31),0);}
}while (!kbhit());
getch();
cleardevice();
//"Мерцание" - последовательно высвечиваются и гасятся две случайные точки
//из-за инерционности зрения возникает эффект мерцающего набора точек}
outtext("blink sky");
getch();
cleardevice();
do{     i=rand()%+9;
				x1=x;  x=rand()%(Gx);
				y1=y;  y=rand()%(Gy);
				putpixel(x,y,i);
				delay(100);
				putpixel(x1,y1,0);
} while (!kbhit());
getch();
cleardevice();

//выводит небо в алмазах в прямоугольную область}
outtext("diamondsky - bar");
getch();
cleardevice();
Gx=getmaxx()-200;
Gy=getmaxy()-200;

do {
	i=rand()%+9;
	x=rand()%(Gx)+100;
	y=rand()%(Gy)+100;
	putpixel(x,y,i);
	for (i=0; i<=rand()%(9);i++)
						putpixel(x-15+rand()%(31),y-15+rand()%(31),0);
} while (!kbhit());
getch();
cleardevice();


//выводит небо в алмазах в triangle}
outtext ("diamond sky  - triangle");
getch();
cleardevice();
Gx=getmaxx();
Gy=getmaxy();
k=(1.0*Gy)/(1.0*Gx);
srand(time(NULL));
do {
	i=rand()%(7)+9;
	x=rand()%(Gx);
	y=rand()%(Gy);
	if (y <=(k*x))  putpixel(x,480-y+1,i);
	for (i=0; i<=rand()%(9);i++) putpixel(x-15+rand()%31,y-15+rand()%31,0);
} while (!kbhit());
getch();
cleardevice();

closegraph();
return 0;}*/


/*#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <ctime>*/

int main ()
{
int const N=5000;
int gx,gy,i,gd,gm;
int X1[N],Y1[N], X[N],Y[N],vX[N],vY[N];

initgraph(&gd,&gm,"");

gx=getmaxx();
gy=getmaxy();
srand (time (NULL));
for (i=0; i<N;i++)
{
 X[i]= 350 + (i%95); //початкові координати околків
 Y[i]= 340 +(i/25);
 putpixel(X[i],Y[i],15);
 vX[i]= -10+rand()%21; //складові швидкостей осколків
 vY[i]= -10+rand()%21;
}

for (i=0; i<N;i++)
{
 X1[i]= 1110 + (i%95); //початкові координати околків
 Y1[i]= 340 +(i/25);
 putpixel(X1[i],Y1[i],15);
 vX[i]= -10+rand()%21; //складові швидкостей осколків
 vY[i]= -10+rand()%21;
}


getch(); // по натисканню клавіші околки розлітаються в різні боки

//for (i=1; i<=299;i++)
//{sound(rand()%i); delay(1); nosound(); } //звук вибуху
/*
do
{   //процесс розльоту осколків

for (i=0; i<N; i++)
{
if ((X[i]+vX[i]> 0) &&( X[i]+vX[i]< gx) &&
(Y[i]+vY[i]> 0) &&( Y[i]+vY[i]<gy))
		//якщо осколок не долетів до краю
	{
	 putpixel(X[i],Y[i], 0);
	 X[i]+=vX[i];
	 Y[i]+=vY[i];
	 putpixel(X[i],Y[i],12);//перемал. в новому положенні 
	}
else // пиксель долетів до краю - обнуляємо його швидкість
	 // і генеруємо звук удару об край
	{	vX[i]=0;
		vY[i]=0;
	//	sound(200); 
	delay(0);// nosound();
	}
	}
}
while (!kbhit());

*/

do
{   //процесс розльоту осколків

for (i=0; i<N; i++)
{	
if ((X1[i]+vX[i]> 0) &&( X1[i]+vX[i]< gx) &&
(Y1[i]+vY[i]> 0) &&( Y1[i]+vY[i]<gy))
		//якщо осколок не долетів до краю
	{
	 putpixel(X1[i],Y1[i], 0);
	 X1[i]+=vX[i];
	 Y1[i]+=vY[i];
	 putpixel(X1[i],Y1[i],12);//перемал. в новому положенні 
	}
else // пиксель долетів до краю - обнуляємо його швидкість
	 // і генеруємо звук удару об край
	{	vX[i]=0;
		vY[i]=0;
	//	sound(200); 
	delay(0);// nosound();
	}
	
	
	if ((X[i]+vX[i]> 0) &&( X[i]+vX[i]< gx) &&
(Y[i]+vY[i]> 0) &&( Y[i]+vY[i]<gy))
		//якщо осколок не долетів до краю
	{
	 putpixel(X[i],Y[i], 0);
	 X[i]+=vX[i];
	 Y[i]+=vY[i];
	 putpixel(X[i],Y[i],12);//перемал. в новому положенні 
	}
else // пиксель долетів до краю - обнуляємо його швидкість
	 // і генеруємо звук удару об край
	{	vX[i]=0;
		vY[i]=0;
	//	sound(200); 
	delay(0);// nosound();
	}
	}
}
while (!kbhit());
closegraph;
return 0;}



/*#include <stdlib.h>
#include <graphics.h>;
#include <iostream>
#include <dos.h>
#include <math.h>
#include <conio.h>
#include <ctime>

int main ()
{
int const n=500; //количество объектов
int gx,gy, gm,gd,i,j;
double L;
short stop;// boolean  признак остановки процесса
long int	 r[n],dr[n], xc[n],yc[n]; //координаты центров объектов
short    good[n];//boolean; признак существования объектов
initgraph(&gm,&gd, "");
gx=getmaxx();
gy=getmaxy();
srand(time(NULL));
//установка начальных параметров объектов
for (i=0; i<n; i++)
{
	r[i]= 5+(rand()%10);   //радиус
	dr[i]= 1+(rand()%3);   //скорость роста
	xc[i]=r[i]+(rand()%(gx-2*r[i]));  //координаты центра
	yc[i]=r[i]+(rand()%(gy-2*r[i]));
	good[i]=1;   //признак существования объекта
}
stop=0; //признак остановки процесса

do
{
 for (i=0; i<n; i++)// перебор объектов
 if (good[i]==1)
	{

circle(xc[i],yc[i],r[i]);
 //выбор объектов
		for (j=0 ; j<n; j++) //анализ соседей j для выбранного объекта
		 if ((j!=i)&&(good[j]==1))
		 { //расстояние между центрами объектов
		 L=sqrt((xc[i]-xc[j])*(xc[i]-xc[j])+(yc[i]-yc[j])*(yc[i]-yc[j]));
		 // если проходит касание объекта "i" с объектом "j" большего радиуса, то рассматриваемый объект "i" уничтожается
		 if ((r[i]+r[j]+dr[i]+dr[j]>=L) && (r[j]>r[i]))
			{ //sound(100); 
			  delay(10); 
			//nosound();
				good[i]=0; break;  
			}
		 } //j
	//при достижении края растущий объект отодвигается от этого края
if (xc[i]-r[i]-dr[i]<= 0) xc[i]+=dr[i];
if(yc[i]-r[i]-dr[i]<= 0) yc[i]+=dr[i];
if(xc[i]+r[i]+dr[i]>=gx) xc[i]-=dr[i];
if(yc[i]+r[i]+dr[i]>=gy) yc[i]-=dr[i];
}//i
//увеличение размеров объектов с контролем максимального размера
for (i=0; i<n; i++)
 { 	 if (good[i]==1) r[i]+=dr[i];
	 if (2*r[i]>gy) stop=1;  }
 delay(100);
 cleardevice();
}
while ((stop==0) && (!kbhit())) ;
closegraph();
return 0;}*/

