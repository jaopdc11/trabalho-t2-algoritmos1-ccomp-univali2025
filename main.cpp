#include <iostream>
#include <cstdlib>
#include <locale.h> // Necessário para usar setlocale e garantir acentuação
#include <ctime>    // Para usar time(0) na semente do rand

using namespace std;

int main() {
    // ----------------------------------------
    // Configuração do locale para aceitar acentuação em português
    // ----------------------------------------
    setlocale(LC_ALL, "Portuguese");

    // ----------------------------------------
    // Identificação dos autores e informações do trabalho
    // ----------------------------------------
    cout << "----------------------------------------\n";
    cout << "Trabalho Mastermind (Senha)\n";
    cout << "Equipe: João Pedro da Conceição Simas, Clara Haag Rodrigues, Leonardo de Souza Pereira\n";
    cout << "Disciplina: Algoritmos e Programação\n";
    cout << "Professor: Rafael Ballottin\n";
    cout << "Data: Maio/2025\n";
    cout << "----------------------------------------\n";

    int opcao = 0; // Variável para armazenar a opção escolhida no menu principal

    // Loop principal do menu: só termina quando o usuário escolher a opção 3 (Sair)
    while (opcao != 3) {
        system("cls"); // Limpa a tela sempre que o menu é exibido

        // Exibe o menu principal e lê a escolha do usuário
        cout << "\nMENU PRINCIPAL\n";
        cout << "1. Jogar\n";
        cout << "2. Sobre\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        // -------------------------------
        // Opção 1: Jogar
        // -------------------------------
        if (opcao == 1) {
            // Geração do código secreto (senha) com 4 números diferentes entre 1 e 6
            srand(time(0)); // Inicializa o gerador de números aleatórios

            int s1, s2, s3, s4; // Cada variável representa um dígito da senha

            // Gera cada número da senha, garantindo que não haja repetição
            do { s1 = rand() % 6 + 1; } while (0); // Primeiro número, qualquer valor entre 1 e 6
            do { s2 = rand() % 6 + 1; } while (s2 == s1);
            do { s3 = rand() % 6 + 1; } while (s3 == s1 || s3 == s2);
            do { s4 = rand() % 6 + 1; } while (s4 == s1 || s4 == s2 || s4 == s3);

            int tentativas = 10; // Número máximo de tentativas permitidas
            bool venceu = false; // Variável para controlar se o jogador acertou a senha

            // Loop das tentativas do jogador
            while (tentativas > 0 && !venceu) {
                int palpite;
                int g1, g2, g3, g4;

                // Instrução clara para o usuário sobre como digitar o palpite
                cout << "\nDigite seu palpite: 4 números entre 1 e 6, juntos e sem repetir (exemplo: 2451): ";
                cin >> palpite;

                // Separa os dígitos usando divisões inteiras e módulo
                g1 = (palpite / 1000) % 10;
                g2 = (palpite / 100) % 10;
                g3 = (palpite / 10) % 10;
                g4 = palpite % 10;

                // Validação do palpite: verifica se está no intervalo e se não há repetição
                if (g1 < 1 || g1 > 6 || g2 < 1 || g2 > 6 || g3 < 1 || g3 > 6 || g4 < 1 || g4 > 6 ||
                    g1 == g2 || g1 == g3 || g1 == g4 || g2 == g3 || g2 == g4 || g3 == g4) {
                    cout << "Palpite inválido! Digite 4 números entre 1 e 6, sem repetir.\n";
                    continue; // Volta para o início do loop sem gastar tentativa
                }

                // Cálculo dos pinos pretos: números corretos na posição correta
                int pretos = 0;
                if (g1 == s1) pretos++;
                if (g2 == s2) pretos++;
                if (g3 == s3) pretos++;
                if (g4 == s4) pretos++;

                // Cálculo dos pinos brancos: números corretos, mas em posição errada
                int brancos = 0;
                if (g1 == s2 || g1 == s3 || g1 == s4) brancos++;
                if (g2 == s1 || g2 == s3 || g2 == s4) brancos++;
                if (g3 == s1 || g3 == s2 || g3 == s4) brancos++;
                if (g4 == s1 || g4 == s2 || g4 == s3) brancos++;

                tentativas--; // Reduz o número de tentativas restantes

                // Exibe o resultado da tentativa para o jogador
                cout << "Tentativas restantes: " << tentativas << endl;
                cout << "Números corretos na posição correta (pretos): " << pretos << endl;
                cout << "Números corretos na posição errada (brancos): " << brancos << endl;

                // Verifica se o jogador acertou a senha (4 pretos)
                if (pretos == 4) {
                    cout << "\nParabéns! Você acertou a senha!\n";
                    venceu = true; // Marca que o jogador venceu
                } else if (tentativas == 0) {
                    // Se acabaram as tentativas, revela a senha correta
                    cout << "\nVocê perdeu! A senha era: ";
                    cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
                }
            }
            system("pause"); // Pausa antes de voltar ao menu, para o usuário ver o resultado
        }
        // -------------------------------
        // Opção 2: Sobre
        // -------------------------------
        else if (opcao == 2) {
            // Exibe informações sobre o jogo, equipe e regras
            cout << "\nSOBRE O JOGO\n";
            cout << "Mastermind (Senha) - Trabalho de Algoritmos e Programação\n";
            cout << "Equipe: João Pedro da Conceição Simas, Clara Haag Rodrigues, Leonardo de Souza Pereira\n";
            cout << "Maio/2025\n";
            cout << "Professor: Rafael Ballottin\n";
            cout << "O jogo consiste em adivinhar uma sequência de 4 números entre 1 e 6, sem repetição, em até 10 tentativas.\n";
            cout << "Após cada tentativa, será informado quantos números estão corretos e na posição correta (pretos),\n";
            cout << "e quantos estão corretos mas na posição errada (brancos).\n";
            cout << "Boa sorte!\n";
            system("pause"); // Pausa para o usuário ler as informações
        }
        // -------------------------------
        // Opção 3: Sair
        // -------------------------------
        else if (opcao == 3) {
            cout << "Saindo do programa. Até logo!\n";
        }
        // -------------------------------
        // Opção inválida
        // -------------------------------
        else {
            cout << "Opção inválida! Tente novamente.\n";
            system("pause"); // Pausa para o usuário ler a mensagem de erro
        }
    }
    // Fim do programa
    return 0;
}