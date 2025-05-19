#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // ----------------------------------------
    // Identificação dos autores e informações do trabalho
    // ----------------------------------------
    cout << "----------------------------------------\n";
    cout << "Trabalho Mastermind\n";
    cout << "Equipe: João Pedro da Conceição Simas, Clara Haag Rodrigues, Leonardo de Souza Pereira\n";
    cout << "Disciplina: Algoritmos e Programacao\n";
    cout << "Professor: Rafael Ballottin\n";
    cout << "Data: Maio/2025\n";
    cout << "----------------------------------------\n";

    int opcao = 0; // Variável para armazenar a opção escolhida no menu

    // Loop principal do menu, só termina quando o usuário escolher 'Sair'
    while (opcao != 3) {
        // Exibe o menu principal
        cout << "\nMENU PRINCIPAL\n";
        cout << "1. Jogar\n";
        cout << "2. Sobre\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao; // Lê a opção do usuário

        // Se o usuário escolher "Jogar"
        if (opcao == 1) {
            // ----------------------------------------
            // Geração do código secreto
            // ----------------------------------------
            // O código é composto por 4 números entre 1 e 6, sem repetição
            srand(time(0)); // Inicializa a semente do gerador de números aleatórios

            int s1, s2, s3, s4; // Variáveis para armazenar cada dígito do código

            // Gera o primeiro número aleatório (não precisa checar repetição)
            do { s1 = rand() % 6 + 1; } while (0);

            // Gera o segundo número, garantindo que não seja igual ao primeiro
            do { s2 = rand() % 6 + 1; } while (s2 == s1);

            // Gera o terceiro número, garantindo que não seja igual aos anteriores
            do { s3 = rand() % 6 + 1; } while (s3 == s1 || s3 == s2);

            // Gera o quarto número, garantindo que não seja igual aos anteriores
            do { s4 = rand() % 6 + 1; } while (s4 == s1 || s4 == s2 || s4 == s3);

            int tentativas = 10; // Número máximo de tentativas permitidas
            bool venceu = false; // Variável para controlar se o jogador venceu

            // Loop das tentativas do jogador
            while (tentativas > 0 && !venceu) {
                int g1, g2, g3, g4; // Variáveis para armazenar o palpite do jogador

                // Solicita o palpite do jogador
                cout << "\nDigite seu palpite (4 numeros entre 1 e 6, sem repetir): ";
                cin >> g1 >> g2 >> g3 >> g4;

                // ----------------------------------------
                // Validação do palpite do jogador
                // ----------------------------------------
                // Verifica se os números estão no intervalo correto e se não há repetição
                if (g1 < 1 || g1 > 6 || g2 < 1 || g2 > 6 || g3 < 1 || g3 > 6 || g4 < 1 || g4 > 6 ||
                    g1 == g2 || g1 == g3 || g1 == g4 || g2 == g3 || g2 == g4 || g3 == g4) {
                    cout << "Entrada invalida! Digite 4 numeros entre 1 e 6, sem repetir.\n";
                    continue; // Volta para o início do loop sem gastar tentativa
                }

                // ----------------------------------------
                // Cálculo dos pinos pretos (acertos exatos)
                // ----------------------------------------
                // Conta quantos números estão corretos e na posição correta
                int pretos = 0;
                if (g1 == s1) pretos++;
                if (g2 == s2) pretos++;
                if (g3 == s3) pretos++;
                if (g4 == s4) pretos++;

                // ----------------------------------------
                // Cálculo dos pinos brancos (acertos fora de posição)
                // ----------------------------------------
                // Conta quantos números estão corretos, mas em posições diferentes
                int brancos = 0;
                // Para cada palpite, verifica se ele existe em outra posição do código
                if (g1 == s2 || g1 == s3 || g1 == s4) brancos++;
                if (g2 == s1 || g2 == s3 || g2 == s4) brancos++;
                if (g3 == s1 || g3 == s2 || g3 == s4) brancos++;
                if (g4 == s1 || g4 == s2 || g4 == s3) brancos++;

                tentativas--; // Reduz o número de tentativas restantes

                // Exibe o resultado da tentativa para o jogador
                cout << "Tentativas restantes: " << tentativas << endl;
                cout << "Numeros corretos na posicao correta (pretos): " << pretos << endl;
                cout << "Numeros corretos na posicao errada (brancos): " << brancos << endl;

                // ----------------------------------------
                // Verifica se o jogador acertou o código
                // ----------------------------------------
                if (pretos == 4) {
                    cout << "\nParabens! Voce acertou o código!\n";
                    venceu = true; // Marca que o jogador venceu
                } else if (tentativas == 0) {
                    // Se acabaram as tentativas, revela a código correta
                    cout << "\nVoce perdeu! O código era: ";
                    cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
                }
            }
            // Ao final do jogo, retorna ao menu principal
            cout << "Voltando ao menu...\n";
        } else if (opcao == 2) {
            // ----------------------------------------
            // Exibe informações sobre o jogo e o grupo
            // ----------------------------------------
            cout << "\nSOBRE O JOGO\n";
            cout << "Mastermind - Trabalho de Algoritmos e Programacao\n";
            cout << "Equipe: João Pedro da Conceição Simas, Clara Haag Rodrigues, Leonardo de Souza Pereira\n";
            cout << "Maio/2025\n";
            cout << "Professor: Rafael Ballottin\n";
            cout << "O jogo consiste em adivinhar uma sequencia de 4 numeros entre 1 e 6, sem repeticao, em ate 10 tentativas.\n";
            cout << "Apos cada tentativa, sera informado quantos numeros estao corretos e na posicao correta (pretos),\n";
            cout << "e quantos estao corretos mas na posicao errada (brancos).\n";
            cout << "Boa sorte!\n";
        } else if (opcao == 3) {
            // ----------------------------------------
            // Encerra o programa
            // ----------------------------------------
            cout << "Saindo do programa. Ate logo!\n";
        } else {
            // ----------------------------------------
            // Caso o usuário digite uma opção inválida
            // ----------------------------------------
            cout << "Opcao invalida! Tente novamente.\n";
        }
    }
    // Fim do programa
    return 0;
}