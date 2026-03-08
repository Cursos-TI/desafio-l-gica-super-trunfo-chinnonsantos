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
CartaTrunfo registarCarta(int numeroCarta) {
    CartaTrunfo carta; // Criamos uma carta temporária para preencher
    
    printf("\n--- REGISTO DA CARTA %d ---\n", numeroCarta);
    
    inputWord("Digite o codigo da cidade (Alfanumerico ate 10 caracteres): \n", "%10s", carta.code);
    inputPhrase("Digite o estado da cidade (Alfanumerico ate 30 caracteres): \n", carta.state, 31);
    inputPhrase("Digite o nome da cidade (Alfanumerico ate 30 caracteres): \n", carta.city, 31);
    inputWord("Digite a populacao da cidade (Entre 0 a 4.294.967.295): \n", "%u", &carta.population);
    inputWord("Digite a area da cidade (em km2 - somente numeros): \n", "%f", &carta.area);
    inputWord("Digite o numero de pontos turisticos da cidade: \n", "%u", &carta.touristAttractions);
    inputWord("Digite o PIB da cidade (em milhoes de Reais): \n", "%f", &carta.gdp);
    inputWord("Digite o IDH da cidade: \n", "%f", &carta.hdi);

    // Realiza os cálculos dinâmicos dentro da própria função
    carta.populationDensity = carta.population / carta.area; 
    carta.gdpPerCapita = (carta.population > 0) ? (carta.gdp * 1000000) / carta.population : 0; 
    
    // Mostra um pequeno resumo após o registo
    printf("\nResumo da Carta %d:\n", numeroCarta);
    printf("Densidade Populacional de %s: %.2f habitantes/km2 \n", carta.city, carta.populationDensity);
    printf("PIB per capita de %s: %.2f Reais \n", carta.city, carta.gdpPerCapita);
    
    return carta; // Devolve a carta preenchida para quem chamou a função
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
    carta1 = registarCarta(1);

    // ==========================================
    // CARTA 2
    // ------------------------------------------
    // Sugestão: SAMPA11, Sao Paulo, Sao Paulo, 12325232, 1521.11, 25, 500000.0, 0.805
    // ==========================================
    carta2 = registarCarta(2);

    // ==========================================
    // RESULTADO
    // ------------------------------------------
    // O critério de comparação escolhido para este desafio é a Densidade Populacional (cardPopulationDensity)
    // Menor densidade = Vencedora!
    // ==========================================
    printf("\n--- RESULTADO FINAL ---\n");
    if (carta1.populationDensity < carta2.populationDensity) {
        printf(
            "A cidade %s tem a menor densidade populacional (%.2f habitantes/km2), sendo a vencedora! \n",
            carta1.city,
            carta1.populationDensity
        );
    } else if (carta2.populationDensity < carta1.populationDensity) {
        printf(
            "A cidade %s tem a menor densidade populacional (%.2f habitantes/km2), sendo a vencedora! \n",
            carta2.city,
            carta2.populationDensity
        );
    } else {
        printf("Ambas as cidades têm a mesma densidade populacional, nenhuma venceu! \n");
    }

    // Como rodar/testar?
    // Veja no Readme!

    return 0;
}
