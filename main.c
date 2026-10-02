#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LETRAS 15

/* =========================================================
   PESSOA 1(Duda) - CRIPTOGRAFIA
   ========================================================= */

/* Primeira camada: cifra de Cesar com SHIFT fixo */
char cifrarCaesar(char letra, int shift)
{
    if (letra >= 'A' && letra <= 'Z')
    {
        shift = shift % 26;

        letra = letra + shift;

        if (letra > 'Z')
        {
            letra = letra - 26;
        }
    }

    return letra;
}

char cifrarLetra(char letra, int shiftFixo, int termoSequencia)
{
    int deslocamentoTotal;

    deslocamentoTotal = shiftFixo + termoSequencia;
    deslocamentoTotal = deslocamentoTotal % 26;

    if (letra >= 'A' && letra <= 'Z')
    {
        letra = letra + deslocamentoTotal;

        if (letra > 'Z')
        {
            letra = letra - 26;
        }
    }

    return letra;
}


/* =========================================================
   PESSOA 2(Yas) - SEQUENCIAS MATEMATICAS
   ========================================================= */


int fibonacci(int posicao)
{
    int a = 1;
    int b = 1;
    int proximo;

    if (posicao == 0 || posicao == 1)
    {
        return 1;
    }

    for (int i = 2; i <= posicao; i++)
    {
        proximo = a + b;
        a = b;
        b = proximo;
    }

    return b;
}



int termoPA(int posicao, int razao)
{
    return 1 + (posicao * razao);
}



int termoPG(int posicao, int razao)
{
    int termo = 1;

    for (int i = 0; i < posicao; i++)
    {
        termo = termo * razao;
    }

    return termo;
}


int ehPrimo(int numero)
{
    if (numero < 2)
    {
        return 0;
    }

    for (int i = 2; i < numero; i++)
    {
        if (numero % i == 0)
        {
            return 0;
        }
    }

    return 1;
}


int termoPrimo(int posicao)
{
    int numero = 2;
    int contador = 0;

    while (1)
    {
        if (ehPrimo(numero))
        {
            if (contador == posicao)
            {
                return numero;
            }

            contador++;
        }

        numero++;
    }
}


/* =========================================================
   (Rah) ESCOLHA DA SEQUENCIA
   ========================================================= */

int obterTermoSequencia(int tipo, int posicao, int razao)
{
    if (tipo == 1)
    {
        return fibonacci(posicao);
    }

    if (tipo == 2)
    {
        return termoPA(posicao, razao);
    }

    if (tipo == 3)
    {
        return termoPG(posicao, razao);
    }

    if (tipo == 4)
    {
        return termoPrimo(posicao);
    }

    return 0;
}


const char* nomeSequencia(int tipo)
{
    if (tipo == 1)
    {
        return "Fibonacci";
    }

    if (tipo == 2)
    {
        return "PA";
    }

    if (tipo == 3)
    {
        return "PG";
    }

    if (tipo == 4)
    {
        return "Primos";
    }

    return "Desconhecida";
}


/* =========================================================
   PESSOA 4 - ARQUIVO DE RESULTADO
   ========================================================= */

void salvarResultado(
    char palavraOriginal[],
    char palavraCodificada[],
    int shift,
    int tipoSequencia,
    int razao,
    int letras)
{
    FILE *arquivo;

    arquivo = fopen("resultado_criptografia.txt", "w");

    if (arquivo == NULL)
    {
        printf("\nErro ao criar o arquivo de resultado!\n");
        return;
    }

    fprintf(arquivo, "RESULTADO DA CRIPTOGRAFIA\n");
    fprintf(arquivo, "==========================\n");
    fprintf(arquivo, "Palavra original: %s\n", palavraOriginal);
    fprintf(arquivo, "Palavra codificada: %s\n", palavraCodificada);
    fprintf(arquivo, "SHIFT: %d\n", shift);
    fprintf(arquivo, "Tipo: %s\n", nomeSequencia(tipoSequencia));

    if (tipoSequencia == 2 || tipoSequencia == 3)
    {
        fprintf(arquivo, "Razao: %d\n", razao);
    }

    fprintf(arquivo, "Letras: %d\n", letras);

    fclose(arquivo);

    printf("\nResultado salvo em resultado_criptografia.txt\n");
}


/* =========================================================
   PESSOA 4 - LOG DE EXECUCAO
   ========================================================= */

void salvarLog(
    char palavraOriginal[],
    char palavraCodificada[],
    int shift,
    int tipoSequencia,
    int razao,
    int letras)
{
    FILE *arquivo;

    arquivo = fopen("log_execucao.txt", "a");

    if (arquivo == NULL)
    {
        printf("\nErro ao criar o arquivo de log!\n");
        return;
    }

    fprintf(arquivo, "====================================\n");
    fprintf(arquivo, "LOG DE EXECUCAO\n");
    fprintf(arquivo, "====================================\n");

    fprintf(arquivo, "Palavra original: %s\n", palavraOriginal);
    fprintf(arquivo, "SHIFT: %d\n", shift);
    fprintf(arquivo, "Sequencia: %s\n", nomeSequencia(tipoSequencia));

    if (tipoSequencia == 2 || tipoSequencia == 3)
    {
        fprintf(arquivo, "Razao: %d\n", razao);
    }

    fprintf(arquivo, "Palavra criptografada: %s\n", palavraCodificada);
    fprintf(arquivo, "Quantidade de letras: %d\n", letras);
    fprintf(arquivo, "Execucao concluida.\n");

    fprintf(arquivo, "====================================\n\n");

    fclose(arquivo);
}


/* =========================================================
   PROGRAMA PRINCIPAL
   ========================================================= */

int main()
{
    char palavraSecreta[MAX_LETRAS + 1] = "";
    char palavraCodificada[MAX_LETRAS + 1] = "";

    int shiftFixo = 0;
    int tipoSequencia = 0;
    int razao = 1;

    int opcaoMenu = 0;
    int dadosInseridos = 0;
    int tamanho = 0;

    do
    {
        printf("\n");
        printf("====================================\n");
        printf("       CRIPTOGRAFIA SIMPLES\n");
        printf("====================================\n");
        printf("1 - Inserir dados\n");
        printf("2 - Executar criptografia\n");
        printf("3 - Sair\n");
        printf("====================================\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoMenu);

        while (getchar() != '\n');


        /* =================================================
           OPCAO 1 - INSERIR DADOS
           ================================================= */

        if (opcaoMenu == 1)
        {
            printf("\nDigite a palavra secreta (ate 15 letras): ");

            fgets(
                palavraSecreta,
                sizeof(palavraSecreta),
                stdin
            );

            palavraSecreta[
                strcspn(palavraSecreta, "\n")
            ] = '\0';

            tamanho = strlen(palavraSecreta);

            if (tamanho == 0)
            {
                printf("\nA palavra nao pode ser vazia.\n");

                dadosInseridos = 0;

                continue;
            }

            if (tamanho > MAX_LETRAS)
            {
                printf("\nA palavra deve ter no maximo 15 letras.\n");

                dadosInseridos = 0;

                continue;
            }


           

            int palavraValida = 1;

            for (int i = 0; i < tamanho; i++)
            {
                if (!isalpha((unsigned char)palavraSecreta[i]))
                {
                    palavraValida = 0;
                    break;
                }

                palavraSecreta[i] =
                    toupper((unsigned char)palavraSecreta[i]);
            }

            if (!palavraValida)
            {
                printf(
                    "\nUse somente letras, sem numeros, espacos ou acentos.\n"
                );

                dadosInseridos = 0;

                continue;
            }


            printf("\nDigite o valor do SHIFT: ");
            scanf("%d", &shiftFixo);

            while (getchar() != '\n');


            

            printf("\n");
            printf("====================================\n");
            printf("       ESCOLHA A SEQUENCIA\n");
            printf("====================================\n");
            printf("1 - Fibonacci\n");
            printf("2 - PA\n");
            printf("3 - PG\n");
            printf("4 - Numeros Primos\n");
            printf("====================================\n");

            printf("Escolha uma sequencia: ");
            scanf("%d", &tipoSequencia);

            while (getchar() != '\n');


            if (tipoSequencia < 1 || tipoSequencia > 4)
            {
                printf("\nSequencia invalida.\n");

                dadosInseridos = 0;

                continue;
            }


            razao = 1;

            if (tipoSequencia == 2)
            {
                printf("\nDigite a razao da PA: ");
                scanf("%d", &razao);

                while (getchar() != '\n');

                if (razao <= 0)
                {
                    printf("\nA razao deve ser maior que zero.\n");

                    dadosInseridos = 0;

                    continue;
                }
            }

            if (tipoSequencia == 3)
            {
                printf("\nDigite a razao da PG: ");
                scanf("%d", &razao);

                while (getchar() != '\n');

                if (razao <= 0)
                {
                    printf("\nA razao deve ser maior que zero.\n");

                    dadosInseridos = 0;

                    continue;
                }
            }


            dadosInseridos = 1;

            printf("\nDados inseridos com sucesso!\n");

            printf("Palavra: %s\n", palavraSecreta);
            printf("SHIFT: %d\n", shiftFixo);
            printf("Sequencia: %s\n", nomeSequencia(tipoSequencia));

            if (tipoSequencia == 2 || tipoSequencia == 3)
            {
                printf("Razao: %d\n", razao);
            }
        }


        /* =================================================
           OPCAO 2 - CRIPTOGRAFAR
           ================================================= */

        else if (opcaoMenu == 2)
        {
            if (!dadosInseridos)
            {
                printf(
                    "\nPrimeiro escolha a opcao 1 e insira os dados.\n"
                );

                continue;
            }


            for (int i = 0; i < tamanho; i++)
            {
                int termo;

                termo = obterTermoSequencia(
                    tipoSequencia,
                    i,
                    razao
                );

                palavraCodificada[i] =
                    cifrarLetra(
                        palavraSecreta[i],
                        shiftFixo,
                        termo
                    );
            }


            palavraCodificada[tamanho] = '\0';



            printf("\n");
            printf("====================================\n");
            printf("             RESULTADO\n");
            printf("====================================\n");

            printf(
                "Palavra original: %s\n",
                palavraSecreta
            );

            printf(
                "SHIFT: %d\n",
                shiftFixo
            );

            printf(
                "Sequencia: %s\n",
                nomeSequencia(tipoSequencia)
            );

            if (tipoSequencia == 2 || tipoSequencia == 3)
            {
                printf(
                    "Razao: %d\n",
                    razao
                );
            }

            printf(
                "Palavra criptografada: %s\n",
                palavraCodificada
            );

            printf(
                "Quantidade de letras: %d\n",
                tamanho
            );

            printf("====================================\n");



            salvarResultado(
                palavraSecreta,
                palavraCodificada,
                shiftFixo,
                tipoSequencia,
                razao,
                tamanho
            );

            salvarLog(
                palavraSecreta,
                palavraCodificada,
                shiftFixo,
                tipoSequencia,
                razao,
                tamanho
            );
        }


        /* =================================================
           OPCAO 3 - SAIR
           ================================================= */

        else if (opcaoMenu == 3)
        {
            printf("\nPrograma encerrado!\n");
        }


        /* =================================================
           OPCAO INVALIDA
           ================================================= */

        else
        {
            printf("\nOpcao invalida!\n");
        }

    }
    while (opcaoMenu != 3);


    return 0;
}
