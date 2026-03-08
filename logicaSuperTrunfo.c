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
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

// Função para coletar dados simples (números, palavras únicas)
// Recebe a pergunta (prompt), a máscara do tipo de dado (format) e o endereço da variável
void inputWord(const char *prompt, const char *format, void *variable) {
    printf("%s", prompt);
    scanf(format, variable);
    clearBuffer(); // Limpa o '\n' ou qualquer lixo residual após a leitura
}

// Função para coletar textos longos com espaços (frases)
// Recebe a pergunta (prompt), o vetor de caracteres (variable) e o tamanho máximo
void inputPhrase(const char *prompt, char *variable, int maxSize) {
    printf("%s", prompt);
    fgets(variable, maxSize, stdin);
    variable[strcspn(variable, "\n")] = 0; // Remove a quebra de linha que o fgets captura
}

// Esta função pede os dados, faz os cálculos e devolve uma carta pronta
TrumpCard registerCard(int cardNumber) {
    TrumpCard card; // Criamos uma carta temporária para preencher
    
    printf("\n--- REGISTO DA CARTA %d ---\n", cardNumber);
    
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
    printf("\nResumo da Carta %d:\n", cardNumber);
    printf("Densidade Populacional de %s: %.2f habitantes/km2 \n", card.city, card.populationDensity);
    printf("PIB per capita de %s: %.2f Reais \n", card.city, card.gdpPerCapita);
    
    return card; // Devolve a carta preenchida para quem chamou a função
}

// Esta função usa o switch para devolver o valor numérico do atributo escolhido.
// Também guarda o nome do atributo e avisa se a regra é invertida (menor vence).
float getAttributeValue(TrumpCard card, int option, char *attributeName, int *isInvertedRule) {
    *isInvertedRule = 0; // Por norma, o maior valor vence

    switch(option) {
        case 1:
            strcpy(attributeName, "Populacao");
            return (float) card.population;
        case 2:
            strcpy(attributeName, "Area");
            return card.area;
        case 3:
            strcpy(attributeName, "PIB");
            return card.gdp;
        case 4:
            strcpy(attributeName, "Pontos Turisticos");
            return (float) card.touristAttractions;
        case 5:
            strcpy(attributeName, "Densidade Populacional");
            *isInvertedRule = 1; // REGRA ESPECIAL: Neste atributo, o MENOR vence!
            return card.populationDensity;
        case 6:
            strcpy(attributeName, "PIB per Capita");
            return card.gdpPerCapita;
        case 7:
            strcpy(attributeName, "IDH");
            return card.hdi;
        default:
            strcpy(attributeName, "Invalido");
            return 0.0;
    }
}

// Comparar um único atributo e devolver quem ganhou (1 para carta 1, 2 para carta 2, 0 empate)
int compareAttribute(TrumpCard card1, TrumpCard card2, int option) {
    char attributeName[30];
    int isInverted;
    float card1AttributeValue = getAttributeValue(card1, option, attributeName, &isInverted);
    float card2AttributeValue = getAttributeValue(card2, option, attributeName, &isInverted);

    printf("\nComparando %s:\n", attributeName);
    printf("Carta 1 (%s): %.2f X ", card1.city, card1AttributeValue);
    printf("Carta 2 (%s): %.2f\n", card2.city, card2AttributeValue);

    if (card1AttributeValue == card2AttributeValue) {
        printf("-> Empate neste atributo!\n");
        return 0;
    }

    // Lógica para decidir quem ganha baseada na regra (normal vs invertida)
    if ((!isInverted && card1AttributeValue > card2AttributeValue) || (isInverted && card1AttributeValue < card2AttributeValue)) {
        printf("-> Carta 1 (%s) venceu em %s!\n", card1.city, attributeName);
        return 1;
    } else {
        printf("-> Carta 2 (%s) venceu em %s!\n", card2.city, attributeName);
        return 2;
    }
}

// ==========================================
// FUNÇÃO PRINCIPAL
// ==========================================

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    TrumpCard card1, card2;
    int choice1 = 0, choice2 = 0;
    int card1Points = 0, card2Points = 0;
    
    printf("\n=== Desafio Super Trunfo - Paises ===\n");
    printf("Vamos cadastrar duas cartas, e depois você vai escolher 2 atributos para comparar! \n");

    // ==========================================
    // CARTA 1
    // ------------------------------------------
    // Sugestão: GYN62, Goias, Goiania, 1536097, 739.2, 15, 120000.0, 0.799
    // ==========================================
    card1 = registerCard(1);

    // ==========================================
    // CARTA 2
    // ------------------------------------------
    // Sugestão: SAMPA11, Sao Paulo, Sao Paulo, 12325232, 1521.11, 25, 500000.0, 0.805
    // ==========================================
    card2 = registerCard(2);

    // MENU INTERATIVO
    printf("\n=== MENU DE BATALHA ===\n");
    printf("Escolha os atributos para a comparacao:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n6 - PIB per Capita\n7 - IDH\n");

    do {
        inputWord("\nEscolha o PRIMEIRO atributo (1 a 7): ", "%d", &choice1);
        if (choice1 < 1 || choice1 > 7) {
            printf("Erro: Escolha um numero valido entre 1 e 7!\n");
        }
    } while (choice1 < 1 || choice1 > 7);
    
    do {
        inputWord("Escolha o SEGUNDO atributo (diferente do primeiro, 1 a 7): ", "%d", &choice2);
        if (choice1 == choice2) {
            printf("Erro: Tem de escolher um atributo diferente!\n");
        } else if (choice2 < 1 || choice2 > 7) {
            printf("Erro: Escolha um numero valido entre 1 e 7!\n");
        }
    } while (choice1 == choice2 || choice2 < 1 || choice2 > 7);

    // ==========================================
    // RESOLUÇÃO DA BATALHA
    // ------------------------------------------
    // Sistema de pontuação justo: cada vitória de um atributo dá 1 ponto à carta.
    // ==========================================
    printf("\n=== RESULTADOS DA BATALHA ===");
    
    // Compara o primeiro atributo
    int winner1 = compareAttribute(card1, card2, choice1);
    if (winner1 == 1) card1Points++;
    else if (winner1 == 2) card2Points++;

    // Compara o segundo atributo
    int winner2 = compareAttribute(card1, card2, choice2);
    if (winner2 == 1) card1Points++;
    else if (winner2 == 2) card2Points++;

    // Declara o Vencedor Final
    printf("\n=== VENCEDOR FINAL ===\n");
    if (card1Points > card2Points) {
        printf("A Carta 1 (%s) e a grande VENCEDORA com %d pontos!\n", card1.city, card1Points);
    } else if (card2Points > card1Points) {
        printf("A Carta 2 (%s) e a grande VENCEDORA com %d pontos!\n", card2.city, card2Points);
    } else {
        printf("A batalha terminou num EMPATE (1x1)!\n");
    }

    // Como rodar/testar?
    // Veja no Readme!

    return 0;
}
