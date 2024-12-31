# include <stdio.h>
# include "subset.h"

boolean isSubset(Set S1, Set S2) {
    int i = 0;
    while (!IsEmpty(S1)) {
        if (IsMember(S1, i) && IsMember(S2, i)) {
            Delete(&S1, i);
        }
        Delete(&S2, i);
        if (IsEmpty(S2) && !IsEmpty(S1)) {
            return false;
        }
        i++;
    }
    return true;
}