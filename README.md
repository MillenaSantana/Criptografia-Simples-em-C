# Criptografia Simples em C

## Integrantes

- Maria Eduarda Santos Guedes - 48216810
- Millena Dias Santana - 47555041
- Raquel Guimarães Pereira - 47813369
- Yasmin Helena Marinho Pinda - 47740981

Projeto desenvolvido para a disciplina **Algoritmo e Pensamento Computacional**.

O programa utiliza a **Cifra de César** combinada com sequências numéricas para realizar uma criptografia simples em uma palavra de até 15 letras.

## Funcionamento

O usuário informa:

- Uma palavra secreta;
- Um valor de SHIFT;
- Uma sequência numérica.

A criptografia utiliza:

**Deslocamento total = SHIFT + termo da sequência**

O programa utiliza duas etapas:

1. Cifra de César com SHIFT fixo;
2. Deslocamento utilizando os termos da sequência escolhida.

## Sequências utilizadas

### Fibonacci

```text
1, 1, 2, 3, 5, 8, 13...
```

### Progressão Aritmética (PA)

Cada termo é obtido adicionando uma razão ao termo anterior.

Exemplo:

```text
5, 8, 11, 14...
```

Razão:

```text
3
```

### Progressão Geométrica (PG)

Cada termo é obtido multiplicando o termo anterior por uma razão.

Exemplo:

```text
2, 4, 8, 16...
```

Razão:

```text
2
```

### Números Primos

```text
2, 3, 5, 7, 11, 13, 17...
```

## Menu do programa

```text
1 - Inserir dados
2 - Executar criptografia
3 - Sair
```

Na opção de inserir dados, o usuário informa a palavra, o SHIFT e a sequência escolhida.

Na opção de executar, o programa realiza a criptografia e apresenta o resultado.

## Arquivos

O programa gera dois arquivos:

### resultado_criptografia.txt

Armazena o resultado da última criptografia.

### log_execucao.txt

Armazena o histórico das execuções realizadas.

## Testes

Foram realizados testes utilizando:

```text
Palavra: CORACAO
SHIFT: 3
```

Resultados:

| Sequência | Resultado |
|---|---|
| Fibonacci | `GSWGKLE` |
| PA (razão 3) | `GVBNSTK` |
| PG (razão 2) | `GTYLVJD` |
| Primos | `HUZKQQI` |


## Informações

**Disciplina:** Algoritmo e Pensamento Computacional  
**Professor:** Francisco de Assis Cavallaro  
**Linguagem:** C
