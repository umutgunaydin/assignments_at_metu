#include <stdio.h>

int main() {

    int i, j, k;
    int num_of_parties;
    int num_of_deputies;
    int number_of_votes[26];
    int maxNumberOfVotes = 0;
    float quotients[26];
    int indexesOfMaxQuotients[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0};
    int number_of_held_seats[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                    0, 0, 0, 0, 0};
    char parties_in_order[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                 'I', 'J', 'K', 'L', 'M', 'N', 'O',
                                 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
                                 'X', 'Y', 'Z'};

    scanf("%d %d\n", &num_of_parties, &num_of_deputies);

    scanf("%d", &number_of_votes[0]);
    for (i = 1; i < num_of_parties; i++) {
        scanf(" %d", &number_of_votes[i]);
    }

    for (k = num_of_deputies; k > 0; k--) {
        float maxQuotient = 0;
        int indexOfMaxQuotient;
        int countOfMaxOfQuotients = 0;

        for (i = 0; i < num_of_parties; i++) {
            quotients[i] = (float) ((float )number_of_votes[i] / (float )(number_of_held_seats[i] + 1));
        }

        for (i = 0; i < num_of_parties; i++) {
            if (maxQuotient < quotients[i]) {
                maxQuotient = quotients[i];
                indexOfMaxQuotient = i;
            }
        }
        for (i = 0; i < num_of_parties; i++) {
            if (maxQuotient == quotients[i]) {
                countOfMaxOfQuotients++;
            }
        }
        if (countOfMaxOfQuotients == 1) {
            number_of_held_seats[indexOfMaxQuotient] += 1;
        } else {
            i = 0;
            for (j = indexOfMaxQuotient; j < num_of_deputies; j++) {
                if (quotients[j] == maxQuotient) {
                    indexesOfMaxQuotients[i++] = j;
                }
            }

            maxNumberOfVotes = number_of_votes[indexOfMaxQuotient];
            for (i = 0; i < countOfMaxOfQuotients; i++) {
                if (maxNumberOfVotes < number_of_votes[indexesOfMaxQuotients[i]]) {
                    indexOfMaxQuotient = indexesOfMaxQuotients[i];
                }
            }

            number_of_held_seats[indexOfMaxQuotient] += 1;

        }
    }
    for (i = 0; i <num_of_parties ; i++) {
        int l,t;
        int max=0;
        int indexOfMaxDeputy;

        for (l = 0; l < num_of_parties; l++) {
            if(max<number_of_held_seats[l]){
                max=number_of_held_seats[l];
            }
        }
        if(max==0){
            continue;
        }
        for (t = 0; t < num_of_parties; t++) {
            if(number_of_held_seats[t]==max){
                indexOfMaxDeputy=t;
                break;
            }
        }
        printf("%c: %d\n",parties_in_order[indexOfMaxDeputy],number_of_held_seats[indexOfMaxDeputy]);
        number_of_held_seats[indexOfMaxDeputy]=0;
    }

    return 0;
}

