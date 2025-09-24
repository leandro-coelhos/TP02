#include "velha.h"
#include <array>

static bool linhaVence(const int tab[3][3], int r, int p) {
    return tab[r][0] == p && tab[r][1] == p && tab[r][2] == p;
}
static bool colunaVence(const int tab[3][3], int c, int p) {
    return tab[0][c] == p && tab[1][c] == p && tab[2][c] == p;
}
static bool diagPrinVence(const int tab[3][3], int p) {
    return tab[0][0] == p && tab[1][1] == p && tab[2][2] == p;
}
static bool diagSecVence(const int tab[3][3], int p) {
    return tab[0][2] == p && tab[1][1] == p && tab[2][0] == p;
}

int Jogar(int tab[3][3]) {
    int xCount = 0, oCount = 0, emptyCount = 0;

    // 1) valida e conta
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int v = tab[i][j];
            if (v != 0 && v != 1 && v != 2) {
                return -2; // valor inválido
            }
            if (v == 1) ++xCount;
            else if (v == 2) ++oCount;
            else ++emptyCount;
        }
    }

    // 2) consistência da contagem básica (X começa)
    if (oCount > xCount) return -2;               // O não pode ter mais que X
    if (xCount - oCount > 1) return -2;           // X não pode ter 2 a mais que O

    // 3) computa linhas vencedoras
    auto venceContagem = [&](int p) {
        int wins = 0;
        for (int r = 0; r < 3; ++r) if (linhaVence(tab, r, p)) ++wins;
        for (int c = 0; c < 3; ++c) if (colunaVence(tab, c, p)) ++wins;
        if (diagPrinVence(tab, p)) ++wins;
        if (diagSecVence(tab, p))  ++wins;
        return wins;
    };

    int xWins = venceContagem(1);
    int oWins = venceContagem(2);

    // 4) impossível se ambos vencem
    if (xWins > 0 && oWins > 0) return -2;

    // 5) sua regra: mais de uma linha vencedora para o MESMO jogador é impossível
    if (xWins > 1 || oWins > 1) return -2;

    // 6) se X venceu: contagem deve ser xCount == oCount+1 (X jogou por último)
    if (xWins == 1) {
        if (xCount != oCount + 1) return -2; // vitória de X inconsistente com a vez
        return 1;
    }

    // 7) se O venceu: contagem deve ser xCount == oCount (O jogou por último)
    if (oWins == 1) {
        if (xCount != oCount) return -2; // vitória de O inconsistente com a vez
        return 2;
    }

    // 8) sem vencedor: indefinido ou empate
    if (emptyCount > 0) return -1; // partida em andamento
    return 0;                      // empate
}
