#include <gtest/gtest.h>
#include "velha.h"

// ---------- VITÓRIA DO X (1) ----------

TEST(VelhaTest, XVenceNaLinha0) {
    int tab[3][3] = {
        {1,1,1},
        {0,2,0},
        {0,2,0}
    };
    EXPECT_EQ(1, Jogar(tab));
}

TEST(VelhaTest, XVenceNaLinha1) {
    int tab[3][3] = {
        {2,0,0},
        {1,1,1},
        {0,2,0}
    };
    EXPECT_EQ(1, Jogar(tab));
}

TEST(VelhaTest, XVenceNaLinha2) {
    int tab[3][3] = {
        {2,0,0},
        {0,2,0},
        {1,1,1}
    };
    EXPECT_EQ(1, Jogar(tab));
}

TEST(VelhaTest, XVenceNaColuna0) {
    int tab[3][3] = {
        {1,2,0},
        {1,0,2},
        {1,0,0}
    };
    EXPECT_EQ(1, Jogar(tab));
}

TEST(VelhaTest, XVenceNaColuna1) {
    int tab[3][3] = {
        {2,1,0},
        {0,1,2},
        {0,1,0}
    };
    EXPECT_EQ(1, Jogar(tab));
}

TEST(VelhaTest, XVenceNaColuna2) {
    int tab[3][3] = {
        {2,0,1},
        {0,2,1},
        {0,0,1}
    };
    EXPECT_EQ(1, Jogar(tab));
}

TEST(VelhaTest, XVenceNaDiagonalPrincipal) {
    int tab[3][3] = {
        {1,2,0},
        {0,1,2},
        {0,0,1}
    };
    EXPECT_EQ(1, Jogar(tab));
}

TEST(VelhaTest, XVenceNaDiagonalSecundaria) {
    int tab[3][3] = {
        {2,0,1},
        {0,1,0},
        {1,0,2}
    };
    EXPECT_EQ(1, Jogar(tab));
}

// ---------- VITÓRIA DO O (2) ----------
// (para O vencer: #X == #O)

TEST(VelhaTest, OVenceNaLinha0) {
    int tab[3][3] = {
        {2,2,2},
        {1,0,1},
        {0,1,0}
    };
    EXPECT_EQ(2, Jogar(tab));
}

TEST(VelhaTest, OVenceNaLinha1) {
    int tab[3][3] = {
        {1,0,1},
        {2,2,2},
        {0,1,0}
    };
    EXPECT_EQ(2, Jogar(tab));
}

TEST(VelhaTest, OVenceNaLinha2) {
    int tab[3][3] = {
        {1,0,1},
        {0,1,0},
        {2,2,2}
    };
    EXPECT_EQ(2, Jogar(tab));
}

TEST(VelhaTest, OVenceNaColuna0) {
    int tab[3][3] = {
        {2,1,0},
        {2,1,1},
        {2,0,0}
    };
    EXPECT_EQ(2, Jogar(tab));
}

TEST(VelhaTest, OVenceNaColuna1) {
    int tab[3][3] = {
        {1,2,0},
        {0,2,1},
        {0,2,1}
    };
    EXPECT_EQ(2, Jogar(tab));
}

TEST(VelhaTest, OVenceNaColuna2) {
    int tab[3][3] = {
        {1,0,2},
        {0,1,2},
        {0,1,2}
    };
    EXPECT_EQ(2, Jogar(tab));
}

TEST(VelhaTest, OVenceNaDiagonalPrincipal) {
    int tab[3][3] = {
        {2,1,0},
        {0,2,1},
        {0,1,2}
    };
    EXPECT_EQ(2, Jogar(tab));
}

TEST(VelhaTest, OVenceNaDiagonalSecundaria) {
    int tab[3][3] = {
        {1,0,2},
        {1,2,0},
        {2,0,1}
    };
    EXPECT_EQ(2, Jogar(tab));
}

// ---------- EMPATE (0) ----------
// Tabuleiro cheio, sem vencedor, #X=5, #O=4
TEST(VelhaTest, Empate) {
    int tab[3][3] = {
        {1,2,1},
        {1,2,2},
        {2,1,1}
    };
    EXPECT_EQ(0, Jogar(tab));
}

// ---------- INDEFINIDO (-1) ----------
// Sem vencedor e ainda com espaços vazios
TEST(VelhaTest, IndefinidoTabuleiroVazio) {
    int tab[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    EXPECT_EQ(-1, Jogar(tab));
}

TEST(VelhaTest, IndefinidoApenasUmX) {
    int tab[3][3] = {
        {1,0,0},
        {0,0,0},
        {0,0,0}
    };
    EXPECT_EQ(-1, Jogar(tab));
}

TEST(VelhaTest, IndefinidoSemVencedorComEspacosVazios) {
    int tab[3][3] = {
        {1,2,0},
        {0,1,0},
        {2,0,0}
    };
    EXPECT_EQ(-1, Jogar(tab));
}

// ---------- IMPOSSÍVEL (-2) ----------
// Regras básicas e casos sem solução válida

// Todos X: impossível (O nunca jogou)
TEST(VelhaTest, ImpossivelTodosX) {
    int tab[3][3] = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    EXPECT_EQ(-2, Jogar(tab));
}

// O tem mais jogadas que X (O começou): impossível
TEST(VelhaTest, ImpossivelOMaisQueX) {
    int tab[3][3] = {
        {2,0,0},
        {0,0,0},
        {0,0,0}
    };
    EXPECT_EQ(-2, Jogar(tab));
}

// Diferença de contagem > 1: impossível
TEST(VelhaTest, ImpossivelXComDuasJogadasAMais) {
    int tab[3][3] = {
        {1,1,0},
        {1,0,0},
        {0,0,0}
    };
    EXPECT_EQ(-2, Jogar(tab));
}

// X vence mas contagem não permite (X deveria ter jogado por último)
TEST(VelhaTest, ImpossivelXVenceMasContagemNaoPermite) {
    int tab[3][3] = {
        {1,1,1}, // X venceu
        {2,2,0},
        {0,0,0}
    };
    // torna impossível: iguala contagem
    tab[2][2] = 2; // X=3, O=3 e X vencedor -> inválido
    EXPECT_EQ(-2, Jogar(tab));
}

// O vence mas contagem não permite (O deveria ter jogado por último)
TEST(VelhaTest, ImpossivelOVenceMasContagemNaoPermite) {
    int tab[3][3] = {
        {2,2,2}, // O venceu
        {1,1,0},
        {0,0,0}
    };
    // torna impossível: iguala contagem
    tab[1][2] = 1; // X=3, O=3 e O vencedor -> inválido
    EXPECT_EQ(-2, Jogar(tab));
}

// Valores inválidos
TEST(VelhaTest, ImpossivelValorInvalidoNegativo) {
    int tab[3][3] = {
        {-1,0,0},
        {0,0,0},
        {0,0,0}
    };
    EXPECT_EQ(-2, Jogar(tab));
}

TEST(VelhaTest, ImpossivelValorInvalidoMaiorQue2) {
    int tab[3][3] = {
        {3,0,0},
        {0,0,0},
        {0,0,0}
    };
    EXPECT_EQ(-2, Jogar(tab));
}

// Dois alinhamentos vencedores do MESMO jogador (tratado como impossível aqui)
TEST(VelhaTest, ImpossivelXVenceEmDuasLinhasSimultaneas) {
    int tab[3][3] = {
        {1,1,1},
        {1,1,1},
        {2,2,0}
    };
    EXPECT_EQ(-2, Jogar(tab));
}

TEST(VelhaTest, ImpossivelOVenceEmDuasColunasSimultaneas) {
    int tab[3][3] = {
        {2,0,2},
        {2,1,2},
        {2,1,0}
    };
    EXPECT_EQ(-2, Jogar(tab));
}
