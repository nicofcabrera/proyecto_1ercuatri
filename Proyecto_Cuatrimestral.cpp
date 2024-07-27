#include <iostream>
#include <conio.h>
#include <windows.h> // API consola windows.
#include <locale> //Libreria para acentos

using namespace std;

//Funcion para limpiar linea de terminal gracias a la biblioteca windows.h
void ClearLines(int numLines) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

    COORD cursorPos = csbi.dwCursorPosition;

    for (int i = 0; i < numLines; ++i) {
        cursorPos.Y--;
        SetConsoleCursorPosition(hConsole, cursorPos);

        DWORD charsWritten;
        FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X, cursorPos, &charsWritten);
        FillConsoleOutputAttribute(hConsole, csbi.wAttributes, csbi.dwSize.X, cursorPos, &charsWritten);
    }

    SetConsoleCursorPosition(hConsole, cursorPos);
}

int main () {
	
	//Funcion para acentos.
	setlocale(LC_ALL, "");
	
	 // Definir el array de cadenas
    string asciiArt[] = {
        "\nMMMMMMMMMWNK0OkkxxxxxxxxkOO0KNWMMMMMMMMM",
        "MMMMMMWX0OkxxxxxxxxxxxxxxxxxxxOKXWMMMMMM",
        "MMMMWKOxxxxxxxxxxxxxxxxxxxxxxxxxxOXWMMMM",
        "MMWXOxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxOXWMM",
        "MWKkxxxxxxxxxxxxk00OkkxxxxxxxxxxxxxxkKWM",
        "WKxxxxxxxxxxxxxxKWWKOkxxxxxxxxxxxxxxxxKW",
        "KkkOOOOOOOOkxxxOXWWX0OOOOOkxxxOOOOOOOO0X",
        "OOXWNNXXNNNNXOk0NWWNXXXNNNNKkOXWNNXXNNNW",
        "k0NWN0kkkOKNWX0KWWXOkkkOXWWXO0WWXOkkkOXW",
        "kKWWKkxxxx0NWXKNWN0xxxxkKWWKOXWWKxxxxxKN",
        "OXWN0xxxkOXWNKKNWXOxxxxONWN00NWNOxxxk0NW",
        "KNWWXKKXXNNX0OXWWKxxxxxKWWXOKWWNXKKXXNNN",
        "WWWXK00K00Okxk0K0OxxxxxOKKOOXWNXK00000OK",
        "MWN0xxxxxxxxxxxxxxxxxxxxxxx0NWNOxxxxxxON",
        "MWXkxxxxxxxxxxxxxxxxxxxxxxx0KK0kxxxxxONM",
        "MMN0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx0NMM",
        "MMMWXOxxxxxxxxxxxxxxxxxxxxxxxxxxxxOXWMMM",
        "MMMMMWX0kxxxxxxxxxxxxxxxxxxxxxxk0XWMMMMM",
        "MMMMMMMWNK0OkxxxxxxxxxxxxxxkO0XNWMMMMMMM",
        "MMMMMMMMMMWNX0OkkxxxxxxkkO0XWMMMMMMMMMMM"
    };
    
    string img_js[] = {
	"\nKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK",
	"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK",
	"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK",
	"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK",
	"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK",
	"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK",
	"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK",
	"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK",
	"KKKKKKKKKKKKKKKKKOkxxkOKKKK0kxddxO0KKKKK",
	"KKKKKKKKKKKKKKKK0l....oKK0d,.    .;o0KKK",
	"KKKKKKKKKKKKKKKK0:   .l00o.  .::'..cOKKK",
	"KKKKKKKKKKKKKKKK0:   .lK0:   :OKOkO0KKKK",
	"KKKKKKKKKKKKKKKK0:   .lKKd'   .;ldOKKKKK",
	"KKKKKKKKKKKKKKKK0:   .lKKKkc'.    .:x0KK",
	"KKKKKKKKKKKKKKKK0:   .lKKKKK0ko:'   'xKK",
	"KKKKKKKKKK0kox0KO;   .lK0xllk0KKk;  .l0K",
	"KKKKKKKKK0l. .,:,.   'xKd'  .,::,.  .xKK",
	"KKKKKKKKKKkc'.   ..:lx0K0x:'.    ..:x0KK",
	"KKKKKKKKKKKK0kxddxO0KKKKKKK0kxddxkO0KKKK",
	"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK"
	};
	
	string img_java[] = {
	"\nMMMMMMMMMMMMMMMMMMMMMMMWXNMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMX0XMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMWXO0WMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMWX0OOKWWWMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMWNKOOOKNNXNWWMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMNKkOKNNX0KXWMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMNOx0NWX0kONMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMXkONMWKkxkXMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMN0OXWMNKOxONMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMWKKNWMWN0x0WMMMMMMMMMMMMMM",
	"MMMMMMMMMWNNNWWWWNWMMWX0NMMMMMWNKKNMMMMM",
	"MMMMMMMMNOdxOKXXNNNNNNXXXXKKXWMW0dkNMMMM",
	"MMMMMMMMWNK0OO0000000000000KNWMW0okNMMMM",
	"MMMMMMMMMMXkxOKXXXXXXXXXK0KWMWX0OKNMMMMM",
	"MMMMMMMMMMWK0OOOOOOOOOOOO0KWWNNNWMMMMMMM",
	"MMMMMMMMWWWWXOOKXXXXXXXKXWMMMMMMMMMMMMMM",
	"MMMMWXOkKNWWXOkkxxxxkxkk0NMMMMWNWMMMMMMM",
	"MMMMWOooxO0KXXNNNXXNNXXNXXXK0000XWMMMMMM",
	"MMMMMWNXK0OOOOOO00000000OOOOOO0KXNWMMMMM",
	"MMMMMMMMMMWNXXKKKKK0000000000KXNWMMMMMMM"
	};
	
	string img_python[] = {
	"\nMMMMMMMMMWKkxdollccccccclox0NMMMMMMMMMMM",
	"MMMMMMMMWKooOK0occcccc::::::xNMMMMMMMMMM",
	"MMMMMMMMWOlo0X0dcccc:::::::;lKWMMMMMMMMM",
	"MMMMMMMMWOlllolcclc::::::::;c0MMMMMMMMMM",
	"MMWNXKKKK0kkkkkxkkdc:::::::;cKWWWWWWMMMM",
	"WKkollllcccccccc:c::::::;;;;c0NXNXXNNWMM",
	"0ocllcccccccccc:::::::;;;;;,c0NXXXXXXNWM",
	"dcllccccccc::::::::;;;;;;;;;oXNXXXXXXXNW",
	"lclccccccc::::::::::::::::lxKNXXXXXXXKXW",
	"ccccccccccoxO000000000000KXNXXXXXXXXKKXW",
	"dccc:::ckNNXXXNNXXXXXXXXXXXXXXXKKKKKKKNW",
	"Ol:c:::c0WXXXNXXXXXXXXXXXXXXKKKKKKKKKXWM",
	"N0oc:::cOWXXXXXXXXXXXXXXKXXKKKKKKKKKXWMM",
	"MWNXK00KNWXXXXXXKXXXNNNNNNNNNNNNNNWWWMMM",
	"MMMMMMMMMNXXXXXXKKKXXXKXXXKKXWMMMMMMMMMM",
	"MMMMMMMMWNXXXXXKKKKKKKKXNWXKKNMMMMMMMMMM",
	"MMMMMMMMMWNXKKKKKKKKKKKXNNXKXWMMMMMMMMMM",
	"MMMMMMMMMMWNNXXKKKKKKKKKKXNNWMMMMMMMMMMM",
	"MMMMMMMMMMMMMWWWNNNNNNNWWWMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMWWWWWWWWWWMMMMMMMMMMMMMMM"
	};
	
	string ganaste[] = {
	"\n #####     #    #     #    #     #####  ####### ###### # ###",
	"#     #   # #   ##    #   # #   #     #    #    #        ###",
	"#        #   #  # #   #  #   #  #          #    #        ###",
	"#  #### #     # #  #  # #     #  #####     #    #####     # ",
	"#     # ####### #   # # #######       #    #    #          ",
	"#     # #     # #    ## #     # #     #    #    #        ###",
	" #####  #     # #     # #     #  #####     #    #######  ###"
	};
	
	string quienSoy[] = {
		"\n #####  #     # ### ####### #     #     #####  ####### #     #  ##### ",
		"#     # #     #  #  #       ##    #    #     # #     #  #   #  #     #",
		"#     # #     #  #  #       # #   #    #       #     #   # #         #",
		"#     # #     #  #  #####   #  #  #     #####  #     #    #       ### ",
		"#   # # #     #  #  #       #   # #          # #     #    #       #   ",
		"#    #  #     #  #  #       #    ##    #     # #     #    #           ",
		" #### #  #####  ### ####### #     #     #####  #######    #       #   "
	};
	
	string graciasPorJugar[] = {
		"\n #####  ######     #     #####  ###    #     #####     ######  ####### ######           # #     #  #####     #    ######  ",
		"#     # #     #   # #   #     #  #    # #   #     #    #     # #     # #     #          # #     # #     #   # #   #     # ",
		"#       #     #  #   #  #        #   #   #  #          #     # #     # #     #          # #     # #        #   #  #     # ",
		"#  #### ######  #     # #        #  #     #  #####     ######  #     # ######           # #     # #  #### #     # ######  ",
		"#     # #   #   ####### #        #  #######       #    #       #     # #   #      #     # #     # #     # ####### #   #   ",
		"#     # #    #  #     # #     #  #  #     # #     #    #       #     # #    #     #     # #     # #     # #     # #    #  ",
		" #####  #     # #     #  #####  ### #     #  #####     #       ####### #     #     #####   #####   #####  #     # #     # "
	};
	
	string perdiste_asci[] = {
		"#     #    #    #######    #######    #    #       #          #    ######  #######    ### ",
		"#     #   # #        #     #         # #   #       #         # #   #     # #     #    ### ",
		"#     #  #   #      #      #        #   #  #       #        #   #  #     # #     #    ### ",
		"####### #     #    #       #####   #     # #       #       #     # #     # #     #     #  ",
		"#     # #######   #        #       ####### #       #       ####### #     # #     #        ",
		"#     # #     #  #         #       #     # #       #       #     # #     # #     #    ### ",
		"#     # #     # #######    #       #     # ####### ####### #     # ######  #######    ### "
	};
	
	
	int gracias = sizeof(graciasPorJugar) / sizeof(graciasPorJugar[0]);
	int perdiste = sizeof(perdiste_asci) / sizeof(perdiste_asci[0]);
	
	int nombreJuego = sizeof(quienSoy) / sizeof(quienSoy[0]);
	for (int i = 0; i < nombreJuego; ++i) {
    cout << quienSoy[i] << endl;
	}

	
	char nombre[10];
	cout<<"\nPara comenzar el juego por favor ingresa tu nombre: ";
	cin>>nombre;
	ClearLines(1);
	cout<<"Bienvenid@! "<<nombre<<endl;
	cout<<"------------------"<<endl;
	
	
	bool validador = false;
	int opcion_menu;
	cout<<"\nMenu Juego"<<endl;
	cout<<"1. Insturcciones"<<endl;
	cout<<"2. JUGAR"<<endl;
	cout<<"3. Salir"<<endl;
	cout<<"Por favor ingrese una opción del [1-3]: ";
	cin>>opcion_menu;
	
	do{
		ClearLines(5);
		
		switch(opcion_menu) {
	    case 1:
	    	ClearLines(100);
	    	cout<<"INSTRUCCIONES"<<endl;
	    	cout<<"1. Deberas adivinar la imagen presentada, eligiendo la opcion que creas correcta, si acertas sumas 1 punto."<<endl;
	    	cout<<"2. Ganaras el juego si logras realizar 4 aciertos con éxito. ¡Mucha suerte!"<<endl;
	    	cout<<"\n¿Estas preparado para JUGAR?"<<endl;
	    	cout<<"1. JUGAR"<<endl;
			cout<<"0. Salir del juego"<<endl;
			cout<<"\nElige la opción deseada: ";
	    	cin>>opcion_menu;
	    	if (opcion_menu == 1){
	    		opcion_menu = 2;
			} else if (opcion_menu == 0) {
				opcion_menu = 3;
			} else{
				opcion_menu = 9;
			}
	    	validador = true;
	    break;
	    case 2: 
	    	ClearLines(10);
	    	cout<<"¡A JUGAR!"<<endl;
	    	validador = false;
	    break;
	    case 3: 
	    	ClearLines(100);
			for (int i = 0; i < gracias; ++i) {
		    cout << graciasPorJugar[i] << endl;
			}
	    	return false;
	    break;
	    default: 
	    	ClearLines(20);
	    	cout<<"\nLa opción que elegiste no es correcta. Vuelve a intentarlo"<<endl;
	    	opcion_menu = 1;
	    	validador = true;
		}
	}while(validador);
		
		
//		########### COMIENZO DEL JUEGO ###############
	
	int contador_juego = 0;
	int opcion_juego_elegida = 0;
	
		//	***** Primera Imagen ********
		ClearLines(100);
    	int rows = sizeof(asciiArt) / sizeof(asciiArt[0]);
		for (int i = 0; i < rows; ++i) {
        cout << asciiArt[i] << endl;
    	}
    	
    	cout<<"\n¡Que LENGUAJE de PROGRAMACIÓN es?";
	    cout<<"\n1. JavaScript"<<endl;
		cout<<"2. C#"<<endl;
		cout<<"3. PHP"<<endl;
		cout<<"\nElija una opción del [1-3]: ";
		cin>>opcion_juego_elegida;
		
		if (opcion_juego_elegida == 3) {
			contador_juego++;
		} 
		
		//	***** Segunda Imagen ********
		ClearLines(100);
		int js = sizeof(img_js) / sizeof(img_js[0]);
		for (int i = 0; i < js; ++i) {
	        cout << img_js[i] << endl;
    	}
    	
    	cout<<"\n¡Que LENGUAJE de PROGRAMACIÓN es?";
    	cout<<"\n1. JavaScript"<<endl;
		cout<<"2. React"<<endl;
		cout<<"3. Typescript"<<endl;
		cout<<"\nElija una opción del [1-3]: ";
		cin>>opcion_juego_elegida;
		
		if (opcion_juego_elegida == 1) {
			contador_juego++;
		} 
		
		//	***** Tercera Imagen ********
		ClearLines(100);
		int java = sizeof(img_java) / sizeof(img_java[0]);
		for (int i = 0; i < java; ++i) {
	        cout << img_java[i] << endl;
    	}
    	
    	cout<<"\n¡Que LENGUAJE de PROGRAMACIÓN es?";
    	cout<<"\n1. JavaScript"<<endl;
		cout<<"2. Java"<<endl;
		cout<<"3. MScript"<<endl;
		cout<<"\nElija una opción del [1-3]: ";
		cin>>opcion_juego_elegida;
		
		if (opcion_juego_elegida == 2) {
			contador_juego++;
		} 
		
		//	***** Cuarta Imagen ********
        
        ClearLines(100);
		int python = sizeof(img_python)	/ sizeof(img_python[0]);
		for (int i = 0; i < python; ++i) {
	        cout << img_python[i] << endl;
    	}
    	
    	cout<<"\n¡Que LENGUAJE de PROGRAMACIÓN es?";
    	cout<<"\n1. Python"<<endl;
		cout<<"2. C++"<<endl;
		cout<<"3. COBOL"<<endl;
		cout<<"\nElija una opción del [1-3]: ";
		cin>>opcion_juego_elegida;
		
		if (opcion_juego_elegida == 1) {
			contador_juego++;
		} 
		
//		******** RESULTADO ***********
		
		ClearLines(100);
		cout<<"Tuviste "<<contador_juego<<" aciertos."<<endl;
		int win = sizeof(ganaste) / sizeof(ganaste[0]);
		
		if(contador_juego == 4){
			for (int i = 0; i < win; ++i) {
	        cout << ganaste[i] << endl;
    	}
			cout<<"\nFELICIDADES! Ganaste el JUEGO!"<<endl;
		}else{
			
			for (int i = 0; i < perdiste; ++i) {
			    cout << perdiste_asci[i] << endl;
			}
	
			cout<<"\nPerdiste, vuelve a intentarlo! ;)"<<endl;
		}
        

		

	
	getch();
	return 0;
}
