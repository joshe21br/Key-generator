#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar uma senha aleatória de 12 caracteres
char* gerarSenha() {
    static const char caracteresPermitidos[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int tamanho = 12;
    char* senha = (char*)malloc((tamanho + 1) * sizeof(char));  // +1 para o caractere nulo no final

    if (senha == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }

    int numCaracteresPermitidos = sizeof(caracteresPermitidos) - 1;
    srand(time(NULL));  // Inicializa a semente do gerador de números aleatórios com o tempo atual

    for (int i = 0; i < tamanho; i++) {
        int indiceAleatorio = rand() % numCaracteresPermitidos;
        senha[i] = caracteresPermitidos[indiceAleatorio];
    }

    senha[tamanho] = '\0';  // Adiciona o caractere nulo ao final da senha

    return senha;
}

int main() {
    char* senha = gerarSenha();
    printf("Senha aleatória: %s\n", senha);

    // Não esqueça de liberar a memória alocada para a senha
    free(senha);

    return 0;
}
