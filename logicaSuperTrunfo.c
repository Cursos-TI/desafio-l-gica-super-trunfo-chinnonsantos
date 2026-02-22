#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// As regras estão descritas no README do projeto

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Código da Carta `cardCode`, Estado `cardState`, Cidade `cardCity`, População `cardPopulation`, 
    // Área `cardArea`, Pontos Turísticos `cardTouristAttractions`, PIB `cardGDP`, IDH `cardHDI`
    char cardCode1[10], cardCode2[10], cardState1[30], cardState2[30], cardCity1[30], cardCity2[30];
    unsigned long long cardPopulation1, cardPopulation2;
    unsigned int cardTouristAttractions1, cardTouristAttractions2;
    float cardArea1, cardArea2, cardGDP1, cardGDP2, cardHDI1, cardHDI2;
    
    printf("\n\nDesafio Super Trunfo - Paises \n");
    printf("Vamos cadastrar duas cartas, comparando a densidade populacional! \n\n");

    // Cadastro da Carta 1 pelo Usuário (Terminal):
    // Sugestão: GYN62, Goiás, Goiânia, 1536097, 739.2, 15, 120000.0, 0.799
    printf("Digite o codigo da cidade 1 (Alfanumerico ate 10 caracteres): \n");
    scanf("%s", cardCode1);

    printf("Digite o estado da cidade 1 (Alfanumerico ate 30 caracteres): \n");
    scanf("%s", cardState1);

    printf("Digite o nome da cidade 1 (Alfanumerico ate 30 caracteres): \n");
    scanf("%s", cardCity1);

    printf("Digite a populacao da cidade 1 (Entre 0 e 9 quintilhoes): \n");
    scanf("%llu", &cardPopulation1);

    printf("Digite a area da cidade 1 (em km2 - somente numeros, permitido decimais): \n");
    scanf("%f", &cardArea1);

    printf("Digite o numero de pontos turisticos da cidade 1 (Entre 0 a 4.294.967.295): \n");
    scanf("%u", &cardTouristAttractions1);

    printf("Digite o PIB da cidade 1 (em milhoes de Reais - somente numeros, permitido decimais): \n");
    scanf("%f", &cardGDP1);

    printf("Digite o IDH da cidade 1 (somente numeros, permitido decimais): \n");
    scanf("%f", &cardHDI1);

    // Cadastro da Carta 2 pelo Usuário (Terminal):
    // Sugestão: SAMPA11, São Paulo, São Paulo, 12325232, 1521.11, 25, 500000.0, 0.805
    printf("Digite o codigo da cidade 2 (Alfanumerico ate 10 caracteres): \n");
    scanf("%s", cardCode2);

    printf("Digite o estado da cidade 2 (Alfanumerico ate 30 caracteres): \n");
    scanf("%s", cardState2);

    printf("Digite o nome da cidade 2 (Alfanumerico ate 30 caracteres): \n");
    scanf("%s", cardCity2);

    printf("Digite a populacao da cidade 2 (Entre 0 e 9 quintilhoes): \n");
    scanf("%llu", &cardPopulation2);

    printf("Digite a area da cidade 2 (em km2 - somente numeros, permitido decimais): \n");
    scanf("%f", &cardArea2);

    printf("Digite o numero de pontos turisticos da cidade 2 (Entre 0 a 4.294.967.295): \n");
    scanf("%u", &cardTouristAttractions2);

    printf("Digite o PIB da cidade 2 (em milhoes de Reais - somente numeros, permitido decimais): \n");
    scanf("%f", &cardGDP2);

    printf("Digite o IDH da cidade 2 (somente numeros, permitido decimais): \n");
    scanf("%f", &cardHDI2);

    // Comparando de forma estática a densidade populacional (cardPopulation)
    // Menor densidade = Vencedora!
    if (cardPopulation1 < cardPopulation2) {
        printf(
            "A cidade %s tem a menor densidade populacional (%llu habitantes), sendo a vencedora! \n",
            cardCity1,
            cardPopulation1
        );
    } else if (cardPopulation2 < cardPopulation1) {
        printf(
            "A cidade %s tem a menor densidade populacional (%llu habitantes), sendo a vencedora! \n",
            cardCity2,
            cardPopulation2
        );
    } else {
        printf("Ambas as cidades têm a mesma densidade populacional, nenhuma venceu! \n");
    }

    // Como rodar/testar?
    // Veja no Readme!

    return 0;
}
