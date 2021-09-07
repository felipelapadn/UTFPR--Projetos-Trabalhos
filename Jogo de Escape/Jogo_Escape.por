programa
{
	inclua biblioteca Sons --> s
     inclua biblioteca Util --> u
	inclua biblioteca Tipos --> tp

	funcao mostrar_opcoes(cadeia esc_do_user_1, cadeia esc_do_user_2)
	{
		escreva("\n[1] - ", esc_do_user_1)
		escreva("\n[2] - ", esc_do_user_2)
		escreva("\nEscolha: ")
	}

	funcao som_ambiente()
	{	
		inteiro carrega = s.carregar_som("MistyEffect.mp3")
		
		s.reproduzir_som(carrega, verdadeiro)
		s.definir_volume(80)
	}

	funcao escreve_matrizPontuacao (real oxigenio, inteiro estado)
	{
		oxi_cadeia=tp.real_para_cadeia(oxigenio)
		
		cadeia pontuacao[2][2]={{"\n	", "Pontos"},{"Oxigênio", oxi_cadeia}}
		se(estado==1)
		{
			escreva("\n----------------\n|  Você fugiu  |")
		}
		se(estado==2)
		{
			escreva("\n----------------\n|  Você morreu  |")
		}
		escreva("\n----------------")
		escreva(pontuacao[0][0], pontuacao[0][1], "\n")
		escreva(pontuacao[1][0],"  ", pontuacao[1][1])
		escreva("\n----------------")
		u.aguarde(4500)
	}

	funcao escreve_oxigenio (inteiro decaimento)
	{
		oxi-= decaimento
		escreva("\nOxigênio restante: ",oxi, "\n")
	}

	funcao texto(cadeia text, logico quebra)
	{
		se (quebra == verdadeiro)
		{
			escreva("\n", text, " ")
		}
		se (quebra == falso)
		{
			escreva("\n", text)
			u.aguarde(4000)
		}
	}
	
	funcao pausa(inteiro pausar)
	{
		u.aguarde(pausar)
		limpa()
	}

	funcao verifica_escolha(caracter &impasse, cadeia esc_do_user_1, cadeia esc_do_user_2)
	{
		logico verifica = verdadeiro

		enquanto(verifica == verdadeiro)
		{	
			se ((impasse == '1') ou (impasse == '2'))
			{
				pare
			}
			se ((impasse != '1') ou (impasse != '2'))
			{
				mostrar_opcoes(esc_do_user_1, esc_do_user_2)
				leia(impasse)
			}
		}
	}
	
	cadeia oxi_cadeia
	caracter impasse
	real oxi=12.0
	inteiro senha[2]={u.sorteia(0,4),u.sorteia(5,9)}, tentativa=1, esc, esc2
	logico acertou_senha = verdadeiro, escolher = verdadeiro
	
	funcao inicio()
	{	
		som_ambiente()
		u.aguarde(1500)
		
		texto("Ano: 2027; Est.: Estação Espacial Nº42; Órbita: 450 km.", falso)
		texto("A Estação Espacial Nº42 foi construída em tempo recorde de 5 anos em um projeto secreto do Brasil.", falso)
		texto("A tripulação foi selecionada no ano de 2020 e treinada intensamente durante todo tempo.", falso)
		texto("Enfim, no início do ano de 2026, a estação foi colocada em órbita mesmo com os sinais estranhos que", verdadeiro) 
		texto("a Terra estava recebendo do vazio.", falso)
		pausa(1500)
		texto("Hoje, em 2027, o Brasil executa um plano de captar os sinais estranhos e revolucionar a ciência.", falso)
		texto("A Estação Espacial Nº42 é equipada com alta tecnologia e dispõe de um gerador de oxigênio. Sua sala", verdadeiro)
		texto("é localizada acima dele.", falso)
		pausa(1500)
		texto("Você está em sua sala de comando quando decide observar o vazio.", falso)
		texto("Olhando a imensidão, uma nave de cor escura é avistada e se aproxima.", falso)
		texto("Nunca viu tal coisa. Decide então acionar o botão de “invasores”, mas sente uma enorme vibração e um", verdadeiro)
		texto("solavanco o faz perder o equilíbrio e bater a cabeça no painel.", falso)
		pausa(1500)
		texto("Depois de um tempo e um pouco desorientado, volta para a janela e, olhando para baixo, você percebe", verdadeiro)
		texto("que o gerador de oxigênio foi atingido!", falso)
		pausa(1500)
		texto("OBJETIVO: Saia da estação antes do oxigênio acabar.", falso)
		pausa(1500)
		texto("Informações sobre o jogo:", verdadeiro)
		texto("1) Você só tem duas opções de escolha (1 e 2).", verdadeiro)
		texto("2) Cada parte da estação espacial tem uma quantidade de oxigênio no ar.", verdadeiro)
		texto("3) A pontuação final será a quantidade de oxigênio restante.", falso)
		pausa(1500)
		texto("Saindo da sua sala, olhando de um lado para o outro no corredor, percebe que a estação está vazia.", falso)
		texto("Todos já foram para a nave de fuga.", falso)
		texto("Se colocando em frente de uma janela do corredor, olha a nave vizinha mais atentamente e percebe", verdadeiro)
		texto("que há uma ponte interligando a Estação e ela. ", falso)
		texto("Sua espinha congela. Sente que alguém está te observando. Mas quando olha em volta, não há nada.", falso)
		pausa(1500)
		texto("Devido a pancada, você esqueceu o caminho certo da saída que leva para a nave.", verdadeiro)
		pausa(3000)
		escreve_oxigenio (2)
		texto("Olhando para o corredor, tem duas opções:", falso)
		u.aguarde(1000)
		mostrar_opcoes("Entrar na porta 2.1", "Seguir pelo corredor")
		leia(impasse)
		verifica_escolha(impasse, "Entrar na porta 2.1", "Seguir pelo corredor")
		
		escolha (impasse)
		{

			caso '1':
				pausa(1000)
				escreve_oxigenio(2)
				texto("Quando você toca na maçaneta ouve passos vindo do lado esquerdo do corredor.", falso)
				texto("Virando-se, consegue ver um ser bizarro vindo ao seu encontro.", falso)
				u.aguarde(1000)
				mostrar_opcoes("Lutar", "Fugir")
				leia(impasse)
				verifica_escolha(impasse, "Lutar", "Fugir")

				escolha (impasse)
				{

					caso '1':
						pausa(1000)
						escreve_oxigenio(2)
						texto("Você infelizmente não tem meios de se defender.", falso)
						texto("O ser leva a melhor, te derruba no chão e aponta um phaser.", falso)
						texto("O final não é muito agradável.", falso)
						escreve_matrizPontuacao(oxi, 2)
						pare

					caso '2':
						pausa(1000)
						texto("Fugindo pelo corredor, encontra dois amigos que estavam a sua procura.", falso)
						texto("Enfim, você é resgatado.", falso)
						escreve_oxigenio(2)
						escreve_matrizPontuacao(oxi, 1)
						pare
				}
				pare
				
			caso '2':
				pausa(1000)
				escreve_oxigenio(2)
				texto("Caminhando pelo corredor, sente uma pequena falta de ar.", falso)
				texto("Chegando no meio do caminho, encontra um arma muito parecida com um phaser e decide guardá-la.", falso)
				texto("Enfim, chega a outra porta.", falso)
				mostrar_opcoes("Continuar caminhando", "Tentar entrar na porta 2.3")
				leia(impasse)
				verifica_escolha(impasse, "Continuar caminhando", "Tentar entrar na porta 2.3")

				escolha (impasse)
				{

					caso '1':
						pausa(1000)
						texto("Sua falta de ar começa a aumentar.", falso)
						
						para (inteiro oxi_acabando = 0; oxi_acabando <= oxi; oxi_acabando++)
						{
							escreve_oxigenio(oxi_acabando)
							u.aguarde(750)
							escreva("\n")
						}
						
						texto("Infelizmente não tem mais volta. Você cai no chão. Sem vida.", falso)
						escreve_matrizPontuacao(oxi, 2)
						pare

					caso '2':
						pausa(1000)
						texto("A porta está trancada com uma senha.", falso)
						texto("Você não se lembra ao certo qual era a senha, mas sabe que", verdadeiro)
						texto("o primeiro número está entre 0 e 4 e o segundo entre 5 e 9.", falso)
						texto("Você acessa o sistema da tranca.", falso)
						//Verifação da senha
                         	para(tentativa; tentativa <= 3; tentativa++)
                           	{	
	                           	escreva("\n", tentativa, "ª tentativa...\n")
	                          	escreva("Digite o primeiro numero da senha: ")
	                          	leia(esc)
	
	                          	escreva("Digite o segundo numero da senha: ")
	                          	leia(esc2)
	
	                          	se ((esc == senha[0]) e (esc2 == senha[1]))
	                          	{
	                          		/*Se acertar a senha, o laço para e segue o jogo e a variavel acertou_senha
	                          		continua verdadeira*/
	                          		escreva("\nSenha correta.\n")
	                          		texto("PORTA ABERTA", falso)
	                          		pausa(1500)
	         						texto("Você entra em uma sala pequena, um pouco escura, cinzenta, com uma porta", verdadeiro)
	         						texto("à sua frente, mas que não há uma tranca.", falso)
	         						texto("Ao seu lado, um botão escrito “Plataforma” espera ser apertado para que", verdadeiro)
	         						texto("você saia e vá para a nave de fuga.", falso)
	         						texto("A porta fica entreaberta e você consegue escutar alguns passos vindos do corredor.",
	         							falso)
	         						texto("Sua espinha congela novamente e, em um rápido movimento, você tenta fechar a porta",
	         							verdadeiro)
	         						texto("e apertar o botão, mas o Ser é rápido demais.", falso)
	         						texto(" Ele entra na sala e, como está um pouco escuro, você só enxerga os olhos azuis",
	         							verdadeiro)
	         						texto("altamente brilhantes, são lindos, mas o dono desses olhos está prestes a te atacar.",
	         							falso)
	         						texto("O que você vai fazer?", falso)
	                          		mostrar_opcoes("Lutar", "Fugir")
						       	leia(impasse)
						       	verifica_escolha(impasse, "Lutar", "Fugir")
								pare
	                          	}
	                          	senao
	                          	{	
	                          		escreva("\nSenha incorreta.\n")
	                          		se (tentativa == 3)
	                          		{	
	                          			/* Se errar as 3 vezes, o laço acaba e o jogo também. A variavel acertou_senha
	                          			recebe falso*/
	                          			pausa(1000)
	              						texto("Sua falta de ar começa a aumentar.", falso)
						
									para (inteiro oxi_acabando = 0; oxi_acabando <= oxi; oxi_acabando++)
									{
										escreve_oxigenio(oxi_acabando)
										u.aguarde(750)
										escreva("\n")
									}
						
									texto("Infelizmente não tem mais volta. Você cai no chão. Sem vida.", falso)
									escreve_matrizPontuacao(oxi, 2)
									acertou_senha = falso
	                          		}
	                          	}
                           	}
                           	//pare

                         /*Não é executado se o personagem errou a senha*/
					se (acertou_senha == verdadeiro)
					{
					      escolha (impasse)
					      {
					      	caso '1':
	                          	     pausa(1000)
	                          	     escreve_oxigenio(2)
	                          	     texto("Você se lembra do phaser que encontrou no corredor. Retira ele do bolso e mira", verdadeiro)
	                          	     texto("no Ser, com a mão trêmula dispara.", falso)
	                          	     texto("Escuta um barulho. Ele está caído no chão.", falso)
	                          	     texto("Sem pensar duas vezes você aperta o botão e sai correndo pelo túnel que envolve", verdadeiro)
	                          	     texto("a plataforma assim que a porta se abre, mas um rugido ecoa da pequena sala.", falso)
	                          	     texto("ROOOOAAAAAARRR!", falso)
	                          	     texto("E vê o Ser saindo da pequena sala com uma gosma azul marinho onde estava o buraco do tiro.",
	                          	     	falso)
	                          	     texto("Ainda faltam 3 metros até chegar na nave, mas seus amigos, vendo a situação e se desesperando",
	                          	     	verdadeiro)
	                          	     texto("também, descem da sala de controle da nave com uma pequena esfera.", falso)
	                          	     texto("Você consegue chegar na porta onde eles estão.", falso)
	                          	     texto("Seus amigos rapidamente te puxam para dentro e um  deles lança a esfera. ", falso)
	                          	     texto("A porta é fechada.", falso)
	                          	     texto("Caindo na frente do Ser a esfera começa a abrir e a brilhar.", falso)
	                          	     texto("Então ela explode!", falso)
	                          	     texto("A plataforma é quebrada e o Ser some no meio da fumaça.", falso)
	                          	     texto("E a estação é deixada para trás quando a nave de fuga é ativada.", falso)
	                          	     escreve_matrizPontuacao(oxi, 1)
	                          	     pare
	
	                          	 caso '2':
	                          	 	pausa(1000)
	                          	     escreve_oxigenio(2)
	                          	     texto("Infelizmente você não consegue apertar o botão a tempo.", falso)
	                          	     texto("O Ser avança em sua direção.", falso)
	                          	     texto("Você apenas fecha os olhos e sente seu corpo amolecendo.", falso)
	                          	     escreve_matrizPontuacao(oxi, 2)
	                          	     pare 
					      }
					}
				
                 }
			
		}

		texto("Apesar dos grandes esforços do Brasil, a estação foi inteiramente desativada e explodida", verdadeiro)
		texto("dois dias após a chegada da tripulação na Terra. Inicialmente haviam planos de explorar a", verdadeiro)
		texto("estação, mas o risco dos ataques atrapalharam todas as hipóteses. Por isso a desativação.", falso)
		texto("A explosão ocorreu para ter certeza de que nenhum ser bizarro estaria colocando os pés na estação.", verdadeiro)
		pausa(1500)
		texto("Estranhamente, as mensagens recebidas pela Terra que vinham do espaço pararam de acontecer.", falso)
		texto("Muitos especularam que as mensagens faziam menções ao plano secreto do Brasil, já que apenas", verdadeiro)
		texto("a Estação Espacial Nº42 foi atacada, entretanto, ninguém soube o que realmente se tratava tudo aquilo.", falso)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 541; 
 * @DOBRAMENTO-CODIGO = [6, 13, 41, 47, 60, 66];
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {senha, 88, 9, 5};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */