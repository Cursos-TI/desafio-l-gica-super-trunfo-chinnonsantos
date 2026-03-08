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

// Criamos um "molde" (struct) para as nossas cartas
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
} CartaTrunfo;

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
    limpar_buffer(); // Limpa o '\n' ou qualquer lixo residual após a leitura
}

// Função para coletar textos longos com espaços (frases)
// Recebe a pergunta (prompt), o vetor de caracteres (variavel) e o tamanho máximo
void inputPhrase(const char *prompt, char *variavel, int tamanhoMaximo) {
    printf("%s", prompt);
    fgets(variavel, tamanhoMaximo, stdin);
    variavel[strcspn(variavel, "\n")] = 0; // Remove a quebra de linha que o fgets captura
}

// ==========================================
// FUNÇÃO PRINCIPAL
// ==========================================

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    CartaTrunfo carta1, carta2;
    
    printf("\n\nDesafio Super Trunfo - Paises \n");
    printf("Vamos cadastrar duas cartas, comparando a densidade populacional! \n\n");

    // ==========================================
    // CARTA 1
    // ------------------------------------------
    // Sugestão: GYN62, Goias, Goiania, 1536097, 739.2, 15, 120000.0, 0.799
    // ==========================================
    inputWord("Digite o codigo da cidade 1 (Alfanumerico ate 10 caracteres): \n", "%10s", carta1.code);
    inputPhrase("Digite o estado da cidade 1 (Alfanumerico ate 30 caracteres): \n", carta1.state, 31);
    inputPhrase("Digite o nome da cidade 1 (Alfanumerico ate 30 caracteres): \n", carta1.city, 31);
    inputWord("Digite a populacao da cidade 1 (Entre 0 a 4.294.967.295): \n", "%i", &carta1.population);
    inputWord("Digite a area da cidade 1 (em km2 - somente numeros, permitido decimais): \n", "%f", &carta1.area);
    inputWord("Digite o numero de pontos turisticos da cidade 1 (Entre 0 a 4.294.967.295): \n", "%u", &carta1.touristAttractions);
    inputWord("Digite o PIB da cidade 1 (em milhoes de Reais - somente numeros, permitido decimais): \n", "%f", &carta1.gdp);
    inputWord("Digite o IDH da cidade 1 (somente numeros, permitido decimais): \n", "%f", &carta1.hdi);

    // Calcular Densidade Populacional e PIB per capita para a Carta 1
    carta1.populationDensity = carta1.population / carta1.area; // Densidade = População / Área
    carta1.gdpPerCapita = (carta1.population > 0) ? (carta1.gdp * 1000000) / carta1.population : 0; // PIB per capita = PIB total / População

    printf("Densidade Populacional da cidade %s: %.2f habitantes/km2 \n", carta1.city, carta1.populationDensity);
    printf("PIB per capita da cidade %s: %.2f Reais \n\n", carta1.city, carta1.gdpPerCapita);

    // ==========================================
    // CARTA 2
    // ------------------------------------------
    // Sugestão: SAMPA11, Sao Paulo, Sao Paulo, 12325232, 1521.11, 25, 500000.0, 0.805
    // ==========================================
    inputWord("Digite o codigo da cidade 2 (Alfanumerico ate 10 caracteres): \n", "%10s", carta2.code);
    inputPhrase("Digite o estado da cidade 2 (Alfanumerico ate 30 caracteres): \n", carta2.state, 31);
    inputPhrase("Digite o nome da cidade 2 (Alfanumerico ate 30 caracteres): \n", carta2.city, 31);
    inputWord("Digite a populacao da cidade 2 (Entre 0 a 4.294.967.295): \n", "%i", &carta2.population);
    inputWord("Digite a area da cidade 2 (em km2 - somente numeros, permitido decimais): \n", "%f", &carta2.area);
    inputWord("Digite o numero de pontos turisticos da cidade 2 (Entre 0 a 4.294.967.295): \n", "%u", &carta2.touristAttractions);
    inputWord("Digite o PIB da cidade 2 (em milhoes de Reais - somente numeros, permitido decimais): \n", "%f", &carta2.gdp);
    inputWord("Digite o IDH da cidade 2 (somente numeros, permitido decimais): \n", "%f", &carta2.hdi);

    // Calcular Densidade Populacional e PIB per capita para a Carta 2
    carta2.populationDensity = carta2.population / carta2.area; // Densidade = População / Área
    carta2.gdpPerCapita = (carta2.population > 0) ? (carta2.gdp * 1000000) / carta2.population : 0; // PIB per capita = PIB total / População

    printf("Densidade Populacional da cidade %s: %.2f habitantes/km2 \n", carta2.city, carta2.populationDensity);
    printf("PIB per capita da cidade %s: %.2f Reais \n\n", carta2.city, carta2.gdpPerCapita);

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
