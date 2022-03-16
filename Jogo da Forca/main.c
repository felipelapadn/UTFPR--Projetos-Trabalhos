#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>

void palavra_secreta(int nivel, char* palavra){
    
		char palavras_nivel_um[4][7] = {"ANCIAO", "BAIO", "CAJOM", "ACORRO"};
    char palavras_nivel_dois[4][10] = {"ADENTADO", "DEFENSA", "HOMEZIAM", "CANDEAS"};
    char palavras_nivel_tres[3][15] = {"RESMUNGADOR ", "PARTIMENTO ", "MARAVILHADO "};
    
		srand(time(NULL));
		int index_palavra;
    
		switch(nivel){
      case 1:
      	index_palavra = rand() % 4;
        strcpy(palavra, palavras_nivel_um[index_palavra]);
        break;
      case 2:
      	index_palavra = rand() % 4;
        strcpy(palavra, palavras_nivel_dois[index_palavra]);
        break;
      case 3:
      	index_palavra = rand() % 3;
        strcpy(palavra, palavras_nivel_tres[index_palavra]);
        break;
  	}
}

void palavra_sem_letra(char* palavra, char* palavra_serceta_sem_letra){
		int cont, tamanho = strlen(palavra);
		for(cont=0; cont < tamanho; cont++){
			palavra_serceta_sem_letra[cont] = '_';
		}
}

void marcar_chute(char* chute, char* palavra, char* palavra_serceta_sem_letra, int *errou, bool *enforcou){
		int cont, cont2 = 0;
		
		for(cont = 0; cont < strlen(palavra); cont++){
			if(palavra[cont] == chute[0]){
				palavra_serceta_sem_letra[cont] = chute[0];
				cont2 += 1;
			}
		}
		if(cont2==0){
			*errou += 1;
			if(*errou == 7){
				*enforcou = true;
			}
		}
}

void mostrar_letras_chutadas(char* letras_chutadas){
	int cont;
	printf("\n\nLetra(s) Chutada(s): ");
	for(cont = 0; cont < strlen(letras_chutadas); cont++){
		printf("%c ", letras_chutadas[cont]);
	}
}
 
void mostrar_palavra(char* palavra_serceta_sem_letra){
	int cont, tamanho = strlen(palavra_serceta_sem_letra);
	printf("\n");
	for(cont = 0; cont < tamanho-1; cont++){
		if(palavra_serceta_sem_letra[cont] != '_')
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		if(palavra_serceta_sem_letra[cont] != 'ÿ')
			printf("%c ", palavra_serceta_sem_letra[cont]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}

void verificar_acertou(bool *acertou, char* palavra_serceta_sem_letra){
	int cont, cont_acertos = 0, tamanho = strlen(palavra_serceta_sem_letra);
	for(cont = 0; cont < tamanho-1; cont++){
		if(palavra_serceta_sem_letra[cont] == '_'){
			*acertou = false;
			break;
		}
		else{
			*acertou = true;
			}
		}
}

void mostrar_forca(int errou){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		if(errou  == 0){
    	printf("\n  _______   \n");
			printf(" |/      |    \n");
      printf(" |            \n");
      printf(" |            \n");
      printf(" |            \n");
      printf(" |            \n");
      printf(" |            \n");
    	printf("_|___         \n");
  	}
    if(errou  == 1){
    	printf("\n  _______     \n");
			printf(" |/      |    \n");
      printf(" |");
      Beep(100, 200);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
      printf("      (_)   \n");
      Beep(100, 200);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |            \n");
      printf(" |            \n");
      printf(" |            \n");
      printf(" |            \n");
    	printf("_|___         \n");
  	}

    if(errou == 2){
    	printf("\n  _______     \n");
    	printf(" |/      |    \n");
			printf(" |");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("      (_)   \n");
			Beep(100, 200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("      /     \n");
			Beep(100, 200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |            \n");
      printf(" |            \n");
      printf(" |            \n");
    	printf("_|___         \n");
		}

    if(errou == 3){
    	printf("\n  _______     \n");
    	printf(" |/      |    \n");
      printf(" |");
      Beep(100, 200);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("      (_)   \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
      Beep(100, 200);
			printf("      /|    \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |            \n");
      printf(" |            \n");
      printf(" |            \n");
    	printf("_|___         \n");
		}
		
    if(errou  == 4){
    	printf("\n  _______     \n");
    	printf(" |/      |    \n");
      printf(" |");
      Beep(100, 200);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("      (_)/  \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
      Beep(100, 200);
			printf("      /|    \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |            \n");
      printf(" |            \n");
      printf(" |            \n");
    	printf("_|___         \n");
		}
		
    if(errou  == 5){
    	printf("\n  _______     \n");
    	printf(" |/      |    \n");
      printf(" |");
      Beep(100, 200);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("      (_)/  \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("      /|    \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |");
      Beep(100, 200);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("       |    \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |            \n");
      printf(" |            \n");
    	printf("_|___         \n");
		}
		
    if(errou  == 6){
    	printf("\n  _______     \n");
    	printf(" |/      |    \n");
      printf(" |");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("      (_)/  \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("      /|    \n");
			Beep(100, 200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("       |    \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |");
      Beep(100, 200);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("      /     \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |            \n");
    	printf("_|___         \n");
		}
		
    if (errou == 7){
    	printf("\n  _______     \n");
    	printf(" |/      |    \n");
      printf(" |");
      Beep(100, 200);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("      (_)/  \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("      /|    \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("       |    \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("      / /    \n");
			Beep(100, 200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
      printf(" |            \n");
    	printf("_|___         \n");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void mensagem_vencedor(){
		sleep(2);
		system("cls");
		sleep(1);
    printf("\n");
		printf("O REI FOI SALVO! O reino sempre esteve em boas mãos e continuou por mais 50 anos.\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf("       ___________      \n");
    printf("      '._==_==_=_.'     \n");
    printf("      .-XX:      /-.    \n");
    printf("     | (|:.     |) |    \n");
    printf("      '-|:.     |-'     \n");
    printf("        XX::.    /      \n");
    printf("         '::. .'        \n");
    printf("           ) (          \n");
    printf("         _.' '._       \n");
    printf("        '-------'       \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void mensagem_perdedor(){
		Beep(1500, 3000);
		sleep(2);
		system("cls");
		sleep(1);
		printf("\n");
    printf("O reino acabou nas mãos dos ladrões.\n",
					"Apesar do reino ter sobrevivido por um pouco mais de 5 anos, acabou caindo devido a má administração.\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("    _______________         \n");
    printf("   x               x       \n");
    printf("  x                 x      \n");
    printf(" x                   x  \n");
    printf(" x   XXXX     XXXX   |   \n");
    printf(" x   XXXX     XXXX   |     \n");
    printf(" x   XXX       XXX   |      \n");
    printf(" x                   |      \n");
    printf(" x__      XXX      __x     \n");
    printf("   |x     XXX     x|       \n");
    printf("   | |           | |        \n");
    printf("   | I I I I I I I |        \n");
    printf("   |  I I I I I I  |        \n");
    printf("   x_             _x       \n");
    printf("     x_         _x         \n");
    printf("       x_______x           \n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void dicas(int *dica, char* palavra, char* palavra_serceta_sem_letra){
	int cont, tamanho = strlen(palavra_serceta_sem_letra);
	if(*dica >= 1){
		for(cont = 0; cont < tamanho; cont++){
			if(palavra_serceta_sem_letra[cont] == '_'){
				printf("\nA palavra secreta tem a letra %c\n", palavra[cont]);
				break;
			}
		}
	}
	*dica -= 1;
}

void chute_upper(char* chute){
	if(chute[0] >= 'a' && chute[0] <= 'z') {
         chute[0] = chute[0] - 32;
      }
}

void cabecalho(int errou, char* palavra_serceta_sem_letra, char* letras_chutadas, int nivel){
	printf("\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
	printf("                    Nível %d", nivel);
	printf("\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
	mostrar_forca(errou);
	mostrar_palavra(palavra_serceta_sem_letra);
	mostrar_letras_chutadas(letras_chutadas);
}

void destacar_palavra(char palavra_da_historia[], int cor){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
	printf("%s", palavra_da_historia);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

int main() {
		
		SetConsoleTitle("Salve o Rei da forca!"); //Título do console
    setlocale(LC_ALL, "Portuguese");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		
		//Declaração de variáveis
    char palavra[18], palavra_serceta_sem_letra[18], letras_chutadas[24] = "";
    int nivel, errou = 0, dica = 5;
    bool enforcou = false, acertou = false;
    
    printf("Preste atenção na história, pois haverá palavras destacadas (cada cor representa um nível diferente) e que poderão\nser a palavra secreta.");
		printf("\nPalavras da cor ");
		destacar_palavra("CIANO", 11);
		printf(": nível 1\nPalavras da cor ");
		destacar_palavra("AMARELA", 14);
		printf(": nível 2\nPalavras da cor ");
		destacar_palavra("VERDE", 10);
		printf(": nível 3\n\n");
		
		printf("\n-= Para pessoas com daltonismo: preste atenção nos símbolos =-");
		printf("\nPalavras com Ð: nível 1");
		printf("\nPalavras com §: nível 2");
		printf("\nPalavras com ¶: nível 3\n\n");
		
		system("pause");
		system("cls");
						
    {//Introdução
    printf("Em um reino muito distante havia um Rei com um passado obscuro.\n");
    sleep(4);
    
    printf("As pessoas que tanto adoravam ele nunca pensariam que, no passado, vivia ");
		printf("com ladrões e conseguiu tomar o poder depois de armar um golpe para a realeza anterior. ");
		printf("Entretanto, os dias de glória desse tal Rei acabaram.\n");
		sleep(4);
		
		printf("Os ladrões vieram buscar a parte do reino que lhes pertence.\n");
		sleep(4);
		system("cls");
		
		printf("(GUARDA) Majestade! O ");
		destacar_palavra("anciao ( Ð )", 11);
		printf(" disse que alguns ladrões estão na porta do castelo e eles\ngostariam de falar com o senhor. ");
		sleep(4);
		
		printf("Vieram em um ");
		destacar_palavra("baio ( Ð )", 11);
		printf(" e dizem que são amigos seus de tempos distantes.\n");
		sleep(4);
		
		printf("\n(REI) Avise os cavaleiros de ");
		destacar_palavra("defensa ( § )", 14);
		printf(" e, se entrarem, podem matar, devem estar bêbados.\n");
		sleep(4);
		
		system("cls");
		printf("Neste momento, os ladrões entram na sala.\n");
		system("cls");
		
		printf("\n(LADRÃO 1) Engano nenhum ");
		destacar_palavra("adentado ( § )", 14);
		printf("! Viemos buscar a nossa parte do reino. ");
		sleep(3);
		
		printf("Aquela parte que vossa majestade prometeu antes de tomar o trono.\n");
		sleep(4);
		
		printf("\n(REI) ");
		destacar_palavra("CAJOM ( Ð )", 11);
		printf("! Guradas, por obséquio, tirem esses dois de minha sala.\n");
		sleep(5);
		
		printf("\n(LADRÃO 1) Se eles encostarem um dedo em nossas roupas, falaremos tudo.\n");
		sleep(5);
		
		printf("\n(REI) Guardas, parem.\n");
		sleep(3);
		system("cls");
		
		printf("Os guardas pararam no mesmo instante. Houve um pequeno ");
		destacar_palavra("partimento ( ¶ )", 10);
		printf(", mas acabou rápido.\n");
		sleep(7);
		system("cls");
		
		printf("\n(LADRÃO 1): Não seja um ");
		destacar_palavra("resmungador ( ¶ )", 10);
		printf(".\n\n(REI) O que os senhores querem?\n");
		printf("\n(LADRÃO 1) Queremos fazer um joguinho. Um jogo de forca. ");
		printf("Se... bem vejamos... aquele guarda ali não acertar as palavras ");
		printf("secretas, bem, você morre. E o seu reino será nosso.\n");
		printf("\n(REI) Seu ");
		destacar_palavra("homeziam ( § )", 14);
		printf("! E se ele acertar?\n");
		sleep(12);
		
		printf("\n(LADRÃO 2) Iremos embora com algum ouro e sem derramar sangue, caso não queira jogar, "); 
		printf("nos dê a parte que merecemos. \nEntão?\n");
		sleep(10);
		system("cls");
		
		printf("O Rei olhou para o guarda e para os ladrões.\n");
		sleep(5);
		
		printf("\n(REI) Negócio fechado. Me coloquem na forca.\n");
		printf("\n(LADRÃO 2): ");
		destacar_palavra("Maravilhado ( ¶ )", 10);
		printf("! Acendemos as ");
		destacar_palavra("candeas ( § )", 14); 
		printf(" caso morra.\n");
		sleep(12);
		system("cls");
		
		printf("Enquanto o Rei caminhava para a forca, todos no caminho olhavam, perguntavam  o que estava");
		printf("acontecendo e até \npediam ");
		destacar_palavra("acorro ( Ð )", 11);
		printf(". Mas as dúvidas logo acabaram, pois os ladrões explicaram a história.\n");
		printf("O Rei olha para você.\n");
		sleep(8);
		
		printf("\n(REI) Tenha bondade e seja competente. Não me mate. Eu confio em você.\n");
		sleep(4);
		system("cls");}
		
		sleep(1);
    
		//1
		nivel = 1;
    while(nivel == 1){
    	
			palavra_secreta(nivel, palavra);
	    palavra_sem_letra(palavra, palavra_serceta_sem_letra);
			
			printf("\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
	    printf("                    Nível 1");
	    printf("\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
	    
			while(enforcou == false && acertou == false){
	    	char chute[2];
	    	
				printf("\nChute uma letra: ");
	    	scanf("%s", &chute[0]);
	    	chute_upper(chute);
	    	system("cls");
				
	  		if(chute[0] == '1'){
	  			cabecalho(errou, palavra_serceta_sem_letra, letras_chutadas, nivel);
	  			dicas(&dica, palavra, palavra_serceta_sem_letra);
	  		}
	    	else if(isalpha(chute[0])){
	    		marcar_chute(chute, palavra, palavra_serceta_sem_letra, &errou, &enforcou);
					verificar_acertou(&acertou, palavra_serceta_sem_letra);
					strcat(letras_chutadas, chute);
					cabecalho(errou, palavra_serceta_sem_letra, letras_chutadas, nivel);
				}
				else
					cabecalho(errou, palavra_serceta_sem_letra, letras_chutadas, nivel);
				printf("\nDigite 1 para pedir uma dica.\nQuantidade de dicas restante: %d\n", dica);
			}
			
			if(acertou == true)
					nivel += 1;
			else
				break;
		}
		
		//2
		if(nivel == 2){
			sleep(1);
			printf("Próximo nível...");
			sleep(1);
			system("cls");
			letras_chutadas[0] = '\0';
			errou = 0;
	    enforcou = false;
			acertou = false;
			
	    while(nivel == 2){
	    	
				palavra_secreta(nivel, palavra);
		    palavra_sem_letra(palavra, palavra_serceta_sem_letra);
				
				printf("\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
		    printf("                    Nível 2");
		    printf("\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
		    
				while(enforcou == false && acertou == false){
		    	char chute[2];
		    	
					printf("\nChute uma letra: ");
		    	scanf("%s", &chute[0]);
		    	chute_upper(chute);
		    	system("cls");
					
		  		if(chute[0] == '1'){
		  			cabecalho(errou, palavra_serceta_sem_letra, letras_chutadas, nivel);
		  			dicas(&dica, palavra, palavra_serceta_sem_letra);
		  		}
		    	else if(isalpha(chute[0])){
		    		marcar_chute(chute, palavra, palavra_serceta_sem_letra, &errou, &enforcou);
						verificar_acertou(&acertou, palavra_serceta_sem_letra);
						strcat(letras_chutadas, chute);
						cabecalho(errou, palavra_serceta_sem_letra, letras_chutadas, nivel);
					}
					else
						cabecalho(errou, palavra_serceta_sem_letra, letras_chutadas, nivel);
					printf("\nDigite 1 para pedir uma dica.\nQuantidade de dicas restante: %d\n", dica);
				}
				
				if(acertou == true)
						nivel += 1;
				else
					break;
			}
		}
		
		//3
		if(nivel == 3){
			sleep(1);
			printf("Próximo nível...");
			sleep(1);
			system("cls");
			letras_chutadas[0] = '\0';
			errou = 0;
	    enforcou = false;
			acertou = false;
			
	    while(nivel == 3){
	    	
				palavra_secreta(nivel, palavra);
		    palavra_sem_letra(palavra, palavra_serceta_sem_letra);
				
				printf("\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
		    printf("                    Nível 3");
		    printf("\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
		    
				while(enforcou == false && acertou == false){
		    	char chute[2];
		    	
					printf("\nChute uma letra: ");
		    	scanf("%s", &chute[0]);
		    	chute_upper(chute);
		    	system("cls");
					
		  		if(chute[0] == '1'){
		  			cabecalho(errou, palavra_serceta_sem_letra, letras_chutadas,nivel);
		  			dicas(&dica, palavra, palavra_serceta_sem_letra);
		  		}
		    	else if(isalpha(chute[0])){
		    		marcar_chute(chute, palavra, palavra_serceta_sem_letra, &errou, &enforcou);
						verificar_acertou(&acertou, palavra_serceta_sem_letra);
						strcat(letras_chutadas, chute);
						cabecalho(errou, palavra_serceta_sem_letra, letras_chutadas, nivel);
					}
					else
						cabecalho(errou, palavra_serceta_sem_letra, letras_chutadas, nivel);
					printf("\nDigite 1 para pedir uma dica.\nQuantidade de dicas restante: %d\n", dica);
				}
				
				if(acertou == true)
						nivel += 1;
				else
					break;
			}
		}
		
		if(acertou == true)
			mensagem_vencedor();
		else{
			printf("\n\nA palavra secreta era %s\n", palavra);
			mensagem_perdedor();
		}
		return 0;
}
