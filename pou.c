#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y){				//essa funcao eu uso para escrever coisas sem varias quebras de linha ou tabulações
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void imprimirluz(int luzacesa){
	
	
	gotoxy(15,5);
	if(luzacesa==1) printf("%c",15);
	else printf("%c",184);
	
	
	
	
	
}




void limparTela(){
    COORD coord;
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO info;

    coord.X = 0;
    coord.Y = 0;
    GetConsoleScreenBufferInfo ( GetStdHandle ( STD_OUTPUT_HANDLE ), &info );
    SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), coord );
    return;
}




void imprimirPOu(){
	
	//o pou fica nas quinas (linha e coluna trocadas):     (
	
	gotoxy(40,8);
	printf("%c",184);
	
	gotoxy(75,8);
	printf("%c",184);
	
	gotoxy(40,20);
	printf("%c",184);
	
	gotoxy(75,20);
	printf("%c",184);
	
	
	
	
	
}



int main(){
	
	FILE* seuPou;					// nome %char1 saude %char2 fome %char3 diversao %char4 sono
	char nome[100],conteudo[200],char1=9,char2=2,char3=32,char4=160,checandobytes;
	int saude,fome,diversao,sono;
	int byteporbyte,tamanho,acheibarreira;
	int comparar=0,precisasalvar=0;
	
	POINT posicao;
    int x, y,copiax,copiay,mexeu=0;
    
    
    
    
    
    
    
    
	
	seuPou = fopen("seu pou.txt","r");
	if((seuPou = fopen("seu pou.txt","r"))==NULL){
		seuPou = fopen("seu pou.txt","w");							//quando eu terminar 100% o projeto, lembrar de tirar esse txt, ou por exemplo a extensao .naomexa
		printf("Ola seja bem vindo.. consigo ver que voce nao tem um Pou so para vc\nGostaria de ter um? De um nome a ele: ");
		gets(nome);
		printf("\nProcessando.... ");
		Sleep(1500);
		printf("Parabens! Voce agora tem um mini Pou. \nTrate com carinho o arquivo chamado \"seu Pou\", esta e a alma de seu bixinho.. \n");
		Sleep(2000);
		system("pause");
		system("cls");
		fprintf(seuPou,"%s",nome);
		fprintf(seuPou,"%c",char1);
		fprintf(seuPou,"1000");
		fprintf(seuPou,"%c",char2);
		fprintf(seuPou,"1001");
		fprintf(seuPou,"%c",char3);
		fprintf(seuPou,"1002");
		fprintf(seuPou,"%c",char4);
		fprintf(seuPou,"1003");
		saude=1000;
		fome=1001;
		diversao=1002;
		sono=1003;
		fclose(seuPou);	
	}else{				//se o arquivo existe, e o usuario esta abrindo o programa
		while(fgets(conteudo,200,seuPou)!=NULL){}
		byteporbyte=0;
				
		fseek(seuPou, 0, SEEK_END);
   		tamanho = ftell(seuPou);
   		acheibarreira=0;
   		
		do{
			if(conteudo[byteporbyte]==9) acheibarreira=1;
			else byteporbyte++;	
		}while(acheibarreira==0);
		
		comparar=0;
		do{
			nome[comparar] = conteudo[comparar];
			comparar++;		
		}while(comparar<byteporbyte);			
		
		//-----------------------------------------------
			
		rewind(seuPou);
		acheibarreira=0;
		do{
			checandobytes = fgetc(seuPou);
			if(checandobytes==char1) acheibarreira=1;			
		}while(acheibarreira==0);
		fscanf(seuPou,"%d",&saude);
							
		rewind(seuPou);
		acheibarreira=0;
		do{
			checandobytes = fgetc(seuPou);
			if(checandobytes==char2) acheibarreira=1;			
		}while(acheibarreira==0);
		fscanf(seuPou,"%d",&fome);		
				
		rewind(seuPou);
		acheibarreira=0;
		do{
			checandobytes = fgetc(seuPou);
			if(checandobytes==char3) acheibarreira=1;			
		}while(acheibarreira==0);
		fscanf(seuPou,"%d",&diversao);
				
		rewind(seuPou);
		acheibarreira=0;
		do{
			checandobytes = fgetc(seuPou);
			if(checandobytes==char4) acheibarreira=1;			
		}while(acheibarreira==0);
		fscanf(seuPou,"%d",&sono);
						
		printf("Bem vindo novamente, %s sentiu saudades! Coloque em tela cheia para melhor experiencia\nPara fechar, pressione esc, mas nunca feche a janela\n",nome);
			//printf("eu li %s maaassss tirei so %s viu!!",conteudo,nome);				//testeeee
			//printf("%d,%d,%d,%d",saude,fome,diversao,sono);							//testeeee
		fclose(seuPou);	
		system("pause");
		system("cls");
				
	}
	
	
	
	gotoxy(1,27);
	printf("Coloque na tela cheia.");
	
	gotoxy(1,35);
    printf("Use as letras do teclado para alimentar o pou, cada letra representa um alimento. com 1000 ele esta cheio, mas em 0 ele morrera\n"
		   "Ao comer, ele perdera saude. Para dar remedios, utilize os numeros do teclado, mas cuidado, os remedios melhoram a saude \n"
		   "porem afetam todos os outros aspectos dele. Para diverti-lo, em tela cheia, passe o mouse pelo Pou. Para que ele durma bem\n"
		   "Pressione enter para apagar a luz. De luz apagada, ele nao pode comer ou tomar remedios. Boa sorte!");
	
		gotoxy(55,23);
		printf("%s",nome);
	
	
	int morreu=0,luzacesa=1,comeu=0,comida,remedio=0,prescricao;
	int copiaSa,copiaF,copiaD,copiaSo,contagem=0,divisao,noPou=0;
	
	float Sa,F,D,So;
	char tecla;
	
	//printf("%d e %d",saude,Sa);
	Sa = saude; 
	//printf("%d e %f",saude,Sa);
	F = fome; 
	D = diversao; 
	So = sono;
	
	
	
	
	
	do{
		
		contagem++;
		
		gotoxy(1,1);
		printf(" ");
		
		if (GetCursorPos(&posicao) && posicao.x != x && posicao.y != y) {
            limparTela();
            //printf("<%ld, %ld>                 \n", posicao.x, posicao.y); 	//teste
            if(copiax!=x || copiay!=y) mexeu = 1;
            if(copiax!=posicao.x || copiay!=posicao.y) mexeu = 1;
            x = posicao.x;
            y = posicao.y;
           
        }
        
        if(posicao.x>=279 && posicao.x<=540 &&  posicao.y>=140 &&  posicao.y<=373) noPou=1;
        
        if(mexeu==1 && noPou==1) D = D + 1;
        
        imprimirPOu();
        
        divisao = contagem % 10;
        
        if(divisao==0){
        	copiax = x;
        	copiay = y;      	
		}
        
        //printf("%d e %d ",copiax,copiay);
		if(mexeu==1) mexeu=0;
		if(noPou==1) noPou=0;
		
		
		
							//a velocidade q as coisas descem sao proporcionais a o sleep 
		F = F - 0.25;
		D = D - 0.25;
		if(luzacesa==1) So = So - 0.25;
		else So = So + 0.5;
		
		
		gotoxy(25,2);
		printf("saude %d          ",saude);
		gotoxy(45,2);
		printf("fome %d          ",fome);
		gotoxy(65,2);
		printf("diversao %d          ",diversao);
		gotoxy(85,2);
		printf("sono %d          ",sono);
		
		imprimirluz(luzacesa);
		
		Sleep(10);
		
		
		/*
		gotoxy(25,4);
		printf("saude %f         ",Sa);
		gotoxy(45,4);
		printf("fome %f         ",F);
		gotoxy(65,4);
		printf("diversao %f         ",D);
		gotoxy(85,4);
		printf("sono %f         ",So);
		*/
		
		
		
		
		if(kbhit()){
			
			precisasalvar = 1;
			
			tecla = getch();
			
			if(tecla==27){
				exit(0);
			}else if(tecla==13){
				
				if(luzacesa==1) luzacesa=0;
				else luzacesa=1;
				
			}else if(tecla>=65 && tecla<=122){
				comeu = 1;				
			}else if(tecla>=49 && tecla<=57){
				remedio = 1;				
			}
			
			
			if(comeu==1 && luzacesa==1){
				comida = tecla - 64;
				F = F + comida;
				Sa = Sa - (comida+10);
								
			}
			
			if(remedio==1 && luzacesa==1){
				
				prescricao = (tecla - 48) * 15;
				Sa = Sa + prescricao;
				
				F = F - (prescricao/3);
				So = So - (prescricao/3);
				D = D - (prescricao/3);
			}
			
			comeu=0;
			remedio=0;
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		saude =  Sa;
		fome =  F;
		diversao = D;
		sono =  So;
		
		
		//Sleep(10);
		
		
	
		
		
		if(saude<=0 || diversao<=0 || fome<=0 || sono<=0) morreu = 1;
		
		
		
		if(precisasalvar==1){											//salvar
		precisasalvar=0;
		seuPou = fopen("seu pou.txt","w+");
		//seuPou = fopen("seu pou.txt","r");
		//fflush(seuPou);
		//fclose();
		seuPou = fopen("seu pou.txt","a");
		fprintf(seuPou,"%s",nome);
		fprintf(seuPou,"%c",char1);
		fprintf(seuPou,"%d",saude);
		fprintf(seuPou,"%c",char2);
		fprintf(seuPou,"%d",fome);
		fprintf(seuPou,"%c",char3);
		fprintf(seuPou,"%d",diversao);
		fprintf(seuPou,"%c",char4);
		fprintf(seuPou,"%d",sono);
		fclose(seuPou);
		}
		
		if(saude>1000) saude=1000;
		if(diversao>1000) diversao=1000;
		if(sono>1000) sono = 1000;
		if(fome>1000) fome = 1000;
		
		
		
	}while(morreu==0);
	
	
	int teste;
	
	system("cls");
	printf("Eu sinto muito, seu Pou infelizmente morreu :(");
	teste = remove("seu pou.txt");
	
	if(teste!=0){
		printf("\nOxi, nao consigo limpar o seu pou pra vc criar outro..\n");
	}
	
	//seuPou = fopen("seu pou.txt","a");
	//remove(seuPou);
	system("pause");
	
	
	
	
	//fclose(seuPou);
	return 0;
}