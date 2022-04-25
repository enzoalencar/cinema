//Bibliotecas
#include <stdio.h>//Blioteca Padrão Entrada e Saida
#include <windows.h>//Biblioteca Funções do Terminal Windows
#include <conio.h>//Biblioteca para Manipular Caracteres na Tela
#include <ctype.h>//Biblioteca para Classificar Caracteres
#include <string.h>

//Cores
#define RST  "\x1B[0m"//Cor Resetar
#define RED  "\e[31;1m"//Cor Vermelho
#define GRN "\e[32;1m"//Cor Verde
#define YEL "\e[33;1m"//Cor Amarelo
#define BLU  "\x1B[34m"//Cor Azul
#define MAG  "\x1B[35m"//Cor Magenta
#define CYN  "\x1B[36m"//Cor Cyano
#define WHT  "\e[38;1m"//Cor Branca
#define REDB  "\e[31;7m"//Vermelho Back Ground
#define REDN  "\e[31;1m"// negrito
//Função Principal
int main()
{
	//Funções Auxiliares
	void Gotoxy(int x, int y);//Mover Menu
	void Retangulo( int ho, int vo, int larg, int alt );//Cria um Retangulo
	void load();//Funçao tela de loading
	void inicio();//Funçao Menu
	load();//Aciona tela de loading
	inicio();//Aciona Função Menu
	return 0;//Retorna 0
}
//Função Mover Menu
void Gotoxy(int x, int y)//Função Recebe x e y
{
//Envia o parametro escolhido para o windows posicionando o Cursor nas respctivas cordenadas
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}
//Função Retangulo
void Retangulo(int ho, int vo, int larg, int alt)
{
    int h, v;
    // Linhas horizontais
     for(h=ho; h < ho+larg; h++)//Laço de Repetição
	 {
        Gotoxy (h, vo); printf (RED"%c", 205);//Imprime o Caracter Especial 206 da tabela ASCII
        Gotoxy(h, vo+alt); printf (RED"%c", 205);//Imprime o Caracter Especial 206 da tabela ASCII
     }
     // Linhas verticais
     for(v=vo; v < vo+alt; v++)
	 {
        Gotoxy (ho, v);  printf (RED"%c", 186);//Imprime o Caracter Especial 186 da tabela ASCII
        Gotoxy(ho+larg, v);  printf (RED"%c", 186);//Imprime o Caracter Especial 186 da tabela ASCII
     }
     // Cantos
     Gotoxy  (ho, vo);    printf (YEL"%c", 201);//Imprime o Caracter Especial 201 da tabela ASCII
     Gotoxy (ho, vo+alt);    printf (YEL"%c", 200);//Imprime o Caracter Especial 200 da tabela ASCII
     Gotoxy (ho+larg, vo);    printf (YEL"%c", 187);//Imprime o Caracter Especial 187 da tabela ASCII
     Gotoxy(ho+larg, vo+alt);    printf (YEL"%c", 188);//Imprime o Caracter Especial 188 da tabela ASCII
}
//Funçao tela  de loading
void load()
{
	int i=0;//Varial i de Contagem
	system("color 00");//Limpar o Terminal
	Gotoxy(39,11);//Determina Posição
	printf("Iniciando...");//Imprime Iniciando
	Retangulo(0, 0, 90, 30);//Retangulo Principal
	Retangulo(16, 12, 59, 4);//Retangulo Menor
	while(i<=50)
	{
		Gotoxy(i+18,14);//Determina Posição
		printf(REDB" "REDN);//Imprime um Espaço Vermelho
		Gotoxy(70,14);//Determina Posição
		printf(RST"%d%%"REDN,i*2);//Imprime a Porcetagem do Carregamento
		Sleep(15);//Delay de 15ms
		i++;//incrementa +1 a i
	}
	Beep(349,100);//Gera um Som a 349 hz por 100 ms
	system("cls");//Limpar o Terminal
}
//Função Menu
void inicio()
{
	system("color 00");//Redefine a sistema para a cor padrão
	void catalogo();//Funçao Catalogo
	void encerrando();//Funçao Sair
	int altura=3;//Variavel que Inicia o o curso em Catalogo
	char ch;//Variavel Usada para Capturar as teclas Usadas
	Retangulo(0, 0, 90, 30);//Retangulo Principal
	Retangulo(36, 8, 17, 10);//Retangulo Mini Menu
	do
	{
    	Gotoxy(42, 10);//Determina Possição
    	printf(YEL"CINEMA"RST);//Imprime Cinema
    	Gotoxy(41, 12);//Determina Possição
    	if(altura==3)//Se for 3
    		printf(RED"Catalogo\n\n\n"RST);//Imprime Catalogo Roxo
    	if(altura!=3)//Se for diferente de 3
 			printf(RST"Catalogo\n\n\n"RST);//Imprime Catalogo Branco
 		Gotoxy(39, 14);//Determina Possição
 		if(altura==5)//Se for 5
    		printf(RED"Funcionarios\n\n\n"RST);//Imprime Funcionarios Roxo
    	if(altura!=5)//Se for diferente de 5
 			printf(RST"Funcionarios\n\n\n"RST);//Imprime Funcionarios Branco
 		Gotoxy(43, 16);//Determina Possição
 		if(altura==7)//Se for 7
 			printf(RED"Sair"RST);//Imprime Sair Roxo
 		if(altura!=7)//Se for diferente de 7
 			printf(RST"Sair\n\n\n"RST);//Imprime Sair Branco
		fflush(stdin);//Limpa o Buffer
		ch=getch();//Lê um Caracter
		switch(ch)//Estrutura de Descisão do Movimento
		{
			case 72://Move ao Prescionar Seta para Cima = 72 Tabela ASCII
				if(altura > 3)
					altura -= 2 ;
				else
					altura= 7;//Se o Valor for Abaixo Voltar a Ultima Opção
				break;
			case 80:
				if(altura < 7)//Move ao Prescionar Seta para Baixo = 80 Tabela ASCII
					altura += 2;
				else
					altura= 3 ;//Se o Valor For Acima Voltar a Primeira Opção
				break;
		}
	}while(ch != 13);//Finaliza ao Prescionar Enter = 13 Tabela ASCII
	Beep(349,100);//Gera um Som a 349 hz por 100 ms
	system("cls");//Limpa o Terminal
	switch(altura)//Estruturas de Descições
	{
		case 7://Caso Selecione Sair
			encerrando();
			break;
		case 5://Caso Selecione Funcionarios
			encerrando();
			break;
		case 3://Caso Selecione Catalogo
			catalogo();
			break;
	}
}
//Função Catalogo
void catalogo()
{
	void encerrando();//Funçao Sair
	void filmesmenu();//Funçao Menu do Filme Especificado
	int i, soma=0,largura=21;//Variaveis Para contruçáo dos Retangulos e Para que o cursor inicie em Filme 1
	char ch;//Variavel Aux para armazenar teclas
	Retangulo(0, 0, 90, 30);//Retangulo Principal
	Gotoxy(42, 6);//Determina Possição
	printf(YEL"FILMES"RST);//Imprime Filmes Amarelo
	for(i = 1 ;i < 4;i++)//Constroi 3 Retangulos
	{
		soma += 20;//Espaçamento entre eles de 20
		Retangulo(soma, 10, 8, 5);
	}
	do
	{
		Gotoxy(21, 16);//Determina Possição
		if(largura==21)
			printf(RED"Filme 1 "RST);//Imprime Filme 1 Vermelho
		if(largura!=21)
			printf(RST"Filme 1 "RST);//Imprime Filme 1 Branco
		Gotoxy(41, 16);//Determina Possição
		if(largura==41)
			printf(RED"Filme 2 "RST);//Imprime Filme 2 Vermelho
		if(largura!=41)
			printf(RST"Filme 2 "RST);//Imprime Filme 2 Branco
		Gotoxy(61, 16);//Determina Possição
		if(largura==61)
			printf(RED"Filme 3 "RST);//Imprime Filme 3 Vermelho
		if(largura!=61)
			printf(RST"Filme 3 "RST);//Imprime Filme 3 Branco
		Gotoxy(80, 25);//Determina Possição
		if(largura==81)
			printf(RED"Sair "RST);//Imprime Sair Vermelho
		if(largura!=81)
			printf(RST"Sair "RST);//Imprime Sair Branco
		Gotoxy(5, 25);//Determina Possição
		if(largura==1)
			printf(RED"Voltar"RST);//Imprime Voltar Vermelho
		if(largura!=1)
			printf(RST"Voltar"RST);//Imprime Voltar Branco
		fflush(stdin);//Limpa o Buffer do Teclado
		ch=getch();//Captura a tecla sem eco e armazena na variavel ch
		switch(ch)
		{
			case 75://Se a tecla esquerda for precionada
				if(largura > 1)
					largura -= 20;
				else
					largura= 81;//Se o limite for execedido ele volta para a ultima valor de largura
				break;
			case 77://Se a tecla direita for precionada
				if(largura < 81)
					largura += 20;
				else
					largura = 1;//Se o limite for execedido ele volta para a primeiro valor de largura
				break;
		}
	}while(ch != 13);//Finaliza ao Prescionar Enter = 13 Tabela ASCII
	Beep(349,100);//Gera um Som a 349 hz por 100 ms
	system("cls");//Limpa o Termianl
	switch(largura)//Estruturas de Descições
	{
		case 1://Caso Selecione Voltar
			inicio();
			break;
		case 21://Caso Selecione Filme 1
			filmesmenu();
			break;
		case 41://Caso Selecione Filme 2
			exit(1);
			break;
		case 61://Caso Selecione Filme 3
			exit(1);
			break;
		case 81://Caso Selecione Sair
			encerrando();
			break;
	}
}
//Função Descrição Filmes e Horarios
void filmesmenu()
{
void encerrando();
void login();
void menulogin();
void assentos();
int i,soma=0;
int y=0,x,largura=21;
char ch;
int xd=1;
int idade=18;
Retangulo(0,0,90,30);//Retangulo Principal
Retangulo(5,3,15,8);//Retangulo Foto
Retangulo(29,3,50,12);//Retangulo Descrição
Retangulo(18,23,50,4);//Retangulo Mini Menu
do
{
	Gotoxy(3,13);
	printf(RED"Maioridade Necessaria"RST);
	Gotoxy(10,12);
	printf(YEL"Filme 1"RST);
	Gotoxy(21,25);
	if(largura==21)
		printf(RED"22:00 "RST);
	if(largura!=21)
		printf(RST"22:00 "RST);
	Gotoxy(40,21);
		printf(YEL"HORARIOS"RST);
	Gotoxy(41,25);
	if(largura==41)
		printf(RED"20:00 "RST);
	if(largura!=41)
		printf(RST"20:00 "RST);
	Gotoxy(61,25);
	if(largura==61)
		printf(RED"18:00 "RST);
	if(largura!=61)
		printf(RST"18:00 "RST);
	Gotoxy(80,25);
	if(largura==81)
		printf(RED"Sair "RST);
	if(largura!=81)
		printf(RST"Sair "RST);
	Gotoxy(5,25);
	if(largura==1)
		printf(RED"Voltar"RST);
	if(largura!=1)
		printf(RST"Voltar"RST);
	fflush(stdin);
	ch=getch();
	switch(ch)
	{
	case 75:
		if(largura>1)
		{
		largura-=20;
		}
		else
		{
		largura=81;
		}

		break;
	case 77:
		if(largura<81)
		{
		largura+=20;
		}
		else
		{
		largura=1;
		}
		break;
	case 13:
		ch=13;
		break;
	}
}while(ch!=13);
Beep(349,100);//Gera um Som a 349 hz por 100 ms
system("cls");
if(largura==81)
	encerrando();
if(largura==1)
	catalogo();
if(largura==21)
	login();
}

void login()//Funçao login
{
    void assentos();
    int tamN = 100, tami = 15;
    int i, vali, cont = 0;
    char nome[tamN], idade[tami];

    do
    {
        do
        {
            system("color 00");//Setar Padrão Cor do Terminal
            Retangulo(0,0,90,30);//Retangulo Principal
            Retangulo(28,8,34,10);//Retangulo Mini Menu
            Gotoxy(40,10);
            printf(YEL"LOGIN"RST);
            Gotoxy(30,12);
            printf(RED"Nome Completo:"RST);
            Gotoxy(30,13);

            if(cont == 0)
            {
            fgets(nome, tamN, stdin);
            }

            if(cont == 1)
            {
            printf("%s", nome);
            }

            nome[strcspn(nome, "\n")] = 0;
            vali = 1;

            for(i = 0; nome[i] != '\0'; i++)
            {
                if(!isalpha(nome[i]) && nome[i] != 32)
                {
                    vali = 0;
                    break;
                }
            }

            if(vali == 0)
            {
                    system("cls");
            }

        }while(vali == 0);

        Gotoxy(30,14);
        printf(RED"Idade:"RST);

        Gotoxy(30,15);
        fgets(idade, tami, stdin);
        vali = 1;

        for(i = 0; idade[i] != '\0'; i++)
        {
            if(isalpha(idade[i]))
            {
                vali = 0;
                system("cls");
                cont=1;
                break;
            }
        }
    }while(vali == 0);
    system("cls");
    assentos();
}

void assentos()
{
	void encerrando();
	Retangulo(0,0,90,30);//Retangulo Principal
	Retangulo(2,1,86,15);//Retangulo Assentos
	Retangulo(38,17,13,2);//Retangulo Bilheteria
	Retangulo(2,20,86,2);//Retangulo Menu
	Retangulo(2,23,86,6);//Opções
	int ler(int *rL,int *rC,int *rB);
	int gravar(int linha,int coluna);
	char Cinema[14][23],g;
	char Cinema1[14][23];
	int l,c,cont=0,cont1,li2,jump=0,i=0,k=0;
	int Ocupado=1,u;
	int largura=1,ch,a,b;
	int j=0;
	int Vetor[2],Vetor1[2];
	int colunasP[322];
	int linhasP[322];
	int h=0;
	int pause;
	//Amonstra de Sala Vazia
	for(l=0;l<14;l++)
		for(c=0;c<23;c++)
			Cinema[l][c]=0;//Tranforma todas as cADEIRAS EM VAZIAS
	ler(linhasP,colunasP,&pause);//CHAMA A FUNÇAO APONTANDO para 3 ponteiros
	if(pause!=0)//Se o ponteiro retorna 0 que significa arquivo vazio ele nao tenta gravar nenhuma matriz
	{
		while(i<pause)//Grava ate o valor contado dentro da funçao que estipula a quantidade de cadeira armazenadas
		{
			a=linhasP[i];//Estipula o Valor de a
			b=colunasP[i];//Estipula o Valor de b
			Cinema[a][b]=1;//Estipula a cadeira como ocupada
			i++;//Incrimenta
		}
	}
	for(l=0;l<14;l++)//Imprime a Matriz na tela
	{
		Gotoxy(5,2+l);
		for(c=0;c<23;c++)
		{
			if(Cinema[l][c]==1)//Se tiver Ocupada Imprime Veremlho
			{
				printf(RED"%c%d "RST,l+65,c);
			}
			else if(Cinema[l][c]==0)//Livre Imprime Verde
			{
				printf(GRN"%c%d "RST,l+65,c);
			}
		}
		printf("\n");
	}
	cont=1;
	Gotoxy(40,18);
	printf(YEL"BILHETERIA"RST);
	do
	{
		Gotoxy(80,21);
		if(largura==41)
			printf(RED"Sair "RST);
		if(largura!=41)
			printf(RST"Sair "RST);
		Gotoxy(36,21);
		if(largura==21)
			printf(RED"Escolher Assentos"RST);
		if(largura!=21)
			printf(RST"Escolher Assentos"RST);
		Gotoxy(5,21);
		if(largura==1)
			printf(RED"Voltar"RST);
		if(largura!=1)
			printf(RST"Voltar"RST);
		fflush(stdin);
		ch=getch();
		switch(ch)
		{
		case 75:
			if(largura>1)
			{
				largura-=20;
			}
			else
			{
				largura=41;
			}

			break;
		case 77:
			if(largura<41)
			{
				largura+=20;
			}
			else
			{
				largura=1;
			}
			break;
		case 13:
			ch=13;
			break;
		}
	}while(ch!=13);
	Beep(349,100);//Gera um Som a 349 hz por 100 ms
	if(largura==41)
	{
		system("cls");
		encerrando();
	}
	if(largura==1)
	{
		system("cls");
		filmesmenu();
	}
	Gotoxy(36,21);
	printf(RST"Escolher Assentos"RST);
	do
	{
		Gotoxy(4,24);
		printf(YEL"Quantos Ingressos Voce deseja ?"RST);
		Gotoxy(4,25);
		fflush(stdin);
		scanf("%d",&j);
		Gotoxy(4,26);
		if(j==0)
			printf(RED"Digite Novamente"RST);
		Gotoxy(4,25);
		printf("                     ");
	}while(j==0);
	Gotoxy(4,25);
	printf("%d",j);
	Beep(349,100);//Gera um Som a 349 hz por 100 ms
	for(i=0;i<j;i++)
	{
		Gotoxy(4,26);
		printf(YEL"Escolha as Cadeiras "RST);
		Gotoxy(4+k,27);
		scanf(" %c%d",&l,&c);
		l=toupper(l);
		g=l-65;
		Cinema[g][c]=1;
		if(g<23 && g>=0 && c<14 && c>=0)
			gravar(g,c);//Entra na funçao e Envia as a coluna e a linha das Cadeira Ocupadas para serem gravadas
		h++;
		k+=4;
	}
	for(l=0;l<14;l++)
	{
		Gotoxy(5,2+l);
		for(c=0;c<23;c++)
		{
			if(Cinema[l][c]==1)//Se tiver Ocupada Imprime Veremlho
			{
				printf(RED"%c%d "RST,l+65,c);
			}
			else if(Cinema[l][c]==0)//Livre Imprime Verde
			{
				printf(GRN"%c%d "GRN,l+65,c);
			}
		}
		printf("\n");
	}
	largura=1;
	do
	{
		Gotoxy(80,21);
		if(largura==41)
			printf(RED"Sair "RST);
		if(largura!=41)
			printf(RST"Sair "RST);
		Gotoxy(78,28);
		if(largura==1)
			printf(RED"Confirmar"RST);
		if(largura!=1)
			printf(RST"Confirmar"RST);
		Gotoxy(5,21);
		if(largura==21)
			printf(RED"Voltar"RST);
		if(largura!=21)
			printf(RST"Voltar"RST);
		fflush(stdin);
		ch=getch();
		switch(ch)
		{
			case 75:
				if(largura>1)
				{
					largura-=20;
				}
				else
				{
					largura=41;
				}
				break;
			case 77:
				if(largura<41)
				{
					largura+=20;
				}
				else
				{
					largura=1;
				}
				break;
			case 13:
				ch=13;
				break;
		}
	}while(ch!=13);
	Beep(349,100);//Gera um Som a 349 hz por 100 ms
	if(largura==41)
		encerrando();
	if(largura==1)
	{
		system("cls");
		inicio();
	}
	if(largura==21)
	{
		system("cls");
		filmesmenu();
	}
}
//Ler os Assentos Ocupados no Arquivo
int ler(int *rL,int *rC,int *rB)
{
	void encerrando();
	int vazio(const char* file_name);//Funçao que Verifica se o arquivo esta vazio
	FILE *cine;//Ponteiro para o arquivo
	int linhas;//Variaveis para leitura
	int colunas;//Variaveis para leitura
	int i=0,cont=0;//Variaveis para Contagem
	cine = fopen("arq","r");//Aponta o ponteiro para o arquivo aberto em modo leitura
	if(cine == NULL)//Se o arquivo nao for encontrado
		encerrando();//Fecha
	if(vazio("arq")==0)//Se o arquivo estiver Vazio
	{
		*rB=0;//Envia para o Ponteiro *rB o Valor 0
		return 0;//Retorna para a Função
	}
	while(fscanf(cine,"%d",&linhas)!= -1 && fscanf(cine,"%d",&colunas)!= -1)//Laço de repetiçao feita para ler ate o arquivo acabar
	{
		*rL=linhas;//Passa o parametro de linhas para o ponteiro
		*rC=colunas;//Passa o parametro de colunas para o ponteiro
		++rL;//Move o ponteiro para o proximo espaço em memoria sua Array ou Vetor
		++rC;//Move o ponteiro para o proximo espaço de memoria em sua Array ou Vetor
		cont++;//Adiciona +1 a Variavel
		*rB=cont;//Passa o Valor do cont para o ponteiro
	}
	fclose(cine);//Fecha o Arquivo
	return 0;//Volta a Função
}
//Funçao gravar aseentos Ocupados
int gravar(int linha,int coluna)
{
	void encerrando();
	FILE *cine;//Ponteiro para o arquivo
	cine = fopen("arq","a+");//Aponta o ponteiro para o arquivo aberto em modo escrita e se precisar criar o arquivo ele cria
	if(cine == NULL)//Se o arquivo nao for encontrado
		encerrando();//Fecha
	fprintf(cine,"%d %d\n",linha,coluna);//Grava no Arquivo a linha e a coluna recebida pela funçao
	fclose(cine);//Fecha o arquivo
}
//Funçao que verifica se o arquivo esta vazio
int vazio(const char* file_name)
{
	void encerrando();
    FILE *cine;//Ponteiro para o arquivo
	cine = fopen(file_name, "r");//Aponta o ponteiro para o arquivo aberto em modo leitura
    if(cine == NULL)//Se o arquivo nao for encontrado
    	encerrando();//Fecha
    fseek(cine, 0, SEEK_END);//Inicia o arquivo com o ponteiro na posição final
    int tamanho = ftell(cine);//Passa o tamanho do arquivo para a variavel tamanho;
    fclose(cine);//Fecha o Arquivo
    return tamanho;//Retorna o Tamanho a Função
}
//Função Para Sair do Progama
void encerrando()
{
	system("color 00");//Limpa o Terminal
	int i=0;//Variavel de Contagme
	Gotoxy(39,11);//Determina posição
	printf("Encerrando...");//Imprime Encerrando
	Retangulo(0, 0, 90, 30);//Retangulo Principal
	Retangulo(16, 12, 59, 4);//Retangulo Principal
	while(i<=50)//Laço para Imprimir os Caracteres
	{
		Gotoxy(i+18,14);//Determina Posição
		printf(REDB" "REDN);//imprime os espaços em Vermelho
		Gotoxy(70,14);//Determina Posição
		printf(RST"%d%%"REDN,i*2);//Imprime A porcentagem de Carregamento
		Sleep(15);//Delay de 15ms
		i++;//Encrementa 1 na variavel i
	}
	Beep(349,100);//Gera um Som a 349 hz por 100 ms
	system("cls");//Limpa o Terminal
	exit(1);//Encerra o Progama
}