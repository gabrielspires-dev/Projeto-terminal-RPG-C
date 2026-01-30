#include <stdio.h>
#include <stdlib.h>  // Para system()
#include <time.h>    // Para srand() e rand()
#include <string.h>  // Para strcpy()
#include <windows.h> // Para Sleep()
#include <locale.h>  // Para setlocale()
#include <wchar.h>   // Para SetConsoleOutputCP()

#ifdef _WIN32  // Verifica se o sistema é Windows
    #define CLEAR_SCREEN() system("cls")
#else        // Para sistemas Unix/Linux
    #define CLEAR_SCREEN() system("clear")
#endif    // Limpa a tela

int menu_inicial() {
    int opcao;
    do {
        printf("========================================================================================================================\n");
        printf(" ________          _______           _________        ___  ___          _______           ________     \n|\\   __  \\        |\\  ___ \\         |\\___   ___\\     |\\  \\|\\  \\        |\\  ___ \\         |\\   __  \\    \n\\ \\  \\|\\  \\       \\ \\   __/|        \\|___ \\  \\_|     \\ \\  \\\\\\  \\       \\ \\   __/|        \\ \\  \\|\\  \\   \n \\ \\   __  \\       \\ \\  \\_|/__           \\ \\  \\       \\ \\   __  \\       \\ \\  \\_|/__       \\ \\   _  _\\  \n  \\ \\  \\ \\  \\       \\ \\  \\_|\\ \\           \\ \\  \\       \\ \\  \\ \\  \\       \\ \\  \\_|\\ \\       \\ \\  \\\\\\  \\| \n   \\ \\__\\ \\__\\       \\ \\_______\\           \\ \\__\\       \\ \\__\\ \\__\\       \\ \\_______\\       \\ \\__\\\\ _\\ \n    \\|__|\\|__|        \\|_______|            \\|__|        \\|__|\\|__|        \\|_______|        \\|__|\\|__|\n                                                                                                       \n                                                                                                       \n                                                                                                       \n                                     ________  ________  ________  ________                            \n                                    |\\   ____\\|\\   __  \\|\\   ____\\|\\   __  \\                           \n                                    \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\___|\\ \\  \\|\\  \\                          \n                                     \\ \\_____  \\ \\   __  \\ \\  \\  __\\ \\   __  \\                         \n                                      \\|____|\\  \\ \\  \\ \\  \\ \\  \\|\\  \\ \\  \\ \\  \\                        \n                                        ____\\_\\  \\ \\__\\ \\__\\ \\_______\\ \\__\\ \\__\\                       \n                                       |\\_________\\|__|\\|__|\\|_______|\\|__|\\|__|                       \n                                       \\|_________|                                                     \n                                                                                                       \n                                                                                                       \n                                                                                                       \n");
        printf("========================================================================================================================");
        printf(" 1) Iniciar o jogo\n");
        printf(" 2) Sair do jogo\n");
        printf("========================================================================================================================\n");
        printf(" Digite: ");
        scanf("%d", &opcao);
        if (opcao == 2) {
            printf("\nSaindo do jogo...\n");
            Sleep(2000); //Sleep() para pausar a execução por 2 segundos
            printf("Obrigado por jogar!\n");
            exit(0); // Encerra o programa
        }
        if (opcao != 1 && opcao != 2) {
            printf("\nOpção inválida! Pressione Enter para tentar novamente...");
            getchar(); getchar();
        }
    } while (opcao != 1);
    return opcao;
}

void mostrar_historia() {
    printf("\n\nHá muito tempo, nas terras de Aether, a magia fluía livremente pelos céus e corredores da antiga capital.\n\n");
    Sleep(3000);
    printf("Porém, um brutal cataclismo despertou criaturas sombrias de seu sono ancestral.\n\n");
    Sleep(3000);
    printf("Goblin, Esqueleto, Orc e Troll espalharam-se pelos bosques e montanhas,\n\n");
    printf("Enquanto Dragões, Fênix, Hidras e Quimeras aterrorizavam vilarejos desvencijados.\n\n");
    Sleep(3000);
    printf("Diz-se que somente o Herói eleito — armado de coragem, lâminas e artefatos místicos \n\n");
    Sleep(3000);
    printf("Poderá restaurar o equilíbrio e devolver a paz a Aether.\n\n");
    Sleep(3000);
    printf("Prepare-se, a sua jornada começa agora!\n\n");
    Sleep(6000);
    printf("Pressione Enter para continuar...");
    getchar(); getchar();
    CLEAR_SCREEN();
}

typedef struct {
    char nome[20];
    int vida;
    int ataque;
    int defesa;
    int pocoes;
} Personagem;

typedef struct { // Estrutura para os itens
    const char *nome_item;
    const char *desc_item;
} Item;

const char *nomes_inimigos[] = {
    "Goblin", "Esqueleto", "Orc", "Troll",
    "Dragão", "Fenix", "Hidra", "Quimera"
}; // ; no final para evitar erro de compilação

const char *descricao_inimigos[] = { // Array de descrições dos inimigos
    "Goblin: Pequeno, astuto e traiçoeiro, costuma atacar em bando nas florestas de Aether.",
    "Esqueleto: Restos animados por magia sombria, vagam sem descanso pelos cemitérios antigos.",
    "Orc: Forte e brutal, os orcs aterrorizam vilarejos com sua força e selvageria.",
    "Troll: Gigante das montanhas, possui regeneração rápida e é temido por sua resistência.",
    "Dragão: Voa pelos céus, cospe fogo e guarda tesouros ancestrais. Um verdadeiro desafio!",
    "Fenix: Ave mística que renasce das cinzas, seu fogo é tanto destrutivo quanto purificador.",
    "Hidra: Monstro de várias cabeças, cada uma cortada faz nascer outras. Difícil de derrotar.",
    "Quimera: Criatura híbrida, mistura de leão, cabra e serpente, cospe fogo e é imprevisível."
};

Item itens[] = { // Array de itens onde cada item tem um nome e uma descrição
    {"Poção Maior",    "Restaura até 50 de vida."},
    {"Bomba de Fogo",  "Causa 40 de dano direto ao inimigo."},
    {"Escudo Mágico",  "Dobra sua defesa pelos próximos 2 turnos."},
    {"Elixir de Vida",  "Restaura completamente sua vida (100)."},
    {"Anel de Protecão", "Aumenta sua defesa em +5 permanentemente nesta batalha."},
    {"Amuleto de Mana",  "Aumenta seu ataque em +5 permanentemente nesta batalha."},
    {"Lámina Flamejante", "Causa 20 de dano e aumenta seu ataque em +5."},
    {"Baú de Poções",    "Concede +3 poções extras no inventário."}
};

int inventario[sizeof(nomes_inimigos)/sizeof(nomes_inimigos[0])] = {0}; // inicialização de inventário em 0
int inimigo_min_dmg, inimigo_max_dmg;  // Variáveis globais para o dano mínimo e máximo do inimigo

void escolher_dificuldade() {
    printf("Bem-vindo ao jogo!\nEscolha o modo de jogo:\n\n1) Fácil\n2) Normal\n3) Difícil\n\n");
    int dificuldade_escolhida;

    do {
        printf("Sua escolha: ");
        scanf("%d", &dificuldade_escolhida);
    } while (dificuldade_escolhida < 1 || dificuldade_escolhida > 3); 
    switch(dificuldade_escolhida) {
        case 1: inimigo_min_dmg = 5; inimigo_max_dmg = 20; break;
        case 2: inimigo_min_dmg = 15; inimigo_max_dmg = 25; break;
        case 3: inimigo_min_dmg = 20; inimigo_max_dmg = 35; break;
    } // Define o dano mínimo e máximo do inimigo com base na dificuldade escolhida
}

void criacao_jogador(Personagem *jogador) {
    printf("\nDigite o nome do seu personagem: ");
    scanf("%19s", jogador->nome);
    jogador->vida = 100;
    jogador->ataque = 20;
    jogador->defesa = 10;
    jogador->pocoes = 3;
    printf("\nBem-vindo %s! Sua Vida: %d, Ataque: %d, Defesa: %d", jogador->nome, jogador->vida, jogador->ataque, jogador->defesa);
    Sleep(3000);
    printf("\n\nVocê tem 3 poções para começar!");
    Sleep(2000);
    printf("\n\nPrepare-se para a batalha!\n");
    Sleep(3500);
}

void criacao_inimigo(Personagem *inimigo, const char *nome) {
    strcpy(inimigo->nome, nome);
    int idx_desc = 0;
    int total_inimigos = sizeof(nomes_inimigos)/sizeof(nomes_inimigos[0]);
    for (int i = 0; i < total_inimigos; i++) {
        if (strcmp(nome, nomes_inimigos[i]) == 0) {
            idx_desc = i;
            break;
        }
    }
    // Randomizador de vida do inimigo (entre 50 e 100 para normais)
    inimigo->vida = 50 + rand() % 51;
    inimigo->ataque = inimigo_min_dmg + rand() % (inimigo_max_dmg - inimigo_min_dmg + 1); //randomiza o ataque do inimigo
    inimigo->defesa = 5 + rand() % 6; // randomiza a defesa do inimigo entre 5 e 10
    inimigo->pocoes = 0;  // inimigos não têm poções

    // Edita a vida e defesa dos inimigos Boss/especiais
    if (strcmp(nome, "Dragão") == 0) {
        inimigo->vida = 80;
        inimigo->defesa = 9;
        printf("\nCuidado! O Dragão é um Boss\n");

    } else if (strcmp(nome, "Fenix") == 0) {
        inimigo->vida = 50;
        inimigo->defesa = 8;
        // Fenix renasce com 40 de vida posteriormente...
        printf("\nCuidado! A Fenix é forte!\n");

    } else if (strcmp(nome, "Hidra") == 0) {
        inimigo->vida = 55;
        inimigo->defesa = 6;
        // Hidra tem regeneração de 45 de vida posteriormente...
        printf("\nCuidado! A Hidra é traiçoeira e tem vida longa!\n");

    } else if (strcmp(nome, "Quimera") == 0) {
        inimigo->vida = 75;
        inimigo->defesa = 8;
        printf("\nCuidado! A Quimera é poderosa!\n");
    }
    // Exibe o aparecimento e informação do inimigo
    printf("\nUm %s aparece!\n\nVida: %d\nAtaque: %d\nDefesa: %d\n\n", inimigo->nome, inimigo->vida, inimigo->ataque, inimigo->defesa);
    Sleep(3500);
    printf("\n%s\n", descricao_inimigos[idx_desc]);
    Sleep(6000);
}

int usar_item(Personagem *jogador, Personagem *inimigo) {
    // Verifica se há pelo menos 1 item no inventário
    int total_itens = sizeof(itens)/sizeof(itens[0]);
    int possui_item = 0;
    for (int i = 0; i < total_itens; i++) {
        if (inventario[i] > 0) {
            possui_item = 1;
            break;
        }
    }
    if (!possui_item) {
        printf("Você não tem itens!\n");
        return -1; // Retorna -1 para voltar ao menu
    }

    printf("\nItens disponíveis:\n");
    for (int i = 0; i < total_itens; i++) {
        if (inventario[i] > 0)
            printf("%d) %s x%d\n", i+1, itens[i].nome_item, inventario[i]);
    }
    printf("Escolha o item ou 0 para voltar porém cuidado pois o inimigo pode ser mais rápido e te atacar!: ");
    int escolha; scanf("%d", &escolha);
    if (escolha == 0) return -1; // Voltar ao menu
    if (escolha < 1 || escolha > total_itens || inventario[escolha-1] == 0) {
        printf("Item inválido!\n");
        return -1;
    }
    int idx = escolha - 1;
    inventario[idx]--;

    switch (idx) {  // Verifica o índice do item
        case 0: // Poção Maior
            jogador->vida = jogador->vida + 50 > 100 ? 100 : jogador->vida + 50;
            printf("Você usou %s! Vida: %d\n", itens[idx].nome_item, jogador->vida);
            break;
        case 1: // Bomba de Fogo
            inimigo->vida -= 40;
            printf("Você lançou %s! %s vida: %d\n", itens[idx].nome_item, inimigo->nome, inimigo->vida);
            break;
        case 2: // Escudo Mágico
            printf("Você usou %s! Defesa dobrada pelos próximos 2 ataques.\n", itens[idx].nome_item);
            return 2;
        case 3: // Elixir de Vida
            jogador->vida = 100;
            printf("Você usou %s! Vida restaurada para %d\n", itens[idx].nome_item, jogador->vida);
            break;
        case 4: // Anel de Proteção
            jogador->defesa += 5;
            printf("Você equipou %s! Defesa aumentada para %d\n", itens[idx].nome_item, jogador->defesa);
            break;
        case 5: // Amuleto de Mana
            jogador->ataque += 5;
            printf("Você equipou %s! Ataque aumentado para %d\n", itens[idx].nome_item, jogador->ataque);
            break;
        case 6: // Lâmina Flamejante
            inimigo->vida -= 20;
            jogador->ataque += 5;
            printf("Você usou %s! %s vida: %d e seu ataque: %d\n", itens[idx].nome_item, inimigo->nome, inimigo->vida, jogador->ataque);
            break;
        case 7: // Baú de Poções
            jogador->pocoes += 3;
            printf("Você equipou %s! Poções adicionadas: 3 (total: %d)\n", itens[idx].nome_item, jogador->pocoes);
            break;
    }
    return -1;
}

void mostrar_descricao_itens() {
    int total_itens = sizeof(itens)/sizeof(itens[0]); // Acessa o total de itens e quantidade
    printf("\n--- Descrição dos Itens no Inventário ---\n");
    for (int i = 0; i < total_itens; i++) { //repetição para cada item
        if (inventario[i] > 0) {
            printf("%d) %s: %s\n", i+1, itens[i].nome_item, itens[i].desc_item);
        }
    }
    printf("Pressione Enter para voltar.\n");
    getchar(); getchar(); // Espera o usuário pressionar Enter
}

void batalha(Personagem *jogador, Personagem *inimigo, int idx_inimigo) {
    int defesa_original = jogador->defesa; // Armazena a defesa original do jogador
    int desfesa_turnos = 0; // Variável para controlar os turnos do escudo mágico
    int fenix_renasceu = 0; // Flag para controlar se a Fenix já renasceu
    int hidra_regenerou = 0; // Flag para controlar se a Hidra Já regenerou

    while (jogador->vida > 0 && inimigo->vida > 0) {
        CLEAR_SCREEN(); // Limpa a tela antes de cada batalha
        printf("________________________________________\n");
        printf("--- Batalha: %s VS %s ---\n", jogador->nome, inimigo->nome);
        printf("Sua Vida: %d  | Seu Ataque: %d\n", jogador->vida, jogador->ataque);
        printf("       Sua Defesa: %d\n", jogador->defesa);
        printf("________________________________________\n");
        printf("%s Vida: %d | Ataque: %d | Defesa: %d\n\n", inimigo->nome, inimigo->vida, inimigo->ataque, inimigo->defesa);
        printf("\nEscolha uma ação:\n\n");
        printf("1) Atacar\n2) Defender\n3) Usar Poção\n4) Usar Item Especial\n5) Ver Descrição de Itens\n6) Sair do Jogo\nDigite: ");
        int escolha;
        scanf("%d", &escolha);
        int item = -1; // Inicializa a variável item

        if (escolha == 6) {
            printf("\nVocê escolheu sair do jogo. Até logo!\n");
            exit(0); // Fecha o jogo
        }
        if (escolha == 4) {  // Usar item especial
            item = usar_item(jogador, inimigo);

            if (item == 2) { // Se o item for o escudo mágico
                jogador->defesa = defesa_original * 2;
                desfesa_turnos = 2;
            }
        } else if (escolha == 5) { // Ver descrição de itens
            mostrar_descricao_itens();
            continue;

        } else if (escolha == 1) { // Atacar
            int dano = jogador->ataque - inimigo->defesa;
            if (dano < 0) dano = 0; // Verifica se o dano é negativo
            inimigo->vida -= dano;
            printf("Você ataca e causa %d de dano!\n", dano);

        } else if (escolha == 2) { // Defender
            printf("Você se defende, reduzindo o próximo ataque em 50%%.\n");
            inimigo->ataque /= 2;
        } else if (escolha == 3) { // Usar poção
            if (jogador->pocoes > 0) {
                jogador->vida += 40; if (jogador->vida > 100) jogador->vida=100;
                jogador->pocoes--;
                printf("Você usa a poção! Vida: %d | Poções: %d\n", jogador->vida, jogador->pocoes);
            } else {
                printf("Sem poções!\n"); continue;
            }
        } else if (escolha != 4 && escolha != 5 && escolha != 1 && escolha != 2 && escolha != 3) {
            printf("Ação inválida!\n\nVocê perde a vez de atacar, o inimigo foi mais rápido!\n");
        }

        //Fenix renascendo
        if (strcmp(inimigo->nome, "Fenix") == 0 && inimigo->vida <= 0 && fenix_renasceu == 0) {
            CLEAR_SCREEN();
            printf("A Fenix foi derrotada?\n\n");
            Sleep(2000);
            printf("Ela começa a brilhar intensamente!\n\n");
            Sleep(2000);
            printf("Uma onda de calor envolve o campo de batalha!\n\n");
            Sleep(2000);
            printf("Como esperado ela renasce das cinzas...\n\n");
            Sleep(3000);
            printf("A Fenix renasce com 40 de vida!\n");
            inimigo->vida = 40;
            fenix_renasceu = 1;
            Sleep(3000);
            continue; // Volta para o próximo turno com a Fenix renascida
        } 
        // Hidra regenerando
        if (strcmp(inimigo->nome, "Hidra") == 0 && inimigo->vida <= 0 && hidra_regenerou == 0) {
            CLEAR_SCREEN();
            printf("Hidra foi derrotada?\n\n");
            Sleep(2000);
            printf("Você cortou todas as cabeças porém se lembra de algo sobre a temida Hidra...\n\n");
            Sleep(3000);
            printf("A Hidra se regenera com 35 de vida rapidamente!\n");
            Sleep(2000);
            printf("Dê um Fim a isto!\n");
            inimigo->vida = 35;
            hidra_regenerou = 1;
            Sleep(3000);
            continue; // Volta para o próximo turno com a Hidra regenerada
        }
        
        if (inimigo->vida <= 0) break; // Verifica se o inimigo foi derrotado
        int dano_inimigo = inimigo->ataque - jogador->defesa;
        if (dano_inimigo < 0) dano_inimigo = 0;
        jogador->vida -= dano_inimigo;
        printf("%s ataca e causa %d de dano!\n", inimigo->nome, dano_inimigo);
        if (escolha == 2) inimigo->ataque *= 2;
        if (desfesa_turnos > 0) {   // Verifica se o escudo mágico está ativo
            desfesa_turnos--;
            if (desfesa_turnos == 0) {   // Verifica se o escudo mágico expirou
                jogador->defesa = defesa_original;
                printf("Seu Escudo Mágico expirou. Defesa voltou a: %d\n", jogador->defesa);
            }
        }
        printf("\nPressione Enter para continuar...\n"); getchar(); getchar();
    }

    if (jogador->vida > 0) {  // Conceder item ao jogador e parabenizá-lo
        CLEAR_SCREEN();
        printf("\nParabéns! Você derrotou %s bravamente!\n\nComo recompensa ganhou o item: %s\n", inimigo->nome, itens[idx_inimigo].nome_item);
        Sleep(3000);
        printf("Você pode ver a descrição do item no inventário!\n\n");
        Sleep(1500);
        inventario[idx_inimigo]++;
        printf("Pressione Enter para o próximo desafio...\n"); getchar(); getchar();
    } else {
        printf("\nVocê foi derrotado... Fim de jogo.\n");
    }
}

void shuffle(char *array[], int n) { // Embaralha o array de nomes de inimigos
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char *tmp = array[i]; array[i] = array[j]; array[j] = tmp;
    }
}

int main() { // Função principal onde o jogo começa e termina
    SetConsoleOutputCP(65001); // Configura a saída para UTF-8 para suportar caracteres especiais
    printf("\n\n\n    Um jogo criado por Gabriel Sá Teles\n");
    Sleep(4000);
    CLEAR_SCREEN();
    printf("\n\n\n    Trabalho de Algoritmo e Programação Estruturada\n                       Sala 212F\n");
    Sleep(6000);
    CLEAR_SCREEN();
    menu_inicial();
    CLEAR_SCREEN();
    srand((unsigned int)time(NULL));  // Inicializa o gerador de números aleatórios
    mostrar_historia();
    escolher_dificuldade();
    Personagem jogador, inimigo;  // Cria os personagens jogador e inimigo
    criacao_jogador(&jogador);
    int total = sizeof(nomes_inimigos)/sizeof(nomes_inimigos[0]); // Tamanho do array de nomes de inimigos
    char *ordem[8]; for(int i=0;i<total;i++) ordem[i]=strdup((char*)nomes_inimigos[i]); // Cria cópias dos nomes dos inimigos
    shuffle(ordem, total);      // Embaralha os nomes dos inimigos
    for(int i=0;i<total;i++) {  // Loop para cada inimigo
        CLEAR_SCREEN(); criacao_inimigo(&inimigo, ordem[i]);
        int idx=0; for(int k=0;k<total;k++) if(strcmp(ordem[i], nomes_inimigos[k])==0) idx=k; // Encontra o índice do inimigo
        batalha(&jogador, &inimigo, idx); // Inicia a batalha
        if (jogador.vida <= 0) break;     // Verifica se o jogador foi derrotado
    } // Fim do loop de batalha
    if (jogador.vida > 0) printf("\nParabéns! Você derrotou todos os inimigos e obteve todos os itens!\n"); // Parabeniza o jogador e fim de jogo
    printf("\nObrigado por jogar!\n");  // Fim de jogo caso o jogador tenha vencido
    return 0;
}
