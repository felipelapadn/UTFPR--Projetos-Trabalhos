# Informações
A proposta final da disciplina de Linguagem de programação estruturada foi fazer um jogo ou um sistema. A minha ideia foi recriar o jogo da Forca. O projeto poderia ser feito em grupo ou individualmente, escolhi fazer sozinho por ser um projeto simples.

# Desenvolvimento do jogo
Primeiramente, foi feito um esquema do jogo e da história com fluxogramas. A história do jogo foi uma parte interessante de fazer, já que o tema que selecionei foi desafiador. O tema era, justamente, a época medieval, logo, as palavras que o jogador deveria acertar precisavam estar de acordo com esse clima e dentro da história. Porcurei palavras que faziam parte de cantigas medievais e, com base nessas palavras, criei a história. Para facilitar os caertos, destquei as palavras que poderiam ser sorteadas para a forca com uma função de colorir.

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

Com base nos fluxogramas criados, fiz o esqueleto do jogo da maneira mais simples possível e com apenas um nível. A estrutura principal foi feita com loops WHILE e com algumas condições para verificar se o jogador acertou a palavra ou não. Depois de conseguir criar uma base, comecei a adicionar funções e mais detalhes ao jogo. De todas sas funções, três se destacam:

