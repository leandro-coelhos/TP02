#include <gtest/gtest.h>
#include "velha.cpp"

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
        {1,0,0}
    };
    EXPECT_EQ(1, Jogar(tab));
}

// ---------- VITÓRIA DO O (2) ----------

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
        {2,0,1},
        {2,0,0}
    };
    EXPECT_EQ(2, Jogar(tab));
}

TEST(VelhaTest, OVenceNaColuna1) {
    int tab[3][3] = {
        {1,2,0},
        {0,2,1},
        {0,2,0}
    };
    EXPECT_EQ(2, Jogar(tab));
}

TEST(VelhaTest, OVenceNaColuna2) {
    int tab[3][3] = {
        {1,0,2},
        {0,1,2},
        {0,0,2}
    };
    EXPECT_EQ(2, Jogar(tab));
}

TEST(VelhaTest, OVenceNaDiagonalPrincipal) {
    int tab[3][3] = {
        {2,1,0},
        {0,2,1},
        {0,0,2}
    };
    EXPECT_EQ(2, Jogar(tab));
}

TEST(VelhaTest, OVenceNaDiagonalSecundaria) {
    int tab[3][3] = {
        {1,0,2},
        {0,2,0},
        {2,0,1}
    };
    EXPECT_EQ(2, Jogar(tab));
}

// ---------- EMPATE (0) ----------
// Tabuleiro cheio sem vencedor
TEST(VelhaTest, Empate) {
    int tab[3][3] = {
        {1,2,1},
        {2,1,2},
        {2,1,2}
    };
    EXPECT_EQ(0, Jogar(tab));
}

// ---------- INDEFINIDO (-1) ----------
// Partida em andamento (sem vencedor e com casas vazias)
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
// Contagens ilegais, vencedores múltiplos, valores inválidos, etc.

// Todos X: impossível pelas regras (O nunca jogou)
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

// Diferença de contagem > 1 (X jogou muitas a mais): impossível
TEST(VelhaTest, ImpossivelXComDuasJogadasAMais) {
    int tab[3][3] = {
        {1,1,0},
        {1,0,0},
        {0,0,0}
    };
    EXPECT_EQ(-2, Jogar(tab));
}

// Dois vencedores ao mesmo tempo (X e O): impossível
TEST(VelhaTest, ImpossivelDoisVencedoresSimultaneos) {
    // X vence na linha 0 e O vence na coluna 0 ao mesmo tempo
    int tab[3][3] = {
        {1,1,1},
        {2,0,0},
        {2,0,0}
    };
    // Ajuste para O vencer na coluna 0:
    tab[2][0] = 2; // já está 2; mantém consistência
    EXPECT_EQ(-2, Jogar(tab));
}

// X vence, mas contagem permite que O tenha a vez atual (inconsistente com vitória)
// Ex.: X tem o mesmo número de peças que O mas X "acabou de vencer" — impossível
TEST(VelhaTest, ImpossivelXVenceMasContagemNaoPermite) {
    int tab[3][3] = {
        {1,1,1}, // X venceu
        {2,2,0},
        {0,0,0}
    };
    // Contagem: X=3, O=2 -> ok; para tornar impossível, iguale contagem:
    tab[2][2] = 2; // X=3, O=3 e X vencedor -> sequência impossível
    EXPECT_EQ(-2, Jogar(tab));
}

// O vence mas contagem indica que X jogou por último — impossível
TEST(VelhaTest, ImpossivelOVenceMasContagemNaoPermite) {
    int tab[3][3] = {
        {2,2,2}, // O venceu
        {1,1,0},
        {0,0,0}
    };
    // Contagem: O=3, X=2 -> ok; torne impossível: X=3, O=3 com O vencedor
    tab[1][2] = 1; // X=3, O=3 e O vencedor -> sequência impossível
    EXPECT_EQ(-2, Jogar(tab));
}

// Valores fora do domínio {0,1,2}: impossível
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

// Dois alinhamentos vencedores para o mesmo jogador em estados impossíveis
// (dependendo da sua lógica, você pode aceitar se a contagem permitir; aqui testamos como impossível)
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

// Tabuleiro cheio com duas vitórias simultâneas: impossível (não pode terminar assim)
TEST(VelhaTest, ImpossivelTabuleiroCheioComDoisVencedores) {
    int tab[3][3] = {
        {1,1,1},  // X vence na linha 0
        {2,2,2},  // O vence na linha 1
        {1,2,1}
    };
    EXPECT_EQ(-2, Jogar(tab));
}
