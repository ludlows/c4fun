#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value>=2 && c.value<=VALUE_ACE);
  assert(c.suit>=SPADES && c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  if(r == STRAIGHT_FLUSH) return "STRAIGHT_FLUSH";
  else if (r == FOUR_OF_A_KIND) return "FOUR_OF_A_KIND";
  else if (r == FULL_HOUSE) return "FULL_HOUSE";
  else if (r == FLUSH) return "FLUSH";
  else if (r == STRAIGHT) return "STRAIGHT";
  else if (r == THREE_OF_A_KIND) return "THREE_OF_A_KIND";
  else if (r == TWO_PAIR) return "TWO_PAIR";
  else if (r == PAIR) return "PAIR";
  else if (r == NOTHING) return "NOTHING";
  return "ERROR";  
}

char value_letter(card_t c) {
  if (c.value == 2 ) return '2';
  else if (c.value == 3) return '3';
  else if (c.value == 4) return '4';
  else if (c.value == 5) return '5';
  else if (c.value == 6) return '6';
  else if (c.value == 7) return '7';
  else if (c.value == 8) return '8';
  else if (c.value == 9) return '9';
  else if (c.value == 10) return '0';
  else if (c.value == 11) return 'J';
  else if (c.value == 12) return 'Q';
  else if (c.value == 13) return 'K';
  else if (c.value == 14) return 'A';
  return '!';
}


char suit_letter(card_t c) {
  if(c.suit == SPADES) return 's';
  else if (c.suit == HEARTS) return 'h';
  else if (c.suit == DIAMONDS) return 'd';
  else if (c.suit == CLUBS) return 'c';
  return '!';
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c),suit_letter(c)); 
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  if(value_let == '2') temp.value = 2;
  else if(value_let == '3') temp.value = 3;
  else if(value_let == '4') temp.value = 4;
  else if(value_let == '5') temp.value = 5;
  else if(value_let == '6') temp.value = 6;
  else if(value_let == '7') temp.value = 7;
  else if(value_let == '8') temp.value = 8;
  else if(value_let == '9') temp.value = 9;
  else if(value_let == '0') temp.value = 10;
  else if(value_let == 'J') temp.value = 11;
  else if(value_let == 'Q') temp.value = 12;
  else if(value_let == 'K') temp.value = 13;
  else if(value_let == 'A') temp.value = 14;
  else{
    printf("the letter of value is invalid. EXIT.\n ");
    exit(EXIT_FAILURE);
  }

  if(suit_let == 's') temp.suit = SPADES;
  else if (suit_let == 'h') temp.suit = HEARTS;
  else if (suit_let == 'd') temp.suit = DIAMONDS;
  else if (suit_let == 'c') temp.suit = CLUBS;
  else {
    printf("the letter of suit is invalid. EXIT.\n");
    exit(EXIT_FAILURE);
  }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  if(c/13 ==0) temp.suit = SPADES;
  else if (c/13 == 1) temp.suit = HEARTS;
  else if (c/13 == 2) temp.suit = DIAMONDS;
  else if (c/13 == 3) temp.suit = CLUBS;
  temp.value = c % 13 + 2;
  return temp;
}
