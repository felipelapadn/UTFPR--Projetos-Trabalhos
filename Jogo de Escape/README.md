# Informações
<p>Na matéria de Fundamentos de Programação, utilizamos o Portugol (uma ferramenta com base na linguagem C) para aprender as estruturas básicas e para desenvolvermos algoritmos. No final da matéria, a professora propôs um trabalho: criar um jogo utilizando todas as estruturas apresentadas nas aulas, podendo ser realizado em grupo ou individualmente. Eu decidi fazer em grupo com mais duas pessoas e tivemos a ideia de desenvolver um jogo de escape.<P>

## Desenvolvimento do jogo
<p>Nós dividimos o desenvolvimento do jogo. Eu fiquei encarregado da história e de fazer algumas funções.<p>
<p>Primeiramente, fizemos um fluxograma para nos auxiliar e para ter uma base da história. Logo em seguida, os outros dois integrantes do grupo começaram o desenvolvimento para que depois eu pudesse incluir o texto no jogo. Durante todo o tempo estávamos dispostsos a ajudar um ao outro e dar palpites do que poderia ser feito para melhorar a jogabilidade. Tivemos várias ideias de como poderíamos dar vida ao nosso jogo da melhor maneira possível, mas decidimos resumir o desenvolvimento por causa do tempo. Depois de "pronto", o jogo passou por algumas reformas para eliminar bugs.<p>
  
## Minha parte do trabalho
  
<p>Eu pensei em fazer uma história com uma pegada mais futurista e com o Brasil como protagonista. E, para me auxiliar, fiz um pequeno roteiro. Logo em seguida comecei a colocar as frases dentro do jogo e a fazer as funções também.<p>

#### História:
<p>A Estação Espacial Nº42 foi construída em tempo recorde de 5 anos em um projeto secreto do Brasil. A tripulação foi selecionada no ano de 2020 e treinada intensamente durante todo tempo. Enfim, no início do ano de 2025, a estação foi colocada em órbita mesmo com os sinais estranhos que a Terra estava recebendo do vazio.<p>
<p>Hoje, em 2027, o Brasil executa um plano de captar os sinais estranhos e revolucionar a ciência.<p>
<p>A Estação Espacial Nº42 é equipada com alta tecnologia e dispõe de um gerador de oxigênio. Sua sala é localizada acima dele.<p>
<p>Você está em sua sala de comando quando decide observar o vazio. Olhando a imensidão, uma nave de cor escura é avistada e se aproxima. Nunca viu tal coisa. Decide então acionar o botão de “invasores”, mas sente uma enorme vibração e um solavanco o faz perder o equilíbrio e bater a cabeça no painel. Depois de um tempo e um pouco desorientado, volta para a janela e, olhando para baixo, você percebe que o gerador de oxigênio foi atingido!<p>
 
#### Objetivo do jogo:
<p>Sair da estação antes que o seu oxigênio acabe.<p>

#### Funções que eu fiz:
- mostrar_opcoes
  ```
  funcao mostrar_opcoes(cadeia esc_do_user_1, cadeia esc_do_user_2)
	{
		escreva("\n[1] - ", esc_do_user_1)
		escreva("\n[2] - ", esc_do_user_2)
		escreva("\nEscolha: ")
	}
  ```
- som_ambiente
  ```
  funcao som_ambiente()
  {	
	inteiro carrega = s.carregar_som("MistyEffect.mp3") /*Carregar um som pelo endereço do arquivo
								e devolve um número na memória. Esse número
								é usado  para a reprodução do som*/
	s.reproduzir_som(carrega, verdadeiro)
	s.definir_volume(80)
  }
  ```

- texto
  ```
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
  ```
- verifica_escolha
  ```
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
  ```
- pausa
  ```
  funcao pausa(inteiro pausar)
  {
	u.aguarde(pausar)
	limpa()
  }
  ```
	
## Créditos
<p>Grupo: Aliana Wakassugui, Felipe Lapa do Nascimento, Rafael Vieira dos Santos<p>
<p>Professora: Suzan K. Borges Piovesan (@skborges)<p>
<p>Música: Misty Effect (Revolt Production Music - "Infinity 2016) (para mais detalhes: https://www.youtube.com/watch?v=4F7sdy2rZws&t=1310s)<p>

## Observações adicionais
<p>Para rodar o jogo e tocar a música ao mesmo tempo, é necessário que os dois estejam na mesma pasta.<p>
<p>O trabalho feito possui, somente, fins didáticos. Caso haja alguma irregularidade entre em contato.<p>
