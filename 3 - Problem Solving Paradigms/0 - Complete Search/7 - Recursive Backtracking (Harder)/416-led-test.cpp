int leds[12], N, numbers[10];
string line;

void genNumbers() {
    memset(numbers, 0, sizeof numbers);
    // Zero
    for (int i=0 ; i<6 ; i++)
        numbers[0] |= (1 << i);
    // One
    numbers[1] |= (1 << 1);
    numbers[1] |= (1 << 2);
    // Two
    numbers[2] |= (1 << 0);
    numbers[2] |= (1 << 1);
    numbers[2] |= (1 << 3);
    numbers[2] |= (1 << 4);
    numbers[2] |= (1 << 6);
    // Three
    for (int i=0 ; i<4 ; i++)
        numbers[3] |= (1 << i);
    numbers[3] |= (1 << 6);
    // Four
    numbers[4] |= (1 << 1);
    numbers[4] |= (1 << 2);
    numbers[4] |= (1 << 5);
    numbers[4] |= (1 << 6);
    // Five
    numbers[5] |= (1 << 0);
    numbers[5] |= (1 << 2);
    numbers[5] |= (1 << 3);
    numbers[5] |= (1 << 5);
    numbers[5] |= (1 << 6);
    // Six
    numbers[6] |= (1 << 0);
    for (int i=2 ; i<7 ; i++)
        numbers[6] |= (1 << i);
    // Seven
    numbers[7] |= (1 << 0);
    numbers[7] |= (1 << 1);
    numbers[7] |= (1 << 2);
    // Eight
    for (int i=0 ; i<7 ; i++)
        numbers[8] |= (1 << i);
    // Nine
    for (int i=0 ; i<4 ; i++)
        numbers[9] |= (1 << i);
    numbers[9] |= (1 << 5);
    numbers[9] |= (1 << 6);
}

int canformSequence(int ledState, int numberToForm, int ledsTurnedOff) {
    int newNumber = numbers[numberToForm];

    for (int i=0 ; i<7 ; i++) {
        if (ledsTurnedOff & (1 << i)) {
            newNumber &= ~(1 << i);
        }
    }

    int ledsOn = __builtin_popcount(newNumber);
    if (__builtin_popcount(newNumber | ledState) == ledsOn) {
        for (int i=0 ; i<7 ; i++) {
            if ((newNumber & (1 << i)) && !(ledState & (1 << i)))
                ledsTurnedOff |= (1 << i);
        }
        return ledsTurnedOff;
    }
    return -1;
}

bool solve(int ledIndex, int countDown, int turnedOff) {
    if (countDown < 0) return false;
    if (ledIndex == N) return true;
    int newTurnedOff = canformSequence(leds[ledIndex], countDown-1, turnedOff);
    if (newTurnedOff != -1)
        return solve(ledIndex+1, countDown-1, newTurnedOff);

    return false;
}

int main() {

    genNumbers();

    while (scanf("%d\n", &N), N) {
        memset(leds, 0, sizeof leds);
        for (int i=0 ; i<N ; i++) {
            getline(cin, line);

            for (int j=0 ; j<7 ; j++) if (line[j] == 'Y')
                leds[i] |= (1 << j);
        }
        bool solved = false;
        for (int i=9 ; i>=0 ; i--) {
            int ledsOn = __builtin_popcount(numbers[i]);
            if (__builtin_popcount(leds[0] | numbers[i]) == ledsOn) {
                int turnedOff = 0;
                for (int j=0 ; j<7 ; j++) {
                    if ((numbers[i] & (1 << j)) && !(leds[0] & (1 << j))) {
                        turnedOff |= (1 << j);
                    }
                }
                if (solve(1, i, turnedOff)) {
                    printf("MATCH\n");
                    solved = true;
                    break;
                }
            }
        }

        if (!solved)
            printf("MISMATCH\n");
    }
}