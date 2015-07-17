#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int todayDate() {
   char* dS[7] = {"Domingo","Lunes","Martes","Miercoles",
                  "Jueves","Viernes","Sabado"};
   time_t tSac = time(NULL);       // instante actual
   struct tm* tmP = localtime(&tSac);
   system("cls");
   cout << dS[tmP->tm_wday] << ", "<< tmP->tm_mday << "-" << tmP->tm_mon+1 << "-"
                          << tmP->tm_year+1900 << "\n\n"; //Dia de la semana, dia del mes, mes, años
   return 0;
}

int main() {
   todayDate();
   int answer, day, month, year;
   char nameEvent[256], description[999];
   string nameFile, nameFile2,nameFile3, contentFile;
   stringstream concatenating1, concatenating2, concatenating3, concatenating4;

   cout << "Hola, bienvenido a la agenda.\n\nOpciones:\nSi quieres salir introduce: 0";
   cout << "\nSi quieres consultar eventos introduce: 1";
   cout << "\nSi quieres quieres crear un nuevo evento introduce: 2";
   cout << "\nSi quieres borrar un evento introduce: 3" << "\nRespuesta: ";
   cin >> answer;
   todayDate();
   //SALIR DEL PROGRAMA
   if(answer == 0){
        cout << "Presiona cualquier tecla para salir.\n\n";
   }
   //CONSULTAR UN EVENTO
   while(answer == 1){
		todayDate();
		cout << "Que dia quieres consultar?\nRespuesta: ";
		cin >> day;
		while(day > 31){
			cout << "\nDia incorrecto.\nVuelva a ingresar el Dia:";
			cin >> day;
		}
		cout << "Que mes quieres consultar? (1-12)\nRespuesta: ";
		cin >> month;
		while(month > 12 || month <= 0){
			cout << "\nMes incorrecto.\nVuelva a ingresar el Mes:";	
			cin >> month;
		}
		cout << "Que year quieres consultar?\nRespuesta: ";
		cin >> year;
		while(sizeof(year) > 5 || sizeof(year) < 4 || year < 2015){
			cout << "\nYear incorrecto.\nVuelva a ingresar el Year:";
			cin >> year;
		}
		
		cout << "Como se llama el evento?\nRespuesta: ";
        cin.ignore();
        cin.getline(nameEvent,sizeof(nameEvent));
        if(sizeof(nameEvent) < sizeof(nameEvent)-4){
            cout << "Vuelve a ingresar: (maximo " << sizeof(nameEvent)-4 << " caracteres):";
            cin.getline(nameEvent,sizeof(nameEvent));
        }

		concatenating3 << day << "-" << month << "-" << year << "-" << nameEvent << ".txt";
		nameFile2 = concatenating3.str();	
		ifstream file (nameFile2.c_str());
		if(!file){
			cout << "Este evento no existe, vuelve a intentarlo";
		} 
		else {
			string descriptionOfEvent;
			if (file.good()){
				getline(file, descriptionOfEvent);
				cout << descriptionOfEvent << endl;
			}
			todayDate();
			cout << "Informacion del evento:\nDia: " << day;
			cout << "\nMes: " << month;
			cout << "\nYear: " << year;
			cout << "\nTitulo: " << nameEvent;
			cout << "\nDescripcion: " << descriptionOfEvent;
		}
		cin.get();
		main();
   }
   //CREAR UN NUEVO EVENTO
   while(answer == 2){
        todayDate();
        cout << "Para que dia quieres crear el evento?\nRespuesta: ";
        cin >> day;
        while(day > 31){
            cout << "\nDia incorrecto.\nVuelva a ingresar el Dia:";
            cin >> day;
        }
        cout << "Para que mes quieres crear el evento? (1-12)\nRespuesta: ";
        cin >> month;
        while(month > 12 || month <= 0){
            cout << "\nMes incorrecto.\nVuelva a ingresar el Mes:";	
            cin >> month;
        }
        cout << "Para que year quieres crear el evento?\nRespuesta: ";
        cin >> year;
        while(sizeof(year) > 5 || sizeof(year) < 4 || year < 2015){
            cout << "\nYear incorrecto.\nVuelva a ingresar el Year:";
            cin >> year;
        }

		cout << "Como quieres llamar al nuevo evento?\nNota: Si ya existe se sobreescribira.\nRespuesta: ";
        cin.ignore();
        cin.getline(nameEvent,sizeof(nameEvent));
        if(sizeof(nameEvent) < sizeof(nameEvent)-4){
            cout << "Vuelve a ingresar: (maximo " << sizeof(nameEvent)-4 << " caracteres):";
            cin.getline(nameEvent,sizeof(nameEvent));
        }

        cout << "Cual es la descripcion del evento?\nRespuesta: ";
        cin.getline(description,sizeof(description));
        if(sizeof(description) < sizeof(999)){
            cout << "Vuelve a ingresar: (maximo " << sizeof(nameEvent) + 1 << " caracteres):";
            cin.getline(description,sizeof(description));
        }

        todayDate();
        cout << "El evento sera creado para la fecha: " << day << "-" << month << "-" << year;
        cout << "\nCon el asunto: " << nameEvent;
        cout << "\nCon la descripcion: "<< description;
        concatenating1 << day << "-" << month << "-" << year << "-" << nameEvent << ".txt";
        nameFile = concatenating1.str();
        ofstream fichero(nameFile.c_str());
		concatenating2 << description;
        contentFile = concatenating2.str();
        fichero << contentFile << endl;
        fichero.close();
		cin.get();
		main();
   }
   //BORRAR EVENTO
   while(answer == 3){
		todayDate();
		cout << "Para cual dia fue creado el evento?\nRespuesta: ";
		cin >> day;
		while(day > 31){
			cout << "\nDia incorrecto.\nVuelva a ingresar el Dia:";
			cin >> day;
		}
		cout << "Para cual mes fue creado el evento? (1-12)\nRespuesta: ";
		cin >> month;
		while(month > 12 || month <= 0){
			cout << "\nMes incorrecto.\nVuelva a ingresar el Mes:";	
			cin >> month;
		}
		cout << "Para que year fue creado el evento?\nRespuesta: ";
		cin >> year;
		while(sizeof(year) > 5 || sizeof(year) < 4 || year < 2015){
			cout << "\nYear incorrecto.\nVuelva a ingresar el Year:";
			cin >> year;
		}
		
		cout << "Como se llama el evento?\nRespuesta: ";
        cin.ignore();
        cin.getline(nameEvent,sizeof(nameEvent));
        if(sizeof(nameEvent) < sizeof(nameEvent)-4){
            cout << "Vuelve a ingresar: (maximo " << sizeof(nameEvent)-4 << " caracteres):";c
            cin.getline(nameEvent,sizeof(nameEvent));
        }
		concatenating4 << day << "-" << month << "-" << year << "-" << nameEvent << ".txt";
		nameFile3 = concatenating4.str();
		if( remove(nameFile3.c_str()) != 0 ){
			perror( "Error borrando el evento, prueba de nuevo" );
		}
		else{
			puts( "El evento ha sido borrado exitosamente" );
		}
		cin.get();
	   main();
   }
   //NUMERO INCORRECTO
   while(answer > 3 || answer < 0) {
		main();
   }
   return 0;
}
