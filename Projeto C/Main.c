// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

HINSTANCE handle;

// Declaracao de ponteiros de funcao para as funcoes da DLL
typedef int (*AbreConexaoImpressora_t)(int, const char *, const char *, int);
typedef int (*FechaConexaoImpressora_t)();
typedef int (*ImpressaoTexto_t)(const char *, int, int, int);
typedef int (*Corte_t)(int);
typedef int (*ImpressaoQRCode_t)(const char *, int, int);
typedef int (*ImpressaoCodigoBarras_t)(int, const char *, int, int, int);
typedef int (*StatusImpressora_t)(int);
typedef int (*AvancaPapel_t)(int);

// Ponteiros para as funcoes da DLL
AbreConexaoImpressora_t AbreConexaoImpressora;
FechaConexaoImpressora_t FechaConexaoImpressora;
ImpressaoTexto_t ImpressaoTexto;
Corte_t Corte;
ImpressaoQRCode_t ImpressaoQRCode;
ImpressaoCodigoBarras_t ImpressaoCodigoBarras;
StatusImpressora_t StatusImpressora;
AvancaPapel_t AvancaPapel;

// Carrega as funcoes da biblioteca
int carregarFuncoes() {
    handle = LoadLibrary("E1_Impressora01.dll");
    if (!handle) {
        fprintf(stderr, "Erro ao carregar a biblioteca.\n");
        return 0;
    }

    AbreConexaoImpressora = (AbreConexaoImpressora_t)GetProcAddress(handle, "AbreConexaoImpressora");
    FechaConexaoImpressora = (FechaConexaoImpressora_t)GetProcAddress(handle, "FechaConexaoImpressora");
    ImpressaoTexto = (ImpressaoTexto_t)GetProcAddress(handle, "ImpressaoTexto");
    Corte = (Corte_t)GetProcAddress(handle, "Corte");
    ImpressaoQRCode = (ImpressaoQRCode_t)GetProcAddress(handle, "ImpressaoQRCode");
    ImpressaoCodigoBarras = (ImpressaoCodigoBarras_t)GetProcAddress(handle, "ImpressaoCodigoBarras");
    StatusImpressora = (StatusImpressora_t)GetProcAddress(handle, "StatusImpressora");
    AvancaPapel = (AvancaPapel_t)GetProcAddress(handle, "AvancaPapel");

    if (!AbreConexaoImpressora || !FechaConexaoImpressora || !ImpressaoTexto || !Corte ||
        !ImpressaoQRCode || !ImpressaoCodigoBarras || !StatusImpressora || !AvancaPapel) {
        fprintf(stderr, "Erro ao carregar as funcoes da biblioteca.\n");
        return 0;
    }
    return 1;
}

// Libera a biblioteca carregada
void liberarBiblioteca() {
    if (handle) {
        FreeLibrary(handle);
    }
}

// Funcao de impressao de menu e selecao de opcoes
void exibirMenu() {
	printf("\n*******************************************************\n\
******************* MENU IMPRESSORA *******************\n\
*******************************************************\n");

    printf("1  - Configurar Conexao\n\
2  - Abrir Conexao\n\
3  - Impressao Texto\n\
4  - Impressao QRCode\n\
5  - Impressao Cod Barras\n\
6  - Impressao XML SAT\n\
7  - Impressao XML Canc SAT\n\
8  - Abrir Gaveta Elgin\n\
9  - Abrir Gaveta\n\
10 - Sinal Sonoro\n\
0  - Fechar Conexao e Sair\n\
-----------------------------------------------\n\n\
Digite a opcao desejada: ");

	//implementar o laço para o menu de apresentação
}



//// Implementacao das opcoes de menu
void configurarConexao() {
	int ret=0;
	int tipo=1;
	const char *modelo="i9";
	const char *conexao="USB";
	int parametro=0;
	printf("%i", ret);
	//ret=AbreConexaoImpressora(tipo, modelo, conexao, parametro);
	printf("Informa��es armazenadas!\n");
    
}

void abrirConexao() {
	int ret;
	ret = AbreConexaoImpressora(1, "i9", "USB", 0);
    if(ret==0){
    	printf("Conexao aberta com sucesso");
	}else{
		printf("Falha na conexao\n erro %i", ret);
	}
	
}

void impressaoTexto() {
     char dados[50]="Imprecao feita";
     int posicao, stilo, tamanho;
     posicao= 1;
     stilo = 4;
     tamanho =0;
//	printf("imprimir texto\n");
    ImpressaoTexto("Imprecao feita" , 1, 4, 0);
    AvancaPapel(5);
    Corte(1);
//  preencher o restante do codigo de acordo com a função e sua necessidade
    
}

void impressaoQRCode() {
	char dados[50]="https://www.youtube.com/watch?v=YHplij1tFiw";
	int tamanho = 6;
    int nivelcorrecao = 4;
	printf("imprimir QRcode\n");
	ImpressaoQRCode(dados, tamanho, nivelcorrecao);
	AvancaPapel(5);
	Corte(1);
	//preencher o restante do codigo de acordo com a função e sua necessidade
    
}

void impressaoCodigoBarras() {
    int 	tipo = 8;
    const char dados[50]="{A012345678912";
    int 	altura = 100;
    int 	largura = 2;
    int 	HRI = 3;
//	printf("imprimir codigo de barra\n");
	ImpressaoCodigoBarras(tipo, dados, altura, largura, HRI);
	AvancaPapel(5);
	Corte(1);
	
	//preencher o restante do codigo de acordo com a função e sua necessidade
    
}

void ImpressaoXMLSAT(){
	int ret;
    const char dados[50] = "path=D:\Projeto C\Projeto C\XMLSAT.xml";
    printf("%c", dados);
    int param = 0;
    
//	char path[50] = "path=D:/Projeto C/Projeto C/XMLSAT.xml";
//	ImpressaoTexto(dados, param);
//	ret = ImprimeXMLSAT();
//	printf("%s", path);
//	FILE *arquivo = fopen(path, "r");
	
//	if (arquivo == NULL) {
//		perror("Erro ao abrir arquivo")
//	}
    AvancaPapel(5);
	Corte(1);
}

void ImpressaoXMLCancSAT(){
    const char dados[50];
    int param = 0;
//    char String assQRCode = "Q5DLkpdRijIRGY6YSSNsTWK1TztHL1vD0V1Jc4spo/CEUqICEb9SFy82ym8EhBRZjbh3btsZhF+sjHqEMR159i4agru9x6KsepK/q0E2e5xlU5cv3m1woYfgHyOkWDNcSdMsS6bBh2Bpq6s89yJ9Q6qh/J8YHi306ce9Tqb/drKvN2XdE5noRSS32TAWuaQEVd7u+TrvXlOQsE3fHR1D5f1saUwQLPSdIv01NF6Ny7jZwjCwv1uNDgGZONJdlTJ6p0ccqnZvuE70aHOI09elpjEO6Cd+orI7XHHrFCwhFhAcbalc+ZfO5b/+vkyAHS6CYVFCDtYR9Hi5qgdk31v23w==";
//        char assQRCode= ImpressaoXMLSAT();
    char path[50] = "file:///D:/Projeto%20C/Projeto%20C/CANC_SAT.xml";
    ImpressaoXMLCancSAT(path, param);
}

void AbrirGavetaElgin(){
          
}

void AbrirGaveta(){
        int pino= 1;
        int ti= 2;
        int tf= 20;
        AbrirGaveta(pino, ti, tf);
}

void SinalSonoro(){
        int qtd=4;
        int tempInicio=50;
        int tempFim=5;
        SinalSonoro(qtd, tempInicio, tempFim);
}

void statusImpressora() {
	printf("");
	//preencher o restante do codigo de acordo com a função e sua necessidade
    
}

// Programa principal
int main() {
    int num=11;
    carregarFuncoes();
    while (num!=0){
        exibirMenu();
        scanf("%i", &num);
        switch (num){
            case 1:
//                configurarConexao();
                break;
            case 2:
                abrirConexao();
                break;
            case 3:
                impressaoTexto();
                break;
            case 4:
                impressaoQRCode();
                break;
            case 5:
                impressaoCodigoBarras();
                break;
            case 6:
                ImpressaoXMLSAT();
                break;
            case 7:
                ImpressaoXMLCancSAT();
                break;
            case 8:
                AbrirGaveta();
                break;
            case 9:
                AbrirGaveta();
                break;
            case 10:
                SinalSonoro();
                break;
            case 0:
                printf("Programa encerrado");
                break;
        }
    }

	//preencher o restante do codigo de acordo com a função e sua necessidade
	
}

