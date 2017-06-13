// Dardos
#include <conio.h>
#include <iostream.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <process.h>
#include <alloc.h>

class dardos
{
	private:
	int oportunidad;

	public:
		void inicio()
		{
			int gdriver=DETECT, gmode, errorcode;
			initgraph (&gdriver, &gmode, "C:\\TURBOC3\\BGI");
			errorcode=graphresult();
			if(errorcode !=grOk)
			{
				cout<<"error de graficos"<<endl;
				getch();
				exit(1);
			}
		}

		void fondo()
		{
			setfillstyle(SOLID_FILL, BROWN);
			bar(0, 0, 640, 480);
		}

		void tablero()
		{
			setfillstyle(SOLID_FILL, BLACK);
			setcolor(BLACK);
			ellipse(320, 250, 0, 360, 200, 195);
			floodfill(320, 240, BLACK);

			setfillstyle(SOLID_FILL, DARKGRAY);
			setcolor(DARKGRAY);
			fillellipse(320, 240, 200, 200);

			setfillstyle(SOLID_FILL, RED);
			setcolor(RED);
			fillellipse(320, 240, 160, 160);

			setfillstyle(SOLID_FILL, BLACK);
			setcolor(BLACK);
			fillellipse(320, 240, 150, 150);

			setfillstyle(SOLID_FILL, RED);
			setcolor(RED);
			fillellipse(320, 240, 110, 110);

			setfillstyle(SOLID_FILL, BLACK);
			setcolor(BLACK);
			fillellipse(320, 240, 100, 100);

			struct arccoordstype infoarco[3];
			for(int i=0; i<20; i=i+2)
			{
				setcolor(WHITE);
				setfillstyle(SOLID_FILL, WHITE);
				arc(320, 240, 27+(i*18), 46+(i*18), 150);
				getarccoords(&infoarco[2]);
				line(320, 240, infoarco[2].xstart, infoarco[2].ystart);
				line(320, 240, infoarco[2].xend, infoarco[2].yend);
				line(infoarco[2].xstart, infoarco[2].ystart, infoarco[2].xend, infoarco[2].yend);
				floodfill( (320+infoarco[2].xstart+infoarco[2].xend)/3, (240+infoarco[2].ystart+infoarco[2].yend)/3, WHITE);

				setcolor(BLACK);
				setfillstyle(SOLID_FILL, BLACK);
				arc(320, 240, 27+(i*18), 46+(i*18), 160);
				getarccoords(&infoarco[0]);
				arc(320, 240, 27+(i*18), 46+(i*18), 150);
				getarccoords(&infoarco[1]);
				line(infoarco[0].xstart, infoarco[0].ystart, infoarco[1].xstart, infoarco[1].ystart);
				line(infoarco[0].xend, infoarco[0].yend, infoarco[1].xend, infoarco[1].yend);
				floodfill((infoarco[0].xstart+infoarco[1].xend)/2, (infoarco[0].ystart+infoarco[1].yend)/2, BLACK);

				arc(320, 240, 27+(i*18), 46+(i*18), 110);
				getarccoords(&infoarco[0]);
				arc(320, 240, 27+(i*18), 46+(i*18), 100);
				getarccoords(&infoarco[1]);
				line(infoarco[0].xstart, infoarco[0].ystart, infoarco[1].xstart, infoarco[1].ystart);
				line(infoarco[0].xend, infoarco[0].yend, infoarco[1].xend, infoarco[1].yend);
				floodfill((infoarco[0].xstart+infoarco[1].xend)/2, (infoarco[0].ystart+infoarco[1].yend)/2, BLACK);
			}

			setfillstyle(SOLID_FILL, BLACK);
			setcolor(BLACK);
			fillellipse(320, 240, 15, 15);

			setfillstyle(SOLID_FILL, RED);
			setcolor(RED);
			fillellipse(320, 240, 6, 6);

			setcolor(BLACK);
			rectangle(115, 35, 525, 450);

			setcolor(BLACK);
			settextstyle(DEFAULT_FONT, 0, 1);
			outtextxy(120, 10, "Pulsa la tecla [ESPACIO].");
		}

		void dibujar_barras()
		{
			setfillstyle(SOLID_FILL, BROWN);
			bar(120-5, 460, 520+5, 475);
			bar(90, 40-5, 105, 440+5);
			setfillstyle(SOLID_FILL, WHITE);
			bar(120-5, 465, 520+5, 470);
			bar(95, 40-5, 100, 440+5);

			barra_izquierda();
		}

		void barra_izquierda()
		{
			int tecla = 0, pos = 0, dir = 0;
			do
			{
				if(!kbhit())
				{
					if(pos >= 400 && dir == 0)
						dir = 1;
					else if(pos <= 0 && dir == 1)
						dir = 0;
					if(dir == 0)
						pos++;
					else if(dir == 1)
						pos--;
					setfillstyle(SOLID_FILL, BROWN);
					bar(90, 40-5+pos, 105, 45-5+pos);
					bar(90, 40+5+pos, 105, 45+5+pos);
					setfillstyle(SOLID_FILL, WHITE);
					bar(95, 40-5+pos, 100, 45-5+pos);
					bar(95, 40+5+pos, 100, 45+5+pos);
					setfillstyle(SOLID_FILL, CYAN);
					bar(90, 40+pos, 105, 45+pos);
					delay(1);
				}
				else
				{
					tecla = getch();
					if(tecla == 32)
						barra_abajo(pos+43);
				}
			}while(tecla != 32);
		}

		void barra_abajo(int posy)
		{
			int tecla = 0, pos = 0, dir = 0;
			do
			{
				if(!kbhit())
				{
					if(pos >= 390 && dir == 0)
						dir = 1;
					else if(pos <= 0 && dir == 1)
						dir = 0;
					if(dir == 0)
						pos++;
					else if(dir == 1)
						pos--;
					setfillstyle(SOLID_FILL, BROWN);
					bar(120-5+pos, 460, 125-5+pos, 475);
					bar(120+5+pos, 460, 125+5+pos, 475);
					setfillstyle(SOLID_FILL, WHITE);
					bar(120-5+pos, 465, 125-5+pos, 470);
					bar(120+5+pos, 465, 125+5+pos, 470);
					setfillstyle(SOLID_FILL, CYAN);
					bar(120+pos, 460, 125+pos, 475);
					delay(1);
				}
				else
				{
					tecla = getch();
					if(tecla == 32)
						pintar_tiro(pos+123, posy);
				}
			}while(tecla != 32);
		}

		void pintar_tiro(int posx, int posy)
		{
			int gano = 0;
			for(int i=0; i<6; i++)
				for(int j=0; j<360; j++)
				{
					struct arccoordstype infoarco;
					setcolor(RED);
					arc(320, 240, j, j+1, i);
					getarccoords(&infoarco);
					if(infoarco.xstart == posx && infoarco.ystart == posy)
						gano = 1;
				}
			setcolor(BLACK);
			setfillstyle(SOLID_FILL, CYAN);
			fillellipse(posx, posy, 5, 5);
			if(gano == 1)
				pantalla_ganador();
			else if(gano == 0 && oportunidad >= 5)
				pantalla_perdedor();
			oportunidad++;
			if(oportunidad < 5)
				dibujar_barras();
			else
				pantalla_perdedor();
		}

		void pantalla_ganador()
		{
			cleardevice();
			fondo();

			setcolor(RED);
			settextstyle(DEFAULT_FONT, 0, 11);
			outtextxy(125, 35, "­HAS");
			settextstyle(DEFAULT_FONT, 0, 10);
			outtextxy(50, 150, "GANADO!");
			setcolor(WHITE);
			settextstyle(DEFAULT_FONT, 0, 11);
			outtextxy(125, 30, "­HAS");
			settextstyle(DEFAULT_FONT, 0, 10);
			outtextxy(50, 155, "GANADO!");

			setcolor(BLACK);
			settextstyle(DEFAULT_FONT, 0, 1);
			outtextxy(10, 465, "Pulsa cualquier tecla para regresar al men£ principal.");

			sound(440);
			delay(400);
			nosound();
			delay(90);

			sound(493);
			delay(400);
			nosound();
			delay(90);

			sound(523);
			delay(400);
			nosound();
			delay(90);

			sound(466);
			delay(120);
			nosound();
			delay(90);

			sound(440);
			delay(200);
			nosound();
			delay(90);

			sound(440);
			delay(200);
			nosound();
			delay(90);


			sound(392);
			delay(200);
			nosound();
			delay(90);

			sound(392);
			delay(120);
			nosound();
			delay(90);

			sound(329);
			delay(600);
			nosound();
			delay(180);

			sound(329);
			delay(100);
			nosound();
			delay(60);

			sound(392);
			delay(75);
			nosound();
			delay(90);

			sound(440);
			delay(250);
			nosound();
			delay(90);

			sound(440);
			delay(50);
			nosound();
			delay(90);

			sound(440);
			delay(50);
			nosound();
			delay(90);

			sound(440);
			delay(50);
			nosound();
			delay(90);

			sound(440);
			delay(50);
			nosound();
			delay(90);

			sound(440);
			delay(200);
			nosound();
			delay(90);

			sound(440);
			delay(50);
			nosound();
			delay(90);

			sound(440);
			delay(150);
			nosound();
			delay(90);

			sound(440);
			delay(100);
			nosound();
			delay(90);

			sound(523);
			delay(300);
			nosound();
			delay(90);

			sound(440);
			delay(50);
			nosound();
			delay(90);

			sound(349);
			delay(100);
			nosound();
			delay(90);

			sound(392);
			delay(100);
			nosound();
			delay(90);

			sound(440);
			delay(800);
			nosound();
			delay(120);

			getch();

			pantalla_inicio();
		}

		void pantalla_perdedor()
		{
			cleardevice();
			fondo();

			setcolor(RED);
			settextstyle(DEFAULT_FONT, 0, 11);
			outtextxy(125, 35, "­HAS");
			settextstyle(DEFAULT_FONT, 0, 9);
			outtextxy(50, 150, "PERDIDO!");
			setcolor(WHITE);
			settextstyle(DEFAULT_FONT, 0, 11);
			outtextxy(125, 30, "­HAS");
			settextstyle(DEFAULT_FONT, 0, 9);
			outtextxy(50, 155, "PERDIDO!");

			setcolor(BLACK);
			settextstyle(DEFAULT_FONT, 0, 1);
			outtextxy(10, 465, "Pulsa cualquier tecla para regresar al men£ principal.");
			getch();

			pantalla_inicio();
		}

		void instrucciones()
		{
			cleardevice();
			fondo();

			setcolor(RED);
			settextstyle(DEFAULT_FONT, 0, 5);
			outtextxy(60, 35, "INSTRUCCIONES");
			setcolor(WHITE);
			settextstyle(DEFAULT_FONT, 0, 5);
			outtextxy(60, 30, "INSTRUCCIONES");

			setcolor(BLACK);
			settextstyle(DEFAULT_FONT, 0, 1);
			outtextxy(10, 100, "Para iniciar con el juego es necesario regresar al men£ principal pulsando");
			outtextxy(10, 110, "cualquier tecla. Posteriormente ingresar al boton de jugar a traves de la");
			outtextxy(10, 120, "tecla [ENTER].");

			outtextxy(10, 140, "El objetivo del juego es tirar el dardo al centro del tablero para ganar.");
			outtextxy(10, 150, "Existen dos barras alrededor del tablero, la primera del lado izquierda");
			outtextxy(10, 160, "determina la posici¢n vertical donde llegar  el dardo. Por ende, la barra");
			outtextxy(10, 170, "inferior, determina la posici¢n horizontal del dardo. Para determinar la");
			outtextxy(10, 180, "posicion donde se detendr  la barra de posicionamiento es necesario pulsar");
			outtextxy(10, 190, "la tecla [ESPACIO].");

			outtextxy(10, 210, "La £nica forma de ganar este juego es llegar a colocar el dardo dentro del");
			outtextxy(10, 220, "circulo central, de otra forma, perder s");

			setcolor(BLACK);
			outtextxy(10, 465, "Pulsa cualquier tecla para regresar al men£ principal.");

			getch();
			pantalla_inicio();
		}

		void pantalla_inicio()
		{
			cleardevice();
			fondo();
			oportunidad = 0;

			settextstyle(DEFAULT_FONT, 0, 12);
			setcolor(RED);
			outtextxy(50, 35, "DARDOS");
			setcolor(WHITE);
			outtextxy(50, 30, "DARDOS");

			setfillstyle(SOLID_FILL, DARKGRAY);
			bar(120, 200, 520, 300);
			setfillstyle(SOLID_FILL, RED);
			bar(120, 190, 520, 290);
			settextstyle(DEFAULT_FONT, 0, 10);
			outtextxy(125, 205, "JUGAR");

			setfillstyle(SOLID_FILL, DARKGRAY);
			bar(170, 330, 480, 380);
			setfillstyle(SOLID_FILL, LIGHTGRAY);
			bar(170, 320, 480, 370);
			settextstyle(DEFAULT_FONT, 0, 3);
			outtextxy(170, 335, "INSTRUCCIONES");

			setfillstyle(SOLID_FILL, DARKGRAY);
			bar(250, 400, 400, 450);
			setfillstyle(SOLID_FILL, LIGHTGRAY);
			bar(250, 390, 400, 440);
			settextstyle(DEFAULT_FONT, 0, 3);
			outtextxy(265, 405, "SALIR");

			int tecla = 0, opcion = 1;
			do
			{
				tecla = getch();
				if(tecla == 80 && opcion == 1)
				{
					setfillstyle(SOLID_FILL, DARKGRAY);
					bar(120, 200, 520, 300);
					setfillstyle(SOLID_FILL, LIGHTGRAY);
					bar(120, 190, 520, 290);
					settextstyle(DEFAULT_FONT, 0, 10);
					outtextxy(125, 205, "JUGAR");

					setfillstyle(SOLID_FILL, DARKGRAY);
					bar(170, 330, 480, 380);
					setfillstyle(SOLID_FILL, RED);
					bar(170, 320, 480, 370);
					settextstyle(DEFAULT_FONT, 0, 3);
					outtextxy(170, 335, "INSTRUCCIONES");

					setfillstyle(SOLID_FILL, DARKGRAY);
					bar(250, 400, 400, 450);
					setfillstyle(SOLID_FILL, LIGHTGRAY);
					bar(250, 390, 400, 440);
					settextstyle(DEFAULT_FONT, 0, 3);
					outtextxy(265, 405, "SALIR");

					opcion = 2;
				}
				else if(tecla == 72 && opcion == 2)
				{
					setfillstyle(SOLID_FILL, DARKGRAY);
					bar(120, 200, 520, 300);
					setfillstyle(SOLID_FILL, RED);
					bar(120, 190, 520, 290);
					settextstyle(DEFAULT_FONT, 0, 10);
					outtextxy(125, 205, "JUGAR");

					setfillstyle(SOLID_FILL, DARKGRAY);
					bar(170, 330, 480, 380);
					setfillstyle(SOLID_FILL, LIGHTGRAY);
					bar(170, 320, 480, 370);
					settextstyle(DEFAULT_FONT, 0, 3);
					outtextxy(170, 335, "INSTRUCCIONES");

					setfillstyle(SOLID_FILL, DARKGRAY);
					bar(250, 400, 400, 450);
					setfillstyle(SOLID_FILL, LIGHTGRAY);
					bar(250, 390, 400, 440);
					settextstyle(DEFAULT_FONT, 0, 3);
					outtextxy(265, 405, "SALIR");

					opcion = 1;
				}
				else if(tecla == 80 && opcion == 2)
				{
					setfillstyle(SOLID_FILL, DARKGRAY);
					bar(120, 200, 520, 300);
					setfillstyle(SOLID_FILL, LIGHTGRAY);
					bar(120, 190, 520, 290);
					settextstyle(DEFAULT_FONT, 0, 10);
					outtextxy(125, 205, "JUGAR");

					setfillstyle(SOLID_FILL, DARKGRAY);
					bar(170, 330, 480, 380);
					setfillstyle(SOLID_FILL, LIGHTGRAY);
					bar(170, 320, 480, 370);
					settextstyle(DEFAULT_FONT, 0, 3);
					outtextxy(170, 335, "INSTRUCCIONES");

					setfillstyle(SOLID_FILL, DARKGRAY);
					bar(250, 400, 400, 450);
					setfillstyle(SOLID_FILL, RED);
					bar(250, 390, 400, 440);
					settextstyle(DEFAULT_FONT, 0, 3);
					outtextxy(265, 405, "SALIR");

					opcion = 3;
				}
				else if(tecla == 72 && opcion == 3)
				{
					setfillstyle(SOLID_FILL, DARKGRAY);
					bar(120, 200, 520, 300);
					setfillstyle(SOLID_FILL, LIGHTGRAY);
					bar(120, 190, 520, 290);
					settextstyle(DEFAULT_FONT, 0, 10);
					outtextxy(125, 205, "JUGAR");

					setfillstyle(SOLID_FILL, DARKGRAY);
					bar(170, 330, 480, 380);
					setfillstyle(SOLID_FILL, RED);
					bar(170, 320, 480, 370);
					settextstyle(DEFAULT_FONT, 0, 3);
					outtextxy(170, 335, "INSTRUCCIONES");

					setfillstyle(SOLID_FILL, DARKGRAY);
					bar(250, 400, 400, 450);
					setfillstyle(SOLID_FILL, LIGHTGRAY);
					bar(250, 390, 400, 440);
					settextstyle(DEFAULT_FONT, 0, 3);
					outtextxy(265, 405, "SALIR");

					opcion = 2;
				}
			}while(tecla != 13);
			if(opcion == 1)
			{
				cleardevice();
				fondo();
				tablero();
				dibujar_barras();
			}
			else if(opcion == 2)
			{
				instrucciones();
			}
			else if(opcion == 3)
			{
				exit(1);
			}
		}
};

void main()
{
	dardos d;
	d.inicio();
	cleardevice();
	d.fondo();
	d.pantalla_inicio();
	getch();
}