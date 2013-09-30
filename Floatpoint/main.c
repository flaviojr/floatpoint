/*
 * main.c
 *
 *  Created on: 04/09/2013
 *      Author: flavioipiranga
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/floatpoint.h"
#include <gmp.h>
/*
 *
 */

#define STAMNUM  43
#define DTAMNUM  313
#define SPTAM  33
#define DPTAM  65
#define SPREC  1
#define DPREC  2


int main(int argc, char** argv) {
	//char *in;
	char* in1, *in2;
	char *binfp;
	double num=0, r;
	int prec;
	int op;
	normbin nb;

	if(!(in1 = malloc(sizeof(char)*1)))
	{
		fprintf(stderr, "Memoria insuficiente");
		exit(EXIT_FAILURE);
	}

	if(!(in2 = malloc(sizeof(char)*1)))
	{
		fprintf(stderr, "Memoria insuficiente");
		exit(EXIT_FAILURE);
	}

	printf("teads");
	do{
		printf("Bem-vindo ao software FP.\n\n");

		printf("Menu de opcoes:\n\n");
		printf("(1) Converter numero para binario.\n");
		printf("(2) Converter binario para numero.\n");
		printf("(3) Converter precisao simples para precisao dupla.\n");
		printf("(4) Converter precisao dupla para precisao simples.\n");
		printf("(5) Adicao.\n");
		printf("(6) Subtracao.\n");
		printf("(7) Multiplicacao.\n");
		printf("(8) Divisao.\n");
		printf("(9) Raiz quadrada.\n");
		printf("(0) Sair.\n\n");

		printf("Digite sua opcao:");
		scanf("%d", &op);

		switch(op){

		case 1:
			printf("Escolha precisao:\n");
			printf("1) Precisao simples\n");
			printf("2) Precisao dupla\n");
			scanf("%d", &prec);

			if(prec == 1){
				in1 = realloc(in1, sizeof(char)*100);
				nb.exp =malloc(sizeof(char)*9) ;
				nb.bin =malloc(sizeof(char)*24);
				nb.sinal = 0;
				nb.exp = "\0";
				nb.bin = "\0";
			}
			else {
				in1 = realloc(in1, sizeof(char)*DTAMNUM);
				nb.exp =malloc(sizeof(char)*12);
				nb.bin =malloc(sizeof(char)*53);
				nb.sinal = 0;
				nb.exp = "\0";
				nb.bin = "\0";
			}

			printf("Digite o numero real que deseja converter para binario:\n");
			scanf("%s", in1);

			if(!(NumToFp(&nb, in1, prec))){
				printf("trata excecao");
			}

			//if((strcmp(nb.bin, "00000000000000000000000") == 0 || strcmp(nb.bin, "0000000000000000000000000000000000000000000000000000") == 0))

			printf("Sinal: %d Expoente: %s Significante: %s\n", nb.sinal, nb.exp, nb.bin);
			printf("%d%s%s\n", nb.sinal, nb.exp, nb.bin);
			break;

		case 2:
			printf("Escolha precisao:\n");
			printf("1) Precisao simples\n");
			printf("2) Precisao dupla\n");
			scanf("%d", &prec);

			if(prec == 1){
				in1 = realloc(in1, sizeof(char)*SPTAM);
			}
			else in1 = realloc(in1, sizeof(char)*DPTAM);

			printf("Digite o numero binario que deseja converter para real:\n");
			scanf("%s", in1);

			r = FpToNum(in1);
			printf("Numero eh igual %.16lf\n", r);
			break;


		case 5:
			printf("Escolha precisao:\n");
			printf("1) Precisao simples\n");
			printf("2) Precisao dupla\n");
			scanf("%d", &prec);

			if(prec == 1){
				in1 = realloc(in1, sizeof(char)*STAMNUM);
				in2 = realloc(in2, sizeof(char)*STAMNUM);
			}
			else {
				in1 = realloc(in1, sizeof(char)*DTAMNUM);
				in2 = realloc(in2, sizeof(char)*DTAMNUM);
			}

			printf("Digite o primeiro numero:\n");
			scanf("%s", in1);
			printf("Digite o segundo numero:\n");
			scanf("%s", in2);

			Add(in1, in2, prec);
			break;

		case 6:

			printf("Escolha precisao:\n");
			printf("1) Precisao simples\n");
			printf("2) Precisao dupla\n");
			scanf("%d", &prec);

			if(prec == 1){
				in1 = realloc(in1, sizeof(char)*STAMNUM);
				in2 = realloc(in2, sizeof(char)*STAMNUM);
			}
			else {
				in1 = realloc(in1, sizeof(char)*DTAMNUM);
				in2 = realloc(in2, sizeof(char)*DTAMNUM);
			}

			printf("Digite o primeiro numero:\n");
			scanf("%s", in1);
			printf("Digite o segundo numero:\n");
			scanf("%s", in2);

			Sub(in1, in2, prec);
			break;
		case 7:

			printf("Escolha precisao:\n");
			printf("1) Precisao simples\n");
			printf("2) Precisao dupla\n");
			scanf("%d", &prec);

			if(prec == 1){
				in1 = realloc(in1, sizeof(char)*STAMNUM);
				in2 = realloc(in2, sizeof(char)*STAMNUM);
			}
			else {
				in1 = realloc(in1, sizeof(char)*DTAMNUM);
				in2 = realloc(in2, sizeof(char)*DTAMNUM);
			}

			printf("Digite o primeiro numero:\n");
			scanf("%s", in1);
			printf("Digite o segundo numero:\n");
			scanf("%s", in2);

			Multiplication(in1, in2, prec);
			break;


		}
	}while(op!=0);

	//BigNumToBin(in, prec);



	//BinToNum("00111111111111111111111111111111");

	return (EXIT_SUCCESS);
}
//21321312321312321321312
//12345678901234567000000
//0.000000000000000000000000000000000000012
