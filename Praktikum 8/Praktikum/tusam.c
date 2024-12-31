#include <stdio.h>
#include "map.h"
#include "boolean.h"

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    Map map;
    CreateEmpty(&map);

    long long count = 0;

    for (int i = 0; i < N; i++) {
        int complement = K - arr[i];

        // Check if the complement exists in the map
        if (IsMember(map, complement)) {
            count += Value(map, complement);
        }

        // Insert or update the current value in the map
        if (IsMember(map, arr[i])) {
            for (int j = 0; j < map.Count; j++) {
                if (map.Elements[j].Key == arr[i]) {
                    map.Elements[j].Value++;
                    break;
                }
            }
        } else {
            Insert(&map, arr[i], 1);
        }
    }

    printf("%lld\n", count);

    return 0;
}
