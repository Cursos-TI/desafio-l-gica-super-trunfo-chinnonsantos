#include <stdio.h>
#include <string.h> // Necessário para a função strcspn()

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// As regras estão descritas no README do projeto

// ==========================================
// DEFINIÇÃO DAS ESTRUTURAS (STRUCTS)
// -------------------------------------------
// Código da Carta `code`, Estado `state`, Cidade `city`, População `population`, 
// Área `area`, Pontos Turísticos `touristAttractions`, PIB `gdp`, IDH `hdi`
//
// Variáveis dinâmicas calculadas posteriormente:
// Densidade Populacional `populationDensity`, PIB per capita `gdpPerCapita`
// ==========================================

// Criamos um "molde" (struct) para as nossas Cartas Trunfo (TrumpCard)
typedef struct {
    char code[11];
    char state[31];
    char city[31];
    unsigned int population;
    float area;
    unsigned int touristAttractions;
    float gdp;
    float hdi;
    float populationDensity;
    float gdpPerCapita;
} TrumpCard;

// ==========================================
// FUNÇÕES AUXILIARES
// ==========================================

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

// Função para coletar dados simples (números, palavras únicas)
// Recebe a pergunta (prompt), a máscara do tipo de dado (formato) e o endereço da variável
void inputWord(const char *prompt, const char *formato, void *variavel) {
    printf("%s", prompt);
    scanf(formato, variavel);
    limparBuffer(); // Limpa o '\n' ou qualquer lixo residual após a leitura
}

// Função para coletar textos longos com espaços (frases)
// Recebe a pergunta (prompt), o vetor de caracteres (variavel) e o tamanho máximo
void inputPhrase(const char *prompt, char *variavel, int tamanhoMaximo) {
    printf("%s", prompt);
    fgets(variavel, tamanhoMaximo, stdin);
    variavel[strcspn(variavel, "\n")] = 0; // Remove a quebra de linha que o fgets captura
}

// Esta função pede os dados, faz os cálculos e devolve uma carta pronta
TrumpCard registarCarta(int numeroCarta) {
    TrumpCard card; // Criamos uma carta temporária para preencher
    
    printf("\n--- REGISTO DA CARTA %d ---\n", numeroCarta);
    
    inputWord("Digite o codigo da cidade (Alfanumerico ate 10 caracteres): \n", "%10s", card.code);
    inputPhrase("Digite o estado da cidade (Alfanumerico ate 30 caracteres): \n", card.state, 31);
    inputPhrase("Digite o nome da cidade (Alfanumerico ate 30 caracteres): \n", card.city, 31);
    inputWord("Digite a populacao da cidade (Entre 0 a 4294967295): \n", "%u", &card.population);
    inputWord("Digite a area da cidade (em km2 - somente numeros): \n", "%f", &card.area);
    inputWord("Digite o numero de pontos turisticos da cidade: \n", "%u", &card.touristAttractions);
    inputWord("Digite o PIB da cidade (em milhoes de Reais): \n", "%f", &card.gdp);
    inputWord("Digite o IDH da cidade: \n", "%f", &card.hdi);

    // Realiza os cálculos dinâmicos dentro da própria função
    card.populationDensity = card.population / card.area; 
    card.gdpPerCapita = (card.population > 0) ? (card.gdp * 1000000) / card.population : 0; 
    
    // Mostra um pequeno resumo após o registo
    printf("\nResumo da Carta %d:\n", numeroCarta);
    printf("Densidade Populacional de %s: %.2f habitantes/km2 \n", card.city, card.populationDensity);
    printf("PIB per capita de %s: %.2f Reais \n", card.city, card.gdpPerCapita);
    
    return card; // Devolve a carta preenchida para quem chamou a função
}

// Esta função usa o switch para devolver o valor numérico do atributo escolhido.
// Também guarda o nome do atributo e avisa se a regra é invertida (menor vence).
float obterValorAtributo(TrumpCard card, int opcao, char *nomeAtributo, int *regraInvertida) {
    *regraInvertida = 0; // Por norma, o maior valor vence

    switch(opcao) {
        case 1:
            strcpy(nomeAtributo, "Populacao");
            return (float) card.population;
        case 2:
            strcpy(nomeAtributo, "Area");
            return card.area;
        case 3:
            strcpy(nomeAtributo, "PIB");
            return card.gdp;
        case 4:
            strcpy(nomeAtributo, "Pontos Turisticos");
            return (float) card.touristAttractions;
        case 5:
            strcpy(nomeAtributo, "Densidade Populacional");
            *regraInvertida = 1; // REGRA ESPECIAL: Neste atributo, o MENOR vence!
            return card.populationDensity;
        case 6:
            strcpy(nomeAtributo, "PIB per Capita");
            return card.gdpPerCapita;
        case 7:
            strcpy(nomeAtributo, "IDH");
            return card.hdi;
        default:
            strcpy(nomeAtributo, "Invalido");
            return 0.0;
    }
}

// Comparar um único atributo e devolver quem ganhou (1 para carta 1, 2 para carta 2, 0 empate)
int compararAtributo(TrumpCard card1, TrumpCard card2, int opcao) {
    char nome[30];
    int invertido;
    float card1AttributeValue = obterValorAtributo(card1, opcao, nome, &invertido);
    float card2AttributeValue = obterValorAtributo(card2, opcao, nome, &invertido);

    printf("\nComparando %s:\n", nome);
    printf("Carta 1 (%s): %.2f X ", card1.city, card1AttributeValue);
    printf("Carta 2 (%s): %.2f\n", card2.city, card2AttributeValue);

    if (card1AttributeValue == card2AttributeValue) {
        printf("-> Empate neste atributo!\n");
        return 0;
    }

    // Lógica para decidir quem ganha baseada na regra (normal vs invertida)
    if ((!invertido && card1AttributeValue > card2AttributeValue) || (invertido && card1AttributeValue < card2AttributeValue)) {
        printf("-> Carta 1 (%s) venceu em %s!\n", card1.city, nome);
        return 1;
    } else {
        printf("-> Carta 2 (%s) venceu em %s!\n", card2.city, nome);
        return 2;
    }
}

// ==========================================
// FUNÇÃO PRINCIPAL
// ==========================================

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    TrumpCard card1, card2;
    int escolha1 = 0, escolha2 = 0;
    int pontosCarta1 = 0, pontosCarta2 = 0;
    
    printf("\n=== Desafio Super Trunfo - Paises ===\n");
    printf("Vamos cadastrar duas cartas, e depois você vai escolher 2 atributos para comparar! \n");

    // ==========================================
    // CARTA 1
    // ------------------------------------------
    // Sugestão: GYN62, Goias, Goiania, 1536097, 739.2, 15, 120000.0, 0.799
    // ==========================================
    card1 = registarCarta(1);

    // ==========================================
    // CARTA 2
    // ------------------------------------------
    // Sugestão: SAMPA11, Sao Paulo, Sao Paulo, 12325232, 1521.11, 25, 500000.0, 0.805
    // ==========================================
    card2 = registarCarta(2);

    // MENU INTERATIVO
    printf("\n=== MENU DE BATALHA ===\n");
    printf("Escolha os atributos para a comparacao:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n6 - PIB per Capita\n7 - IDH\n");
    
    inputWord("\nEscolha o PRIMEIRO atributo (1 a 7): ", "%d", &escolha1);
    
    do {
        inputWord("Escolha o SEGUNDO atributo (diferente do primeiro, 1 a 7): ", "%d", &escolha2);
        if (escolha1 == escolha2) {
            printf("Erro: Tem de escolher um atributo diferente!\n");
        }
    } while (escolha1 == escolha2);

    // ==========================================
    // RESOLUÇÃO DA BATALHA
    // ------------------------------------------
    // Sistema de pontuação justo: cada vitória de um atributo dá 1 ponto à carta.
    // ==========================================
    printf("\n=== RESULTADOS DA BATALHA ===");
    
    // Compara o primeiro atributo
    int vencedor1 = compararAtributo(card1, card2, escolha1);
    if (vencedor1 == 1) pontosCarta1++;
    else if (vencedor1 == 2) pontosCarta2++;

    // Compara o segundo atributo
    int vencedor2 = compararAtributo(card1, card2, escolha2);
    if (vencedor2 == 1) pontosCarta1++;
    else if (vencedor2 == 2) pontosCarta2++;

    // Declara o Vencedor Final
    printf("\n=== VENCEDOR FINAL ===\n");
    if (pontosCarta1 > pontosCarta2) {
        printf("A Carta 1 (%s) e a grande VENCEDORA com %d pontos!\n", card1.city, pontosCarta1);
    } else if (pontosCarta2 > pontosCarta1) {
        printf("A Carta 2 (%s) e a grande VENCEDORA com %d pontos!\n", card2.city, pontosCarta2);
    } else {
        printf("A batalha terminou num EMPATE (1x1)!\n");
    }

    // Como rodar/testar?
    // Veja no Readme!

    return 0;
}
