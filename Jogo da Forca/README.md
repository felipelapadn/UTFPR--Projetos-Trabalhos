# Informações
A proposta final da disciplina de Linguagem de programação estruturada foi fazer um jogo ou um sistema. A minha ideia foi recriar o Jogo da Forca. O projeto poderia ser feito em grupo ou individualmente, escolhi fazer sozinho por ser um projeto simples.

# Desenvolvimento do jogo
Primeiramente, foi feito um esquema do jogo e da história com fluxogramas. A história do jogo foi uma parte interessante de fazer, já que o tema que selecionei foi desafiador. O tema era, justamente, a época medieval, logo, as palavras que o jogador deveria acertar precisavam estar de acordo com esse clima e dentro da história. Porcurei palavras que faziam parte de cantigas medievais e, com base nessas palavras, criei a história. Para facilitar os acertos, destquei as palavras que poderiam ser sorteadas para a forca com uma função de colorir.

- Função para destacar palavras:
```
void destacar_palavra(char palavra_da_historia[], int cor){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
	printf("%s", palavra_da_historia);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

	printf("Preste atenção na história, pois haverá palavras destacadas (cada cor representa um nível diferente) e que poderão\nser a palavra secreta.");
	printf("\nPalavras da cor ");
	destacar_palavra("CIANO", 11);
	printf(": nível 1\nPalavras da cor ");
	destacar_palavra("AMARELA", 14);
	printf(": nível 2\nPalavras da cor ");
	destacar_palavra("VERDE", 10);
	printf(": nível 3\n\n");
```

Com base nos fluxogramas criados, fiz o esqueleto do jogo da maneira mais simples possível e com apenas um nível. A estrutura principal foi feita com loops **WHILE** e com algumas condições para verificar se o jogador acertou a palavra ou não. Depois de conseguir criar uma base, comecei a adicionar funções e mais detalhes ao jogo. De todas as funções, três se destacam:

- Função para sortear a palavra secreta:
```
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
```

- Função para marcar o chute do jogador:
```
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
```
- Função para gerar uma dica:
```
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
```

E depois de criar a estrutura completa para o primeiro nível, repliquei para os dois seguintes.

### Dificuldades
Houve algumas complicações durante o projeto, por conta de ser o primeiro contato com a linguagem C. O jogo é baseado em **STRING**, então manipulação de caracteres foi um assunto que precisava ser entendido e aplicado com muito cuidado. Em muitos momentos do desenvolvimento, os **PRINTFs** saiam com resultados absurdso ou as variáveis, simplesmente, não retornavam valores. Depois de muito estudar as bibliotecas __string.h__ e __ctype.h__, consegui conduzir o projeto até a sua conclusão sem muitos desvios.

# Observações adicionais
- Refrência para as cantigas:
Lopes, Graça Videira; Ferreira, Manuel Pedro et al. (2011-), Cantigas Medievais Galego Portuguesas [base de dados online]. Lisboa: 	Instituto de Estudos Medievais, FCSH/NOVA. [Consulta em (indicar data da consulta)] Disponível em: <http://cantigas.fcsh.unl.pt>. Acesso em: 28 de nov. 2021.

O trabalho feito possui, somente, fins didáticos. Caso haja alguma irregularidade entre em contato.
