static constexpr uint8_t COL0_PIN = 13;
static constexpr uint8_t COL1_PIN = 12;
static constexpr uint8_t COL2_PIN = 11;

static constexpr uint8_t ROW0_PIN = A0;
static constexpr uint8_t ROW1_PIN = A1;
static constexpr uint8_t ROW2_PIN = A2;

static constexpr uint8_t LED1_PIN = 1;
static constexpr uint8_t LED2_PIN = 2;
static constexpr uint8_t LED3_PIN = 3;
static constexpr uint8_t LED4_PIN = 4;
static constexpr uint8_t LED5_PIN = 5;
static constexpr uint8_t LED6_PIN = 6;
static constexpr uint8_t LED7_PIN = 7;
static constexpr uint8_t LED8_PIN = 8;
static constexpr uint8_t LED9_PIN = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  
}
 
int16_t evaluate() {
  // evaluate diagonals
  if (pin) {
    if (LED1_PIN == 1) {
      return -10;
    } else {
      return 10;
    }
  }

  if (LED7_PIN == LED5_PIN && LED5_PIN == LED3_PIN) {
    if (board[2][0] == PLAYER1) {
      return -10;
    } else if (board[2][0] == PLAYER2) {
      return 10;
    }
  }

  // evaluate rows
  for (uint8_t row = 0; row < BOARD_SIZE; ++row) {
    if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
      if (board[row][0] == PLAYER1) {
        return -10;
      } else if (board[row][0] == PLAYER2) {
        return 10;
      }
    }
  }

  // evaluate columns
  for (uint8_t col = 0; col < BOARD_SIZE; ++col) {
    if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
      if (board[0][col] == PLAYER1) {
        return -10;
      } else if (board[0][col] == PLAYER2) {
        return 10;
      }
    }
  }

  return 0;
}

bool isMoveLeft() {
  for (uint8_t row = 0; row < BOARD_SIZE; ++row) {
    for (uint8_t col = 0; col < BOARD_SIZE; ++col) {
      if (board[row][col] == NONE) {
        return true;
      }
    }
  }
  return false;
}