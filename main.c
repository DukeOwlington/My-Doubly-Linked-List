#include "main.h"

// constant strings definitions
const static char * const menuChoice = "1: Insert at head\n"
    "2: Insert at tail\n"
    "3: Delete first\n"
    "4: Delete by index\n"
    "5: Delete last\n"
    "6: Print list\n"
    "7: Quit";

const static char * const incorrectMessage = "Incorrect choice";

enum MenuPoints {
  INSERT_AT_HEAD = 1,
  INSERT_AT_TAIL,
  DELETE_FIRST,
  DELETE_BY_INDEX,
  DELETE_LAST,
  PRINT_LIST,
  QUIT
};

// print menu points string
void PrintMenu(void) {
  puts(menuChoice);
}

int RequestNumber(char *purpouse) {
  int number = 0;
  int num_length = 10;
  int base = 10;
  printf("%s", purpouse);
  char *string_number = CreateString(num_length);
  number = strtol(string_number, NULL, base);
  return number;
}

int main() {
  MenuPoints menu_point;
  Node *head = NULL;
  char *purpouse;
  int number = 0;
  while (menu_point != QUIT) {
    PrintMenu();
    scanf("%d", (int*) &menu_point);
    getchar();
    switch (menu_point) {
      case INSERT_AT_HEAD:
        purpouse = "Enter the number you want to insert: ";
        number = RequestNumber(purpouse);
        head = InsertAtHead(head, number);
        break;
      case INSERT_AT_TAIL:
        purpouse = "Enter the number you want to insert: ";
        number = RequestNumber(purpouse);
        head = InsertAtTail(head, number);
        break;
      case DELETE_FIRST:
        head = DeleteFirst(head);
        break;
      case DELETE_BY_INDEX:
        purpouse = "Enter the index of number: ";
        number = RequestNumber(purpouse);
        head = DeleteByIndex(head, number);
        break;
      case DELETE_LAST:
        head = DeleteLast(head);
        break;
      case PRINT_LIST:
        Print(head);
        break;
      case QUIT:
        head = DeleteList(head);
        break;
      default:
        puts(incorrectMessage);
        break;
    }
  }
  return EXIT_SUCCESS;
}
