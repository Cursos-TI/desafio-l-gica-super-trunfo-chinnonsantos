#include <stdio.h>
#include <string.h> // Necessário para a função strcspn()

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// As regras estão descritas no README do projeto

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Código da Carta `cardCode`, Estado `cardState`, Cidade `cardCity`, População `cardPopulation`, 
    // Área `cardArea`, Pontos Turísticos `cardTouristAttractions`, PIB `cardGDP`, IDH `cardHDI`
    char cardCode1[11], cardCode2[11], cardState1[31], cardState2[31], cardCity1[31], cardCity2[31];
    unsigned int cardPopulation1, cardPopulation2, cardTouristAttractions1, cardTouristAttractions2;
    float cardArea1, cardArea2, cardGDP1, cardGDP2, cardHDI1, cardHDI2;
    // Variaveis dinâmica: PIB per capita `cardGDPPerCapita`, Densidade Populacional `cardPopulationDensity`
    float cardGDPPerCapita1, cardGDPPerCapita2, cardPopulationDensity1, cardPopulationDensity2;
    
    printf("\n\nDesafio Super Trunfo - Paises \n");
    printf("Vamos cadastrar duas cartas, comparando a densidade populacional! \n\n");

    // ==========================================
    // CARTA 1
    // ------------------------------------------
    // Sugestão: GYN62, Goias, Goiania, 1536097, 739.2, 15, 120000.0, 0.799
    // ==========================================
    printf("Digite o codigo da cidade 1 (Alfanumerico ate 10 caracteres): \n");
    scanf("%s", cardCode1);
    limparBuffer(); // Limpa o '\n' deixado pelo scanf acima

    printf("Digite o estado da cidade 1 (Alfanumerico ate 30 caracteres): \n");
    fgets(cardState1, 31, stdin);
    cardState1[strcspn(cardState1, "\n")] = 0; // Remove o caractere de nova linha

    printf("Digite o nome da cidade 1 (Alfanumerico ate 30 caracteres): \n");
    fgets(cardCity1, 31, stdin);
    cardCity1[strcspn(cardCity1, "\n")] = 0; // Remove o caractere de nova linha

    printf("Digite a populacao da cidade 1 (Entre 0 a 4.294.967.295): \n");
    scanf("%i", &cardPopulation1);
    limparBuffer(); // Limpa o '\n' deixado pelo scanf acima

    printf("Digite a area da cidade 1 (em km2 - somente numeros, permitido decimais): \n");
    scanf("%f", &cardArea1);
    limparBuffer(); // Limpa o '\n' deixado pelo scanf acima

    printf("Digite o numero de pontos turisticos da cidade 1 (Entre 0 a 4.294.967.295): \n");
    scanf("%u", &cardTouristAttractions1);
    limparBuffer(); // Limpa o '\n' deixado pelo scanf acima

    printf("Digite o PIB da cidade 1 (em milhoes de Reais - somente numeros, permitido decimais): \n");
    scanf("%f", &cardGDP1);
    limparBuffer(); // Limpa o '\n' deixado pelo scanf acima

    printf("Digite o IDH da cidade 1 (somente numeros, permitido decimais): \n");
    scanf("%f", &cardHDI1);
    limparBuffer(); // Limpa o '\n' deixado pelo scanf acima

    // Calcular Densidade Populacional e PIB per capita para a Carta 1
    cardPopulationDensity1 = cardPopulation1 / cardArea1; // Densidade = População / Área
    cardGDPPerCapita1 = (cardPopulation1 > 0) ? (cardGDP1 * 1000000) / cardPopulation1 : 0; // PIB per capita = PIB total / População
    printf("Densidade Populacional da cidade %s: %.2f habitantes/km2 \n", cardCity1, cardPopulationDensity1);
    printf("PIB per capita da cidade %s: %.2f Reais \n\n", cardCity1, cardGDPPerCapita1);

    // ==========================================
    // CARTA 2
    // ------------------------------------------
    // Sugestão: SAMPA11, Sao Paulo, Sao Paulo, 12325232, 1521.11, 25, 500000.0, 0.805
    // ==========================================
    printf("Digite o codigo da cidade 2 (Alfanumerico ate 10 caracteres): \n");
    scanf("%s", cardCode2);
    limparBuffer(); // Limpa o '\n' deixado pelo scanf acima

    printf("Digite o estado da cidade 2 (Alfanumerico ate 30 caracteres): \n");
    fgets(cardState2, 31, stdin);
    cardState2[strcspn(cardState2, "\n")] = 0; // Remove o caractere de nova linha

    printf("Digite o nome da cidade 2 (Alfanumerico ate 30 caracteres): \n");
    fgets(cardCity2, 31, stdin);
    cardCity2[strcspn(cardCity2, "\n")] = 0; // Remove o caractere de nova linha

    printf("Digite a populacao da cidade 2 (Entre 0 a 4.294.967.295): \n");
    scanf("%i", &cardPopulation2);
    limparBuffer(); // Limpa o '\n' deixado pelo scanf acima

    printf("Digite a area da cidade 2 (em km2 - somente numeros, permitido decimais): \n");
    scanf("%f", &cardArea2);
    limparBuffer(); // Limpa o '\n' deixado pelo scanf acima

    printf("Digite o numero de pontos turisticos da cidade 2 (Entre 0 a 4.294.967.295): \n");
    scanf("%u", &cardTouristAttractions2);
    limparBuffer(); // Limpa o '\n' deixado pelo scanf acima

    printf("Digite o PIB da cidade 2 (em milhoes de Reais - somente numeros, permitido decimais): \n");
    scanf("%f", &cardGDP2);
    limparBuffer(); // Limpa o '\n' deixado pelo scanf acima

    printf("Digite o IDH da cidade 2 (somente numeros, permitido decimais): \n");
    scanf("%f", &cardHDI2);
    limparBuffer(); // Limpa o '\n' deixado pelo scanf acima

    // Calcular Densidade Populacional e PIB per capita para a Carta 2
    cardPopulationDensity2 = cardPopulation2 / cardArea2; // Densidade = População / Área
    cardGDPPerCapita2 = (cardPopulation2 > 0) ? (cardGDP2 * 1000000) / cardPopulation2 : 0; // PIB per capita = PIB total / População
    printf("Densidade Populacional da cidade %s: %.2f habitantes/km2 \n", cardCity2, cardPopulationDensity2);
    printf("PIB per capita da cidade %s: %.2f Reais \n\n", cardCity2, cardGDPPerCapita2);

    // ==========================================
    // RESULTADO
    // ------------------------------------------
    // O critério de comparação escolhido para este desafio é a Densidade Populacional (cardPopulationDensity)
    // Menor densidade = Vencedora!
    // ==========================================
    if (cardPopulationDensity1 < cardPopulationDensity2) {
        printf(
            "A cidade %s tem a menor densidade populacional (%.2f habitantes/km2), sendo a vencedora! \n",
            cardCity1,
            cardPopulationDensity1
        );
    } else if (cardPopulationDensity2 < cardPopulationDensity1) {
        printf(
            "A cidade %s tem a menor densidade populacional (%.2f habitantes/km2), sendo a vencedora! \n",
            cardCity2,
            cardPopulationDensity2
        );
    } else {
        printf("Ambas as cidades têm a mesma densidade populacional, nenhuma venceu! \n");
    }

    // Como rodar/testar?
    // Veja no Readme!

    return 0;
}
