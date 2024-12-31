# include <stdio.h>
# include <stdlib.h>
# include "arrayGames.h"

void UrusToko(TabGames games, int Q) {
    for (int i = 0; i < Q; i++) {
        int aksi;
        scanf("%d", &aksi);
        if (aksi == 0) {
            TulisIsi(games);
        } else if (aksi == 1) {
            int maxRating = MaxRating(games);
            printf("%d\n", JumlahGamesRating(games, maxRating));
        } else if (aksi == 2) {
            printf("%s\n", MinHargaNama(games));
        } else if (aksi == 3) {
            int maxRating = MaxRating(games);
            for (int i = 1; i <= games.Neff; i++) {
                if (games.TI[i].rating == maxRating) {
                    printf("%s\n", games.TI[i].nama);
                }
            }
        }
    }
}